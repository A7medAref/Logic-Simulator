#include "XOR3.h"
#include <fstream>
XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	Set_noOfConnectedPins(3);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPins[0].SetConnected(false);
	m_InputPins[1].SetConnected(false);
	m_InputPins[2].SetConnected(false);
	m_Label = "ignore";
}
int XOR3::no()
{
	return m_ConnectedPins;

}
void XOR3::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 3) ? x : m_ConnectedPins;
}
void XOR3::Operate()
{
	int ones = 0;
	//caclulate the output status as the ORing of the two input pins
	for (int i = 0; i < 3; i++)
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
// Draws 2-input OR gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, m_Selected);
}

void XOR3::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawXOR3(GInfo, m_Selected);
}

OutputPin &XOR3::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *XOR3::Get_InputPin()
{
	return m_InputPins;
}

int XOR3::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR3::save(ofstream &file)
{
	file << "XOR3" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
