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
	s = linksprite.updata("test","6");
	Serial.println(s);
	delay(3000);
	v = linksprite.query_data("test");
    Serial.println("The get is :");
	Serial.println(v);
	delay(3000);
}