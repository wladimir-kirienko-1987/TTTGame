#pragma once

#include "TTTModel.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


typedef enum{
	Empty = 0,
	Random = 1,
	Mixed = 2,
} tAIType;

class TTT_AI
{
	tAIType AIType; 
	TTTModel* pModel;

	void GetAIMoveEmpty(int& x,int& y);
	void GetAIMoveRandom(int& x,int& y);
	//void GetAIMoveMixed(int& x,int& y);
	bool isCellEmpty(int& x,int& y);

public:
	TTT_AI(TTTModel* pModelIn);
	void SetAIType(tAIType AITypeIn);
	void GetAIMove(int& x,int& y);

	~TTT_AI(void);
};
