//
//  main.cpp
//  TwoStackInOneArray
//
//  Created by 徐 BOWEI on 15/9/24.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//
//算法思想：
//关键在top[2],bot[2]两个关键的“指针”数组，没什么难点.
//需要注意的是isfull()中判断方式是判断top[0]与top[1]是否相邻
#include <iostream>
#include "TwoStackInOneArray.h"
#include <stdlib.h>

#define MinStackSize (5)

struct DblStack{
    int top[2],bot[2];
    int Capacity;
    ElementType *Array;
};
Stack MakeEmpty(Stack S)
{
    S->top[0] = S->bot[0];
    S->top[1] = S->bot[1];
    return S;
}
Stack CreateStack(int MaxElements)
{
    Stack S;
    
    if (MaxElements<MinStackSize) {
        Error("Stack is too small!");
    }
    S = (Stack)malloc(sizeof(struct DblStack));
    if (!S) {
        FatalError("Out of space!111");
    }
    S->Array = (ElementType *) malloc(sizeof(ElementType)*MaxElements);
    if (S->Array==NULL) {
        FatalError("Out of space!");
    }
    S->Capacity =MaxElements;
    S->bot[0] = -1;
    S->bot[1] = MaxElements;
    MakeEmpty(S);
    return S;
}
int IsEmpty(Stack S,int i)
{
    return S->top[i] == S->bot[i];
}
int IsFull(Stack S)
{
    return S->top[0]+1==S->top[1];
}
void Dblpush(Stack S,ElementType X,int i)
{
    if (IsFull(S)) {
        Error("The stack is full!");
    }else if(i == 0)
    {
        S->Array[++(S->top[i])] = X;
    }else if(i == 1)
    {
        S->Array[--S->top[i]] = X;
    }
}
int Dblpop(Stack S,int i,ElementType &X)
{
    if (IsEmpty(S, i)) {
        Error("Empty stack!");
        return 0;
    }
    else
    {
        return X = S->Array[S->top[i]--];
    }
}
//输出数组，方便debug
void ShowStack(Stack S)
{
    for (int i = 0; i<=S->top[0]; i++) {
        printf("[%d]-",S->Array[i]);
    }
    for (int i = S->top[0]+1; i<S->top[1]; i++) {
        printf("[ ]-");
    }
    for (int i = S->top[1]; i<S->Capacity; i++) {
        printf("[%d]-",S->Array[i]);
    }
}
int main(int argc, const char * argv[]) {
    Stack S = CreateStack(10);
    Dblpush(S, 1, 0);
    Dblpush(S, 2, 1);
    ShowStack(S);
    return 0;
}
