#pragma once

#include <iostream>

using namespace std;

#include "TTTModel.h"
#include "TTT_AI.h"

class TTTController
{
TTTModel* pModel;
TTT_AI* pAI;
bool AIPlayFlag;


public:
	TTTController(TTTModel* pModelIn, TTT_AI* pAIIn);
	
	void GetMove(tCell CellType);

	int Process();

	void AI_On();
	void AI_Off();

	
	~TTTController(void);
};
