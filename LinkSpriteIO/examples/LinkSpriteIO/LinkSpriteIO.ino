#include<LinkSpriteIO.h>

String deviceID = "xxxxxxxx";
String apikey = "xxxxxxx";

LinkSpriteIO linksprite(deviceID,apikey);

void setup(){
    Serial.begin(9600);
    linksprite.begin();
}

void loop(){
    String s;
    int v;
	s = linksprite.update("test","6");
	Serial.println(s);
	delay(3000);
	v = linksprite.query("test");
    Serial.println("The get is :");
	Serial.println(v);
	delay(3000);
}