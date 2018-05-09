

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 


#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
int y=4;
int x=4;
int b=0;
void setup()   {                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3C (for the 128x32)
 
  delay(2000);


  display.clearDisplay();

}


void loop() {
 
     eyeblink();
    
 delay(900);

 display.clearDisplay();   

}


////////////////////////////////////////////////////////////////////////////////////////////////
void eyeblink() {
 

   for (int16_t i=0; i<11; i++) {
    display.fillRoundRect(30, 20-i,35, i, 10/4, WHITE);
    display.fillRoundRect(30, 18,  35, i, 10/4, WHITE);
    display.fillRoundRect(75, 20-i,35, i, 10/4, WHITE);
    display.fillRoundRect(75, 18,  35, i, 10/4, WHITE);
    display.display();
    delay(10);
    }
    
 for (int16_t j=11; j>0; j--) {
    display.fillRoundRect(30, 20-j,35, j, 10/4, WHITE);
    display.fillRoundRect(30, 18,  35, j, 10/4, WHITE);
    display.fillRoundRect(75, 20-j,35, j, 10/4, WHITE);
    display.fillRoundRect(75, 18,  35, j, 10/4, WHITE);
    
    display.display();
   delay(10);
 }

}
   





