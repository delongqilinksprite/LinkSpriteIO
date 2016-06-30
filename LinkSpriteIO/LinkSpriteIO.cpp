#include<LinkSpriteIO.h>

LinkSpriteIO::LinkSpriteIO()
{
	
}

LinkSpriteIO::LinkSpriteIO(String deviceID,String apikey)
{
	this->deviceID = deviceID;
	this->apikey = apikey;
}

void LinkSpriteIO::begin()
{
	Serial.begin(115200);
	WiFiManager wifiManager;
    wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
    wifiManager.autoConnect("LinkNodeAP");
}

int LinkSpriteIO::Register(String id,String fackey)
{
    if (client.connect("www.linksprite.io",80)) 
    {  
        String  postStr2 ="{";
        postStr2 +="\"action\":\"register\",";
        postStr2 +="\"deviceid\":\"";
        postStr2 += id;
        postStr2 +="\",";
        postStr2 +="\"apikey\":\"";
        postStr2 += fackey;
        postStr2 +="\"}";
		client.print("POST /api/http HTTP/1.1\n");
		client.print("Host: ");
		client.print("www.linksprite.io");
		client.print("\nContent-Type: application/json\n");
		client.print("Content-Length: ");
		client.print(postStr2.length());
		client.print("\n\n");
		client.print(postStr2);  
   }
   delay(200);
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
    String param = request.substring(index1, index2 + 1);
    client.stop();   
    int flag = param.indexOf("reason");
    if(flag==-1)
    {
		int index3 = param.indexOf("apikey");
		int index4 = param.indexOf("deviceid");
		apikey = param.substring(index3+9, index3+45);
		deviceID = param.substring(index4+11, index4 +21);
		return 0;
    }
	return -1;
  } 
  return -1;
}


int LinkSpriteIO::query(String serach)
{
   int dat = 0;
   String s1;
   s1="\"";
   s1+=serach;
   s1+="\"";   
   if (client.connect("www.linksprite.io",80)) 
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
    client.print("www.linksprite.io");
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);  
  }
 delay(80);
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
   String val = request.substring(index3+l+3, index3+l+8); 
   client.stop();
   dat = val.toInt();   
   delay(2);  
   return dat;
 }
}

query_val LinkSpriteIO::query(String s1,String s2)
{
   query_val query_dat; 
   String ss;
   ss="\"";
   ss+=s1;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s2;
   ss+="\""; 
   if (client.connect("www.linksprite.io",80)) 
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
         postStr += ss;
         postStr +="]";
         postStr +="}";
    client.print("POST /api/http HTTP/1.1\n");
    client.print("Host: ");
    client.print("www.linksprite.io");
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);  
  }
 delay(80);
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
   int index3 = request.indexOf(s1);
   String param = request.substring(index1, index2+1);
   int le = s1.length();
   String val_1 = request.substring(index3+le+3, index3+le+8); 
   int index4 = request.indexOf(s2);
   int ld = s2.length();
   String val_2 = request.substring(index4+ld+3, index4+ld+8); 
   client.stop();
   query_dat.d1 = val_1.toInt();
   query_dat.d2 = val_2.toInt();
   delay(2);  
   return query_dat;
 }
}

query_val LinkSpriteIO::query(String s1,String s2,String s3)
{
   query_val query_dat; 
   String ss;
   ss="\"";
   ss+=s1;
   ss+="\"";   
   ss+=",";
   ss+="\"";
   ss+=s2;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s3;
   ss+="\""; 
   if (client.connect("www.linksprite.io",80)) 
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
         postStr += ss;
         postStr +="]";
         postStr +="}";
    client.print("POST /api/http HTTP/1.1\n");
    client.print("Host: ");
    client.print("www.linksprite.io");
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);  
  }
 delay(80);
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
   int index3 = request.indexOf(s1);
   int index4 = request.indexOf(s2);
   int index5 = request.indexOf(s3);
   String param = request.substring(index1, index2+1);
   int le = s1.length();
   String val_1 = request.substring(index3+le+3, index3+le+8); 
   int ld = s2.length();
   String val_2 = request.substring(index4+ld+3, index4+ld+8);
   int lf = s3.length();
   String val_3 = request.substring(index5+lf+3, index5+lf+8);   
   client.stop();
   query_dat.d1 = val_1.toInt();
   query_dat.d2 = val_2.toInt();
   query_dat.d3 = val_3.toInt();
   delay(2);  
   return query_dat;
 }
}

