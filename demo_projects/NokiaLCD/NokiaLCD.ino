#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

#include <Wire.h>
#include <Adafruit_BMP085.h>

const int BMP_VCC_PIN = 2;

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

// Connect VCC of the BMP085 sensor to VCC
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here
Adafruit_BMP085 bmp;

void setup() {
  pinMode(BMP_VCC_PIN, OUTPUT);
  digitalWrite(BMP_VCC_PIN, HIGH);
  
  display.begin();
  display.setContrast(50);
  display.clearDisplay();   // clears the screen and buffer

  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.display();

  bmp.begin();

  Serial.begin(9600);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  
  Serial.print("Temperature = ");
  display.println("  Temperature");
  float temp = bmp.readTemperature();
  Serial.print(temp);
  display.print(temp);
  Serial.println(" *C");
  display.println(" C");
  
  Serial.print("Pressure = ");
  display.println("   Pressure");
  float press = bmp.readPressure();
  Serial.print(press);
  display.print(press);
  Serial.println(" Pa");
  display.println(" Pa");
  
  // Calculate altitude assuming 'standard' barometric
  // pressure of 1013.25 millibar = 101325 Pascal
  Serial.print("Altitude = ");
  display.println("   Altitude ");
  float alt = bmp.readAltitude();
  Serial.print(alt);
  display.print(alt);
  Serial.println(" meters");
  display.println(" m");
  
  Serial.println();
  display.display();
  delay(500);

}
