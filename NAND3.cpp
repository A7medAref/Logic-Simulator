#include "NAND3.h"
#include <fstream>
NAND3::NAND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
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


void NAND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	for (int i = 0; i < 3; i++)
	{

		if (m_InputPins[i].getStatus() == LOW)
		{
			m_OutputPin.setStatus(HIGH);
			break;
		}
		else {
			m_OutputPin.setStatus(LOW);
		}
	}
	//Add you code here
}


// Function Draw
// Draws 3-input NAND gate
void NAND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND3(m_GfxInfo ,m_Selected);
}

void NAND3::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawNAND3(GInfo, m_Selected);
}

OutputPin& NAND3::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *NAND3::Get_InputPin()
{
	return m_InputPins;
}

int NAND3::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int NAND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

int NAND3::no()
{
	return m_ConnectedPins;
}

void NAND3::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 3) ? x : m_ConnectedPins;
}

void NAND3::save(ofstream &file)
{
	file << "NAND3" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
