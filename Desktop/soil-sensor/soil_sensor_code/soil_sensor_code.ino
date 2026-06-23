//Smart Soil Moisture Sensor
//Reads soil moisture data via a DIY resistive voltage divider circuit and provides visual feedback using LED lights and OLED screen



//Libraries needed
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

//Define variables and constants
#define green 5
#define red 4
#define blue 15 

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(green , OUTPUT);
  pinMode(red , OUTPUT);
  pinMode(blue, OUTPUT);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
      Serial.println(F("SSD1306 allocation failed"));
      for(;;); 
  } 

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE); 
  display.display(); 

  delay(100);
}

void loop() {

  int moisture_read = analogRead(34);
  
  Serial.print("Moisture Reading: ");
  Serial.println(moisture_read);

  
  display.clearDisplay();
  
  display.setTextSize(1);      
  display.setCursor(0, 0);   
  display.print("Val:");

  display.print(moisture_read);

  // 2. SHOW STATUS TEXT BELOW
  display.setTextSize(2);      
  display.setCursor(0, 24);    

  if (moisture_read <= 800) {
    display.println("TOO DRY");
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
  }
  else if (moisture_read > 800 && moisture_read < 2000) {
    display.println("ALL GOOD!");
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }
  else {    
    display.println("TOO WET!");
    digitalWrite(blue, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
  }

  // Push everything onto the physical screen
  display.display();

  delay(200);
}
