#ifndef LINKSPRITEIO_H
#define LINKSPRITEIO_H

#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <stdlib.h>

class LinkSpriteIO
{
public:
	LinkSpriteIO(String deviceID,String apikey);
	void begin();
	int StrtoDec(String a);
	String updata(String type,String val);
	int query_data(String serach);
private:
	WiFiClient client;
    String deviceID;
	String apikey;
	char *server = "www.linksprite.io";
};

#endif
