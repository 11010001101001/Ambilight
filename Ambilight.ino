/*
   Управление лентой на WS2812 с компьютера
   Создано не знаю кем, допилил и перевёл AlexGyver http://alexgyver.ru/
   2017
   Упростил 11010001101001
   2025
*/
#include <FastLED.h>

#define NUM_LEDS 97       // число светодиодов в ленте
#define DI_PIN 5          // пин, к которому подключена лента
#define serialRate 115200 // скорость связи с ПК

int new_bright, new_bright_f;
unsigned long bright_timer;

uint8_t prefix[] = {'A', 'd', 'a'}, hi, lo, chk, i; // кодовое слово Ada для связи

CRGB leds[NUM_LEDS]; // создаём ленту

void setup()
{
  FastLED.addLeds<WS2812B, DI_PIN, RGB>(leds, NUM_LEDS); // инициализация светодиодов

  Serial.begin(serialRate);
  Serial.print("Ada\n"); // Связаться с компом
}

void loop()
{
  for (i = 0; i < sizeof prefix; ++i)
  {
  waitLoop:
    while (!Serial.available())
      ;
    ;
    if (prefix[i] == Serial.read())
      continue;
    i = 0;
    goto waitLoop;
  }

  while (!Serial.available())
    ;
  ;
  hi = Serial.read();
  while (!Serial.available())
    ;
  ;
  lo = Serial.read();
  while (!Serial.available())
    ;
  ;
  chk = Serial.read();
  if (chk != (hi ^ lo ^ 0x55))
  {
    i = 0;
    goto waitLoop;
  }

  memset(leds, 0, NUM_LEDS * sizeof(struct CRGB));
  for (uint8_t i = 0; i < NUM_LEDS; i++)
  {
    byte r, g, b;
    // читаем данные для каждого цвета
    while (!Serial.available())
      ;
    r = Serial.read();
    while (!Serial.available())
      ;
    g = Serial.read();
    while (!Serial.available())
      ;
    b = Serial.read();
    leds[i].r = r;
    leds[i].g = g;
    leds[i].b = b;
  }
  FastLED.show(); // записываем цвета в ленту
}