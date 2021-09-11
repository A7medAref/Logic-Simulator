#ifndef _LED_H
#define _LED_H

#include "Action.h"
#include "../LED.h"

class AddLED: public Action
{

private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx ,Cy;	//Center point of the gate
	int x1 ,y1 ,x2 ,y2;//Two corners of the rectangluar area
	bool loaded; // To Check whether the component is loaded
public:
	AddLED(ApplicationManager *pApp);
	AddLED(ApplicationManager *pApp ,bool l ,int cx ,int cy);
	virtual ~AddLED(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif