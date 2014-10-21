#include "OctoWS2811.h"
#include "Arduino.h"
#include "ledSkeleton.h"

ledSkeleton::ledSkeleton(void) {

}

void ledSkeleton::setLedInstance( OctoWS2811 *leds, int ledsPerStrip ) {

    ledInstance = leds;
    _ledsPerStrip = ledsPerStrip;
    _pulsing = false;
    _pulsingDirection = true;
    _currentColor = 0;
    
    _h = 0;
    _s = 0;
    _l = 0;
    
    _pulseSpeed = 1;
    _maxLightness = 100;
    
}

void ledSkeleton::initLEDs() {

	ledInstance->begin();
	ledInstance->show();

}

void ledSkeleton::setLEDColor(unsigned int h, unsigned int s, unsigned int l) {

	setHue(h);
	setSaturation(s);
	setLightness(l);

	//_currentColor = color;
	int color = makeColor(h, s, l);

	// iterate over ALL of the pixels and set them to one color
  	for (int i=0; i < ledInstance->numPixels(); i++) {
    	ledInstance->setPixel(i, color);
  	}
  	
  	ledInstance->show();

}

void ledSkeleton::clearLEDColor() {

	// iterate over ALL of the pixels and set them to one color
  	for (int i=0; i < ledInstance->numPixels(); i++) {
    	ledInstance->setPixel(i, 0x000000);
  	}
  	
  	ledInstance->show();

}

void ledSkeleton::setLEDPartColor(unsigned int h, unsigned int s, unsigned int l, int channel, int ledsToChange) {

	int color = makeColor(h, s, l);
	
	if(channel == rightLeg.channel ) {
	
		// Check if right leg and reverse the way we light the LEDs

		// Iterate over just the pixels for that body part and set them to one color
		int pos = _ledsPerStrip * (channel-1) + getRightLegSize();
		int end = pos - ledsToChange;
	
		for (pos; pos >= end; pos--) {
			ledInstance->setPixel(pos, color);
		}
  	
  	} else if(channel == spine.channel ) {
  	
		// iterate over just the pixels for that body part and set them to one color
		int startpos = _ledsPerStrip * (channel-1);
		int end = startpos + ledsToChange;
	
		for (int pos = startpos; pos < end; pos++) {
		
			if(pos < startpos + 15) {
				ledInstance->setPixel(pos, color);
			} else {
				ledInstance->setPixel(pos, color);
				ledInstance->setPixel(pos + 4, color);
				ledInstance->setPixel(pos + (4*2), color);
				ledInstance->setPixel(pos + (4*3), color);
				ledInstance->setPixel(pos + (4*4), color);
				ledInstance->setPixel(pos + (4*5), color);
			}
		}
  	
  	} else {
  	
		// iterate over just the pixels for that body part and set them to one color
		int pos = _ledsPerStrip * (channel-1);
		int end = pos + ledsToChange;
	
		for (pos; pos < end; pos++) {
				ledInstance->setPixel(pos, color);
		}
  	
  	}
  	
  	ledInstance->show();

}

void ledSkeleton::setLEDEq(unsigned int h, unsigned int s, unsigned int l, unsigned int eqSize) {

	//int totalSize = getLeftLegSize() + getRightLegSize() + getSpineSize() + getLeftArmSize() + getRightArmSize();

	//if(eqSize > totalSize) {
	//	eqSize = totalSize;
	//}

	setLEDPartColor(h, s, l, leftLeg.channel, eqSize);

	setLEDPartColor(h, s, l, rightLeg.channel, eqSize);
	
	setLEDPartColor(h, s, l, spine.channel, eqSize - leftLeg.size );
	
	setLEDPartColor(h, s, l, leftArm.channel, eqSize - leftLeg.size - spine.size );

	setLEDPartColor(h, s, l, rightArm.channel, eqSize - rightLeg.size - spine.size );

}

void ledSkeleton::initLeftArm(unsigned int channel, unsigned int size) {
	leftArm.channel = channel;
	leftArm.size = size;
}

void ledSkeleton::initRightArm(unsigned int channel, unsigned int size) {
	rightArm.channel = channel;
	rightArm.size = size;
}

void ledSkeleton::initLeftLeg(unsigned int channel, unsigned int size) {
	leftLeg.channel = channel;
	leftLeg.size = size;
}

void ledSkeleton::initRightLeg(unsigned int channel, unsigned int size) {
	rightLeg.channel = channel;
	rightLeg.size = size;
}

void ledSkeleton::initSpine(unsigned int channel, unsigned int size) {
	spine.channel = channel;
	spine.size = size;
}

void ledSkeleton::initRib(unsigned int channel, unsigned int size) {
}

//

int ledSkeleton::getLeftLegChannel() {
	return leftLeg.channel;
}

int ledSkeleton::getRightLegChannel() {
	return rightLeg.channel;
}

int ledSkeleton::getLeftArmChannel() {
	return leftArm.channel;
}

int ledSkeleton::getRightArmChannel() {
	return rightArm.channel;
}

int ledSkeleton::getSpineChannel() {
	return spine.channel;
}

int ledSkeleton::getRibChannel() {
	//return _ribChannel;
}

//

int ledSkeleton::getLeftLegSize() {
	return leftLeg.size;
}

int ledSkeleton::getRightLegSize() {
	return rightLeg.channel;
}

