

// простейшие динамические эффекты
// сначала ознакомься с примером microLED_guide !!!

#define STRIP_PIN 13     // пин ленты
#define NUMLEDS 42     // кол-во светодиодов

#define COLOR_DEBTH 3
#include <microLED.h>   // подключаем библу

microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip;
unsigned long MMdelta = 0L;

unsigned long MyMillis()
{
  return millis()- MMdelta;
}

void MMReset(unsigned long val = 0L)
{
  MMdelta = millis() - val;  
}


void setup() {
  Serial.begin(115200);
  strip.setBrightness(70);
  strip.clear();
  strip.show();  
Serial.begin(115200);
  Serial.println("MyMillis demo");
  
   
}


void loop() {

uint32_t sec = millis() / 1000ul;      // полное количество секунд после включения
  int timeHours = (sec / 3600ul);        // часы
  int timeMins = (sec % 3600ul) / 60ul;  // минуты
  int timeSecs = (sec % 3600ul) % 60ul;  // секунды

uint32_t ttm = MyMillis() / 1000ul;      // полное количество секунд после включения
  int timeHoursttm = (ttm / 3600ul);        // часы
  int timeMinsttm = (ttm % 3600ul) / 60ul;  // минуты
  int timeSecsttm = (ttm % 3600ul) % 60ul;  // секунды

Serial.println(timeHours);
Serial.println(timeMins);
Serial.println(timeSecs);
Serial.println(timeSecsttm);
strip.clear();
if (timeSecs == 10)
{
   Serial.println("time 30 sec");// выполнять действия
   strip.set(0, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (timeSecs == 20)
{
   Serial.println("time 30 sec");// выполнять действия
   strip.set(1, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}
if (timeSecs == 30)
{
   Serial.println("time 30 sec");// выполнять действия
  strip.set(2, mRGB(255, 0, 0));   // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (timeSecs == 40)
{
   Serial.println("time 30 sec");// выполнять действия
   strip.set(3, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}


if (timeSecs == 50)
{
   Serial.println("time 30 sec");// выполнять действия
   strip.set(4, mRGB(255, 0, 0));   // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (timeSecs == 0)
{
   Serial.println("time 30 sec");// выполнять действия
   strip.set(5, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}
delay(1000);
  
  

}
