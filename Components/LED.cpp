#include "../LED.h"
#include <fstream>
LED::LED(const GraphicsInfo &r_GfxInfo ,int r_FanOut):Gate(2 ,0)
{
	Set_noOfConnectedPins(2);
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_Label = "ignore";
}


void LED::Operate()
{
	if (m_InputPins[0].getStatus() == HIGH)
	{
		this->SelectComp();
	}
}
void LED::Set_noOfConnectedPins(int x)
{
	m_ConnectedPins = (x <= 2) ? x : m_ConnectedPins;
}

// Function Draw
// Draws 2-input AND gate
void LED::Draw(Output *pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(m_GfxInfo, m_Selected);
}

void LED::Draw(GraphicsInfo GInfo ,bool m_selected ,Output *pOut)
{
	pOut->DrawLED(GInfo ,m_Selected);
}

OutputPin &LED::Get_OutputPin()
{
	OutputPin z(1);
	return z;
}

InputPin *LED::Get_InputPin()
{
	return m_InputPins;
}

int LED::GetInputs()
{
	return 0;
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

int LED::no()
{
	return m_ConnectedPins;
}



//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n ,STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void LED::save(ofstream &file)
{
	file << "LED" << " " << ( m_GfxInfo.x1 + m_GfxInfo.x2 ) / 2 << " " << ( m_GfxInfo.y1 + m_GfxInfo.y2 ) / 2 << endl << m_Label << endl;
}
