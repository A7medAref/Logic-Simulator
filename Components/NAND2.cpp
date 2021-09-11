#include "NAND2.h"
#include <fstream>
NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
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
void NAND2::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 2) ? x : m_ConnectedPins;
}

int NAND2::no()
{
	return m_ConnectedPins;

}

void NAND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	for (int i = 0; i < 2; i++)
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
// Draws 2-input AND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo, m_Selected);
}

void NAND2::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawNAND2(GInfo, m_Selected);
}

OutputPin& NAND2::Get_OutputPin() 
{
	return m_OutputPin;
}

InputPin *NAND2::Get_InputPin()
{
	return m_InputPins;
}

int NAND2::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NAND2::save(ofstream &file)
{
	file << "NAND2" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
