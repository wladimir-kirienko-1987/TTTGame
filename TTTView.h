#pragma once


#include <iostream>

using namespace std;

#include "TTTModel.h"

class TTTView
{
	TTTModel* pModel;

public:
	TTTView(TTTModel* pModelIn);
	
	void ShowBoard();

	~TTTView(void);
};
