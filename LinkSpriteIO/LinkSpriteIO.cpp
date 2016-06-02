#include<LinkSpriteIO.h>

LinkSpriteIO::LinkSpriteIO(String deviceID,String apikey)
{
	this->deviceID = deviceID;
	this->apikey = apikey;
}

void LinkSpriteIO::begin()
{
	WiFiManager wifiManager;
    wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
    wifiManager.autoConnect("LinkNodeAP");
}

int LinkSpriteIO::StrtoDec(String a)
{
	if(a == "0")
       return 0;
    if(a == "1")
       return 1;  
    if(a == "2")
       return 2;
    if(a == "3")
       return 3;  
    if(a == "4")
        return 4;
    if(a == "5")
       return 5;  
    if(a == "6")
        return 6;
    if(a == "7")
       return 7;  
    if(a == "8")
        return 8;
    if(a == "9")
       return 9;  
}

int LinkSpriteIO::query(String serach)
{
   int dat = 0;
   String s1;
   s1="\"";
   s1+=serach;
   s1+="\"";   
   if (client.connect(server,80)) 
   {  
   String  postStr ="{";
         postStr +="\"action\":\"query\",";
         postStr +="\"apikey\":\"";
         postStr += apikey;
         postStr +="\",";
         postStr +="\"deviceid\":\"";
         postStr += deviceID;
         postStr +="\",";
         postStr += "\"params\":";
         postStr += "[";
         postStr += s1;
         postStr +="]";
         postStr +="}";
    client.print("POST /api/http HTTP/1.1\n");
    client.print("Host: ");
    client.print(server);
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);  
  }
 delay(100);
 String request = "";
 while (client.available()) 
 {
   char c = client.read();
   request +=c;
 } 
 if (request!= NULL)
 {
   int index1 = request.indexOf(":{");
   int index2 = request.indexOf("},");
   int index3 = request.indexOf(serach);
   int l = serach.length();
   String param = request.substring(index1, index2+1);
   String val = request.substring(index3+l+3, index3+l+4); 
   client.stop();
   dat = StrtoDec(val);   
   delay(100);  
   return dat;
 }
}

String LinkSpriteIO::update(String type,String val)
{
   String param;
   String s = "\"";
   s += type;
   s += "\":"; 
   if (client.connect(server,80)) 
   {  
     String  postStr1 ="{";
           postStr1 +="\"action\":\"update\",";
           postStr1 +="\"apikey\":\"";
           postStr1 += apikey;
           postStr1 +="\",";
           postStr1 +="\"deviceid\":\"";
           postStr1 += deviceID;
           postStr1 +="\",";
           postStr1 +="\"params\":";
           postStr1 +="{";
           postStr1 +=s;
           postStr1 +="\"";
           postStr1 +=val;
           postStr1 +="\"\r\n";
           postStr1 +="}";
           postStr1 +="}";
    client.print("POST /api/http HTTP/1.1\n");
    client.print("Host: ");
    client.print(server);
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr1.length());
    client.print("\n\n");
    client.print(postStr1);
  }
   delay(100);
   String request = "";
   while (client.available()) 
   {
     char c = client.read();
     request +=c;
   } 
   if (request!= NULL)
   {
     int index1 = request.indexOf(":{");
     int index2 = request.indexOf("},");
     param = request.substring(index1, index2 + 1);
     client.stop();   
   } 
   return param;
}