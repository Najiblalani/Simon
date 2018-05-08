// constant varibles for the pins for each button and led along with the buzzer
const int buttonGreenPin = 3;  
const int ledGreenPin =  11;      
const int buttonRedPin = 4;  
const int ledRedPin =  12; 
const int buttonBluePin = 2;  
const int ledBluePin =  13; 
const int buzzer = 10;


int randomleds[5]; //declare array to store 5 random numbers
int z; //delclared to keep track of the index to play leds 

//button states intitally set to 0
int buttonRedState = 0; 
int buttonGreenState = 0;
int buttonBlueState = 0;
     
void setup() {

  Serial.begin(9600); //sets the data rate at 9600 for serial data transmision
  randomSeed(analogRead(0)); //helps generate random numbers
  
  pinMode(ledGreenPin, OUTPUT); //set the green led as an output 
  pinMode(buttonGreenPin, INPUT); //set the green button as a input
  pinMode(ledRedPin, OUTPUT); //set red led as an output
  pinMode(buttonRedPin, INPUT); //set red button as an input
  pinMode(ledBluePin, OUTPUT); //set blue led a an output
  pinMode(buttonBluePin, INPUT); //set blue button as an input
  pinMode(buzzer, OUTPUT);// 
      
  for (int x = 0; x<5; x++){ //generates a random number between 0 to 2...
   randomleds[x] = random(3); //...and stores in the array 
  }
  for(z = 0; z<5; z++){ //calls the function to play random leds 5 times
   randomLights();
  }
             }

void loop() {
 playerInput(); //calls the function so that when a button is pressed... 
            }  //...the corresponding led and buzzer note activate

void playerInput(void){ //method to read if a button is being pressed
  
 buttonGreenState = digitalRead(buttonGreenPin);
  
  if (buttonGreenState == LOW){ // if the button is pressed turns on green led and plays a note
    digitalWrite(ledGreenPin, HIGH); //turn led on 
    tone(buzzer, 800); // Send .8KHz sound signal...
    delay(500);        // ...for .5 sec
    noTone(buzzer);     // Stop sound...
    delay(500);        // ...for .5sec
                              }
  else { //remains idle if the button is not being pressed
       digitalWrite(ledGreenPin, LOW);
       }
  
 buttonRedState = digitalRead(buttonRedPin);

  if (buttonRedState == LOW){ // if the button is pressed turns on red led and plays a note
    digitalWrite(ledRedPin, HIGH);
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(500);        // ...for .5 sec
    noTone(buzzer);     // Stop sound...
    delay(500);        // ...for .5 sec
                            }                                        
  else { //remains idle if the button is not being pressed
       digitalWrite(ledRedPin, LOW);
       } 
       
 buttonBlueState = digitalRead(buttonBluePin);

  if (buttonBlueState == LOW){ // if the button is pressed turns on blue led and plays a note
    digitalWrite(ledBluePin, HIGH);
    tone(buzzer, 600); // Send .6KHz sound signal...
    delay(500);        // ...for .5 sec
    noTone(buzzer);     // Stop sound...
    delay(500);        // ...for .5 sec
  }
  else { //remains idle if the button is not being pressed
       digitalWrite(ledBluePin, LOW);
       }
                   }

void randomLights(void){ //method to turn on a random led
   
 switch (randomleds[z]){ //tunrs on a led at the z postion in the randomleds array
   case 2: //if the value at the index is 2 red led blinks and the buzzer plays
   {
        digitalWrite(ledRedPin, HIGH); //red led turns on
        tone(buzzer, 1000); //buzzer plays at 1KHz for 1 second
        delay(1000);
        noTone(buzzer);
        digitalWrite(ledRedPin, LOW);//red led turns back off
        delay(1000); //waits one second before next led is played
        break;
   }
   case 1: //if the value at the index is 1 the green led blinks and the buzzer plays
   {
        digitalWrite(ledGreenPin, HIGH); //green led turns on
        tone(buzzer, 800); //buzzer plays at .8KHz for 1 second
        delay(1000);
        noTone(buzzer);
        digitalWrite(ledGreenPin, LOW); //green led turns back off
        delay(1000); //waits one second before the next led is played
        break;
   }
   case 0: //if the vaue at the index is o the blue led blinks and the buzzer plays
   { 
        digitalWrite(ledBluePin, HIGH); //blue led turns on
        tone(buzzer, 600); //buzzer plays at .6KHz for 1 second
        delay(1000);
        noTone(buzzer);
        digitalWrite(ledBluePin, LOW); //blue led turns back off
        delay(1000); //waits one second before the next led is played
        break;
   }
                       }
                      }


