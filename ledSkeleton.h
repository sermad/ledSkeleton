#ifndef ledSkeleton_h
#define ledSkeleton_h

#include "Arduino.h"

class OctoWS2811;

class ledSkeleton {

  public:
  
    ledSkeleton(void);
    
	void setLedInstance( OctoWS2811* leds, int ledsPerStrip );
	
	void initLEDs();
	
	void setLEDColor(unsigned int h, unsigned int s, unsigned int l);
	
	void clearLEDColor();
	
	void setLEDPartColor(int color, int channel, int ledsToChange);
	
	void pulseLEDs();
	
	void pulseStart();
	void pulseStop();
	
	void initLeftArm(unsigned int channel);
	void initRightArm(unsigned int channel);
	
	void initLeftLeg(unsigned int channel);
	void initRightLeg(unsigned int channel);
	
	void initBody(unsigned int channel);
	
	void setPulsing(boolean p);
	void setPulsingDirection(boolean p);
	
	void setLightness(unsigned int l);
	
	int getHue();
	int getSaturation();
	int getLightness();
	
	void setMaxLightness(unsigned int ml);
	int getMaxLightness();
	
	//int returnLeftLegChannel();
	
	boolean getPulsing();
	boolean getPulsingDirection();
	
	// color functions
	int makeColor(unsigned int hue, unsigned int saturation, unsigned int lightness);
	unsigned int h2rgb(unsigned int v1, unsigned int v2, unsigned int hue);
    
  private:
    
    OctoWS2811* ledInstance;
    
    int _ledsPerStrip;
    int _currentColor;
    
    int _h;
    int _s;
    int _l;
    
    int _pulseSpeed;
    
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
