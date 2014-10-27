//
// Example to show pulsing the costume via serial
//

#include <OctoWS2811.h>
#include <ledSkeleton.h>

#include <Entropy.h>

// setup memory for LEDs
// set this to be the length of the longest strip
const int ledsPerStrip = 64;

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];
const int config = WS2811_GRB | WS2811_800kHz;

// init LEDs
OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

// init ledSkeleton
ledSkeleton ledCostume;

int mode = 0;

long previousMillis = 0;
long currentMillis = 0;

long pixelSweepMillis = 0;

long generalMillis = 0;

int fillSkeletonCounter = 1;

boolean handShake = false;

int timer1 = 15200; // intro
int timer2 = 19300; // thriller beat

int timer3 = 47700; // skrillex intro

int timer4 = 49000; // skrillex strobe

int timer5 = 59200; // skrillex
int timer6 = 62300; // skrillex

int timer7 = 72800; // skrillex

int timer8 = 76200; // star wars

int timer9 = 122200; // halloween
int timer10 = 136500; // laughter

int timer11 = 148000; // laughter

int totalSize = 0;

// max lightness
int ml = 5;

// to-fix
int kickSize, hatSize, snareSize;
int totalEQ;

int legSweepCounter = 1;
boolean legSweepDirection = true;

int spineSweepCounter = 0;
boolean spineSweepDirection = true;

int armSweepCounter = 1;
boolean armSweepDirection = true;

int rainbowCounter = 0;

int randomPixelCounter = 0;

void setup() {
  
  // pass LEDs reference to costume 
  ledCostume.setLedInstance(&leds, ledsPerStrip);

  // init the strip for the body parts
  ledCostume.initLeftLeg( 1 , 15);
  ledCostume.initRightLeg( 2 , 15);
  
  ledCostume.initSpine( 3 , 12);
  ledCostume.initRib( 3 , 4);
  
  ledCostume.initLeftArm( 4, 12 );
  ledCostume.initRightArm( 5 , 12);
  
  // init the LEDs
  ledCostume.initLEDs();
  
  // blank LEDs
  ledCostume.clearLEDColor();
  
  // random
  Entropy.Initialize();
  
  // open serial port
  Serial.begin(9600);
  
  setupRandomPixel();
  
  /*while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }*/

  // pause main loop until we get the handshake from processing
  //establishContact();
  
}

void loop() {
  
  currentMillis = millis();
  
  if(!handShake) {
    
    checkHandShake();
    
  } else {

    // set the lights mode based on the current time
    setMode(currentMillis);
    
    // read in the song data from processing
    readSerial();
  
    // set the lights
    viewMode(currentMillis);
  
 }

}

//
// establishContact
//
/*void establishContact() {
  
  while (Serial.available() <= 0) {
    
    Serial.print(1);   // send a 1
    
    //delay(500);
    
  }
}*/

//
// setMode
//
void setMode(long c) {
  
    c = c - previousMillis;

    if(c > timer1 && c < timer2) { // if timer > 5 seconds then change mode
    
      setupPulseToTheBeat();
      mode = 1;
      
    } else if(c > timer2 && c < timer3) { // if timer > 10 seconds then change mode
      
      mode = 2;
      
    } else if(c > timer3 && c < timer4) { // if timer > 10 seconds then change mode
      
      mode = 3;
      
    } else if(c > timer4 && c < timer5) { // if timer > 10 seconds then change mode
      
      mode = 4;
      
    } else if(c > timer5 && c < timer6) { // if timer > 10 seconds then change mode
      
      mode = 5;
      
    } else if(c > timer6 && c < timer7) { // if timer > 10 seconds then change mode
      
      mode = 6;
      
    } else if(c > timer7 && c < timer8) { // if timer > 10 seconds then change mode
      
      mode = 7;
      
    } else if(c > timer8 && c < timer9) { // if timer > 10 seconds then change mode
      
      mode = 8;
      
    } else if(c > timer9 && c < timer10) { // if timer > 10 seconds then change mode
      
      mode = 9;
      
    } else if(c > timer10 && c < timer11) { // if timer > 10 seconds then change mode
      
      mode = 10;
      
    } else if(c > timer11) {
      
      mode = 11;
      
    }
    
}

//
// readSerial
//
void readSerial() {
  
    if (Serial.available() > 0) {
    
      // read in the eq
      // to fix - make this a struct
      kickSize = Serial.read();
      snareSize = Serial.read();
      hatSize = Serial.read();
      
      totalEQ = kickSize + snareSize + hatSize;

    }
    
}

//
// checkHandShake
//
void checkHandShake() {
  
    if (Serial.available() > 0) {
    
      int num = Serial.read() - '0';
    
      if(num == 0) {
        
        handShake = true;
        previousMillis = millis();
        
      }

    }
    
}

void viewMode(long c) {
  
  switch(mode) {
    
      case 0:

        // intro
        fillSkeleton(c); // working
        //pulseToTheBeat(kickSize, snareSize, hatSize); // working

      break;
      
      case 1:
      
        // thriller intro
        pulseToTheBeat(kickSize, snareSize, hatSize); // fix colours
    
      break;
    
      case 2:
        
        // thriller beat
        eqToTheBeatThriller(kickSize, snareSize, hatSize); // working
    
      break;
      
      case 3:
      
        // skrillex intro
        
   // set the colours of the parts
  ledCostume.leftLeg.h = 0;
  ledCostume.leftLeg.s = 0;
  ledCostume.leftLeg.maxLightness = 5;
  ledCostume.leftLeg.pulsing = true;
  
  ledCostume.rightLeg.h = 0;
  ledCostume.rightLeg.s = 0;
  ledCostume.rightLeg.pulsing = true;
  
  ledCostume.spine.h = 0;
  ledCostume.spine.s = 0;
  ledCostume.spine.maxLightness = 5;
  ledCostume.spine.pulsing = true;
  
  ledCostume.leftArm.h = 0;
  ledCostume.leftArm.s = 0;
  ledCostume.leftArm.maxLightness = 5;
  ledCostume.leftArm.pulsing = true;
  
  ledCostume.rightArm.h = 0;
  ledCostume.rightArm.s = 0;
  ledCostume.rightArm.maxLightness = 5;
  ledCostume.rightArm.pulsing = true;
        
        ledCostume.pulseLEDCostume(150); // delay
    
      break;
      
      case 4:
        // skrillex change
        //pixelSweep(50); // broken
        strobe(5);
    
      break;
      
      case 5:
        
        // skrillex change
        rainbow(); // working
    
      break;
      
      case 6:
      
        // skrillex change
        //strobeRandom(0);
        eqToTheBeatSkrillex(kickSize, snareSize, hatSize);
    
      break;
      
      case 7:
      
        // skrillex
        rainbow(); // working
        ledCostume.clearLEDColor();
    
      break;
      
      case 8:
      
        // starwars
        ledCostume.setLEDEq(49 , 100 , 5 , kickSize + snareSize + hatSize);
        ledCostume.clearLEDColor();
    
      break;
      
      case 9:
      
        // halloween
        randomPixel(0);
    
      break;
      
      case 10:
      
        // laughing
        ledCostume.setLEDEq(360 , 90 , 5 , kickSize + snareSize + hatSize);
        ledCostume.clearLEDColor();
    
      break;
      
      case 11:
      
        // end
    
      break;
    
    }
  
}
