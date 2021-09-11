#ifndef _AND2_H
#define _AND2_H

/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"

class AND2:public Gate
{
	bool input1, input2; 
public:
	virtual void Set_noOfConnectedPins(int x);
	virtual int Get_noOfConnectedPins() const;
	GraphicsInfo back();
	AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Draw(GraphicsInfo, bool, Output* pOut);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual OutputPin& Get_OutputPin();
	virtual InputPin *Get_InputPin();
	virtual int GetInputs();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual int no();
	virtual void set(bool i1,bool i2);
	void save(ofstream &file);
};

#endif