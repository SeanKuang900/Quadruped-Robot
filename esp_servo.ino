#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "LWT29387";
const char* password = "83jd234Y1163";

WebServer server(80);


//FRONT LEFT
Servo FLHIP;
const int FLHpin = 33;
Servo FLKNEE;
const int FLKpin = 32;

//FRONT RIGHT
Servo FRHIP;
const int FRHpin = 26;
Servo FRKNEE;
const int FRKpin = 25;

//BACK LEFT
Servo BLHIP;
const int BLHpin = 27;
Servo BLKNEE;
const int BLKpin = 13;

//BACK RIGHT
Servo BRHIP;
const int BRHpin = 12;
Servo BRKNEE;
const int BRKpin = 14;

void goForward() {

}

void goLeft() {


}

void goBackward() {


}

void goRight() {

}

void handleRoot() {

    String webpage = R"rawliteral(

<!DOCTYPE html>

<html>

<head>

<style>

body {
    margin: 0;
    background-color: black;
    height: 100vh;

    display: flex;
    justify-content: center;
    align-items: center;
}

.controls {
    display: grid;
    grid-template-columns: 90px 90px 90px;
    grid-template-rows: 90px 90px;
    gap: 15px;
}

button {
    width: 90px;
    height: 90px;

    background-color: #222;
    color: white;

    border: none;
    border-radius: 15px;

    font-size: 45px;
}

button:active {
    background-color: #555;
}

.up {
    grid-column: 2;
    grid-row: 1;
}

.left {
    grid-column: 1;
    grid-row: 2;
}

.down {
    grid-column: 2;
    grid-row: 2;
}

.right {
    grid-column: 3;
    grid-row: 2;
}

</style>

</head>

<body>

<div class="controls">

    <button class="up" onclick="goForward()">↑</button>

    <button class="left" onclick="goLeft()">←</button>

    <button class="down" onclick="goBackward()">↓</button>

    <button class="right" onclick="goRight()">→</button>

</div>


<script>

function goForward() {
    fetch("/forward");
}

function goLeft() {
    fetch("/left");
}

function goBackward() {
    fetch("/backward");
}

function goRight() {
    fetch("/right");
}

</script>

</body>

</html>

)rawliteral";

    server.send(200, "text/html", webpage);
}

void setup() {

    Serial.begin(115200);

    FRHIP.attach();

    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid, password, 6);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Connected!");

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);

    server.on("/forward", goForward);
    server.on("/left", goLeft);
    server.on("/backward", goBackward);
    server.on("/right", goRight);

    server.begin();
}


void loop() {

    server.handleClient();

}