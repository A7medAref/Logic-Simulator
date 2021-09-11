#ifndef _ADD_XNOR_GATE_H
#define _ADD_XNOR_GATE_H

#include "Actions/Action.h"
#include "XNOR2.h"

class AddXNORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool loaded; // To Check whether the component is loaded
public:
	AddXNORgate2(ApplicationManager* pApp);
	AddXNORgate2(ApplicationManager *pApp ,bool l ,int cx ,int cy);
	virtual ~AddXNORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif

