#include "OctoWS2811.h"
#include "Arduino.h"
#include "ledSkeleton.h"

ledSkeleton::ledSkeleton(void) {

}

void ledSkeleton::setLedInstance( OctoWS2811 *leds, int ledsPerStrip, int maxLightness ) {

    ledInstance = leds;
    _ledsPerStrip = ledsPerStrip;
    _pulsing = false;
    _pulsingDirection = true;
    _currentColor = 0;
    _currentLightness = 0;
    _lightnessStep = 1;
    _maxLightness = maxLightness;
    
}

void ledSkeleton::setLEDColor(int color) {

	_currentColor = color;

	// iterate over ALL of the pixels and set them to one color
  	for (int i=0; i < ledInstance->numPixels(); i++) {
    	ledInstance->setPixel(i, _currentColor);
  	}
  	
  	ledInstance->show();

}

void ledSkeleton::clearLEDColor() {

	_currentColor = 0x000000;

	// iterate over ALL of the pixels and set them to one color
  	for (int i=0; i < ledInstance->numPixels(); i++) {
    	ledInstance->setPixel(i, _currentColor);
  	}
  	
  	ledInstance->show();

}

void ledSkeleton::setLEDPartColor(int color, int channel, int ledsToChange) {

	_currentColor = color;

	// iterate over just the pixels for that body part and set them to one color
	int pos = _ledsPerStrip * (channel-1);
	int end = pos + ledsToChange;
	
	//Serial.println(end);
	
  	for (pos; pos < end; pos++) {
    	ledInstance->setPixel(pos, _currentColor);
  	}
  	
  	ledInstance->show();

}

void ledSkeleton::initLeftArm(int channel) {
	_leftArmChannel = channel;
}

void ledSkeleton::initRightArm(int channel) {
	_rightArmChannel = channel;
}

void ledSkeleton::initLeftLeg(int channel) {
	_leftLegChannel = channel;
}

void ledSkeleton::initRightLeg(int channel) {
	_rightLegChannel = channel;
}

void ledSkeleton::initBody(int channel) {
	_bodyChannel = channel;
}

int ledSkeleton::returnLeftLegChannel() {
	return _leftLegChannel;
}

int ledSkeleton::returnCurrentLightness() {
	return _currentLightness;
}

void ledSkeleton::setCurrentLightness(int l) {
	_currentLightness = l;
}

boolean ledSkeleton::returnPulsing() {
	return _pulsing;
}

void ledSkeleton::setPulsing(boolean p) {
	_pulsing = p;
}

void ledSkeleton::setPulsingDirection(boolean p) {
	_pulsingDirection = p;
}

boolean ledSkeleton::returnPulsingDirection() {
	return _pulsingDirection;
}

void ledSkeleton::startPulse() {
	_pulsing = true;
	_pulsingDirection = true;
}

void ledSkeleton::stopPulse() {
	_pulsing = false;
	_pulsingDirection = true;
}

void ledSkeleton::pulse() {

}