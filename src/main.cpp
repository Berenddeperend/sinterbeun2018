// #include <Arduino.h>


#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

int moistValue;
int mappedMoistValue;
int delayTime = 600000; //10mins

void setup(void)
{
  /* U8g2 Project: SSD1306 Test Board */
  //pinMode(10, OUTPUT);
  //pinMode(9, OUTPUT);
  //digitalWrite(10, 0);
  //digitalWrite(9, 0);		
  
  /* U8g2 Project: KS0108 Test Board */
  //pinMode(16, OUTPUT);
  //digitalWrite(16, 0);	
  
  
  u8x8.begin();
  u8x8.setPowerSave(0);
  

  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
}

void loop(void)
{
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  // u8x8.setFont(u8x8_font_amstrad_cpc_extended_u);
  


  digitalWrite(13, HIGH);
  delay(200);

  moistValue = analogRead(A1);
  mappedMoistValue = map(moistValue, 0, 1024, 100, 0);


  // u8x8.drawString(2,3,"Hello World!");

  String temp = String(mappedMoistValue) + "%";
  char tab2[1024];
  strcpy(tab2, temp.c_str());

  
  // u8x8.drawString(2,3,tab2);
  u8x8.drawString(3,2,"Vochtniveau"); // 16 chars lang
  
  u8x8.drawString(7,4,tab2);

  Serial.print("moist=");
  Serial.println(String(mappedMoistValue));

  digitalWrite(13, LOW);
  delay(delayTime);




  // u8x8.refreshDisplay();		// only required for SSD1606/7  
}