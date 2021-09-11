#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H
#include<stack>
#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include <vector>
#include <fstream>
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* Copied_Component;
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	int SelectedComponent;
	bool Simulated;

	stack<Action *> UndoStack;
	stack<Action *> RedoStack;
	stack<Component *> UndoStackc;
	struct lP
	{
		int cx ,cy;
	};



public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(GraphicsInfo GInfo,Component* pComp);
	Component* getCopied() const;
	int GetCompCount();
	void SelectComponent(int Sx, int Sy);
	void SetCopiedComp();            // Makes a copy of the selected component
	void DeleteComp();               // Deletes Selected Component
	void CutComp();					// Cuts Selected Component
	void PasteComp(int Sx, int Sy);  //Paste Component function takes a clicked position and pastes there
	void EditComponent();
	void Msave(ofstream &h);
	void Mload(ifstream &h);
	void SimulateComponents();
	void ChangeSimulation();
	bool GetSimulated();
	void UnSelect();
	bool CanDraw(int Sx ,int Sy);
	//destructor
	//destructor
	~ApplicationManager();
	bool ValidConnenction(GraphicsInfo* g, Component*&p1, Component*& p2);
	void Undo();
	void Redo();
	Component *getlastcomp();
};

#endif