#ifndef _SAVE_H
#define _SAVE_H

#include<fstream>
#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "Action.h"
class Save: public Action
{
	ofstream write;
public:
	Save(ApplicationManager *pApp);
	virtual ~Save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
