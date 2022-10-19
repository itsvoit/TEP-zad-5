//
// Created by voit on 19.10.2022.
//

#ifndef TEP_ZAD_5_CTAB_H
#define TEP_ZAD_5_CTAB_H


#define DEF_TAB_SIZE 10
class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE;}
	CTab(const CTab &cOther);
	CTab(CTab &&cOther);
	CTab &operator=(const CTab &cOther);
	CTab &operator=(CTab &&cOther);
	~CTab();
	bool bSetSize(int iNewSize);
	bool bSetValAtIndex(int iNewVal, int iIndex);
	int iGetSize() { return(i_size); }
	void vPrint();
private:
	void v_copy(const CTab &cOther);
	int *pi_tab;
	int i_size;
};//class CTab


#endif //TEP_ZAD_5_CTAB_H
