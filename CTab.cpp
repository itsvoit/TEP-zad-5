//
// Created by voit on 19.10.2022.
//

#include "CTab.h"
#include <iostream>

CTab::CTab(const CTab &cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}//CTab::CTab(const CTab &cOther)

CTab::CTab(CTab &&cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	std::cout << "MOVE ";
}//CTab::CTab(CTab &&cOther)


CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}//CTab::~CTab()

CTab &CTab::operator=(const CTab &cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}//CTab CTab::operator=(const CTab &cOther)

CTab &CTab::operator=(CTab &&cOther) {
	if (this == &cOther) return (*this);

	if (pi_tab != NULL) delete pi_tab;
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	std::cout << "MOVE op= ";

	return (*this);
} // CTab CTab::operator=(const CTab &&)

void CTab::v_copy(const CTab &cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)

bool CTab::bSetSize(int iNewSize) {
	if (iNewSize <= 0) return false;
	if (iNewSize == i_size) return true;

	int *pi_temp_tab = new int [iNewSize];

	int i_min = std::min(iNewSize, i_size);
	for (int i = 0; i < i_min; ++i) {
		pi_temp_tab[i] = pi_tab[i];
	}

	delete [] pi_tab;
	pi_tab = pi_temp_tab;
	i_size = iNewSize;

	return true;
}// bool CTab::bSetSize(int iNewSize)

bool CTab::bSetValAtIndex(int iNewVal, int iIndex) {
	if (iIndex < 0 || iIndex >= i_size) return false;
	if (pi_tab == NULL) return false;

	pi_tab[iIndex] = iNewVal;

	return true;
}

void CTab::vPrint() {
	if (pi_tab == NULL) return;

	for (int i = 0; i < i_size; ++i) {
		std::cout << pi_tab[i] << ' ';
	}
	std::cout << std::endl;
}

