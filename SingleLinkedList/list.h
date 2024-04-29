#pragma once

typedef struct USERDATA {
	int age;
	char name[32];
	char phone[32];
	struct USERDATA* pPrev;
	struct USERDATA* pNext;
} USERDATA;

USERDATA g_HeadNode;
USERDATA g_TailNode;

void AddNewNode(int age, const char* pszName, const char* pszPhone);
void InitList(void);
void ReleaseList(void);
USERDATA* SearchByName(const char* pszName);
void RemoveNode(USERDATA* pRemove);