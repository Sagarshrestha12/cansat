
  #include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus  gps;              // The TinyGPS++ object
SoftwareSerial  ss(4, 5) ;   // The serial connection to the GPS device
float latitude , longitude;
String date_str , time_str , lat_str , lng_str;
void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
Serial.println("what");
 }
void loop()
{
 while (ss.available() > 0){
   Serial.println("jj:");
    if (gps.encode(ss.read()))
    {
      Serial.println("jj:");
      if (gps.location.isValid())
      {
        latitude = gps.location.lat();
        lat_str = String(latitude , 6);
        longitude = gps.location.lng();
        lng_str = String(longitude , 6);
        Serial.println(lat_str);
        Serial.println(lng_str);
      }}}
}// Print the IP address
