#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h";

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

		free(pDelete);
	}

	InitList();
}

USERDATA* SearchByName(const char* pszName) {
	USERDATA* pTmp = g_HeadNode.pNext;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->name, pszName) == 0) 
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}

void RemoveNode(USERDATA* pRemove) {
	USERDATA* pPrev = pRemove->pPrev;
	USERDATA* pNext = pRemove->pNext;

	pPrev->pNext = pRemove->pNext;
	pNext->pPrev = pRemove->pPrev;

	free(pRemove);
	return;
}
