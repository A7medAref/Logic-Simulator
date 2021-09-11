#ifndef _SWT_H
#define _SWT_H

/*
  Class SWT
  -----------
  represent the SWT
*/

#include "Components/Gate.h"

class SWT :public Gate
{
public:
	SWT (const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Draw(GraphicsInfo ,bool ,Output *pOut);
	virtual OutputPin& Get_OutputPin();
	virtual InputPin *Get_InputPin();
	virtual int GetInputs();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void save(ofstream &file);

};




#endif
