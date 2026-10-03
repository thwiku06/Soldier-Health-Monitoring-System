
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <DHTesp.h>

#define BLYNK_TEMPLATE_ID "TMPL3UUvZHVJZ"
#define BLYNK_TEMPLATE_NAME "Soldier Health Monitoring System"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>


#define PULSE_PIN 34
#define DHTPIN 4
#define BUTTON_PIN 14
#define LED_PIN 27

LiquidCrystal_I2C lcd(0x27,16,2);
DHTesp dht;

const byte ROWS=4,COLS=4;

char keys[ROWS][COLS]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS]={13,5,26,25};
byte colPins[COLS]={23,33,18,19};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

int bpm=0;
bool beat=false;
unsigned long lastBeat=0;
int threshold=2000;
float displayTemp=25;

bool showKeyMessage=false;
unsigned long keyMessageTime=0;

char ssid[]="YOUR_WIFI";
char pass[]="YOUR_PASSWORD";

BlynkTimer timer;
String currentStatus="NORMAL";
String lastMessage="System Ready";

void showMessage(const char *msg){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(msg);
  showKeyMessage=true;
  keyMessageTime=millis();
}

void sendData(){
  Blynk.virtualWrite(V0,bpm);
  Blynk.virtualWrite(V1,displayTemp);
  Blynk.virtualWrite(V2,currentStatus);
  Blynk.virtualWrite(V3,lastMessage);
  Blynk.virtualWrite(V4,digitalRead(BUTTON_PIN)==LOW?1:0);
}

void setup(){
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
  timer.setInterval(1000L,sendData);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);

  lcd.init();
  lcd.backlight();

  dht.setup(DHTPIN,DHTesp::DHT11);

  lcd.setCursor(0,0);
  lcd.print("SOLDIER HEALTH");
  lcd.setCursor(0,1);
  lcd.print("WATCH STARTING");
  delay(2000);
  lcd.clear();
}

void loop(){
  Blynk.run();
  timer.run();

  float t=dht.getTemperature();
  if(!isnan(t))
    displayTemp=displayTemp*0.9+t*0.1;

  int pulse=analogRead(PULSE_PIN);

  if(pulse>threshold && !beat){
    beat=true;
    unsigned long now=millis();
    if(lastBeat){
      int newBpm=60000/(now-lastBeat);
      if(newBpm>40 && newBpm<180)
        bpm=(bpm*3+newBpm)/4;
    }
    lastBeat=now;
  }

  if(pulse<threshold-50)
    beat=false;

  char key=keypad.getKey();

  if(key){
    switch(key){
      case '1': lastMessage="Need Backup"; showMessage(lastMessage.c_str()); break;
      case '2': lastMessage="Injured"; showMessage(lastMessage.c_str()); break;
      case '3': lastMessage="Enemy Seen"; showMessage(lastMessage.c_str()); break;
      case '4': lastMessage="Mission Done"; showMessage(lastMessage.c_str()); break;
      case '5': lastMessage="Need Medic"; showMessage(lastMessage.c_str()); break;
      case '6': lastMessage="Low Ammo"; showMessage(lastMessage.c_str()); break;
      case '7': lastMessage="Need Supply"; showMessage(lastMessage.c_str()); break;
      case '8': lastMessage="Safe"; showMessage(lastMessage.c_str()); break;
      case '9': lastMessage="Returning"; showMessage(lastMessage.c_str()); break;
      case '0': lastMessage="Cancel Alert"; showMessage(lastMessage.c_str()); digitalWrite(LED_PIN,LOW); break;
      case '*': lastMessage="SOS ALERT"; showMessage(lastMessage.c_str()); digitalWrite(LED_PIN,HIGH); break;
      case '#': lastMessage="Status Sent"; showMessage(lastMessage.c_str()); break;
      case 'A': lastMessage="Alpha"; showMessage(lastMessage.c_str()); break;
      case 'B': lastMessage="Bravo"; showMessage(lastMessage.c_str()); break;
      case 'C': lastMessage="Charlie"; showMessage(lastMessage.c_str()); break;
      case 'D': lastMessage="Delta"; showMessage(lastMessage.c_str()); break;
    }
  }

  if(showKeyMessage){
    if(millis()-keyMessageTime<2000){
      delay(20);
      return;
    }
    showKeyMessage=false;
    lcd.clear();
  }

  lcd.setCursor(0,0);
  lcd.print("HR:");
  lcd.print(bpm);
  lcd.print(" BPM   ");

  if(digitalRead(BUTTON_PIN)==LOW){
    digitalWrite(LED_PIN,HIGH);
    currentStatus="EMERGENCY";
    if((millis()/1000)%2==0){
      lcd.setCursor(0,1);
      lcd.print("EMERGENCY      ");
    }else{
      lcd.setCursor(0,1);
      lcd.print(displayTemp,1);
      lcd.write((uint8_t)223);
      lcd.print("C             ");
    }
  }else{
    digitalWrite(LED_PIN,LOW);
    currentStatus="NORMAL";
    lcd.setCursor(0,1);
    lcd.print(displayTemp,1);
    lcd.write((uint8_t)223);
    lcd.print("C NORMAL      ");
  }

  delay(20);
}
