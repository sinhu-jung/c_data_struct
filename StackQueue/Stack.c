#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USERDATA {
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pPrev;
	struct USERDATA* pNext;
} USERDATA;

USERDATA g_HeadNode = { 0, "__Dummy Head__" };
USERDATA g_TailNode = { 0, "__Dummy Tail__" };

void InitList(void) {
	g_HeadNode.pNext = &g_TailNode;
	g_TailNode.pPrev = &g_HeadNode;
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

void Push(USERDATA* pUser) {
	USERDATA* pNewNode = (USERDATA*)malloc(sizeof(USERDATA));
	memcpy(pNewNode, pUser, sizeof(USERDATA));
	pNewNode->pPrev = NULL;
	pNewNode->pNext = NULL;

	USERDATA* pNextNode = g_HeadNode.pNext;
	pNewNode->pPrev = &g_HeadNode;
	pNewNode->pNext = g_HeadNode.pNext;

	pNextNode->pPrev = pNewNode;
	g_HeadNode.pNext = pNewNode;
}

int IsEmpty(void) {
	if (g_HeadNode.pNext == &g_TailNode)
		return 1;
	return 0;
}

USERDATA* Pop() {
	if (IsEmpty()) {
		puts("Error: Stack Underflow.");
		return NULL;
	}
	USERDATA* pPop = g_HeadNode.pNext;
	g_HeadNode.pNext = pPop->pNext;
	pPop->pNext->pPrev = pPop->pPrev;
	return pPop;
}

int main(void) {
	InitList();

	USERDATA user = { 0, "Test01" };
	Push(&user);
	user.age = 11;
	strcpy_s(user.name, sizeof(user.name), "Test02");
	Push(&user);
	user.age = 12;
	strcpy_s(user.name, sizeof(user.name), "Test03");
	Push(&user);

	for (int i = 0; i < 3; ++i) {
		USERDATA* pUser = Pop();
		printf("Pop: %d, %s\n", pUser->age, pUser->name);
		free(pUser);
	}

	PrintList();

	ReleaseList();
	return 0;
}