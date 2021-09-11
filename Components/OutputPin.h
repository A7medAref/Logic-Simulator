#ifndef _OUTPUTPIN_H
#define _OUTPUTPIN_H

/*class OutputPin 
  ---------------
 An output pin obtains its value as a result of calculating the outputs of
 a component. The output pin propagates its value immediately to the associated connections
*/
#include "Pin.h"
class Connection;	//Forward class declartion


class OutputPin: public Pin	//inherited from class Pin
{
private:
	//Array of connections (poniters) to be connected to that OutputPin
	//For simplicity, we consider it a constant length
	Connection* m_Connections[MAX_CONNS];	
	int m_FanOut;	//Maximum No. of connections connected to that output pin (depends on the component)
	int m_Conn;		//Actual No. of connections connected to that output pin
	int ConnectionIndices[MAX_CONNS]; //Array of connection indices in CompList
public:
	OutputPin(int r_FanOut);	
	bool ConnectTo(Connection *r_Conn, int I);	//connect to a new connection
	Connection** GetConnections();  //return array of connections out of this pin
	int GetConnCount(); //returns number of connections out of this pin
	int* GetConnIndices(); //returns indices of the components in CompList
};

#endif