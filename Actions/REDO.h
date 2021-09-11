#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class RedoAction: public Action
{
public:
	/* Constructor */
	RedoAction(ApplicationManager *pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual  bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~RedoAction();
};


