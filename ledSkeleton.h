#ifndef ledSkeleton_h
#define ledSkeleton_h

#include "Arduino.h"

class OctoWS2811;

class ledSkeleton {

  public:
  
  	typedef struct {
 		String name;
 		unsigned int channel;
 		unsigned int size;
 		unsigned int h;
 		unsigned int s;
 		unsigned int l;
 		unsigned int pulsingSpeed = 1;
 		unsigned int maxLightness = 10;
 		boolean pulsing = false;
 		boolean pulsingDirection = true;
 		long currentMillis;
		long previousMillis;
 	} _bodypart;
 	
 	_bodypart leftLeg;
 	_bodypart rightLeg;
 	
 	_bodypart leftArm;
 	_bodypart rightArm;
 	
 	_bodypart spine;
 	_bodypart rib;
 	
 	int totalSize;
  
    ledSkeleton(void);
    
	void setLedInstance( OctoWS2811* leds, int ledsPerStrip );
	
	void initLEDs();
	
	void setLEDColor(unsigned int h, unsigned int s, unsigned int l);
	
	void clearLEDColor();
	
	void setLEDPartColor(unsigned int h, unsigned int s, unsigned int l, int channel, int ledsToChange);
	void setLEDPixel(unsigned int h, unsigned int s, unsigned int l, unsigned int pos);
	
	void pulseLEDCostume(long d);
	
	void pulsePart(_bodypart* p, long d);
	
	void pulseStart();
	void pulseStop();
	
	void initLeftArm(unsigned int channel, unsigned int size);
	void initRightArm(unsigned int channel, unsigned int size);
	
	void initLeftLeg(unsigned int channel, unsigned int size);
	void initRightLeg(unsigned int channel, unsigned int size);
	
	void initSpine(unsigned int channel, unsigned int spineSize);
	void initRib(unsigned int channel, unsigned int ribSize);
	
	int getLeftArmChannel();
	int getRightArmChannel();
	
	int getLeftLegChannel();
	int getRightLegChannel();
	
	int getSpineChannel();
	int getRibChannel();
	
	int getLeftArmSize();
	int getRightArmSize();
	
	int getLeftLegSize();
	int getRightLegSize();
	
	int getSpineSize();
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
	
	OctoWS2811* ledInstance;
    
  private:
    
    int _ledsPerStrip;
    int _currentColor;
    
    int _h;
    int _s;
    int _l;
    
    int _pulseSpeed;
    
    int _maxLightness;
    
 	long _currentMillis;
	long _previousMillis;
		
    //int _lightnessStep;
    
	//int _leftArmChannel;
	//int _rightArmChannel;
	
	//int _leftLegChannel;
	//int _rightLegChannel;
	
	//int _spineChannel;
	//int _ribChannel;
	
	//int _leftArmSize;
	//int _rightArmSize;
	
	//int _leftLegSize;
	//int _rightLegSize;
	
	//int _spineSize;
	//int _ribSize;
	
	//int number_of_ribs;
    
    boolean _pulsing;
    boolean _pulsingDirection;
    
};

#endif
