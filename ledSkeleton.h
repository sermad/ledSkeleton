#ifndef ledSkeleton_h
#define ledSkeleton_h

#include "Arduino.h"

class OctoWS2811;

class ledSkeleton {

  public:
  
    ledSkeleton(void);
    
	void setLedInstance( OctoWS2811* leds, int ledsPerStrip, int maxLightness );
	
	void setLEDColor(int color);
	
	void clearLEDColor();
	
	void setLEDPartColor(int color, int channel, int ledsToChange);
	
	void pulse();
	
	void startPulse();
	void stopPulse();
	
	void initLeftArm(int channel);
	void initRightArm(int channel);
	
	void initLeftLeg(int channel);
	void initRightLeg(int channel);
	
	void initBody(int channel);
	
	void setPulsing(boolean p);
	
	void setCurrentLightness(int l);
	void setPulsingDirection(boolean p);
	
	int returnCurrentLightness();
	
	int returnLeftLegChannel();
	
	boolean returnPulsing();
	boolean returnPulsingDirection();
    
  private:
    
    OctoWS2811* ledInstance;
    
    int _ledsPerStrip;
    int _currentColor;
    int _pulseStep;
    int _currentLightness;
    int _maxLightness;
    int _lightnessStep;
    
	int _leftArmChannel;
	int _rightArmChannel;
	
	int _leftLegChannel;
	int _rightLegChannel;
	
	int _bodyChannel;
    
    boolean _pulsing;
    boolean _pulsingDirection;
    
};

#endif
