#ifndef _DELETE_H
#define _DELETE_H

#include "Action.h"
#include "..\Components\Component.h"

class Delete : public Action
{
private:
	int Sx, Sy; // Point to be clicked
public:
	Delete(ApplicationManager* pApp);
	virtual ~Delete(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
