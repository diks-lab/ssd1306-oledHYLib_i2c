#pragma once

#include "oledHYLib_font.h"

#define SSD1306_ADDRESS_LOW 0x3C
#define SSD1306_ADDRESS_HIGH 0x3D
#define SSD1306_ADDRESS SSD1306_ADDRESS_LOW

#define OLED_XSIZE_BIT 128
#define OLED_YSIZE_PAGE (64 / 8) // MSB が下
#define mFONTWIDTH 6
#define sFONTWIDTH 5

const uint32_t Frequensy_OLED = 400000; // Max=400kHz

//--------------------------------------------------------------------------------------------
//  ## class library ##
//--------------------------------------------------------------------------------------------
class OLEDHY
{
private:
  // ---------- コンストラクタ
  OLEDHY() = default;

public:
  static OLEDHY &getInstance();

  // ---------- メンバ関数（メソッド）の定義
  void begin(uint8_t lcd_Addr = SSD1306_ADDRESS); // 初期化
  void disp_on(void);                             // 表示する
  void disp_off(void);                            // 表示を消す　SSD1306内のHardwareBufferは消えない
  void invertScreen(void);                        // 上下反転

  // ---- clear/fill系　HardwareBufferを0x00クリアまたは、8bitのPagePatternでフィルする
  void clearFullPage(void); //
  void clearRect(uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage);
  void fillRect(uint8_t PagePat, uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage);
  // ---- area fill系　領域bitmapをまとめて転送　SRAM領域とFlash領域用(_pgm)がある
  void drawRect(uint8_t *p, uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage);
  void drawRect_pgm(uint8_t *p, uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage);

  // ---- draw singleFont　HYs: small 1 font(5*7) / 縦1page(8dot),  HYm: 1 midlle font(6*11)/ 縦2page(16dot)
  //  fontwidth: 空白を含むフォント横幅(fontの横dot数以上に設定のこと)
  void draw_VfontHYm(int code, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_VfontHYs(int code, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);

  // ---- draw strings　HYs: 1 Ssize font(5*7) / 1 page line(8dot),  HYm: 1 Msize font(6*11)/ 2 page line(16dot)
  // attribute有無の2種あり　　attribute:  0: non modification  1: under line , 2: reverse B/W
  void draw_stringHYm(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0);
  void draw_stringHYm(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_stringHYm(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0);
  void draw_stringHYm(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_stringHYs(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0);
  void draw_stringHYs(char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_stringHYs(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0);
  void draw_stringHYs(const char *s, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);

  // ---- draw dual strings  2 Msize font strings / 3 page line( 24dot)
  // attribute有無の2種あり　　attribute:  0: non modification  1: under line , 2: reverse B/W
  void draw_dual_stringHYm(char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1);
  void draw_dual_stringHYm(char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_dual_stringHYm(char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1);
  void draw_dual_stringHYm(char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_dual_stringHYm(const char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1);
  void draw_dual_stringHYm(const char *s0, char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_dual_stringHYm(const char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0, uint8_t att1);
  void draw_dual_stringHYm(const char *s0, const char *s1, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);

  // ---- 整数の表示
  void draw_num_m(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0);
  void draw_num_m(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);
  void draw_num_s(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth, uint8_t att0);
  void draw_num_s(int num, uint8_t XstartBit, uint8_t YstartPage, uint8_t fontwidth);

private:
  uint8_t _Addr;
  bool _initialised = false;

  void set_rect(uint8_t XstartBit, uint8_t YstartPage, uint8_t XlengthBit, uint8_t YlengthPage);
};

extern OLEDHY &dispHY;