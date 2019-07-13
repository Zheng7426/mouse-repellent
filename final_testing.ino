// Robo India Tutorial 
// Digital Input and Output on LED 
// Hardware: NodeMCU
#include <ESP8266WiFi.h>

const char* ssid="LearningFactory";
const char* password = "Factory1";
const int PWM_ao = 4;
int pulse;
String header;
//int ledPin = 13;
WiFiServer server(80);
void setup() {
  
  //pinMode(ledPin,OUTPUT);
  //digitalWrite(ledPin,LOW);
  //pinMode(PWM_ao, OUTPUT); 
  Serial.begin(115200);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

  server.begin();
  Serial.println("NodeMCU Server started");

  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");


}
void loop()  { 
  // Check if a client has connected
  WiFiClient client = server.available();
if (client) {
    Serial.println("New client");
    // boolean to locate when the http request ends
    boolean blank_line = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        header += c;
  
        if (c == '\n' && blank_line) {

          // checking if header is valid
          // bmljazpuaWNrMTIz = 'nick:nick123'  base64 encode
    
          Serial.print(header);
          
          // Finding the right credential string
          if(header.indexOf("bmljazpuaWNrMTIz") >= 0) {
            //successful login
            Serial.println("HTTP/1.1 200 OK");
            Serial.println("Content-Type: text/html");
            Serial.println("Connection: close");
            Serial.println();
            // turns the GPIOs on and off
            if(header.indexOf("GET / HTTP/1.1") >= 0) {
                Serial.println("Main Web Page");
            }   
            else if(header.indexOf("GET /PWM=0 HTTP/1.1") >= 0){
              pulse = 0;
              analogWrite(PWM_ao, pulse);
            }
            else if(header.indexOf("GET /PWM=50 HTTP/1.1") >= 0){
              pulse = 50;
              analogWrite(PWM_ao, pulse);
            }
            else if(header.indexOf("GET /PWM=100 HTTP/1.1") >= 0){
              pulse = 100;
              analogWrite(PWM_ao, pulse);
            }
            else if(header.indexOf("GET /PWM=300 HTTP/1.1") >= 0){
              pulse = 300;
              analogWrite(PWM_ao, pulse);
            }
            else if(header.indexOf("GET /PWM=400 HTTP/1.1") >= 0){
              pulse = 400;
              analogWrite(PWM_ao, pulse);
            }
            else if(header.indexOf("GET /PWM=450 HTTP/1.1") >= 0){
              pulse = 450;
              analogWrite(PWM_ao, pulse);
            }
            else if(header.indexOf("GET /PWM=melody HTTP/1.1") >= 0){
             analogWrite(PWM_ao, 12);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 12);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    
    analogWrite(PWM_ao, 18);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 18);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    
    analogWrite(PWM_ao, 20);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 20);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 18);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(100);

    //second verse
     analogWrite(PWM_ao, 16.5);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 16.5);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);

    analogWrite(PWM_ao, 14.5);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 14.5);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);

    analogWrite(PWM_ao, 13);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);
    analogWrite(PWM_ao, 13);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(20);

    analogWrite(PWM_ao, 12);
    delay(500);
    analogWrite(PWM_ao, 0);
    delay(40);
            }
            
  // Match the request
  /*if (request.indexOf("/PWM=0") != -1) {
    pulse = 0;
    digitalWrite(PWM_ao, LOW);
  }*/
  /*if(request.indexOf("/PWM=20") != -1) {
    pulse = 20;
    analogWrite(PWM_ao, pulse);
  }
  if(request.indexOf("/PWM=50") != -1) {
    pulse = 50;
    analogWrite(PWM_ao, pulse);
  }
   if(request.indexOf("/PWM=120") != -1) {
    pulse = 120;
    analogWrite(PWM_ao, pulse);
  }*/
  //main web page
 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css\">");
  client.println("<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css\" integrity=\"sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO\" crossorigin=\"anonymous\">");
  client.println("<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css\">");
  client.println("<link rel=\"stylesheet\" href=\"https://fonts.googleapis.com/css?family=Work+Sans:300,500\">");
  client.println("<style type=\"text/css\">body{font-family: 'Work Sans', sans-serif;}");
  client.println("header {position: relative;background-color: black;height: 110vh;min-height: 23rem;width: 100%;overflow: hidden;}");
  client.println("header video {position: absolute;top: 50%;left: 50%;min-width: 100%;min-height: 100%;width: auto;height: auto;z-index: 0;-ms-transform: translateX(-50%) translateY(-50%);-moz-transform: translateX(-50%) translateY(-50%);-webkit-transform: translateX(-50%) translateY(-50%);transform: translateX(-50%) translateY(-50%);}");
  client.println("header .container {position: relative;z-index: 2;}");
  client.println("header .btn {box-shadow: 2px 4px 6px rgb(32,19,16);}");
  client.println("header .bg-deeper {box-shadow: 2px 4px 6px rgb(14,14,8);}");
  client.println("header h1,h2,h3 {text-shadow: 2px 2px rgb(32,19,16);}");
  client.println("#hong .btn-dark:hover {color: #ff0000;}");
  client.println("#chen .btn-dark:hover {color: #ff8000;}");
  client.println("#huang .btn-dark:hover {color: rgb(255,212,60);}");
  client.println("#lv .btn-dark:hover {color: #80ff00;}");
  client.println("#qing .btn-dark:hover {color: #00bfff;}");
  client.println("#lan .btn-dark:hover {color: #0040ff;}");
  client.println("#zi .btn-dark:hover {color: #8000ff;}");
  client.println("header .overlay {position: absolute;top: 0;left: 0;height: 100%;width: 100%;background-color: black;opacity: 0.5;z-index: 1;}");
  client.println("@media only screen and (max-width: 420px){header .h-100 {/*min-height: 100% !important;*/}.bg-deeper .display-3 {font-size: 2.5rem;font-weight: 500;line-height: 1.2;}.bg-deeper h5 {display: none;}.bg-deeper h2 {display: none;/*font-size: 1.3rem;*/}.bg-deeper h3 {font-size: 1.25rem;}}</style>");
  client.println("</head>");

  client.println("<body>");
  client.println("<header>");
  client.println("<div class=\"overlay\"></div>");
  client.println("<video width=\"560\" id=\"myVideo\" autoplay muted playsinline>");
  client.println("<source src=\"http://zheng-basics.oss-cn-beijing.aliyuncs.com/capstone_01.mp4\" type=\"video/mp4\">");
  client.println("</video>");
  client.println("<div class=\"container h-100 intro-header\">");
  client.println("<div class=\"d-flex text-center h-100\">");
  client.println("<div class=\"my-auto w-100 text-white col-sm-12 col-md-9 col-lg-12\">");
  client.println("<div class=\"bg-deeper\" style=\"background-color: rgba(14,14,8,0.6);border-radius:.3rem;\">");
  client.println("<h1 class=\"display-3\">Repellent device</h1>");
  client.println("<h2>Choose your desirable frequency range below.</h2>");
  client.print("<h3 style=\"font-weight:bold;\">The device is now: ");
  if(pulse == 50) {
    client.print("<span style=\"color:#7CFC00\">Operating at 2.22 kHz.</span></h3>");
  }
  if(pulse == 100) {
    client.print("<span style=\"color:#7CFC00\">Operating at 4.48 kHz.</span></h3>");
  }
  if(pulse == 300) {
    client.print("<span style=\"color:#7CFC00\">Operating at 13.59 kHz.</span></h3>");
  }
  if(pulse == 400) {
    client.print("<span style=\"color:#7CFC00\">Operating at 22 kHz.</span></h3>");
  }
  if(pulse == 450) {
    client.print("<span style=\"color:#7CFC00\">Operating at 34 kHz.</span></h3>");
  }
  if(pulse == 0) {
    client.print("<span style=\"color:#7CFC00\">Activated.</span></h3>");
  }
  client.println("<h5 style=\"visibility:hidden;\">.</h5></div>");
  client.println("<br>");
  client.println("<div id=\"hong\"><a href=\"/PWM=0\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6 hover-red\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>TURN OFF</strong></a></div>");
  client.println("<div id=\"chen\"><a href=\"/PWM=50\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>LOW</strong></a></div>");
  client.println("<div id=\"huang\"><a href=\"/PWM=100\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>MEDIUM</strong></a></div>");
  client.println("<div id=\"lv\"><a href=\"/PWM=300\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>HIGH</strong></a></div>");
  client.println("<div id=\"qing\"><a href=\"/PWM=400\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>ULTRASONIC I</strong></a></div>");
  client.println("<div id=\"lan\"><a href=\"/PWM=450\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>ULTRASONIC II</strong></a></div>"); 
  client.println("<div id=\"zi\"><a href=\"/PWM=melody\" class=\"btn btn-dark btn-lg btn-outline-light col-lg-6\" style=\"display:block;margin:7px auto;border-bottom:2px solid white;border-right:2px solid white;\"><strong>\"MELODY\"</strong></a></div>");
  
  client.println("</div></div></div></header>");
    client.println("<script>var iterations = 1;myVideo.addEventListener('ended', function () {if (iterations < 15) {this.currentTime = 0;this.play();iterations ++;}}, false);</script>");
  client.println("</body></html>");
          }
          else {
           client.println("HTTP/1.1 401 Unauthorized");
           client.println("WWW-Authenticate: Basic realm=\"Secure\"");
           client.println("Content-Type: text/html");
           client.println();
           client.println("<html>Authentication failed</html>");
          }
          header = "";
        break;
        }
        if (c == '\n') {
          // when starts reading a new line
          blank_line = true;
        }
        else if (c != '\r') {
          // when finds a character on the current line
          blank_line = false;
        }
      }
    }  

  
  //client.println("<i class=\"fa fa-rss\" style=\"font-size:48px;\"></i>");
  //client.println("<div class=\"row justify-content-md-center\">");
  //client.println("<div><a href=\"/PWM=100\" class=\"btn btn-outline-dark btn-lg btn-block\" role=\"button\">Turn to 100</a></div>");
  //client.println("</div>");
  //client.println("<div class=\"row justify-content-md-center\">");
  //client.println("<div><a href=\"/PWM=300\" class=\"btn btn-outline-dark btn-lg btn-block\" role=\"button\">Turn to 300</a></div>");
                     
  //client.println("<br><br>");
  //client.println("</div>");
  //client.println("<a href=\"/PWM=100\"\"><button>Turn to 100 </button></a>");
  //client.println("<a href=\"/PWM=300\"\"><button>Turn to 300 </button></a><br />");
  
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
  }
}
             

