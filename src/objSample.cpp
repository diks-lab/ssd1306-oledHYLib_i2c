#include "objSample.h"
#include "oledHYLib_i2c.h"

extern QueueHandle_t queue;

void ObjectA::run()
{
  while (1)
  {
    if (status())
    {
      for (int i = 0; i < 3; i++)
      {
        dispOled(_num + i);
        delay(500);
      }
      xQueueSend(queue, &_num, (TickType_t)0);
      _enabled = false;
    }
    delay(1);
  }
}

void ObjectA::dispOled(int attr)
{
  dispHY.clearRect(0, 2, 128, 6);
  dispHY.draw_stringHYm("# ", 0, 0, 6);
  dispHY.draw_num_m(attr, 12, 0, 6);

  dispHY.draw_stringHYm("DrawString M/S", 24, 0, 6);
  for (int w = 5; w < 10; w++)
  {
    dispHY.draw_stringHYm("FontWidth ", 0, 3, w + 1, attr);
    dispHY.draw_num_m(w + 1, 10 * (w + 1), 3, w + 1, attr);
    dispHY.draw_stringHYs("FontWidth ", 0, 6, w, attr);
    dispHY.draw_num_s(w, 10 * w, 6, w, attr);
    delay(250);
  }
}

void ObjectB::run()
{
  while (1)
  {
    if (status())
    {
      for (int i = 0; i < 3; i++)
      {
        dispOled(_num + i);
        delay(500);
      }
      xQueueSend(queue, &_num, (TickType_t)0);
      _enabled = false;
    }
    delay(1);
  }
}

void ObjectB::dispOled(int attr)
{
  dispHY.clearRect(0, 2, 128, 6);
  dispHY.draw_stringHYm("# ", 0, 0, 6);
  dispHY.draw_num_m(attr, 12, 0, 6);

  dispHY.draw_stringHYm("DrawDualString M", 24, 0, 6);
  for (int w = 5; w < 9; w++)
  {
    dispHY.draw_dual_stringHYm("FontWidth ", "ABCDEFGHIJKLMN", 0, w - 5 + 2, w + 1, attr, attr);
    dispHY.draw_num_m(w + 1, 10 * (w + 1), w - 5 + 2, w + 1, attr & 2);
    delay(500);
    if (w < 8)
      dispHY.clearRect(0, w - 5 + 2, 128, 3);
  }
}

void ObjectC::run()
{
  while (1)
  {
    if (status())
    {
      dispOled(_num);
      xQueueSend(queue, &_num, (TickType_t)0);
      _enabled = false;
    }
    delay(1);
  }
}

void ObjectC::dispOled(int attr)
{
  dispHY.clearRect(0, 2, 128, 6);
  dispHY.draw_stringHYm("# ", 0, 0, 6);
  dispHY.draw_num_m(attr, 12, 0, 6);

  dispHY.draw_stringHYm("DrawFont M", 24, 0, 6);
  for (int ch = 0x20; ch < 0x7f + 16; ch += 16)
  {
    int c = ch;
    for (int y = 2; y < 8; y += 2)
    {
      for (int x = 0; x < 128; x += 8)
      {
        dispHY.draw_VfontHYm(c++, x, y, 7);
        if (c >= 0x7f)
          c = 0x20;
      }
    }
    delay(500);
  }
}

void ObjectD::run()
{
  while (1)
  {
    if (status())
    {
      dispOled(_num);
      xQueueSend(queue, &_num, (TickType_t)0);
      _enabled = false;
    }
    delay(1);
  }
}

void ObjectD::dispOled(int attr)
{
  dispHY.clearRect(0, 2, 128, 6);
  dispHY.draw_stringHYm("# ", 0, 0, 6);
  dispHY.draw_num_m(attr, 12, 0, 6);

  dispHY.draw_stringHYm("DrawFont S", 24, 0, 6);
  for (int ch = 0x20; ch < 0x7f + 16; ch += 21)
  {
    int c = ch;
    for (int y = 2; y < 8; y++)
    {
      for (int x = 0; x < 128 - 2; x += 6)
      { // 21chars
        dispHY.draw_VfontHYs(c++, x, y, 5);
        if (c >= 0x7f)
          c = 0x20;
      }
    }
    delay(500);
  }
}

void ObjectE::run()
{
  while (1)
  {
    if (status())
    {
      dispOled(_num);
      xQueueSend(queue, &_num, (TickType_t)0);
      _enabled = false;
    }
    delay(1);
  }
}

void ObjectE::dispOled(int attr)
{
  dispHY.clearRect(0, 2, 128, 6);
  dispHY.draw_stringHYm("# ", 0, 0, 6);
  dispHY.draw_num_m(attr, 12, 0, 6);

#define PT0 0x08
#define PT1 0x78
  unsigned char aa[9] = {0, 50, 96, 64, 126, 110, 32, 64, 0};
  unsigned char bb[9] = {0, 25, 40, 126, 100, 32, 70, 40, 0};

  dispHY.draw_stringHYm("Draw/FillRect", 24, 0, 6);
  for (int x = 0; x < 128; x++)
  {
    int pat = PT0;
    if ((x & 0x07) == 0 || x == 127)
      pat = PT1;
    dispHY.fillRect(pat, x, 2, 1, 1);
  }
  for (int j = 0; j < 2; j++)
  {
    for (int i = 0; i < 256; i++)
    {
      int ii = i >> 5;
      int a = ((aa[ii + 1] - aa[ii]) * (i & 0x1f) >> 5) + aa[ii];
      int b = ((bb[ii + 1] - bb[ii]) * (i & 0x1f) >> 5) + bb[ii];
      sub_drawberX(a, 3);
      dispHY.clearRect(4, 4, 24, 1);
      dispHY.draw_num_s(a, 4, 4, 5);
      sub_drawberX(b, 5);
      dispHY.clearRect(4, 6, 24, 1);
      dispHY.draw_num_s(b, 4, 6, 5);
      dispHY.fillRect(0xff, 0, 2, 1, 6);
      delay(10);
    }
  }
  delay(1000);
}

void ObjectE::sub_drawberX(int lv, int y)
{
  for (int x = 1; x < 128; x++)
  {
    int pat = 0x00;
    if (lv > x)
      pat = 0x7e;
    dispHY.fillRect(pat, x, y, 1, 1);
  }
}
