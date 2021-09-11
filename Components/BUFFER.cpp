#include "BUFFER.h"

BUFFER::BUFFER(const GraphicsInfo &r_GfxInfo ,int r_FanOut):Gate(1 ,r_FanOut)
{
	Set_noOfConnectedPins(4);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_Inputs = 1;
	m_Label = "ignore";
}


void BUFFER::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
		m_OutputPin.setStatus(m_InputPins[0].getStatus());
	
	
}

void BUFFER::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuff(m_GfxInfo,m_Selected);
}
void BUFFER::Draw(GraphicsInfo GInfo ,bool m_selected ,Output *pOut)
{
	pOut->DrawBuff(GInfo ,m_Selected);
}

OutputPin &BUFFER::Get_OutputPin()
{
	return m_OutputPin;
}

InputPin *BUFFER::Get_InputPin()
{
	return m_InputPins;
}

void BUFFER::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 4) ? x : m_ConnectedPins;
}

int BUFFER::GetInputs()
{
	return m_Inputs;
}

//returns status of outputpin
int BUFFER::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFFER::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

int BUFFER::no()
{
	return m_ConnectedPins;
}

//Set status of an input pin ot HIGH or LOW
void BUFFER::setInputPinStatus(int n ,STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void BUFFER::save(ofstream &file)
{
	file << "BUFFER" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}

