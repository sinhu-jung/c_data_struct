#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA {
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

USERDATA* g_pHeadNode = NULL;

void AddNewNode(int age,const char* pszName, const char* pszPhone) {
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pNext = NULL;

	if (g_pHeadNode == NULL) 
		g_pHeadNode = pNewNode;
	else {
		//Queue 구조
		USERDATA* pTail = g_pHeadNode;
		while (pTail->pNext != NULL)
			pTail = pTail->pNext;
		pTail->pNext = pNewNode;

		//Stack 구조
		/*pNewNode->pNext = g_pHeadNode;
		g_pHeadNode = pNewNode;*/
	}
}

void ReleaseList(void) {
	USERDATA* pTmp = g_pHeadNode;
	USERDATA* pDelete;
	while (pTmp != NULL)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete: [%p] %d %s %s [%p]\n", pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete);
	}

	g_pHeadNode = NULL;
}

void InitDummyData(void) {
	AddNewNode(10, "Hoon", "010-1111-1111");
	AddNewNode(11, "Hoon1", "010-2222-2222");
	AddNewNode(12, "Hoon2", "010-3333-3333");
}

void PrintList(void) {
	USERDATA* pTmp = g_pHeadNode;

	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n", pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
}

int main(void) {

	InitDummyData();
	PrintList();
	ReleaseList();

	return 0;
}