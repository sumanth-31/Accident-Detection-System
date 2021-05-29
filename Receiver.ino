void setup()
{
    Serial.begin(9600);
}
void loop()
{
    //  while(1){
    //    while(Serial.available()){
    //      Serial.print((char)Serial.read());
    //    }
    //  }
    while (1)
    {
        if (Serial.available())
        {
            String latitude = Serial.readStringUntil('@');
            String longitude = Serial.readStringUntil('!');

            Serial.println("ACCIDENT DETECTED NEARBY\n");
            Serial.println("LATITUDE: " + latitude + " LONGITUDE: " + longitude);
            break;
        }
    }
}