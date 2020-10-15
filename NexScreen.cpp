/**
* @file NexScreen.cpp
*
* The definition of class NexScreen.
*
* @author kosza (email:<koszab@gmail.com>)
* @date 2016/9/16
*
* @copyright
*/

#include "NexScreen.h" 

NexScreen::NexScreen()
	:NexObject(0, 0, "screen")
{
	this->__cb_event = NULL;
}


void NexScreen::attachCallback(byte event, NexScreenEventCb callback){
    this->__cb_event = callback;    
}

bool NexScreen::setBrightness(byte buffer) {
	String cmd;
	buffer = min((int)buffer, 100);	
	cmd += "dim=";
	cmd += buffer;
	sendCommand(cmd.c_str());
	return recvRetCommandFinished();
}

bool NexScreen::Sleep() {
	String cmd;
	cmd += "sleep=1";
	sendCommand(cmd.c_str());
	return recvRetCommandFinished();
}

bool NexScreen::Wakeup() {
	String cmd;
	cmd += "sleep=0";
	sendCommand(cmd.c_str());
	return recvRetCommandFinished();
}

bool NexScreen::setAutoWakeup(byte buffer) {
	String cmd;
	cmd += "thup=";
	cmd += buffer;
	sendCommand(cmd.c_str());
	return recvRetCommandFinished();
}

bool NexScreen::setScreenTouchTimeout(int buffer) {
	String cmd;
	buffer = min(buffer, 65535);
	if (buffer == 1 || buffer == 2) return false;
	cmd += "thsp=";
	cmd += buffer;
	sendCommand(cmd.c_str());
	return recvRetCommandFinished();
}

void NexScreen::eventCallback(void)
{
    /*if (__cb_event)
    {
        __cb_event();
    }*/
}

