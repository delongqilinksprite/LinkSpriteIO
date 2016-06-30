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
