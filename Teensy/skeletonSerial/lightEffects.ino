void setupPulseToTheBeat() {
  
// set LED parts
  ledCostume.leftLeg.h = 20;
  ledCostume.leftLeg.s = 100;
  ledCostume.leftLeg.maxLightness = ml;
  ledCostume.leftLeg.pulsing = true;
  
  ledCostume.rightLeg.h = 20;
  ledCostume.rightLeg.s = 100;
  ledCostume.rightLeg.maxLightness = ml;
  ledCostume.rightLeg.pulsing = true;
  
  ledCostume.spine.h = 30;
  ledCostume.spine.s = 100;
  ledCostume.spine.maxLightness = ml;
  ledCostume.spine.pulsing = true;
  
  ledCostume.leftArm.h = 40;
  ledCostume.leftArm.s = 100;
  ledCostume.leftArm.maxLightness = ml;
  ledCostume.leftArm.pulsing = true;
  
  ledCostume.rightArm.h = 40;
  ledCostume.rightArm.s = 100;
  ledCostume.rightArm.maxLightness = 5;
  ledCostume.rightArm.pulsing = true;
  
}

void pulseToTheBeat(int kickSize, int snareSize, int hatSize) {
  
  if(kickSize >= 15) {
    
  ledCostume.leftLeg.pulsing = true;
  ledCostume.rightLeg.pulsing = true;
  
  }
  
  if(snareSize >= 16) {
    
  ledCostume.spine.pulsing = true;
  
  }
  
  if(hatSize >= 12) {
    
  ledCostume.leftArm.pulsing = true;
  ledCostume.rightArm.pulsing = true; 
 
 }

  ledCostume.pulseLEDCostume(80); // delay
    
}

void eqToTheBeatThriller(int kickSize, int snareSize, int hatSize) {
  
  ledCostume.leftLeg.h = 243;
  ledCostume.leftLeg.s = 100;
  ledCostume.leftLeg.l = ml;;
  ledCostume.leftLeg.maxLightness = 5;
  
  ledCostume.rightLeg.h = 243;
  ledCostume.rightLeg.s = 100;
  ledCostume.rightLeg.l = ml;
  ledCostume.rightLeg.maxLightness = 5;
  
  ledCostume.spine.h = 330;
  ledCostume.spine.s = 100;
  ledCostume.spine.l = ml;
  ledCostume.spine.maxLightness = 5;
  
  ledCostume.leftArm.h = 350;
  ledCostume.leftArm.s = 100;
  ledCostume.leftArm.l = ml;
  ledCostume.leftArm.maxLightness = 5;
  
  ledCostume.rightArm.h = 350;
  ledCostume.rightArm.s = 100;
  ledCostume.rightArm.l = ml;
  ledCostume.rightArm.maxLightness = 5;
  
        // light up left leg
      ledCostume.setLEDPartColor( ledCostume.leftLeg.h, ledCostume.leftLeg.s, ml, ledCostume.leftLeg.channel, kickSize);
      
      // light up right leg
      ledCostume.setLEDPartColor( ledCostume.rightLeg.h, ledCostume.rightLeg.s, ml, ledCostume.rightLeg.channel, kickSize);
      
      // light up spine
      ledCostume.setLEDPartColor( ledCostume.spine.h, ledCostume.spine.s, ml, ledCostume.spine.channel, snareSize);
      
      // light up left arm
      ledCostume.setLEDPartColor( ledCostume.leftArm.h, ledCostume.leftArm.s, ml, ledCostume.leftArm.channel, hatSize);
    
      // light up right arm
      ledCostume.setLEDPartColor( ledCostume.rightArm.h, ledCostume.rightArm.s, ml, ledCostume.rightArm.channel, hatSize);
      
      ledCostume.clearLEDColor();
}



void eqToTheBeatSkrillex(int kickSize, int snareSize, int hatSize) {
  
  ledCostume.leftLeg.h = 116;
  ledCostume.leftLeg.s = 100;
  ledCostume.leftLeg.l = ml;
  ledCostume.leftLeg.maxLightness = 5;
  
  ledCostume.rightLeg.h = 116;
  ledCostume.rightLeg.s = 100;
  ledCostume.rightLeg.l = ml;
  ledCostume.rightLeg.maxLightness = 5;
  
  ledCostume.spine.h = 304;
  ledCostume.spine.s = 100;
  ledCostume.spine.l = ml;
  ledCostume.spine.maxLightness = 5;
  
  ledCostume.leftArm.h = 175;
  ledCostume.leftArm.s = 100;
  ledCostume.leftArm.l = ml;
  ledCostume.leftArm.maxLightness = 5;
  
  ledCostume.rightArm.h = 175;
  ledCostume.rightArm.s = 100;
  ledCostume.rightArm.l = ml;
  ledCostume.rightArm.maxLightness = 5;
  
        // light up left leg
      ledCostume.setLEDPartColor( ledCostume.leftLeg.h, ledCostume.leftLeg.s, ml, ledCostume.leftLeg.channel, kickSize);
      
      // light up right leg
      ledCostume.setLEDPartColor( ledCostume.rightLeg.h, ledCostume.rightLeg.s, ml, ledCostume.rightLeg.channel, kickSize);
      
      // light up spine
      ledCostume.setLEDPartColor( ledCostume.spine.h, ledCostume.spine.s, ml, ledCostume.spine.channel, snareSize);
      
      // light up left arm
      ledCostume.setLEDPartColor( ledCostume.leftArm.h, ledCostume.leftArm.s, ml, ledCostume.leftArm.channel, hatSize);
    
      // light up right arm
      ledCostume.setLEDPartColor( ledCostume.rightArm.h, ledCostume.rightArm.s, ml, ledCostume.rightArm.channel, hatSize);
      
      ledCostume.clearLEDColor();
}

