#include<LinkSpriteIO.h>

String deviceID = "xxxxxxxxxx";
String factorykey = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxx";

LinkSpriteIO linksprite;

void setup()
{
    String s;
    Serial.begin(115200);
    linksprite.begin();
    if(linksprite.Register(deviceID,factorykey)==0)
      Serial.println("Register ok!");
    else
    {
      Serial.println("Register failure!");
      while(1);
    }
    s = linksprite.update("test","8");
    Serial.println(s);  
}

void loop()
{ 
  int v;
  v = linksprite.query("test");
  Serial.println("The get is :");
  Serial.println(v);  
}
