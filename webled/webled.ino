/*
 

 In this sketch folder is a basic webpage and a copy of zepto.js, a
 minimized version of jQuery.  When you upload your sketch, these files
 will be placed in the /arduino/www/webled folder on your SD card.

 You can then go to http://your_yun_name.local/sd/webled
 to see the output of this sketch.


 */

#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

// Listen on default port 5555, the webserver on the Yun
// will forward there all the HTTP requests for us.
YunServer server;
String readString; 

void setup() {
  Serial.begin(9600);

  // Bridge startup
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  //digitalWrite(13, HIGH);

 

  // Listen for incoming connection only from localhost
  // (no one from the external network could connect)
  server.listenOnLocalhost();
  server.begin();

 
}

void loop() {
  // Get clients coming from server
  YunClient client = server.accept();

  // There is a new client?
  if (client) {
    // read the command
    String command = client.readString();
    command.trim();        //kill whitespace
    Serial.println(command);
    
   

    if (command == "ledon") {
       digitalWrite(13, HIGH);
    }
    else if (command == "ledoff") {
       digitalWrite(13, LOW);
    }
    // Close connection and free resources.
    client.stop();
   
  
  }
  
 

  delay(50); // Poll every 50ms
}