void eqToTheBeatStarWars(int kickSize, int snareSize, int hatSize) {
  
  ledCostume.leftLeg.h = 49;
  ledCostume.leftLeg.s = 100;
  ledCostume.leftLeg.l = ml;
  
  ledCostume.rightLeg.h = 49;
  ledCostume.rightLeg.s = 100;
  ledCostume.rightLeg.l = ml;
  
  ledCostume.spine.h = 29;
  ledCostume.spine.s = 100;
  ledCostume.spine.l = ml;
  
  ledCostume.leftArm.h = 4;
  ledCostume.leftArm.s = 9;
  ledCostume.leftArm.l = ml;
  
  ledCostume.rightArm.h = 4;
  ledCostume.rightArm.s = 9;
  ledCostume.rightArm.l = ml;
  
        // light up left leg
      ledCostume.setLEDPartColor( ledCostume.leftLeg.h, ledCostume.leftLeg.s, ml, ledCostume.leftLeg.channel, kickSize);
      
      // light up right leg
      ledCostume.setLEDPartColor( ledCostume.rightLeg.h, ledCostume.rightLeg.s, ml, ledCostume.rightLeg.channel, kickSize);
      
      // light up spine
      ledCostume.setLEDPartColor( ledCostume.spine.h, ledCostume.spine.s, ml, ledCostume.spine.channel, snareSize);
      
      // light up left arm
      ledCostume.setLEDPartColor( ledCostume.leftArm.h, ledCostume.leftArm.s, ml, ledCostume.leftArm.channel, hatSize);
    
      // light up right arm
      ledCostume.setLEDPartColor( ledCostume.rightArm.h, ledCostume.rightArm.s, ml, ledCostume.rightArm.channel, hatSize);
      
      ledCostume.clearLEDColor();
}


void eqCostumeToTheBeat(int kickSize, int snareSize, int hatSize) {
  
  ledCostume.leftLeg.h = 300;
  ledCostume.leftLeg.s = 100;
  ledCostume.leftLeg.l = ml;
  //ledCostume.leftLeg.maxLightness = 5;
  
  ledCostume.rightLeg.h = 300;
  ledCostume.rightLeg.s = 100;
  ledCostume.rightLeg.l = ml;
  //ledCostume.rightLeg.maxLightness = 5;
  
  ledCostume.spine.h = 200;
  ledCostume.spine.s = 100;
  ledCostume.spine.l = ml;
  //ledCostume.spine.maxLightness = 5;
  
  ledCostume.leftArm.h = 50;
  ledCostume.leftArm.s = 100;
  ledCostume.leftArm.l = ml;
  ledCostume.leftArm.maxLightness = 5;
  
  ledCostume.rightArm.h = 50;
  ledCostume.rightArm.s = 100;
  ledCostume.rightArm.l = ml;
  //ledCostume.rightArm.maxLightness = 2;
  
        // light up left leg
      ledCostume.setLEDPartColor( ledCostume.leftLeg.h, ledCostume.leftLeg.s, ml, ledCostume.leftLeg.channel, kickSize + snareSize + hatSize);
      
      // light up right leg
      ledCostume.setLEDPartColor( ledCostume.rightLeg.h, ledCostume.rightLeg.s, ml, ledCostume.rightLeg.channel, kickSize + snareSize + hatSize);
      
      // light up spine
      ledCostume.setLEDPartColor( ledCostume.spine.h, ledCostume.spine.s, ml, ledCostume.spine.channel, kickSize + snareSize + hatSize);
      
      // light up left arm
      ledCostume.setLEDPartColor( ledCostume.leftArm.h, ledCostume.leftArm.s, ml, ledCostume.leftArm.channel, kickSize + snareSize + hatSize);
    
      // light up right arm
      ledCostume.setLEDPartColor( ledCostume.rightArm.h, ledCostume.rightArm.s, ml, ledCostume.rightArm.channel, kickSize + snareSize + hatSize);
      
      ledCostume.clearLEDColor();
}