int ledSkeleton::getLeftArmSize() {
	return leftArm.size;
}

int ledSkeleton::getRightArmSize() {
	return rightArm.size;
}

int ledSkeleton::getSpineSize() {
	return spine.size;
}

int ledSkeleton::getRibSize() {
	//return _ribSize;
}

//

int ledSkeleton::getHue() {
	return _h;
}

int ledSkeleton::getSaturation() {
	return _s;
}

int ledSkeleton::getLightness() {
	return _l;
}

void ledSkeleton::setHue(unsigned int h) {
	_h = h;
}

void ledSkeleton::setSaturation(unsigned int s) {
	_s = s;
}

void ledSkeleton::setLightness(unsigned int l) {
	_l = l;
}

void ledSkeleton::setMaxLightness(unsigned int ml) {
	_maxLightness = ml;
}

int ledSkeleton::getMaxLightness() {
	return _maxLightness;
}

boolean ledSkeleton::getPulsing() {
	return _pulsing;
}

void ledSkeleton::setPulsing(boolean p) {
	_pulsing = p;
}

void ledSkeleton::setPulsingDirection(boolean p) {
	_pulsingDirection = p;
}

boolean ledSkeleton::getPulsingDirection() {
	return _pulsingDirection;
}

void ledSkeleton::pulseStart() {
	_pulsing = true;
	_pulsingDirection = true;
}

void ledSkeleton::pulseStop() {
	_pulsing = false;
	_pulsingDirection = true;
}

void ledSkeleton::pulsePart(_bodypart* p, unsigned int d) {

	delay(d);

	// check if we are pulsing
    if( p->pulsing ) {
      
		// rising pulse
		if(p->pulsingDirection ) {

        	if(p->l < p->maxLightness ) {
          
    			p->l += p->pulsingSpeed;

        	} else {
          
				// reached peak - reverse pulse direction
				p->pulsingDirection = false;
          
			}
        
		} else {
        
			// falling pulse
        	if(p->l > 0) {

          		p->l -= p->pulsingSpeed;
          
        	} else {
          
          		// pulsing finished
          		p->pulsingDirection = true;
          		p->pulsing = false;
          
        	}
        
      	}
      
    }
    
    setLEDPartColor( p->h, p->s, p->l, p->channel, p->size);

}

void ledSkeleton::pulseLEDCostume(unsigned int d) {

	delay( d );

	// check if we are pulsing
    if( getPulsing() ) {
      
		// rising pulse
		if(getPulsingDirection() ) {

        	if(getLightness() < getMaxLightness() ) {
          
    			// increment lightness
    			int l2 = getLightness();
    			l2++;
    			setLightness(l2);

        	} else {
          
				// reached peak - reverse pulse direction
				setPulsingDirection(false);
          
			}
        
		} else {
        
			// falling pulse
        	if(getLightness() > 0) {
          
          		int l2 = getLightness();
          		l2--;
          		setLightness(l2);
          
        	} else {
          
          		// pulsing finished
          		pulseStop();
          
        	}
        
      	}
      
    }

}

// The code taken from Paul Stoffregen
// All credit to him

// Convert HSL (Hue, Saturation, Lightness) to RGB (Red, Green, Blue)
//
//   hue:        0 to 359 - position on the color wheel, 0=red, 60=orange,
//                            120=yellow, 180=green, 240=blue, 300=violet
//
//   saturation: 0 to 100 - how bright or dull the color, 100=full, 0=gray
//
//   lightness:  0 to 100 - how light the color is, 100=white, 50=color, 0=black
//

// Note - LEDs white out pretty quickly so pushing the lightness too high
// might get you white when you think you should get a different color

int ledSkeleton::makeColor(unsigned int hue, unsigned int saturation, unsigned int lightness) {
	unsigned int red, green, blue;
	unsigned int var1, var2;

	if (hue > 359) hue = hue % 360;
	if (saturation > 100) saturation = 100;
	if (lightness > 100) lightness = 100;

	// algorithm from: http://www.easyrgb.com/index.php?X=MATH&H=19#text19
	if (saturation == 0) {
		red = green = blue = lightness * 255 / 100;
	} else {
		if (lightness < 50) {
			var2 = lightness * (100 + saturation);
		} else {
			var2 = ((lightness + saturation) * 100) - (saturation * lightness);
		}
		var1 = lightness * 200 - var2;
		red = h2rgb(var1, var2, (hue < 240) ? hue + 120 : hue - 240) * 255 / 600000;
		green = h2rgb(var1, var2, hue) * 255 / 600000;
		blue = h2rgb(var1, var2, (hue >= 120) ? hue - 120 : hue + 240) * 255 / 600000;
	}
	return (red << 16) | (green << 8) | blue;
}

unsigned int ledSkeleton::h2rgb(unsigned int v1, unsigned int v2, unsigned int hue) {
	if (hue < 60) return v1 * 60 + (v2 - v1) * hue;
	if (hue < 180) return v2 * 60;
	if (hue < 240) return v1 * 60 + (v2 - v1) * (240 - hue);
	return v1 * 60;
}

// alternate code:
// http://forum.pjrc.com/threads/16469-looking-for-ideas-on-generating-RGB-colors-from-accelerometer-gyroscope?p=37170&viewfull=1#post37170