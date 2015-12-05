//
//  main.cpp
//  HashTable
//
//  Created by 徐 BOWEI on 15/9/10.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "hashtab.h"
using namespace std;

#define MinTableSzie (10)

struct ListNode
{
	ElementType Element;
	Position Next;
};

typedef Position List;

struct HashTbl
{
	int TableSize;
	List *TheLists;
};

static int NextPrime(int N)
{
	int i;
	if (N % 2 == 0)
	{
		N++;
	}
	for (;; N+=2)
	{
		for(i = 3;i*i<=N;i += 2)
			if (N % i == 0)
			{
				goto ContOuter;
			}
			return N;
		ContOuter: ;	
	}
}

Index Hash(ElementType Key, int TableSize)
{
	return Key % TableSize;
}

HashTable InitializeTable(int TableSize)
{
	HashTable  H;

	if (TableSize < MinTableSzie)		
	{
		Error("table size is too small!");
		return NULL;
	}

	H = (HashTable) malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		FatalError("out of space!");
	}

	H->TableSize = NextPrime(TableSize);

	H->TheLists =(List*) malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
	{
		FatalError("out of space!");
	}

	// H -> TheLists = malloc(H -> TableSize * sizeof(struct ListNode));
	// 据说可以替代82行？是怎么做到的？
	for (int i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = (ListNode*)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
		{
			FatalError("out of space!");
		}
		else {
			H->TheLists[i]->Next = NULL;
		}
	}
    return H;
}

Position Find(ElementType Key,HashTable H)
{
	Position P;
	List L;

	L = H->TheLists[Hash(Key,H->TableSize)];
	P = L->Next;
	while(P != NULL && P->Element != Key)
	{
		P = P->Next;
	}
	return P;
}

void Insert(ElementType Key,HashTable H)
{
	Position Pos,NewCell;
	List L;

	Pos = Find(Key,H);
	if(Pos == NULL)
	{
		NewCell =(ListNode*) malloc(sizeof(struct ListNode));
		if(NewCell == NULL)
		{
			FatalError("out of space!");
		}
		else
		{
			L = H->TheLists[Hash(Key,H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void DestroyTable(HashTable H)
{

	for (int i = 0; i < H->TableSize; ++i)
	{
		Position P = H->TheLists[i];
		Position Tmp;

		while(P != NULL)
		{
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}

	free(H->TheLists);
	free(H);
}
void DrawHashTbl(HashTable H)
{
    if (H == NULL) {
        return;
    }else
    {
        List *lists = H->TheLists;
        for (int i = 0; i<H->TableSize; i++) {
         cout<<"["<<i<<"]";
            ListNode *listnode = lists[i]->Next;
            for (int j = 0; listnode!=NULL; j++) {
                cout<<"--->"<<"("<<listnode->Element<<")";
                listnode = listnode->Next;
            }
            cout<<endl;
        }
    }
}
int main(int argc, const char * argv[]) {
    HashTable H;
    H = InitializeTable(10);
    for (int i = 0; i<100; i++) {
        Insert(i, H);
    }
//	Insert(1,H);
    DrawHashTbl(H);
    return 0;
}
