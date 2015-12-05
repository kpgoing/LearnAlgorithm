//
//  main.c
//  StackADT
//
//  Created by 徐 BOWEI on 15/8/5.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <stdio.h>
#include "StackADT.h"
#include <stdlib.h>

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        FatalError("Out of space!!");
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if (S == NULL) {
        Error("Must use CreateStack first!");
    }
    else
    {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void Push(ElementType X,Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        FatalError("Out of space!");
    }
    else
    {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S)) {
        return S->Next->Element;
    }
    Error("Empty Stack!");
    return  0;
}

void Pop(Stack S)
{
    PtrToNode FirstCell;
    
    if (IsEmpty(S)) {
        Error("Empty Stack!");
    }
    else
    {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}
int main()
{
    Stack S = CreateStack();
    Push(1, S);
    Push(2, S);
    printf("%d",Top(S));
}