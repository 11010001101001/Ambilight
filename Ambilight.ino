/*
   Управление лентой на WS2812 с компьютера
   Создано не знаю кем, допилил и перевёл AlexGyver http://alexgyver.ru/
   2017

   Упростил, отрефачил 11010001101001 вместе с chat gpt 5.2
   После блокировки/режима сна/выключения экрана по таймауту чтобы загоралося снова в планировщике винды добавьте перезапуск Ambibox
   2025
*/

#include <FastLED.h>

#define NUM_LEDS 97        // число светодиодов в ленте
#define DI_PIN 5           // пин, к которому подключена лента
#define serialRate 115200  // скорость связи с ПК

CRGB leds[NUM_LEDS];  // создаём ленту

const uint8_t prefix[] = { 'A', 'd', 'a' };

bool waitByte(uint16_t timeout = 1000) {
  uint32_t t = millis();
  while (!Serial.available()) {
    if (millis() - t > timeout) return false;
  }
  return true;
}

void clearBytes() {
  while (Serial.available()) Serial.read();
}

void clearLED() {
  FastLED.clear();
  FastLED.show();
}

void setup() {
  FastLED.addLeds<WS2812B, DI_PIN, RGB>(leds, NUM_LEDS);  // инициализация светодиодов
  Serial.begin(serialRate);
  Serial.print("Ada\n");  // Связаться с компом
  memset(leds, 0, NUM_LEDS * sizeof(struct CRGB));
}

void loop() {
  uint8_t state = 0, hi, lo, chk;

  if (!waitByte(5000)) { clearLED(); }

  // ---- поиск префикса "Ada" ----
  while (state < sizeof(prefix)) {
    if (!waitByte()) { clearBytes(); return; }

    uint8_t b = Serial.read();

    if (b == prefix[state]) {
      state++;
    } else {
      state = (b == prefix[0]) ? 1 : 0;
    }
  }

  // ---- читаем заголовок ----
  if (!waitByte()) { clearBytes(); return; }
  hi = Serial.read();

  if (!waitByte()) { clearBytes(); return; }
  lo = Serial.read();

  if (!waitByte()) { clearBytes(); return; }
  chk = Serial.read();

  if (chk != (hi ^ lo ^ 0x55)) {
    clearBytes();
    return;
  }

  // ---- читаем данные ----
  for (uint8_t i = 0; i < NUM_LEDS; i++) {
    if (!waitByte()) { clearBytes(); return; }
    leds[i].r = Serial.read();

    if (!waitByte()) { clearBytes(); return; }
    leds[i].g = Serial.read();

    if (!waitByte()) { clearBytes(); return; }
    leds[i].b = Serial.read();
  }

  FastLED.show();
}