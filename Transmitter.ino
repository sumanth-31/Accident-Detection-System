#include <SoftwareSerial.h>
SoftwareSerial gps(9, 8); // RX, TX

char str[70];
String gpsString = "";
char *test = "$GPGGA";
String latitude = "No Range      ";
String longitude = "No Range     ";
int temp = 0, i;
boolean gps_status = 0;

int memspin = A0;
int mems;
int x;
int y;

void setup()
{
    Serial.begin(9600);
    //  Serial.println("Hey bro");
    //  Serial.write("Message sending");
    gps.begin(9600);
    get_gps();
    pinMode(memspin, INPUT);
}
//long lastTime=millis();
void loop()
{
    //  if(millis()-lastTime>1000){
    //  Serial.println("Hey bro");
    //  Serial.write("Message sending");
    //  lastTime=millis();
    //   }
    //  Serial.println(latitude+" "+longitude);
    //  mems = analogRead(memspin);
    ////  Serial.print("mems: ");
    ////  Serial.println(mems);
    delay(1000);
    //
    if (mems <= 370 || mems >= 420)
    {
        tracking1();
        delay(1000);
    }
}

void gpsEvent()
{
    gpsString = "";
    while (1)
    {
        while (gps.available() > 0) //checking serial data from GPS
        {
            char inChar = (char)gps.read();
            gpsString += inChar;
            //store data from GPS into gpsString
            i++;
            if (i < 7)
            {
                if (gpsString[i - 1] != test[i - 1]) //checking for $GPGGA sentence
                {
                    i = 0;
                    gpsString = "";
                }
            }
            if (inChar == '\r')
            {
                if (i > 65)
                {
                    gps_status = 1;
                    break;
                }
                else
                {
                    i = 0;
                }
            }
        }
        if (gps_status)
            break;
    }
    //  Serial.println("Exited gps");
}

void get_gps()
{
    gps_status = 0;
    int x = 0;
    while (gps_status == 0)
    {
        gpsEvent();
        //    Serial.println("Exited gps Event");
        int str_lenth = i;
        latitude = "";
        longitude = "";
        int comma = 0;
        while (x < str_lenth)
        {
            if (gpsString[x] == ',')
                comma++;
            if (comma == 2) //extract latitude from string
                latitude += gpsString[x + 1];
            else if (comma == 4) //extract longitude from string
                longitude += gpsString[x + 1];
            x++;
        }
        int l1 = latitude.length();
        latitude[l1 - 1] = ' ';
        l1 = longitude.length();
        longitude[l1 - 1] = ' ';
        i = 0;
        x = 0;
        str_lenth = 0;
        //    Serial.println(latitude + ";" + longitude);
        delay(100);
    }
}

void send_data(String message)
{
    Serial.println(message);
    delay(100);
}

void tracking1()
{
    //Serial.print("Latitude:");
    //send_data(latitude);
    //Serial.print("Longitude:");
    // send_data(longitude);
    String x = (latitude + '@' + longitude + '!');

    Serial.println(x);
}