// подключаем библиотеку для работы с матричной клавиатурой
#include <AmperkaKB.h>

// создаём объект для работы с матричной клавиатурой
// указывая номера arduino подключенные к шлейфу клавиатуры
// начиная с первого вывода шлейфа
AmperkaKB KB(2, 3, 4, 5, 6);

int hours = 0;
int minutes = 0;
int seconds = 0;
// создаем объект класса long для хранения счетчика
long lastTime = 0;
#define STRIP_PIN 13     // пин ленты
#define NUMLEDS 42     // кол-во светодиодов

#define COLOR_DEBTH 3
#include <microLED.h>   // подключаем библу ленты

microLED<NUMLEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_AVER> strip;


void setup()
{

  strip.setBrightness(100);
  // открываем монитор Serial порта
  Serial.begin(9600);
  // указываем тип клавиатуры
  KB.begin(KB1x4);
  // второй необзятельный параметр:
  // время длительного зажатия кнопки
  // по умолчанию 2000, изменим на 5000 мс
  // KB.begin(KB4x3, 5000);
  setTime(__TIMESTAMP__);
  strip.clear(); ///обновляем ленту
  strip.show();    // выводим изменения
  
}

void loop()
{

   ///Serial.println(minutes, seconds);
  // считывание данных с клавиатуры
  KB.read();
  // опеределяем клик кнопки
  if (KB.justPressed()) {
    // печатаем номер кнопки и её символ в последовательный порт
    Serial.print("Key is press ");
    Serial.print(KB.getNum);
    Serial.print(" = \"");
    Serial.print(KB.getChar);
    Serial.println("\"");
     Serial.println(minutes);
    

    // если нажимаем 1 то прибавляем минуту к таймеру
     if (KB.getNum == 1) {
      Serial.print("add 5 min  ");
      minutes = minutes + 5;
      Serial.println(minutes);
      }
  
  
  
  
  
  }



if (seconds == 10)
{  
  strip.clear(); ///обновляем ленту
   
   strip.set(0, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (seconds == 20)
{  
  strip.clear(); ///обновляем ленту
   
   strip.set(1, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (seconds == 30)
{  
  strip.clear(); ///обновляем ленту
   
   strip.set(2, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (seconds == 40)
{  
  strip.clear(); ///обновляем ленту
   
   strip.set(3, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (seconds == 50)
{  
  strip.clear(); ///обновляем ленту
   
   strip.set(4, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}

if (seconds == 0)
{  
  strip.clear(); ///обновляем ленту
  
  strip.set(5, mRGB(255, 0, 0));    // заливаем ~зелёным с 0 по 6: счёт идёт с 0, заливается до указанного -1
   strip.show();                     // выводим изменения

}


///Serial.println(seconds);
  
  // как только разница между текущим временем и временем записанным в lastTime становится больше 1000 миллисекунд...
  while(millis()-lastTime > 1000) {
    //...обновляем  lastTime и добавляем к счетчику Секунд +1
    lastTime = millis();
    seconds++;
    // как только счетчик секунд достигнет 60, обнуляем его и добавляем к счетчику Минут +1...
    if (seconds >= 60) {
       seconds = 0;
       minutes++;
    }
    // ...тоже самое для Часов...
    if (minutes >= 60) {
       minutes = 0;
       hours++;
    }
    // ... и обнуляем счетчик Часов в конце дня
    if (hours >= 24) {
       hours = 0;
    }
  }
  
  

}




void setTime(const char* compileTimeStamp) 
{
    hours = ((compileTimeStamp[11] - '0') * 10
        + (compileTimeStamp[12] - '0'));
 
    minutes = ((compileTimeStamp[14] - '0') * 10
        + (compileTimeStamp[15] - '0'));
 
    seconds = ((compileTimeStamp[17] - '0') * 10
        + (compileTimeStamp[18] - '0'));
}
