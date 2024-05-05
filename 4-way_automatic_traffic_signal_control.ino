#include <Arduino.h>

// Define pin numbers for each traffic light signal
int red1Pin = 27;
int yellow1Pin = 14;
int green1Pin = 12;

int red2Pin = 19;
int yellow2Pin = 18;
int green2Pin = 5;

int red3Pin = 25;
int yellow3Pin = 33;
int green3Pin = 32;

int red4Pin = 16;
int yellow4Pin = 4;
int green4Pin = 0;

void setup() {
  // Initialize the pin modes
  pinMode(red1Pin, OUTPUT);
  pinMode(yellow1Pin, OUTPUT);
  pinMode(green1Pin, OUTPUT);

  pinMode(red2Pin, OUTPUT);
  pinMode(yellow2Pin, OUTPUT);
  pinMode(green2Pin, OUTPUT);

  pinMode(red3Pin, OUTPUT);
  pinMode(yellow3Pin, OUTPUT);
  pinMode(green3Pin, OUTPUT);

  pinMode(red4Pin, OUTPUT);
  pinMode(yellow4Pin, OUTPUT);
  pinMode(green4Pin, OUTPUT);
}

void loop()
{
  automate_signals();

}

void automate_signals() {
  initialstate_allred(); // intintial state
  while (true) {
    lane12();
    lane34();
    lane1();
    lane4();
    lane2();
    lane3();
  }
}

//  == == == == ==initial state - all red == == == == == == == == == == == == == ==
void initialstate_allred() {

  digitalWrite(red1Pin, HIGH);
  digitalWrite(yellow1Pin, LOW);
  digitalWrite(green1Pin, LOW);

  digitalWrite(red2Pin, HIGH);
  digitalWrite(yellow2Pin, LOW);
  digitalWrite(green2Pin, LOW);

  digitalWrite(red3Pin, HIGH);
  digitalWrite(yellow3Pin, LOW);
  digitalWrite(green3Pin, LOW);

  digitalWrite(red4Pin, HIGH);
  digitalWrite(yellow4Pin, LOW);
  digitalWrite(green4Pin, LOW);
  delay(10000);
} //  == == == == == == == == == == == == == == == == == == == == == == == == == == =


//================lane 1 and 2=================================
void lane12() {
  digitalWrite(red1Pin, 0);
  digitalWrite(yellow1Pin, 0);
  digitalWrite(green1Pin, 1);

  digitalWrite(red2Pin, 0);
  digitalWrite(yellow2Pin, 0);
  digitalWrite(green2Pin, 1);

  digitalWrite(red3Pin, 1);
  digitalWrite(yellow3Pin, 0);
  digitalWrite(green3Pin, 0);

  digitalWrite(red4Pin, 1);
  digitalWrite(yellow4Pin, 0);
  digitalWrite(green4Pin, 0);
  delay(10000);

  //transition
  digitalWrite(green1Pin, 0);
  digitalWrite(green2Pin, 0);
  digitalWrite(yellow1Pin, 1);
  digitalWrite(yellow2Pin, 1); // from lane lane 1and 2

  //transition to lane 3 an4
  digitalWrite(yellow3Pin, 1);
  digitalWrite(yellow4Pin, 1);

  delay(2000);

} //  ================================================


//==========lane 3 and 4=======================================
void lane34() {
  digitalWrite(red1Pin, 1);
  digitalWrite(yellow1Pin, 0);
  digitalWrite(green1Pin, 0);

  digitalWrite(red2Pin, 1);
  digitalWrite(yellow2Pin, 0);
  digitalWrite(green2Pin, 0);

  digitalWrite(red3Pin, 0);
  digitalWrite(yellow3Pin, 0);
  digitalWrite(green3Pin, 1);

  digitalWrite(red4Pin, 0);
  digitalWrite(yellow4Pin, 0);
  digitalWrite(green4Pin, 1);
  delay(10000);

  //transition
  digitalWrite(green4Pin, 0);
  digitalWrite(green3Pin, 0);
  digitalWrite(yellow3Pin, 1);
  digitalWrite(yellow4Pin, 1); // from lane lane 3 and 4

  //tranistion to lane 1
  digitalWrite(yellow1Pin, 1);
  delay(2000);
} //  ================================================


