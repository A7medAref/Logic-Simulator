#include "SWITCH.h"
#include <fstream>
SWT::SWT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_Label = "ignore";
}


void SWT::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	if (this->GetSelected() == true)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else
		m_OutputPin.setStatus(LOW);
	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void SWT::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCH(m_GfxInfo ,m_Selected);
}
void SWT::Draw(GraphicsInfo GInfo ,bool m_selected ,Output *pOut)
{
	pOut->DrawSWITCH(GInfo ,m_Selected);
}
OutputPin& SWT::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *SWT::Get_InputPin()
{
	return 0;
}

int SWT::GetInputs()
{
	return 0;
}

//returns status of outputpin
int SWT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWT::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void SWT::setInputPinStatus(int n ,STATUS s)
{
	0.0;
}

void SWT::save(ofstream &file)
{
	file << "Switch" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
