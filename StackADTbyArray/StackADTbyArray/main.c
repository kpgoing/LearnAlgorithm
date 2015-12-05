//
//  main.c
//  StackADTbyArray
//
//  Created by 徐 BOWEI on 15/8/5.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <stdio.h>
#include "StackADTbyArray.h"
#include <stdlib.h>

#define EmptyTOS (-1)
#define MinStackSize (5)


struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
    Stack S;
    
    if (MaxElements<MinStackSize) {
        Error("Stack is too small!");
    }
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        FatalError("Out of space! ");
    }
    S->Array = malloc(sizeof(ElementType)*MaxElements);
    if (S->Array==NULL) {
        FatalError("Out of space!");
    }
    S -> Capacity = MaxElements;
    MakeEmpty(S);
    
    return  S;
}

void DisposeStack(Stack S)
{
    if (S!=NULL) {
        free(S->Array);
        free(S);
    }
}
int IsEmpty(Stack S)
{
    return S->TopOfStack==EmptyTOS;
}
int IsFull(Stack S)
{
    return S->TopOfStack== (S->Capacity)-1;
}
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}
void Push(ElementType X,Stack S)
{
    if (IsFull(S)) {
        Error("The stack is full!");
    }else
    S->Array[++S->TopOfStack] = X;
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack];
    }
    Error("Empty stack!");
    return 0;
}
void Pop(Stack S)
{
    if (IsEmpty(S)) {
        Error("Empty stack!");
    }
    else
    {
        S->TopOfStack--;
    }
}
ElementType PopAndTop(Stack S)
{
    if (IsEmpty(S)) {
        Error("Empty stack!");
        return 0;
    }
    else
    {
        return S->Array[S->TopOfStack--];
    }
}
int main()
{
    Stack S = CreateStack(100);
    for (int i = 0; i<100;i++) {
        Push(i, S);
    }
    for (int i = 0; i<100; i++) {
        printf("%d\n",PopAndTop(S));
    }
}


