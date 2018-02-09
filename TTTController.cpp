#include "TTTController.h"

TTTController::TTTController(TTTModel* pModelIn,TTT_AI* pAIIn):pModel(pModelIn), pAI(pAIIn),AIPlayFlag(false)
{
	cout << "Game start... " << endl;
}

void TTTController::GetMove(tCell CellType)
{
	int x=-1,y=-1;
	
	if (CellType == _x) cout << "Cross move now... " << endl;
	else cout << "Zero move now... " << endl;
	cout << "Player enter move (x y):";
	
	if (AIPlayFlag){
		if (CellType != _x){
			cin >> x >> y;
		}
		else{
			pAI->GetAIMove(x,y);
			cout << ++x <<" "<< ++y << endl;
		}
	}
	else{
		cin >> x >> y;
	}

	try{
		pModel->Set(CellType,x-1,y-1);
	}
	catch (TTTModelExeption e){
		
		tModelExeption eType = e.GetType();

		switch (eType){
			case Default: cout << "Unknown error" << endl; break;
			case EmptySet: cout << "EmptySet error" << endl; break;
			case BoardOvf: cout << "BoardOvf error" << endl; break;
			case AlreadyFill: cout << "AlreadyFill error" << endl; break;
			default: cout << "Unknown error"; break;
		}
		
		GetMove(CellType);
	}
}

int TTTController::Process()
{
	tGameState GameState;
	static tCell CellType = _0;

	GetMove(CellType);

	
	GameState = pModel->CheckState();	

	switch (GameState){
		case _0_win: cout << "Zero win" << endl; break;
		case _x_win: cout << "Cross win" << endl; break;
		case _draw: cout << "Draw" << endl; break;
		default: cout << "Next move..."<< endl; break;
	}

	CellType = (tCell) ((int)CellType ^ 1); 

	if ( GameState == _next ) return 1;
	else return 0;
}

void TTTController::AI_On()
{
	AIPlayFlag = true;
}

void TTTController::AI_Off()
{
	AIPlayFlag = false;
}


TTTController::~TTTController(void)
{
}

