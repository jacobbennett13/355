/*
    uCam III.h
	Designed for the UCAMIII by 4D systems
	Based on code written for the UCAMII

*/

#ifndef UCAMIII_h
#define UCAMIII_h
#define UCAMIII_BUF_SIZE 64



#include <Arduino.h>
#include <SoftwareSerial.h>

class UCAMIII {

public:
    UCAMIII();

    boolean init();
    boolean takePicture();
    void setDebug(SoftwareSerial *debugSerial);
    int numberOfPackages();
    SoftwareSerial *debugSerial;
    unsigned long imageSize;

    int getData();    
    byte imgBuffer[UCAMIII_BUF_SIZE];    // this is also set in _PACK_SIZE

    
private:
    unsigned long image_pos;
    int package_no;
    int send_initial();
    int set_package_size();
    int do_snapshot();
    int get_picture();
    int send_ack();
    int wait_for_sync();
    int attempt_sync();
    boolean wait_for_bytes(byte command[6]);
};

#endif
