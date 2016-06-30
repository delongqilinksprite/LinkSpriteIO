#ifndef LINKSPRITEIO_H
#define LINKSPRITEIO_H

#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <stdlib.h>
#include <string>

typedef struct
{
	int d1=0;
	int d2=0;
	int d3=0;
	int d4=0;
	int d5=0;
}query_val;

class LinkSpriteIO
{
public:
	LinkSpriteIO();
	LinkSpriteIO(String deviceID,String apikey);
	void begin();
	String update(String type,String val);
	int query(String serach);
	query_val query(String s1,String s2);
	query_val query(String s1,String s2,String s3);
	query_val query(String s1,String s2,String s3,String s4);
	query_val query(String s1,String s2,String s3,String s4,String s5);
    int Register(String id,String fackey);
private:
	WiFiClient client;
    String deviceID;
	String apikey;
	String factorykey;
};

#endif
