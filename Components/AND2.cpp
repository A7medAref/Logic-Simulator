#include "AND2.h"
#include <fstream>
void AND2::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 2) ? x : m_ConnectedPins;
}

int AND2::Get_noOfConnectedPins() const
{
	return m_ConnectedPins;
}

GraphicsInfo AND2::back()
{
	return m_GfxInfo;
}



AND2::AND2(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
 , input1 (0), input2(0)
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


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	for (int i = 0; i < 2; i++)
	{

		if (m_InputPins[i].getStatus() == LOW)
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
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo, m_Selected);
}

void AND2::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	pOut->DrawAND2(GInfo, m_Selected);
}

//returns status of outputpin
int AND2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

OutputPin& AND2::Get_OutputPin()
{
	return  m_OutputPin;
}

InputPin *AND2::Get_InputPin()
{
	return m_InputPins;
}

int AND2::GetInputs()
{
	return m_Inputs;
}

//Set status of an input pin to HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

int AND2::no()
{
	return m_ConnectedPins;

}

void AND2::set(bool i1, bool i2)
{
	input1 = i1;
	input2 = i2;
}

void AND2::save(ofstream &file)
{
	file << "AND2" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
