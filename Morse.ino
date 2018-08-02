#include <stdio.h>

void convertToMorse(char*);

int SLOW = 750;
int FAST = 250;

#define MSG "Message"

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  beginMorse();

  char *msg = MSG;
  convertToMorse(msg);

  endMorse();
}

void dot() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(FAST);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(FAST); 
}

void dash() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(SLOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(FAST); 
}

void between() {
  pause(SLOW * 2); 
}

void space() {
  pause(SLOW * 4);
}

void pause(int time) {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(time);  
}

void beginMorse() {
  blinkLed(10);
  pause(2000);   
}

void endMorse() {
  pause(5000);  
}

void convertToMorse(char* sentence) {
  for (int i = 0; i < strlen(sentence); i++) {
    char c = sentence[i];
    toMorse(tolower(c));
    between();
  }
}

void toMorse(char c) {
  switch(c) {
    case 'a' : a(); break;
    case 'b' : b(); break;
    case 'c' : letterC(); break;
    case 'd' : d(); break;
    case 'e' : e(); break;
    case 'f' : f(); break;
    case 'g' : g(); break;
    case 'h' : h(); break;
    case 'i' : i(); break;
    case 'j' : j(); break;
    case 'k' : k(); break;
    case 'l' : l(); break;
    case 'm' : m(); break;
    case 'n' : n(); break;
    case 'o' : o(); break;
    case 'p' : p(); break;
    case 'q' : q(); break;
    case 'r' : r(); break;
    case 's' : s(); break;
    case 't' : t(); break;
    case 'u' : u(); break;
    case 'v' : v(); break;
    case 'w' : w(); break;
    case 'x' : x(); break;
    case 'y' : y(); break;
    case 'z' : z(); break;
    case ' ' : space(); break;
    case '0' : zero(); break;
    case '1' : one(); break;
    case '2' : two(); break;
    case '3' : three(); break;
    case '4' : four(); break;
    case '5' : five(); break;
    case '6' : six(); break;
    case '7' : seven(); break;
    case '8' : eight(); break;
    case '9' : nine(); break;
    default : blinkLed(20); break; /* blink 20 times to indicate there's something wrong! */
  }
}

void blinkLed(int t) {
  for(int i = 0; i < t; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);  
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(100); 
  }
}

/* Codes from https://morsecode.scphillips.com/morse2.html */
void a() { dot();dash(); }
void b() {   dash();dot();dot();dot(); }
void letterC() {  dash();dot();dash();dot(); }
void d() {  dash();dot();dot(); }
void e() {  dot(); }
void f() {  dot();dot();dash();dot(); }
void g() {  dash();dash();dot(); }
void h() {  dot();dot();dot();dot(); }
void i() {  dot();dot(); }
void j() {  dot();dash();dash();dash(); }
void k() {  dash();dot();dash(); }
void l() {  dot();dash();dot();dot(); }
void m() {  dash();dash(); }
void n() {  dash();dot(); }
void o() {  dash();dash();dash(); }
void p() {  dot();dash();dash();dot(); }
void q() {  dash();dash();dot();dash(); }
void r() {  dot();dash();dot(); }
void s() {  dot();dot();dot(); }
void t() {  dash(); }
void u() {  dot();dot();dash(); }
void v() {  dot();dot();dot();dash(); }
void w() {  dot();dash();dash(); }
void x() {  dash();dot();dot();dash(); }
void y() {  dash();dot();dash();dash(); }
void z() {  dash();dash();dot();dot(); }
void zero() {   dash();dash();dash();dash();dash(); }
void one() {  dot();dash();dash();dash();dash(); }
void two() {  dot();dot();dash();dash();dash(); }
void three() {  dot();dot();dot();dash();dash(); }
void four() {   dot();dot();dot();dot();dash(); }
void five() {   dot();dot();dot();dot();dot(); }
void six() {  dash();dot();dot();dot();dot(); }
void seven() {  dash();dash();dot();dot();dot(); }
void eight() {  dash();dash();dash();dot();dot(); }
void nine() { dash();dash();dash();dash();dot(); }
