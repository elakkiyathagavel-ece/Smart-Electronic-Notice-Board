#include <WiFi.h>
#include <WebServer.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "SmartNotice";
const char* password = "12345678";

WebServer server(80);

LiquidCrystal_I2C lcd(0x27, 16, 2);

String notice = "No Notice";

void setup() {
  Serial.begin(115200);

  // LCD Setup
  Wire.begin(21, 22);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("SMART NOTICE");

  lcd.setCursor(0, 1);
  lcd.print("BOARD READY");

  // Create Wi-Fi
  WiFi.softAP(ssid, password);

  Serial.println("Smart Notice Board WiFi Started");
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Webpage
  server.on("/", []() {
    String page = "<html>";
    page += "<head>";
    page += "<title>Smart Notice Board</title>";
    page += "</head>";

    page += "<body>";
    page += "<h1>SMART NOTICE BOARD</h1>";

    page += "<form action='/send' method='GET'>";
    page += "<input type='text' name='notice'>";
    page += "<input type='submit' value='SEND'>";
    page += "</form>";

    page += "</body>";
    page += "</html>";

    server.send(200, "text/html", page);
  });

  // SEND Button
  server.on("/send", []() {
    if (server.hasArg("notice")) {
      notice = server.arg("notice");

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("NOTICE:");

      lcd.setCursor(0, 1);
      lcd.print(notice.substring(0, 16));

      Serial.print("Notice: ");
      Serial.println(notice);
    }

    server.sendHeader("Location", "/");
    server.send(303);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
