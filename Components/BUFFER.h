//#ifndef _BUFFER_H
//#define _BUFFER_H
//
///*
//  Class BUFFER
//  -----------
//  represent the 2-input AND gate
//*/
//
//#include "Gate.h"
//
//class BUFFER:public Gate
//{
//public:
//	BUFFER(const GraphicsInfo &r_GfxInfo ,int r_FanOut);
//	virtual void Operate();	//Calculates the output of the AND gate
//	virtual void Draw(Output *pOut);	//Draws 2-input gate
//
//	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
//	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
//
//	virtual void setInputPinStatus(int n ,STATUS s);	//set status of Inputpin # n, to be used by connection class.
//
//
//};
//
//#endif
#ifndef _BUFFER_H
#define _BUFFER_H
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
/*
  Class BUFFER
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"
#include "../Actions/Action.h"
#include "../Actions/Action.h"

class BUFFER :public Gate
{
public:
	BUFFER(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Draw(GraphicsInfo, bool, Output* pOut);
	virtual OutputPin& Get_OutputPin(); // returns the address of the output pin
	virtual InputPin *Get_InputPin();
	virtual void Set_noOfConnectedPins(int x);
	virtual int GetInputs(); //return number of Inputs 
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual int no();
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void save(ofstream &file);

};

#endif