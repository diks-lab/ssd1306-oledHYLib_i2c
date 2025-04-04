//--------------------------------------------------------------
// Class メンバ関数の中身を定義
// version 0.91 / 20230914
//
// I2C アレンジ 2025.03.31
//--------------------------------------------------------------
#include <Arduino.h>
#include <pgmspace.h>
#include <Wire.h>

#include "oledHYLib_i2c.h" // Classの定義

OLEDHY &dispHY = dispHY.getInstance();

// ----- prototype
char *num2str(int num, char *str);

#define NUMofSPIDATA 20
const uint8_t SSD1306_init_params[] PROGMEM = {
    0x8A, 0x3F, // Set Multiplex Ratio  0xA8, 0x3F
    0xD3, 0x00, // Set Display Offset 0xD3, 0x00
    0x40,       // Set Display Start Line 0x40
    0xA1,       // Set Segment re-map 0xA0/0xA1   =>  A1:column address 127 is mapped to SEG0
    0xC8,       // Set COM Output Scan Direction 0xC0,/0xC8
    0xDA, 0x12, // Set COM Pins hardware configuration 0xDA => 0x02:Alternative
    0x81, 0x7F, // Set Contrast Control 0x81,     => default=0x7F
    0xA4,       // Disable Entire Display On
    0xA6,       // Set Normal Display 0xA6, Inverse display 0xA7
    0xD5, 0x80, // Set Display Clock Divide Ratio/Oscillator Frequency 0xD5, 0x80
    0x20, 0x00, // Set Memory Addressing Mode     => 00b: Horizontal Addressing Mode
    0x8D, 0x14, // Charge Pump Command Table 0x8D => 0x14: Enable Charge Pump
    0xAF        // Display On
};

//-----------------------------------------------------
// low level SSD1306 OLED library
//-----------------------------------------------------

// ------ get instance -----
OLEDHY &OLEDHY::getInstance()
{
  static OLEDHY instance;
  return instance;
}

