/* ============================================
LinkSpriteIO library for LinkNode D1 

LinkSpriteIO is an IoT cloud platform to link devices. LinkSprite has released a complete set of hardware for LinkSpriteIO with open source hardware designs and open source firmware.
The overall LinkSpriteIO architecture including LinkSpriteIO cloud, web/desktop/mobile apps and LinkSpriteIO-compatible nodes is illustrated by following graph.

LinkNode D1 is Arduino-compatible WiFi development board which is powered by the high integrated WiFi chip ESP-8266EX.
Thanks for the contribution from open source community who have developed Arduino core for ESP8266, this let Aduino IDE program LinkNode D1 without any change. At the same time, LinkNode D1 has Arduino-compatible pin out which make it very easy to connect to Arduino shield.

auther: Derron form LinkSprite
date:2016.7.13
file:LinkSpriteIO-DIY
===============================================
*/


#include<LinkSpriteIO.h>

String deviceID = "xxxxxxxxxx";
String apikey = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxx";

LinkSpriteIO linksprite(deviceID,apikey);

void setup()
{
    String s;
    Serial.begin(115200);
    linksprite.begin();
    linksprite.update("test1","1");
    linksprite.update("test2","11");
    linksprite.update("test3","111");
    linksprite.update("test4","1111");
    s = linksprite.update("test5","11111");
    Serial.println(s);
}

void loop()
{ 
    query_val val;
    val = linksprite.query("test1","test2","test3","test4","test5");
    Serial.println("The get is :");
    Serial.println(val.d1);
    Serial.println(val.d2);
    Serial.println(val.d3);
    Serial.println(val.d4);
    Serial.println(val.d5);
}
