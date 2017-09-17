#ifndef SERIALCLASS_H
#define SERIALCLASS_H

#define ARDUINO_WAIT_TIME 2000

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Serial
{
private:

	HANDLE hSerial;

	bool connected;

	COMSTAT status;

	DWORD errors;

public:
	
	Serial(const char *portName);
	
	~Serial();

	int ReadData(char *buffer, unsigned int nbChar);
	
	bool WriteData(const char *buffer, unsigned int nbChar);
	
	bool IsConnected();

	int inputStatus(Serial arduino);

};

#endif 