//CS479 UIC LAB 4 - foot sensor
//Authors: Orlando, ALeks
import processing.serial.*;
import org.gicentre.utils.stat.*;

Serial myPort;
int mm = 0;
int mf = 0;
int lf = 0;
int heel = 0;

void setup(){
  String portName = Serial.list()[2]; 
  myPort = new Serial(this, Serial.list()[2], 115200);
  myPort.bufferUntil('\n');

}

void draw(){

}

void serialEvent(Serial myPort) {
  String data = myPort.readStringUntil('\n');
  data = trim(data);
  println("DATA:" + data);
  
  String[] values = data.split(",");
  
  println("MM: " + values[0]);
  println("MF: " + values[1]);
  println("LF: " + values[2]);
  println("HEEL: " + values[3]);
  
  mm = int(values[0]);
  mf = int(values[1]);
  lf = int(values[2]);
  heel = int(values[3]);
  
  


}
