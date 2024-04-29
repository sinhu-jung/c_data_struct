#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "list.h"
#include "ui.h"

MY_MENU PrintMenu(void) {
	MY_MENU input = 0;

	system("cls");
	printf("[1]New\t[2]Search\t[3]Print\t[4]Remove\t[0]Exit\n");
	scanf_s("%d%*c", &input);
	return input;
}

void EventLoopRun(void) {
	MY_MENU menu = 0;

	while ((menu = PrintMenu()) != 0)
	{
		switch (menu) {
		case NEW:
			break;
		case SEARCH:
			Search();
			break;
		case PRINT:
			PrintList();
			break;
		case REMOVE:
			break;
		default:
			break;
		}
	}
	puts("Bye~!");
	return;
}

void PrintList(void) {
	USERDATA* pTmp = &g_HeadNode;

	while (pTmp != NULL)
	{
		printf("[%p] %d %s %s [%p]\n", pTmp, pTmp->age, pTmp->name, pTmp->phone, pTmp->pNext);
		pTmp = pTmp->pNext;
	}
	puts("[End of list]");
	_getch();
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

void Search(void) {
	char name[32] = { 0 };
	gets_s(name, sizeof(name));

	USERDATA* pResult = SearchByName(name);
	if (pResult != NULL) {
		printf("%d, %s, %s\n", pResult->age, pResult->name, pResult->phone);
	}
	else
		puts("Not Found");
	_getch();
}