//
// Created by voit on 19.10.2022.
//

#include <iostream>
#include "CTab.h"
#include "CMySmartPointer.h"

void v_test_smart_pointers(){
	CMySmartPointer<CTab> p_tab = CMySmartPointer<CTab>(new CTab);

	for (int i = 0; i < DEF_TAB_SIZE; ++i) {
		p_tab->bSetValAtIndex(i, i);
	}

	p_tab->vPrint();

	{
		std::cout << "Create new smart ptr\n";
		CMySmartPointer<CTab> test = p_tab;
		std::cout << "End of its scope\n";
	}

//	std::cout << p_tab.getCounter()->iGet() << '\n';
}

CTab v_test_move_semantics_create_CTab(){
	std::cout << "Test MS create out\n";
	CTab out;
	int newSize = 5;
	out.bSetSize(newSize);
	for (int i = 0; i < newSize; ++i) {
		out.bSetValAtIndex(i, i);
	}
	std::cout << "Out: ";
	out.vPrint();
	std::cout << "Return out with MS\n";
	return std::move(out);
}

void v_test_move_semantics(){
	std::cout << "Test MS start\n";
	CTab tab = v_test_move_semantics_create_CTab();
	std::cout << "Tab: ";
	tab.vPrint();
	CTab newTab;
	std::cout << "Use operator= with MS\n";
	newTab = std::move(tab);
	std::cout << "New tab: ";
	newTab.vPrint();
}

int main(){
	v_test_smart_pointers();
	v_test_move_semantics();

	return 0;
}