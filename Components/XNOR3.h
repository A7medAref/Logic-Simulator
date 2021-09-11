#ifndef _XNOR3_H
#define _XNOR3_H

/*
  Class XNOR3
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"

class XNOR3 :public Gate
{
public:
	XNOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	void Set_noOfConnectedPins(int x);
	virtual void Operate();	//Calculates the output of the AND gate
	int no();
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Draw(GraphicsInfo, bool, Output* pOut);
	virtual OutputPin& Get_OutputPin();
	virtual InputPin *Get_InputPin();
	virtual int GetInputs();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void save(ofstream &file);

};

#endif