#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "InputPin.h"
#include "OutputPin.h"
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
protected:
	string m_Label;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	Center center;
	bool m_Selected;		// Whether this component is selected or not
	bool m_Deleted;			// Deleted or Not
	int m_ConnectedPins;
public:
	
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void Draw(GraphicsInfo, bool ,Output* pOut) = 0;	//for each component to Draw itself
	void SetDeleted(bool);  //Set whether the component is deleted or not
	void SetSelected(bool);  // Set whether the component is selected or not
	void SelectComp();    // Selects a component
	bool GetSelected() const; // Returns whether the component is selected or not
	bool GetDeleted() const;  // Returns whether the component is deleted or not

	virtual void save(ofstream &file)=0;  //Saves a component
	void SetLabel(const string &label); //Sets label of component
	string GetLabel();
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual int GetInputs() = 0;  // returns number of inputs
	void SetCenter(int Cx, int Cy);
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	GraphicsInfo GetGraphicsInfo() const;
	Center GetCenter() const;
	virtual void Set_noOfConnectedPins(int x);  //Sets the number of connected pins
	virtual int Get_noOfConnectedPins() const;  //Returns  the number of connected pins
	virtual int no()=0;//return the number of aviable connection
	virtual OutputPin& Get_OutputPin() = 0;  //Returns output Pin
	virtual InputPin* Get_InputPin() = 0; //Returns array of input pins

	virtual void set(bool i1, bool i2);
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
	
};

#endif
