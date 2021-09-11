#ifndef _COPY_H
#define _COPY_H

#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class Copy : public Action
{
private:
	int Sx, Sy; // Point to be clicked
public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};
#endif