//
// Created by voit on 18.10.2022.
//

#ifndef TEP_ZAD_5_CMYSMARTPOINTER_H
#define TEP_ZAD_5_CMYSMARTPOINTER_H

class CRefCounter
{
public:
	CRefCounter() { i_count = 0; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
private:
	int i_count;
};//class CRefCounter


template<typename POINTER_TYPE>
class CMySmartPointer {
public:
	CMySmartPointer(POINTER_TYPE *pcPointer) {
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
	}//CMySmartPointer(CSellData *pcPointer)

	CMySmartPointer(const CMySmartPointer<POINTER_TYPE> &pcOther) {
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}//CMySmartPointer(const CMySmartPointer &pcOther)

	~CMySmartPointer() {
		if (pc_counter->iDec() == 0) {
			delete pc_pointer;
			delete pc_counter;
		}//if (pc_counter->iDec())
	}//~CMySmartPointer()

	POINTER_TYPE &operator*() {
		return (*pc_pointer);
	}

	POINTER_TYPE *operator->() {
		return (pc_pointer);
	}

	CMySmartPointer<POINTER_TYPE> &operator=(const CMySmartPointer<POINTER_TYPE> &pcOther) {
		if (this == &pcOther) return (*this);

		if (pc_counter->iDec() == 0) {
			delete pc_pointer;
			delete pc_counter;
		}//if (pc_counter->iDec())

		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;

		return (*this);
	}

//	CRefCounter *getCounter(){
//		return pc_counter;
//	}

private:
	CRefCounter *pc_counter;
	POINTER_TYPE *pc_pointer;

};

#endif //TEP_ZAD_5_CMYSMARTPOINTER_H
