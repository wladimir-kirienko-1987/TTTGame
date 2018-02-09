#include "TTT_AI.h"

TTT_AI::TTT_AI(TTTModel* pModelIn):pModel(pModelIn),AIType(Random)
{
}

void TTT_AI::GetAIMoveEmpty(int& x,int& y)
{
	for (int i=0;i<BOARD_SIZE;i++)
		for (int j=0;j<BOARD_SIZE;j++)
			if (pModel->Get(i,j) == _e){ 
				x=i;
				y=j;
			}
}

bool TTT_AI::isCellEmpty(int& x,int& y)
{
		if (pModel->Get(x,y) == _e) return true;
		else return false;
}

void TTT_AI::SetAIType(tAIType AITypeIn){
	AIType = AITypeIn;
}

void TTT_AI::GetAIMoveRandom(int& x,int& y)
{
	srand (time(NULL));
	do{
	x = rand() % 3;
	y = rand() % 3;
	} while (!isCellEmpty(x,y));
}



void TTT_AI::GetAIMove(int& x,int& y)
{
	switch (AIType){
		case Empty: GetAIMoveEmpty(x,y); break;
		case Random: GetAIMoveRandom(x,y); break;
//		case Mixed: GetAIMoveMixed(x,y); break;
		default: break;
	}	
}		

TTT_AI::~TTT_AI(void)
{
}
