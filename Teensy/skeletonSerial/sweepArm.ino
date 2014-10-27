void sweepArm() {
  
  int h = 100;
  int s = 50;
  
  int armOffset = ledCostume.leftLeg.size + ledCostume.rightLeg.size + ledCostume.spine.size + (ledCostume.rib.size * 6);
  
  //Serial.println(armSweepCounter);
  
  // rising
  if(armSweepDirection) {
    
    if(armOffset + armSweepCounter <= ledCostume.totalSize) {
      
      ledCostume.setLEDPixel(h, s, 20, armOffset + armSweepCounter);
      ledCostume.setLEDPixel(h, s, 5, armOffset + armSweepCounter - 1);
      ledCostume.setLEDPixel(h, s, 2, armOffset + armSweepCounter - 2);

      ledCostume.ledInstance->show();
      
      armSweepCounter++;
      
    } else {
      
      armSweepDirection = false;
      
    }
    
  } else {
    
    // falling
    if(armOffset + armSweepCounter > armOffset + 3) {
    
      ledCostume.setLEDPixel(h, s, 20, armOffset + armSweepCounter);
      
      if(armSweepCounter + 1 < ledCostume.leftArm.size + ledCostume.rightArm.size) {
      
        ledCostume.setLEDPixel(h, s, 5, armOffset + armSweepCounter + 1);
      
      }
      
      if(armSweepCounter + 2 < ledCostume.leftArm.size + ledCostume.rightArm.size) {
      
        ledCostume.setLEDPixel(h, s, 2, armOffset + armSweepCounter + 2);
      
      }
      
    ledCostume.ledInstance->show();
    
    armSweepCounter--;
    
    } else {
      
      armSweepDirection = true;
      
    }
  
  }

}
