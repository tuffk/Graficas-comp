#pragma once
#include "Robot.h"

class Interface
{
public:
	Interface();
	~Interface();

	void display();
	void reshape(int, int);
	void keyboard(unsigned char, int, int);

private:
	
	Robot *robot;
	void init();
};


