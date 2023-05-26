#include <WiFi.h>

#include <HTTPClient.h>

int x1=0,x2=0,x3=0;

// Set our wifi name and password

const char* ssid = "AndroidAP";

const char* password = "qwertyuio";

int trigPin1 = 5;
int echoPin1 = 18;

int trigPin2 = 23;
int echoPin2 = 22;

int trigPin3 = 21;
int echoPin3 = 19;

int duration1,duration2,duration3;
int distance1,distance2,distance3;


String serverName1 = "http://api.thingspeak.com/update?api_key=JN4XFN7MRVOSOACS&field1=0";

String serverName2   = "http://api.thingspeak.com/update?api_key=S2K1K01SDH3CYFLY&field1=0";

String serverName3 = "http://api.thingspeak.com/update?api_key=K5GAKGJERT5LT3AD&field1=0";


unsigned long lastTime = 0;

unsigned long timerDelay = 10000;



void setup() {

  Serial.begin(115200);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT);

  //Serial.begin(9600); // Opens up the serial port with a baudrate of 9600 bits per second

  WiFi.begin(ssid, password); // Attempt to connect to wifi with our password

  Serial.println("Connecting"); // Print our status to the serial monitor

  // Wait for wifi to connect

  while(WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.print("Connected to WiFi network with IP Address: ");

  Serial.println(WiFi.localIP());

}

void loop() {


  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1= duration1*0.0351/2;

  digitalWrite(trigPin2, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.0351/2;

  digitalWrite(trigPin3, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= duration3*0.0351/2;


  Serial.println(distance1);
  Serial.println(distance2);
  Serial.println(distance3);
  delay(100);

  if ((millis() - lastTime) > timerDelay) { // Check if its been a 10 sec (1/6)minute

    if(WiFi.status()== WL_CONNECTED){ // Check to make sure wifi is still connected

      //x1= distance1;
      if(distance1<30){
        x1=0;
      }
      else{
        x1=1;
      }



      //x2= distance2;
      if(distance2<30){
        x2=0;
      }
      else{
        x2=1;
      }
      //x3= distance3;
      if(distance3<30){
        x3=0;
      }
      else{
        x3=1;
      }

      sendData1(x1); // Call the sendData function defined below
      sendData2(x2);
      sendData3(x3);

    }

    else {

      Serial.println("WiFi Disconnected");

    }

    lastTime = millis();

  }

}

void sendData1(int dta)
{

  HTTPClient http; // Initialize our HTTP client

  Serial.println(dta);



  String url = serverName1 + "&field1=" + dta; // Define our entire url

      

  http.begin(url.c_str()); // Initialize our HTTP request

      

  int httpResponseCode = http.GET(); // Send HTTP request

      

  if (httpResponseCode > 0){ // Check for good HTTP status code

    Serial.print("HTTP Response code: ");

    Serial.println(httpResponseCode);

  }else{

    Serial.print("Error code: ");

    Serial.println(httpResponseCode);

  }

  http.end();

}

void sendData2(int dta)
{

  HTTPClient http; // Initialize our HTTP client

  Serial.println(dta);



  String url = serverName2 + "&field1=" + dta; // Define our entire url

      

  http.begin(url.c_str()); // Initialize our HTTP request

      

  int httpResponseCode = http.GET(); // Send HTTP request

      

  if (httpResponseCode > 0){ // Check for good HTTP status code

    Serial.print("HTTP Response code: ");

    Serial.println(httpResponseCode);

  }else{

    Serial.print("Error code: ");

    Serial.println(httpResponseCode);

  }

  http.end();

}

void sendData3(int dta)
{

  HTTPClient http; // Initialize our HTTP client

  Serial.println(dta);



  String url = serverName3 + "&field1=" + dta; // Define our entire url

      

  http.begin(url.c_str()); // Initialize our HTTP request

      

  int httpResponseCode = http.GET(); // Send HTTP request

      

  if (httpResponseCode > 0){ // Check for good HTTP status code

    Serial.print("HTTP Response code: ");

    Serial.println(httpResponseCode);

  }else{

    Serial.print("Error code: ");

    Serial.println(httpResponseCode);

  }

  http.end();

}