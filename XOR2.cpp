#include "XOR2.h"
#include <fstream>
XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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

void XOR2::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 2) ? x : m_ConnectedPins;
}

int XOR2::no()
{
	return m_ConnectedPins;

}
void XOR2::Operate()
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
		m_OutputPin.setStatus(LOW);
	}
	else {
		m_OutputPin.setStatus(HIGH);
	}
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo ,m_Selected);
}

void XOR2::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawXOR2(GInfo, m_Selected);
}

OutputPin& XOR2::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *XOR2::Get_InputPin()
{
	return m_InputPins;
}

int XOR2::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR2::save(ofstream &file)
{
	file << "XOR2" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
