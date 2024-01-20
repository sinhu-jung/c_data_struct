#include <stdio.h>

typedef struct USERDATA
{
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pNext;
} USERDATA;

int main(void) {
	USERDATA aList[4] = {
		{20, "Tester01", "010-1234-5678", NULL},
		{21, "Tester02", "010-1234-5678", NULL},
		{22, "Tester03", "010-1234-5678", NULL},
		{23, "Tester04", "010-1234-5678", NULL},
	};

	aList[0].pNext = &aList[1];
	aList[1].pNext = &aList[2];
	aList[2].pNext = &aList[3];
	aList[3].pNext = NULL;

	printf("%s\n", aList[0].name);
	printf("%s\n", aList[0].pNext->name);
	printf("%s\n", aList[0].pNext->pNext->name);
	printf("%s\n", aList[0].pNext->pNext->pNext->name);

	return 0;
}