void strobe(int s) {
  
  // working
  
  // set LED parts
  ledCostume.leftLeg.h = 0;
  ledCostume.leftLeg.s = 0;
  ledCostume.leftLeg.maxLightness = ml;
  ledCostume.leftLeg.pulsing = true;
  
  ledCostume.rightLeg.h = 0;
  ledCostume.rightLeg.s = 0;
  ledCostume.rightLeg.maxLightness = ml;
  ledCostume.rightLeg.pulsing = true;
  
  ledCostume.spine.h = 0;
  ledCostume.spine.s = 0;
  ledCostume.spine.maxLightness = ml;
  ledCostume.spine.pulsing = true;
  
  ledCostume.leftArm.h = 0;
  ledCostume.leftArm.s = 0;
  ledCostume.leftArm.maxLightness = ml;
  ledCostume.leftArm.pulsing = true;
  
  ledCostume.rightArm.h = 0;
  ledCostume.rightArm.s = 0;
  ledCostume.rightArm.maxLightness = ml;
  ledCostume.rightArm.pulsing = true;

  ledCostume.pulsePart(&ledCostume.leftLeg, s); // part, delay
  
  ledCostume.pulsePart(&ledCostume.rightLeg, s); // part, delay
  
  ledCostume.pulsePart(&ledCostume.spine, s); // part, delay
  
  ledCostume.pulsePart(&ledCostume.leftArm, s); // part, delay
  
  ledCostume.pulsePart(&ledCostume.rightArm, s); // part, delay
  
}

void rainbow() {
  
  if(rainbowCounter < 360) {
  
    ledCostume.setLEDColor(rainbowCounter, 50, ml);
    rainbowCounter++;
  
  } else {
    
    rainbowCounter = 0;
    
  }

}

void strobeRandom(int s) {
  
  // working
  
  // set LED parts
  ledCostume.leftLeg.h = ledCostume.rightLeg.h = Entropy.random(0,50);
  ledCostume.leftLeg.s = 50;
  
  ledCostume.rightLeg.s = 50;
  
  ledCostume.spine.h = Entropy.random(50,150);
  ledCostume.spine.s = 50;
  
  ledCostume.leftArm.h = ledCostume.rightArm.h = Entropy.random(150,350);
  ledCostume.leftArm.s = 50;
  
  ledCostume.rightArm.s = 50;

  // light up left leg
  ledCostume.setLEDPartColor( ledCostume.leftLeg.h, ledCostume.leftLeg.s, ml, ledCostume.leftLeg.channel, ledCostume.leftLeg.size);
  
  // light up right leg
  ledCostume.setLEDPartColor( ledCostume.rightLeg.h, ledCostume.rightLeg.h, ml, ledCostume.rightLeg.channel, ledCostume.rightLeg.size);
  
  // light up spine
  ledCostume.setLEDPartColor( ledCostume.spine.h, ledCostume.spine.h, ml, ledCostume.spine.channel, ledCostume.spine.size + ledCostume.rib.size);
  
  // light up left arm
  ledCostume.setLEDPartColor( ledCostume.leftArm.h, ledCostume.leftArm.s, ml, ledCostume.leftArm.channel, ledCostume.leftArm.size);

  // light up right arm
  ledCostume.setLEDPartColor( ledCostume.rightArm.h, ledCostume.rightArm.s, ml, ledCostume.rightArm.channel, ledCostume.rightArm.size);
  
}

void randomLED() {

  for(int i=0;i < ledCostume.ledInstance->numPixels();i++) {
    
    ledCostume.setLEDPixel(i, 100, ml, i);
    
  }
  
}

void matrixLED() {
  
}

void pixelSweep(long c) {
  
  // broken
  
  if(c - pixelSweepMillis > 100) {
    
    pixelSweepMillis = c;
    
    ledCostume.clearLEDColor();
   
    sweepLeg();

    sweepArm();
  
  }
  
}

//
// Pre-computer random pixels because entropy is soooooo slooooooooowwwwww
//
void setupRandomPixel() {
  
  for(int i=0;i<=totalSize;i++) {
    
    int tempRand = Entropy.random(0, ledCostume.totalSize + 1);
    int tempRand2 = Entropy.random(1, ml + 1);
    
    ledCostume.randomPixelArray[i].h = tempRand;
    ledCostume.randomPixelArray[i].s = 100;
    ledCostume.randomPixelArray[i].l = tempRand2;
  
  }
  
}

void randomPixel(long c) {
  
  for(int i=0;i<=totalSize;i++) {
    
    ledCostume.setLEDPixel(ledCostume.randomPixelArray[i].h, ledCostume.randomPixelArray[i].s, ledCostume.randomPixelArray[i].l, i);
    ledCostume.ledInstance->show();
    
  }
  
}

void fillSkeleton(long c) {
  
  //Serial.println("fillSkeleton");
  
  if(c - generalMillis > 170) { // working
    
    generalMillis = c;
    
    ledCostume.setLEDPixel(20, fillSkeletonCounter, ml, fillSkeletonCounter);
    
    fillSkeletonCounter++;
  
    ledCostume.ledInstance->show();
  
  }
  
}
