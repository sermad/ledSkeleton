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
	
	void setLEDPartColor(unsigned int h, unsigned int s, unsigned int l, int channel, int ledsToChange);
	
	void pulseLEDs();
	
	void pulseStart();
	void pulseStop();
	
	void initLeftArm(unsigned int channel, unsigned int size);
	void initRightArm(unsigned int channel, unsigned int size);
	
	void initLeftLeg(unsigned int channel, unsigned int size);
	void initRightLeg(unsigned int channel, unsigned int size);
	
	void initBody(unsigned int channel, unsigned int backsize, unsigned int ribsize);
	
	int getLeftArmChannel();
	int getRightArmChannel();
	
	int getLeftLegChannel();
	int getRightLegChannel();
	
	int getBodyChannel();
	
	int getLeftArmSize();
	int getRightArmSize();
	
	int getLeftLegSize();
	int getRightLegSize();
	
	int getBackSize();
	int getRibSize();
	
	void setPulsing(boolean p);
	void setPulsingDirection(boolean p);
	
	void setLEDEq(unsigned int h, unsigned int s, unsigned int l, unsigned int eqSize);
	
	void setHue(unsigned int h);
	void setSaturation(unsigned int s);
	void setLightness(unsigned int l);
	
	int getHue();
	int getSaturation();
	int getLightness();
	
	void setMaxLightness(unsigned int ml);
	int getMaxLightness();
	
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
	
	int _leftArmSize;
	int _rightArmSize;
	
	int _leftLegSize;
	int _rightLegSize;
	
	int _backSize;
	int _ribSize;
    
    
    boolean _pulsing;
    boolean _pulsingDirection;
    
};

#endif