query_val LinkSpriteIO::query(String s1,String s2,String s3,String s4)
{
   query_val query_dat; 
   String ss;
   ss="\"";
   ss+=s1;
   ss+="\"";   
   ss+=",";
   ss+="\"";
   ss+=s2;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s3;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s4;
   ss+="\""; 
   if (client.connect("www.linksprite.io",80)) 
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
         postStr += ss;
         postStr +="]";
         postStr +="}";
    client.print("POST /api/http HTTP/1.1\n");
    client.print("Host: ");
    client.print("www.linksprite.io");
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);  
  }
 delay(80);
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
   int index3 = request.indexOf(s1);
   int index4 = request.indexOf(s2);
   int index5 = request.indexOf(s3);
   int index6 = request.indexOf(s4);
   String param = request.substring(index1, index2+1);
   int le = s1.length();
   String val_1 = request.substring(index3+le+3, index3+le+8); 
   int ld = s2.length();
   String val_2 = request.substring(index4+ld+3, index4+ld+8);
   int lf = s3.length();
   String val_3 = request.substring(index5+lf+3, index5+lf+8); 
   int lg = s4.length();
   String val_4 = request.substring(index6+lg+3, index6+lg+8);
   client.stop();
   query_dat.d1 = val_1.toInt();
   query_dat.d2 = val_2.toInt();
   query_dat.d3 = val_3.toInt();
   query_dat.d4 = val_4.toInt();
   delay(2);  
   return query_dat;
 }
}

query_val LinkSpriteIO::query(String s1,String s2,String s3,String s4,String s5)
{
   query_val query_dat; 
   String ss;
   ss="\"";
   ss+=s1;
   ss+="\"";   
   ss+=",";
   ss+="\"";
   ss+=s2;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s3;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s4;
   ss+="\""; 
   ss+=",";
   ss+="\"";
   ss+=s5;
   ss+="\"";
   if (client.connect("www.linksprite.io",80)) 
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
         postStr += ss;
         postStr +="]";
         postStr +="}";
    client.print("POST /api/http HTTP/1.1\n");
    client.print("Host: ");
    client.print("www.linksprite.io");
    client.print("\nContent-Type: application/json\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);  
  }
 delay(80);
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
   int index3 = request.indexOf(s1);
   int index4 = request.indexOf(s2);
   int index5 = request.indexOf(s3);
   int index6 = request.indexOf(s4);
   int index7 = request.indexOf(s5);
   String param = request.substring(index1, index2+1);
   int le = s1.length();
   String val_1 = request.substring(index3+le+3, index3+le+8); 
   int ld = s2.length();
   String val_2 = request.substring(index4+ld+3, index4+ld+8);
   int lf = s3.length();
   String val_3 = request.substring(index5+lf+3, index5+lf+8); 
   int lg = s4.length();
   String val_4 = request.substring(index6+lg+3, index6+lg+8);
   int lh = s5.length();
   String val_5 = request.substring(index7+lh+3, index7+lh+8);
   client.stop();
   query_dat.d1 = val_1.toInt();
   query_dat.d2 = val_2.toInt();
   query_dat.d3 = val_3.toInt();
   query_dat.d4 = val_4.toInt();
   query_dat.d5 = val_5.toInt();
   delay(2);  
   return query_dat;
 }
}

String LinkSpriteIO::update(String type,String val)
{
   String param;
   String s = "\"";
   s += type;
   s += "\":"; 
   if (client.connect("www.linksprite.io",80)) 
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
    client.print("www.linksprite.io");
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