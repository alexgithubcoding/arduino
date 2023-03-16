
#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
OpenLog myLog; //Create instance


void setup() {
  Wire.begin(); 
  myLog.begin(); //Open connection to OpenLog (no pun intended)

  Serial.begin(9600); //9600bps is used for debug statements

  String myFile = "Alex.txt";

  //Get size of file
  long sizeOfFile = myLog.size(myFile);

  if (sizeOfFile == -1) {
    myLog.create(myFile);
    //Record something to the default log
    myLog.println("This goes to the log file");
    myLog.syncFile();
  } else {

  }
  myLog.append(myFile);
  myLog.println("This also goes to the log file");

  myLog.syncFile();
}

void loop() {

}
