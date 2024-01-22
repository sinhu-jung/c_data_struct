#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA {
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pPrev;
	struct USERDATA* pNext;
} USERDATA;

//USERDATA* g_pHeadNode = NULL;
USERDATA g_HeadNode = { 0, "__Dummy Head__" };
USERDATA g_TailNode = { 0, "__Dummy Tail__" };

void AddNewNode(int age, const char* pszName, const char* pszPhone) {
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	pNewNode->age = age;
	strcpy_s(pNewNode->name, sizeof(pNewNode->name), pszName);
	strcpy_s(pNewNode->phone, sizeof(pNewNode->phone), pszPhone);
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL;

	USERDATA* pPrevNode = g_TailNode.pPrev;
	pNewNode->pPrev = g_TailNode.pPrev;
	pNewNode->pNext = &g_TailNode;

	pPrevNode->pNext = pNewNode;
	g_TailNode.pPrev = pNewNode;
}

void InitList(void) {
	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
	return;
}

void ReleaseList(void) {
	USERDATA* pTmp = g_HeadNode.pNext;
	USERDATA* pDelete;
	while (pTmp != NULL && pTmp != &g_TailNode)
	{
		pDelete = pTmp;
		pTmp = pTmp->pNext;

		printf("Delete: [%p] %d %s %s [%p]\n", pDelete, pDelete->age, pDelete->name, pDelete->phone, pDelete->pNext);

		free(pDelete);
	}

	InitList();
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

void RemoveNode(USERDATA* pRemove) {
	USERDATA* pPrev = pRemove->pPrev;
	USERDATA* pNext = pRemove->pNext;

	pPrev->pNext = pRemove->pNext;
	pNext->pPrev = pRemove->pPrev;

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

void PrintListReverse(void) {
	USERDATA* pTmp = g_TailNode.pPrev;

	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n", pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pPrev);
		pTmp = pTmp->pPrev;
	}
	putchar('\n');
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

int main(void) {

	//InitDummyData();
	InitList();
	TestStep01();
	TestStep02();
	TestStep03();

	ReleaseList();

	return 0;
}