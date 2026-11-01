#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_SHT31.h>

#define SCREEN_HEIGHT 64
#define OLED_ADDRESS 0x3C
Adafruit_SSD1306 display(128, 64, &Wire, -1);
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
   Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    while (true);
  }

  if (!sht31.begin(0x44)) {
  Serial.println("Couldn't find SHT31");
}
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // charge pump on, address 0x3C
  display.clearDisplay();                     // clear the RAM buffer
  display.setTextSize(2);                     // 2x the 6x8 font
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Hello!");
  display.drawCircle(100, 40, 15, SSD1306_WHITE);
  display.display();                          // send the buffer to the screen
}

void loop() {float temperature = sht31.readTemperature();
float humidity = sht31.readHumidity();

Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" °C");

Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");}
