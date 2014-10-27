//
// Code that analyses music playing and sends that vi
// serial so it can control the LED Skeleton.
//
// Code is as-is. Lot's to fix up but it works.
//

import ddf.minim.*;
import ddf.minim.analysis.*;

import processing.serial.*;

Minim minim;
AudioPlayer imperial;

BeatDetect imperial_beat;

BeatListener imperial_bl;

Serial myPort;  // Create object from Serial class

int val;

float kickSize, snareSize, hatSize;

int beatSensitivity = 40; // 10  -> ??

float decay = 0.96;

void setup() {
   
  size(512, 200, P3D);
  
  // Set your serial
  String portName = "/dev/tty.usbmodem505471";
  myPort = new Serial(this, portName, 9600); 
  
  minim = new Minim(this);
  
  imperial = minim.loadFile("full_horror_mix.wav", 1024);
  //skrillex = minim.loadFile("skrillex.wav", 1024);
  //thriller = minim.loadFile("thriller.mp3", 1024);
  
  imperial_beat = new BeatDetect(imperial.bufferSize(), imperial.sampleRate());
  //skrillex_beat = new BeatDetect(skrillex.bufferSize(), skrillex.sampleRate());
  //thriller_beat = new BeatDetect(thriller.bufferSize(), thriller.sampleRate());

  imperial_beat.setSensitivity(beatSensitivity); 
  //skrillex_beat.setSensitivity(beatSensitivity);
  //thriller_beat.setSensitivity(beatSensitivity);  
  
  kickSize = snareSize = hatSize = 32;
  // make a new beat listener, so that we won't miss any buffers for the analysis
  
  imperial_bl = new BeatListener(imperial_beat, imperial);
  //skrillex_bl = new BeatListener(skrillex_beat, skrillex);
  //thriller_bl = new BeatListener(thriller_beat, thriller);
  
  textFont(createFont("Helvetica", 16));
  textAlign(CENTER);
}

void draw() {
  
  background(0);
  fill(255);
  
  if( !imperial.isPlaying() ) {
  
   if ( myPort.available() > 0) {  // If data is available,
    
    //val = myPort.read();         // read it and store it in val
    
    //println(val);
    
    // 49 == 1 from teensy
    //if(val == 49) {
       playSong();
    //}
    
  }
  
  playSong();
  
  } else {
  
  if ( imperial_beat.isKick() ) kickSize = 15;
  if ( imperial_beat.isSnare() ) snareSize = 16;
  if ( imperial_beat.isHat() ) hatSize = 12;
  
  textSize(kickSize);
  text("KICK", width/4, height/2);
  textSize(snareSize);
  text("SNARE", width/2, height/2);
  textSize(hatSize);
  text("HAT", 3*width/4, height/2);
  
  //kickSize = constrain(kickSize * decay, 0, 12);
  //snareSize = constrain(snareSize * decay, 0, 19);
  //hatSize = constrain(hatSize * decay, 0, 12);

  // this code is awful - to-fix
  myPort.write( int (kickSize) );
  myPort.write( int (snareSize) );
  myPort.write( int (hatSize) );
  
  //println("kickSize - " + int (kickSize) + " snareSize - " + int (snareSize) + " hatSize - " + int (hatSize));
  
  kickSize = kickSize * decay;
  snareSize = snareSize * decay;
  hatSize = hatSize * decay;
  
  }
  
}

void playSong() {
  
  myPort.write("0");
  
  //delay(1000);
  
  imperial.play();
  
}
