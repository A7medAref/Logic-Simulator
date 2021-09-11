#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"

class UndoAction: public Action
{
public:
	/* Constructor */
	UndoAction(ApplicationManager *pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual  bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~UndoAction();
};


