#ifndef _Edit_H
#define _Edit_H
#include "Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class Edit: public Action
{
private:
	int Sx ,Sy; // Point to be clicked
public:
	Edit(ApplicationManager *pApp);
	virtual ~Edit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
