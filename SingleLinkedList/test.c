#include "list.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

void InitDummyData(void) {
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Hoon1", "010-2222-2222");
	AddNewNode(12, "Hoon2", "010-3333-3333");
}

void TestStep01(void) {
	puts("TestStep01()--------------------------------");
	AddNewNode(10, "Hoon1", "010-4444-4444");
	AddNewNode(11, "Hoon2", "010-2222-2222");
	AddNewNode(12, "Hoon3", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchByName("Hoon1");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	PrintList();
	PrintListReverse();
	ReleaseList();
	putchar('\n');
}

void TestStep02(void) {
	puts("TestStep02()--------------------------------");
	AddNewNode(10, "Hoon1", "010-4444-4444");
	AddNewNode(11, "Hoon2", "010-2222-2222");
	AddNewNode(12, "Hoon3", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchByName("Hoon2");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	PrintList();
	ReleaseList();
	putchar('\n');
}

void TestStep03(void) {
	puts("TestStep03()--------------------------------");
	AddNewNode(10, "Hoon1", "010-4444-4444");
	AddNewNode(11, "Hoon2", "010-2222-2222");
	AddNewNode(12, "Hoon3", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchByName("Hoon3");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	PrintList();
	ReleaseList();
	putchar('\n');
}