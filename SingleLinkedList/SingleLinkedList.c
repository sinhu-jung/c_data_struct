#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA {
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

//USERDATA* g_pHeadNode = NULL;
USERDATA g_HeadNode = { 0, "__Dummy Node__" };

void AddNewNode(int age,const char* pszName, const char* pszPhone) {
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

		//Queue ±¸Á¶
		USERDATA* pTail = &g_HeadNode;
		while (pTail->pNext != NULL)
			pTail = pTail->pNext;
		pTail->pNext = pNewNode;

}

void ReleaseList(void) {
	USERDATA* pTmp = g_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete: [%p] %d %s %s [%p]\n", pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete);
	}

	g_HeadNode.pNext = NULL;
}

void InitDummyData(void) {
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Hoon1", "010-2222-2222");
	AddNewNode(12, "Hoon2", "010-3333-3333");
}

USERDATA* SearchByName(const char* pszName) {
	USERDATA* pTmp = g_HeadNode.pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->name, pszName) == 0) {
			printf("\"%s\": Found\n", pszName);
			return pTmp;
		}

		pTmp = pTmp->pNext;
	}

	printf("\"%s\":Not Found\n", pszName);
	return NULL;
}

USERDATA* SearchToRemove(const char* pszName) {
	USERDATA* pPrev = &g_HeadNode;

	while (pPrev->pNext != NULL)
	{
		if (strcmp(pPrev->pNext->name, pszName) == 0) 
			return pPrev;
		pPrev = pPrev->pNext;
	}

	return NULL;
}

void RemoveNode(USERDATA* pPrev) {
	USERDATA* pRemove = NULL;
		
	pRemove = pPrev->pNext;
	pPrev->pNext = pRemove->pNext;
	printf("RemoveNode(): %s\n", pRemove->name);
	free(pRemove);
	return;
}

void PrintList(void) {
	USERDATA* pTmp = g_HeadNode.pNext;

	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n", pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	putchar('\n');
}

void TestStep01(void) {
	puts("TestStep01()--------------------------------");
	AddNewNode(10, "Hoon1", "010-4444-4444");
	AddNewNode(11, "Hoon2", "010-2222-2222");
	AddNewNode(12, "Hoon3", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchToRemove("Hoon1");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	PrintList();
	ReleaseList();
	putchar('\n');
}

void TestStep02(void) {
	puts("TestStep02()--------------------------------");
	AddNewNode(10, "Hoon1", "010-4444-4444");
	AddNewNode(11, "Hoon2", "010-2222-2222");
	AddNewNode(12, "Hoon3", "010-3333-3333");
	PrintList();

	USERDATA* pPrev = SearchToRemove("Hoon2");
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

	USERDATA* pPrev = SearchToRemove("Hoon3");
	if (pPrev != NULL)
		RemoveNode(pPrev);
	PrintList();
	ReleaseList();
	putchar('\n');
}

int main(void) {

	//InitDummyData();

	TestStep01();
	TestStep02();
	TestStep03();

	ReleaseList();

	return 0;
}