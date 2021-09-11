#ifndef _ADD_XOR_GATE3_H
#define _ADD_XOR_GATE3_H

#include "Action.h"
#include "../Components/XOR3.h"

class AddXORgate3: public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx ,Cy;	//Center point of the gate
	int x1 ,y1 ,x2 ,y2;	//Two corners of the rectangluar area
	bool loaded; // To Check whether the component is loaded
public:
	AddXORgate3(ApplicationManager *pApp);
	virtual ~AddXORgate3(void);

	AddXORgate3(ApplicationManager *pApp ,bool l ,int cx ,int cy);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
