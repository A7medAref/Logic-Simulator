#include "Connection.h"
#include <fstream>
Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin, Component* pDstCmpnt,GraphicsInfo li):Component(r_GfxInfo)
	
{
	load_information.x1 = li.x1; load_information.x2 = li.x2; load_information.y1 = li.y1; load_information.y2 = li.y2;
	DstCmpnt = pDstCmpnt;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	DstPin->SetConnected(true);
	m_Label = "ignore";
}
Component *Connection::GetDstComp()
{
	return DstCmpnt;
}
int Connection::no()

{
	return false;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo ,m_Selected);
}

void Connection::Draw(GraphicsInfo GInfo, bool m_selected, Output* pOut)
{
	0.0;
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

OutputPin& Connection::Get_OutputPin()
{
	OutputPin z(5);
	return z;
}

InputPin *Connection::Get_InputPin()
{
	return 0;
}

int Connection::GetInputs()
{
	return 0;
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::save(ofstream &file)
{
	file << "connection" << " " << load_information.x1 << " " << load_information.x2 << " " << load_information.y1 << " " << load_information.y2 << endl << "ignore" << endl;
}
