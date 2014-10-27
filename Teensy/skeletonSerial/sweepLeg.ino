void sweepLeg() {

int h = 100;
int s = 50;

if(legSweepDirection) {
    
    if(legSweepCounter <= ledCostume.leftLeg.size + ledCostume.rightLeg.size - 1) {
      
      ledCostume.setLEDPixel(h, s, 20, legSweepCounter);
      ledCostume.setLEDPixel(h, s, 5, legSweepCounter - 1);
      ledCostume.setLEDPixel(h, s, 2, legSweepCounter - 2);

      ledCostume.ledInstance->show();
      
      legSweepCounter++;
      
    } else {
      
      legSweepDirection = false;
      
    }
    
  } else {
    
    if(legSweepCounter > 1) {
    
      ledCostume.setLEDPixel(h, s, 20, legSweepCounter);
      
      if(legSweepCounter + 1 < ledCostume.leftLeg.size + ledCostume.rightLeg.size) {
      
        ledCostume.setLEDPixel(h, s, 5, legSweepCounter + 1);
      
      }
      
      if(legSweepCounter + 2 < ledCostume.leftLeg.size + ledCostume.rightLeg.size) {
      
        ledCostume.setLEDPixel(h, s, 2, legSweepCounter + 2);
      
      }
      
    ledCostume.ledInstance->show();
    
    legSweepCounter--;
    
    } else {
      
      legSweepDirection = true;
      
    }
  
  }
  
}
