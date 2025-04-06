//--------------------------------------------------------------
//  OLED display(SSD1306)
//      HYライブラリ(SPIでSSD1306直アクセス)検討
//  ② 作成した HYライブラリ用縦形式のミドルサイズフォントをテストする
//  for ATmega328 and AVR64DB32
//--------------------------------------------------------------
#include <Arduino.h>
#include "oledHYLib_i2c.h"
#include "objSample.h"

const gpio_num_t ledPin = GPIO_NUM_21;

TaskHandle_t thp[5]; // マルチスレッドのタスクハンドル格納用
QueueHandle_t queue; // タスク間通信 キュー

// object作成
ObjectA objA;
ObjectB objB;
ObjectC objC;
ObjectD objD;
ObjectE objE;

// prototype
void taskA(void *args);
void taskB(void *args);
void taskC(void *args);
void taskD(void *args);
void taskE(void *args);

//----------------------------------------------------------------------
//  SAMPLE PROGRAM
//----------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);
  delay(2000);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  dispHY.begin(); // initialize

  dispHY.clearFullPage(); // fillRect( 0x00,0, 0, OLED_XSIZE_BIT,OLED_YSIZE_PAGE );
  dispHY.invertScreen();
  dispHY.disp_on();

  dispHY.fillRect(0xff, 0, 0, 128, 8);
  dispHY.fillRect(0x00, 4, 1, 128 - 8, 8 - 2);
  delay(200);
  dispHY.draw_stringHYm("OLED(SSD1306/I2C)", 12, 1, 6);
  delay(200);
  dispHY.draw_stringHYm("HYlib DEMO sample", 12, 3, 6);
  delay(200);
  dispHY.draw_stringHYs("yama musicalinstruments", 6, 5, 5);
  delay(1500);
  for (int i = 0; i < 4; i++)
  {
    delay(300);
    // digitalWrite(ledPin, LOW);
    dispHY.disp_off();
    delay(100);
    // digitalWrite(ledPin, HIGH);
    dispHY.disp_on();
  }
  // digitalWrite(ledPin, LOW);
  dispHY.clearFullPage();

  // タスク間通信 キュー作成
  queue = xQueueCreate(1, sizeof(int));

  xTaskCreatePinnedToCore(taskA, "taskA", 4096, NULL, 5, &thp[0], 0);
  xTaskCreatePinnedToCore(taskB, "taskB", 4096, NULL, 4, &thp[1], 0);
  xTaskCreatePinnedToCore(taskC, "taskC", 4096, NULL, 3, &thp[2], 0);
  xTaskCreatePinnedToCore(taskD, "taskD", 4096, NULL, 2, &thp[3], 0);
  xTaskCreatePinnedToCore(taskE, "taskE", 4096, NULL, 1, &thp[4], 0);

  Serial.println("-------------------------------------------------");
  objA.setEnable();
}

void loop(void)
{
  int num;

  // タスク終了をキューで受け取る
  if (xQueueReceive(queue, &num, 0))
  {
    //Serial.printf("Num:%d Receive\n", num);
    switch (num)
    {
    case 1:
      objB.setEnable();
      break;
    case 4:
      objC.setEnable();
      break;
    case 7:
      objD.setEnable();
      break;
    case 8:
      objE.setEnable();
      break;
    case 9:
      dispHY.clearFullPage();
      delay(3000);
      objA.setEnable();
      break;
    }
  }
}
void taskA(void *args)
{
  objA.init(1);
  objA.run();
}

void taskB(void *args)
{
  objB.init(4);
  objB.run();
}

void taskC(void *args)
{
  objC.init(7);
  objC.run();
}

void taskD(void *args)
{
  objD.init(8);
  objD.run();
}

void taskE(void *args)
{
  objE.init(9);
  objE.run();
}
