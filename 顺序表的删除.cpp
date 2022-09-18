#include<iostream>
#include<stdio.h>
#include<malloc.h>

#define maxsize 1024

using namespace std;

typedef struct
{
	char data[maxsize];
	int last;
}sqList;

sqList* create(sqList *&L);
void print(sqList* L);
void delet(sqList* L, char x);

int main()
{
	sqList *L;
	char x;
	create(L);
	printf("Print x which is waiting for being delet:");
	getchar();
	scanf("%c",&x,sizeof(x));
	delet(L,x);
	printf("After delet:");
	print(L);
	return 0;
}

//建立顺序表
sqList* create(sqList *&L)
{
	int i = 0;
	char ch;
	L = (sqList*)malloc(sizeof(sqList));
	L->last = 0;
	printf("Please input the elements and end with '#'\n");
	while((ch = getchar()) != '#')
	{
		L -> data[i] = ch;
		L -> last++;
		i++;
	}
}

//输出顺序表
void print(sqList *L)
{
	for(int i = 0; i < L->last; i++)
	{
		cout << ' '<< L->data[i];
	}
}

void delet(sqList* L, char x)
{
	int key = 0;//新顺序表指针
	for(int i = 0; i < L->last; i++)
	{
		if(L->data[i] != x )
		{
			L->data[key] = L->data[i];
			key++;
		}
	}
	L->last = key;
}






