#include "TTTView.h"

TTTView::TTTView(TTTModel* pModelIn):pModel(pModelIn)
{

}

void TTTView::ShowBoard()
{
	int k = 0;

	cout << "Board: " << endl;
	cout << "  1 2 3" << endl;
	cout << "1 ";
	for (int i=0;i<BOARD_SIZE;i++)
		for (int j=0;j<BOARD_SIZE;j++)
		{
			if ( pModel->Get(j,i) == _x) cout << "x ";
			else if ( pModel->Get(j,i) == _0) cout << "0 ";
			else cout << "_ ";
			if ( (++k) % 3 == 0 ){ 
				cout << endl;
				if (k == 3) cout << "2 ";
				if (k == 6) cout << "3 ";
			}
		}
}		

TTTView::~TTTView(void)
{

}
