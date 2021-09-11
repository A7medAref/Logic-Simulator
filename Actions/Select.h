#ifndef _SELECT_H
#define _SELECT_H

#include "..\Actions\Action.h"
#include "..\Components\Component.h"
#include <vector>
class Select : public Action
{
private:
	vector <Component*> SelectedCompList;
	int Sx, Sy; //Clicked point in Selection
public:
	Select(ApplicationManager* pApp);
	virtual ~Select(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};


#endif