// ------ initialize ------
void OLEDHY::begin(uint8_t lcd_Addr)
{
  if (_initialised)
    return;

  _Addr = lcd_Addr;

  // init.I2C
  Wire.begin();
  Wire.setClock(Frequensy_OLED);

  Wire.beginTransmission(_Addr);
  Wire.write(0b00000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (command) follow Max=31byte
  for (int i = 0; i < NUMofSPIDATA; i++)
  {
    Wire.write((uint8_t)pgm_read_byte(SSD1306_init_params + i));
  }
  Wire.endTransmission();
  _initialised = true;
}
// ------ display on ------
void OLEDHY::disp_on(void)
{
  Wire.beginTransmission(_Addr);
  Wire.write(0b10000000);
  Wire.write(0xAF);
  Wire.endTransmission();
}
// ------ display off ------
void OLEDHY::disp_off(void)
{
  Wire.beginTransmission(_Addr);
  Wire.write(0b10000000);
  Wire.write(0xAE);
  Wire.endTransmission();
}

void OLEDHY::invertScreen(void)
{
  Wire.beginTransmission(_Addr);
  Wire.write(0b00000000);
  Wire.write(0xA0);
  Wire.write(0xC0);
  Wire.endTransmission();
}

void OLEDHY::set_rect(uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage)
{
  Wire.beginTransmission(_Addr);
  Wire.write(0b00000000); // control byte, Co bit = 0 (continue), D/C# = 0 (command)
  Wire.write(0x21);       // 描画範囲指定　x:ドット単位 0から
  Wire.write(XstartBit);
  Wire.write(XstartBit + XlengthBit - 1); // x:16-27 (27含む) 12dot
  Wire.write(0x22);                       // 描画範囲指定　y:PAGE(8ドット unsigned char)単位 0から
  Wire.write(YstartPage);
  Wire.write(YstartPage + YlengthPage - 1); // y:1-3 (3含む) 3 PAGE
  Wire.endTransmission();
}

void OLEDHY::drawRect(uint8_t *p, uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage)
{
  set_rect(XstartBit, YstartPage, XlengthBit, YlengthPage);
  for (int i = 0; i < XlengthBit * YlengthPage; i++)
  {
    Wire.beginTransmission(_Addr);
    Wire.write(0b11000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    Wire.write(*p++);
    Wire.endTransmission();
  }
}

void OLEDHY::drawRect_pgm(uint8_t *p, uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage)
{
  set_rect(XstartBit, YstartPage, XlengthBit, YlengthPage);
  Wire.beginTransmission(_Addr);
  Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
  for (int i = 0; i < XlengthBit * YlengthPage; i++)
  {
    Wire.write(*p++);
  }
  Wire.endTransmission();
}

void OLEDHY::fillRect(uint8_t PagePat, uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage)
{
  set_rect(XstartBit, YstartPage, XlengthBit, YlengthPage);
  for (int i = 0; i < XlengthBit * YlengthPage; i++)
  {
    Wire.beginTransmission(_Addr);
    Wire.write(0b11000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    Wire.write(PagePat);
    Wire.endTransmission();
  }
}

void OLEDHY::clearRect(uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage)
{
  fillRect(0x00, XstartBit, YstartPage, XlengthBit, YlengthPage);
}

void OLEDHY::clearFullPage(void)
{
  fillRect(0x00, 0, 0, OLED_XSIZE_BIT, OLED_YSIZE_PAGE);
}

//---------------------------------------------------------------------------------------------------
//  over load functions    attr : 0:normal  1:underline 2:reverse
//---------------------------------------------------------------------------------------------------
void OLEDHY::draw_stringHYm(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_stringHYm((char *)s, XstartBit, YstartPage, fontwidth);
}
//  over load    attr : 0:normal  1:underline 2:reverse
void OLEDHY::draw_stringHYm(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_stringHYm(s, XstartBit, YstartPage, fontwidth, 0);
}
// over load
void OLEDHY::draw_stringHYm(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0)
{
  OLEDHY::draw_stringHYm((char *)s, XstartBit, YstartPage, fontwidth, att0);
}
// overload ------ draw Ssize strings     attr : 0:normal  1:underline 2:reverse------
void OLEDHY::draw_stringHYs(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_stringHYs((char *)s, XstartBit, YstartPage, fontwidth, 0);
}
// overload ------ draw Ssize strings     attr : 0:normal  1:underline 2:reverse------
void OLEDHY::draw_stringHYs(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_stringHYs(s, XstartBit, YstartPage, fontwidth, 0);
}
// overload
void OLEDHY::draw_stringHYs(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0)
{
  OLEDHY::draw_stringHYs((char *)s, XstartBit, YstartPage, fontwidth, att0);
}
// overload
void OLEDHY::draw_dual_stringHYm(const char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_dual_stringHYm((char *)s0, (char *)s1, XstartBit, YstartPage, fontwidth, 0, 0);
}
// overload
void OLEDHY::draw_dual_stringHYm(const char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_dual_stringHYm((char *)s0, (char *)s1, XstartBit, YstartPage, fontwidth, 0, 0);
}
// overload
void OLEDHY::draw_dual_stringHYm(char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_dual_stringHYm((char *)s0, (char *)s1, XstartBit, YstartPage, fontwidth, 0, 0);
}
// overload
void OLEDHY::draw_dual_stringHYm(char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_dual_stringHYm(s0, s1, XstartBit, YstartPage, fontwidth, 0, 0);
}
// overload
void OLEDHY::draw_dual_stringHYm(const char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1)
{
  OLEDHY::draw_dual_stringHYm((char *)s0, (char *)s1, XstartBit, YstartPage, fontwidth, att0, att1);
}
// overload
void OLEDHY::draw_dual_stringHYm(const char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1)
{
  OLEDHY::draw_dual_stringHYm((char *)s0, (char *)s1, XstartBit, YstartPage, fontwidth, att0, att1);
}
// overload
void OLEDHY::draw_dual_stringHYm(char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1)
{
  OLEDHY::draw_dual_stringHYm((char *)s0, (char *)s1, XstartBit, YstartPage, fontwidth, att0, att1);
}
// overload
void OLEDHY::draw_num_m(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_num_m(num, XstartBit, YstartPage, fontwidth, 0);
}
// overload
void OLEDHY::draw_num_s(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  OLEDHY::draw_num_s(num, XstartBit, YstartPage, fontwidth, 0);
}
//---------------------------------------------------------------------------------------------------
// ------ draw Msize strings     attr : 0:normal  1:underline 2:reverse------
//---------------------------------------------------------------------------------------------------
void OLEDHY::draw_stringHYm(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0)
{
  uint8_t d;
  uint8_t strlength = 128 / 6; // max
  int code;
  uint8_t *p;

  // check strings length
  for (int i = 0; i < OLED_XSIZE_BIT; i++)
  {
    if (s[i] == 0)
    {
      strlength = i;
      break;
    }
  }

  // --------------------------------------------------------------
  // 一括 set_rect() 方式
  set_rect(XstartBit, YstartPage, fontwidth * strlength, 2);
  // --------------------------------------------------------------
  // ----- 1 char の上半分の処理を文字数分
  for (int i = 0; i < strlength; i++)
  {
    int j;
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    code = s[i] - 0x20;
    p = (uint8_t *)VfontHYm[code][0];
    for (j = 0; j < mFONTWIDTH; j++)
    {
      d = pgm_read_byte(p++);
      if (att0 == 2)
        d ^= 0xfe;
      Wire.write(d);
    }
    Wire.endTransmission();

    // 文字間生成
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (; j < fontwidth; j++)
    {
      d = 0;
      if (att0 == 2)
        d ^= 0xfe;
      Wire.write(d);
    }
    Wire.endTransmission();
  }
  // ----- 1 char の下半分の処理を文字数分
  for (int i = 0; i < strlength; i++)
  {
    int j;
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    code = s[i] - 0x20;
    p = (uint8_t *)VfontHYm[code][1];
    for (j = 0; j < mFONTWIDTH; j++)
    {
      d = pgm_read_byte(p++);
      if (att0 == 1)
        d |= 0x40;
      if (att0 == 2)
        d ^= 0x7f;
      Wire.write(d);
    }
    Wire.endTransmission();
    // 文字間生成
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (; j < fontwidth; j++)
    {
      d = 0;
      if (att0 == 1)
        d |= 0x40;
      if (att0 == 2)
        d ^= 0x7f;
      Wire.write(d);
    }
    Wire.endTransmission();
  }
}

//---------------------------------------------------------------------------------------------------
// ------ draw Ssize strings     attr : 0:normal  1:underline 2:reverse------
//---------------------------------------------------------------------------------------------------
void OLEDHY::draw_stringHYs(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0)
{
  uint8_t d;
  uint8_t strlength = 128 / 6; // max
  int code;
  uint8_t *p;

  // --------------------------------------------------------------
  // check strings length
  for (int i = 0; i < OLED_XSIZE_BIT; i++)
  {
    if (s[i] == 0)
    {
      strlength = i;
      break;
    }
  }

  // --------------------------------------------------------------
  // 一括 set_rect() 方式
  set_rect(XstartBit, YstartPage, fontwidth * strlength, 1);
  // --------------------------------------------------------------
  // ----- 1 char の上半分の処理を文字数分
  for (int i = 0; i < strlength; i++)
  {
    int j;
    code = s[i] - 0x20;
    p = (uint8_t *)VfontHYs[code];
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (j = 0; j < sFONTWIDTH; j++)
    {
      d = pgm_read_byte(p++);
      if (att0 == 1)
        d |= 0x80;
      if (att0 == 2)
        d ^= 0x7f;
      Wire.write(d);
    }
    Wire.endTransmission();
    // 文字間生成
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (; j < fontwidth; j++)
    {
      d = 0;
      if (att0 == 1)
        d |= 0x80;
      if (att0 == 2)
        d ^= 0x7f;
      Wire.write(d);
    }
    Wire.endTransmission();
  }
}

//----------------------------------------------------------------------------------------------------
//  Draw dual strings / 3page(24dot lines)
//----------------------------------------------------------------------------------------------------
void OLEDHY::draw_dual_stringHYm(char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1)
{
  uint8_t d;
  uint8_t strlength0 = 128 / 6, strlength1 = 128 / 6, max_strl; // max
  uint8_t code0, code1;
  uint8_t *p0, *p1;

  // check strings length
  for (int i = 0; i < OLED_XSIZE_BIT; i++)
  {
    if (s0[i] == 0)
    {
      strlength0 = i;
      break;
    }
  }
  for (int i = 0; i < OLED_XSIZE_BIT; i++)
  {
    if (s1[i] == 0)
    {
      strlength1 = i;
      break;
    }
  }
  max_strl = strlength0;
  if (strlength0 < strlength1)
    max_strl = strlength1;
  //

  // --------------------------------------------------------------
  // 一括 set_rect() 方式
  set_rect(XstartBit, YstartPage, fontwidth * max_strl, 3);
  // --------------------------------------------------------------
  // ----- 1 pageの処理を文字数分
  for (int i = 0; i < max_strl; i++)
  {
    int j;
    if (i < strlength0)
      code0 = s0[i] - 0x20;
    else
      code0 = 0;
    if (i < strlength1)
      code1 = s1[i] - 0x20;
    else
      code1 = 0;
    p0 = (uint8_t *)VfontHYm[code0][0]; // 1行目の上
    p1 = (uint8_t *)VfontHYm[code0][1]; // 2行目の下
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (j = 0; j < mFONTWIDTH; j++)
    {
      d = (pgm_read_byte(p0++) >> 1) | (pgm_read_byte(p1++) << 7);
      if (att0 == 2)
        d ^= 0xff;
      Wire.write(d);
    }
    Wire.endTransmission();
    // 文字間生成
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (; j < fontwidth; j++)
    {
      d = 0;
      if (att0 == 2)
        d ^= 0xff;
      Wire.write(d);
    }
    Wire.endTransmission();
  }
  // ----- 2 pageの処理を文字数分
  for (int i = 0; i < max_strl; i++)
  {
    int j;
    if (i < strlength0)
      code0 = s0[i] - 0x20;
    else
      code0 = 0;
    if (i < strlength1)
      code1 = s1[i] - 0x20;
    else
      code1 = 0;
    p0 = (uint8_t *)VfontHYm[code0][1]; // 1行目の下
    p1 = (uint8_t *)VfontHYm[code1][0]; // 2行目の上
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (j = 0; j < mFONTWIDTH; j++)
    {
      d = (pgm_read_byte(p0++) >> 1) | (pgm_read_byte(p1++) << 3);
      if (att0 == 1)
        d |= 0x08;
      if (att0 == 2)
        d ^= 0x0f;
      if (att1 == 2)
        d ^= 0xf0;
      Wire.write(d);
    }
    Wire.endTransmission();
    // 文字間生成
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (; j < fontwidth; j++)
    {
      d = 0;
      if (att0 == 1)
        d |= 0x08;
      if (att0 == 2)
        d ^= 0x0f;
      if (att1 == 2)
        d ^= 0xf0;
      Wire.write(d);
    }
    Wire.endTransmission();
  }

  // ----- 3 page の下半分の処理を文字数分
  for (int i = 0; i < max_strl; i++)
  {
    int j;
    if (i < strlength1)
      code1 = s1[i] - 0x20;
    else
      code1 = 0;
    p0 = (uint8_t *)VfontHYm[code1][0];
    p1 = (uint8_t *)VfontHYm[code1][1];
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (j = 0; j < mFONTWIDTH; j++)
    {
      d = (pgm_read_byte(p0++) >> 5) | (pgm_read_byte(p1++) << 3);
      if (att1 == 1)
        d |= 0x80;
      if (att1 == 2)
        d ^= 0xff;
      Wire.write(d);
    }
    Wire.endTransmission();
    // 文字間生成
    Wire.beginTransmission(_Addr);
    Wire.write(0b01000000); // control byte, Co bit = 1 (1byte only), D/C# = 0 (data)
    for (; j < fontwidth; j++)
    {
      d = 0;
      if (att1 == 1)
        d |= 0x80;
      if (att1 == 2)
        d ^= 0xff;
      Wire.write(d);
    }
    Wire.endTransmission();
  }
}
//-------------------------------------------------------------------------------
// ★ VfontHYm pgm_read_byte()
void OLEDHY::draw_VfontHYm(int code, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  if (code < 0x20 || code > 0x7f)
    code = 0x20; // blabk char
  code -= 0x20;
  drawRect_pgm((uint8_t *)VfontHYm[code][0], XstartBit, YstartPage, mFONTWIDTH, 1);
  drawRect_pgm((uint8_t *)VfontHYm[code][1], XstartBit, YstartPage + 1, mFONTWIDTH, 1);
  /*
    if ( fontwidth > sFONTWIDTH )
      OLEDHY::fillRect( 0x00, XstartBit + mFONTWIDTH, YstartPage, fontwidth - sFONTWIDTH , 2 );
  */
}

// ★ VfontHYs pgm_read_byte()
void OLEDHY::draw_VfontHYs(int code, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth)
{
  if (code < 0x20 || code > 0x7f)
    code = 0x20; // blabk char
  code -= 0x20;
  drawRect_pgm((uint8_t *)VfontHYs[code], XstartBit, YstartPage, sFONTWIDTH, 1);
  if (fontwidth > sFONTWIDTH)
    OLEDHY::fillRect(0x00, XstartBit + sFONTWIDTH, YstartPage, fontwidth - sFONTWIDTH, 1);

  drawRect_pgm((uint8_t *)VfontHYs[(uint8_t)code], XstartBit, YstartPage, sFONTWIDTH, 1);
}

//-------------------------------------------------------------------------
//  Draw integer number
//-------------------------------------------------------------------------
void OLEDHY::draw_num_m(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t attr)
{
  char str[20];
  draw_stringHYm(num2str(num, str), XstartBit, YstartPage, fontwidth, attr);
}
void OLEDHY::draw_num_s(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t attr)
{
  char str[20];
  draw_stringHYs(num2str(num, str), XstartBit, YstartPage, fontwidth, attr);
}

// -------------------------------------------
char *num2str(int num, char *str)
{
  int point = 10;
  int n = num;

  str[point] = 0;
  if (num < 0)
    n = -num;
  if (n > 0)
  {
    while (n)
    {
      int wk = n / 10;
      str[--point] = (n - wk * 10) + '0';
      n = wk;
    }
  }
  else
  {
    str[--point] = '0';
  }
  if (num < 0)
    str[--point] = '-';
  return (str + point);
}
