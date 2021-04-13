#define BLYNK_PRINT Serial 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " S_Dhdv9XltboGCO159Mr1WCXJXSriE_E";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ATTGjg27Ea";
char pass[] = "p?8fdbwvv5n4";


float cf = 5; // calibration factor
const int ffs1 = 25; //  
const int ffs2 = 33; //
const int ffs3 = 34; //
const int ffs4 = 35; //
const int ffs5 = 32; //
int ffsdata = 0;
int ffsdata1 = 0;
int ffsdata2 = 0;
int ffsdata3 = 0;
int ffsdata4 = 0;
float vout,vout1,vout2,vout3,vout4;

float value;
float value1;
float value2;
float value3;
float value4;
BLYNK_WRITE(V0)
{
  value = param.asFloat(); // Get value as float
}

BLYNK_WRITE(V1)
{
  value1 = param.asFloat(); // Get value as float
}

BLYNK_WRITE(V2)
{
  value2 = param.asFloat(); // Get value as float
}

BLYNK_WRITE(V3)
{
  value3 = param.asFloat(); // Get value as float
}

BLYNK_WRITE(V4)
{
  value4 = param.asFloat(); // Get value as float
}

void setup()
{

  Blynk.begin(auth, ssid, pass);
  Serial.begin(115200);
  pinMode(ffs1, INPUT);
  pinMode(ffs2, INPUT);
  pinMode(ffs3, INPUT);
  pinMode(ffs4, INPUT);
  pinMode(ffs5, INPUT);
}

void loop()
{
  Blynk.run();
int ffsdata = 0;
int ffsdata1 = 0;
int ffsdata2 = 0;
int ffsdata3 = 0;
int ffsdata4 = 0;
float  vout=0;
float  vout1=0;
float  vout2=0;
float  vout3=0;
float  vout4=0;
ffsdata = analogRead(ffs1);
vout = (ffsdata * 5.0) / 1023.0;
vout = vout * cf ;
ffsdata1 = analogRead(ffs2);
vout1 = (ffsdata1 * 5.0) / 1023.0;
vout1 = vout1 * cf;
ffsdata2 = analogRead(ffs3);
vout2 = (ffsdata2 * 5.0) / 1023.0;
vout2 = vout2 * cf;
ffsdata3 = analogRead(ffs4);
vout3 = (ffsdata3 * 5.0) / 1023.0;
vout3 = vout3 * cf ;
ffsdata4 = analogRead(ffs5);
vout4 = (ffsdata4 * 5.0) / 1023.0;
vout4 = vout4 * cf ;
if((vout > 0.0f) || (vout1 > 0.0f) || (vout2 > 0.0f) || (vout3 > 0.0f) || (vout4 > 0.0f))
{
   Serial.print(vout);
   Serial.print(",");
   Serial.print(vout1);
   Serial.print(",");
   Serial.print(vout2);
   Serial.print(",");
   Serial.print(vout3);
   Serial.print(",");
   Serial.print(vout4);
   Serial.println("");  
 

               Blynk.virtualWrite(V0, float(vout));
               Blynk.virtualWrite(V1, float(vout1));
               Blynk.virtualWrite(V2, float(vout2));
               Blynk.virtualWrite(V3, float(vout3));
               Blynk.virtualWrite(V4, float(vout4));
               
               
}
delay(100);
}
