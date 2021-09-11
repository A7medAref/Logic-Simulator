#include "NOR3.h"
#include <fstream>
NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
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


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	for (int i = 0; i < 3; i++)
	{

		if (m_InputPins[i].getStatus() == HIGH)
		{
			m_OutputPin.setStatus(LOW);
			break;
		}
		else {
			m_OutputPin.setStatus(HIGH);
		}
	}
	//Add you code here
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo ,m_Selected);
}

void NOR3::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawNOR3(GInfo, m_Selected);
}

OutputPin& NOR3::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *NOR3::Get_InputPin()
{
	return m_InputPins;
}

int NOR3::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int NOR3::no()
{
	return m_ConnectedPins;
}

void NOR3::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 3) ? x : m_ConnectedPins;
}

void NOR3::save(ofstream &file)
{
	file << "NOR3" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
