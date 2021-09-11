#include "XNOR2.h"
#include <fstream>
XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	Set_noOfConnectedPins(2);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].SetConnected(false);
	m_InputPins[1].SetConnected(false);
	m_Label = "ignore";
}


void XNOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int ones = 0;
	//caclulate the output status as the ORing of the two input pins
	for (int i = 0; i < 2; i++)
	{

		if (m_InputPins[i].getStatus() == HIGH)
		{
			ones++;
		}
	}
	if (ones % 2 == 0)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else {
		m_OutputPin.setStatus(LOW);
	}
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XNOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXNOR2(m_GfxInfo ,m_Selected);
}

void XNOR2::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawXNOR2(GInfo, m_Selected);
}

OutputPin& XNOR2::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *XNOR2::Get_InputPin()
{
	return m_InputPins;
}

int XNOR2::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int XNOR2::no()
{
	return m_ConnectedPins;
}

void XNOR2::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 2) ? x : m_ConnectedPins;
}

void XNOR2::save(ofstream &file)
{
	file << "XNOR2" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