//================lane 1=================================
void lane1() {
  digitalWrite(red1Pin, 0);
  digitalWrite(yellow1Pin, 0);
  digitalWrite(green1Pin, 1);

  digitalWrite(red2Pin, 1);
  digitalWrite(yellow2Pin, 0);
  digitalWrite(green2Pin, 0);

  digitalWrite(red3Pin, 1);
  digitalWrite(yellow3Pin, 0);
  digitalWrite(green3Pin, 0);

  digitalWrite(red4Pin, 1);
  digitalWrite(yellow4Pin, 0);
  digitalWrite(green4Pin, 0);
  delay(10000);

  //transition
  digitalWrite(green1Pin, 0);
  digitalWrite(yellow1Pin, 1); // from lane lane 1

  //transition to lane 4
  digitalWrite(yellow4Pin, 1);
  delay(2000);
}  //  ================================================


//==================lane 4============================
void lane4() {
  digitalWrite(red1Pin, 1);
  digitalWrite(yellow1Pin, 0);
  digitalWrite(green1Pin, 0);

  digitalWrite(red2Pin, 1);
  digitalWrite(yellow2Pin, 0);
  digitalWrite(green2Pin, 0);

  digitalWrite(red3Pin, 1);
  digitalWrite(yellow3Pin, 0);
  digitalWrite(green3Pin, 0);

  digitalWrite(red4Pin, 0);
  digitalWrite(yellow4Pin, 0);
  digitalWrite(green4Pin, 1);
  delay(10000);

  //  transition
  digitalWrite(green4Pin, 0);
  digitalWrite(yellow4Pin, 1); // from lane lane 4

  //transition to lane 2
  digitalWrite(yellow2Pin, 1);
  delay(2000);
}  //  ================================================


//===============lane 2==================================
void lane2() {
  digitalWrite(red1Pin, 1);
  digitalWrite(yellow1Pin, 0);
  digitalWrite(green1Pin, 0);

  digitalWrite(red2Pin, 0);
  digitalWrite(yellow2Pin, 0);
  digitalWrite(green2Pin, 1);

  digitalWrite(red3Pin, 1);
  digitalWrite(yellow3Pin, 0);
  digitalWrite(green3Pin, 0);

  digitalWrite(red4Pin, 1);
  digitalWrite(yellow4Pin, 0);
  digitalWrite(green4Pin, 0);
  delay(10000);

  //  transition
  digitalWrite(green2Pin, 0);
  digitalWrite(yellow2Pin, 1); // from lane lane 2

  //transition to lane 3
  digitalWrite(yellow3Pin, 1);
  delay(2000);
}//  ================================================


//============lane 3=====================================
void lane3() {
  digitalWrite(red1Pin, 1);
  digitalWrite(yellow1Pin, 0);
  digitalWrite(green1Pin, 0);

  digitalWrite(red2Pin, 1);
  digitalWrite(yellow2Pin, 0);
  digitalWrite(green2Pin, 0);

  digitalWrite(red3Pin, 0);
  digitalWrite(yellow3Pin, 0);
  digitalWrite(green3Pin, 1);

  digitalWrite(red4Pin, 1);
  digitalWrite(yellow4Pin, 0);
  digitalWrite(green4Pin, 0);
  delay(10000);

  //  transition
  digitalWrite(green3Pin, 0);
  digitalWrite(yellow3Pin, 1); // from lane lane 3

  // transistion to lane 1 and 2
  digitalWrite(yellow1Pin, 1);
  digitalWrite(yellow2Pin, 1);
  delay(2000);
} //  ================================================
