#ifndef _LOAD_H
#define _LOAD_H

#include<fstream>
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "Action.h"
class Load: public Action
{
	ifstream read;
public:
	Load(ApplicationManager *pApp);
	virtual ~Load(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif