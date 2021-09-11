#include "NOT.h"
#include <fstream>
NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	Set_noOfConnectedPins(4);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].SetConnected(false);
	m_Inputs = 1;
	m_Label = "ignore";
}


void NOT::Operate()
{
	//caclulate the output status as the ORing of the two input pins
	if (m_InputPins[0].getStatus() == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else {
		m_OutputPin.setStatus(LOW);
	}
	//Add you code here
}


// Function Draw
// Draws 2-input OR gate
void NOT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOT(m_GfxInfo,m_Selected);
}

void NOT::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawNOT(GInfo, m_Selected);
}

OutputPin& NOT::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *NOT::Get_InputPin()
{
	return m_InputPins;
}

int NOT::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int NOT::no()
{
	return m_ConnectedPins;
}

void NOT::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 4) ? x : m_ConnectedPins;
}

void NOT::save(ofstream &file)
{
	file << "NOT" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
