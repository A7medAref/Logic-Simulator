#pragma once

#ifndef _ADD_BUFFER_GATE_H
#define _ADD_BUFFER_GATE_H

#include "Action.h"
#include"../Components/BUFFER.h"


class AddBUFFERgate: public Action
{
private:

	//Parameters for rectangular area to be occupied by the gate
	int Cx ,Cy;	//Center point of the gate
	int x1 ,y1 ,x2 ,y2;	//Two corners of the rectangluar area
	bool loaded; // To Check whether the component is loaded
public:
	AddBUFFERgate(ApplicationManager *pApp ,bool l ,int cx ,int cy);
	AddBUFFERgate(ApplicationManager *pApp);
	virtual ~AddBUFFERgate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute(); // The return value is used in Undo Action

	virtual void Undo();
	virtual void Redo();


};

#endif