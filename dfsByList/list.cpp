//
//  main.c
//  list
//
//  Created by 徐 BOWEI on 15/8/2.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <stdio.h>
#include "list.h"
#include <stdlib.h>
//struct Node
//{
//    
//    ElementType Element;
//    Position Next;
//};
void DeleteList(List L)
{
    Position P;
    Position TmpCell;
    P = L->Next;
    L->Next = NULL;
    while(P!=NULL)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}
List MakeEmpty(List L)
{
    if (L!=NULL)
    {
        DeleteList(L);
    }
    L =(List)(malloc(sizeof(struct Node)));
    if (L == NULL)
    {
        FatalError("out of space!");
    }
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}
int IsLast(Position P,List L)
{
    return P->Next == NULL;
}
Position Find(ElementType X,List L)
{
    Position P;
    P = L->Next;
    while(P!=NULL&&P->Element!=X)
    {
        P = P->Next;
    }
    return P;
}
Position FindPrevious(ElementType X,List L)
{
    Position P;
    P = L->Next;
    while(P->Next!=NULL&&P->Next->Element!=X)
    {
        P = P->Next;
    }
    return P;
}
void Delete(ElementType X,List L)
{
    Position P;
    Position TmpCell;
    P = FindPrevious(X,L);
    if (!IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}
void Insert(ElementType X,List L, Position P)
{
    Position TmpCell;
    
    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        FatalError("out of space!");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}
Position Header(List L)
{
    return L;
}
Position First(List L)
{
    return L->Next;
}
Position Advance(Position P)
{
    return P->Next;
}
ElementType Retrieve(Position P)
{
    return P->Element;
}
Position FindLast(List L)
{
    Position P;
    P = L;
    while (!IsLast(P, L)) {
        P = P->Next;
    }
    return P;
}
Position FindListAndDeleteItFromList(List L)
{
    Position P,preP = NULL;
    P = L;
    while (!IsLast(P, L)) {
        preP = P;
        P = P->Next;
    }
    if (preP!=NULL) {
        preP->Next = NULL;
    }
    return P;
}
void ShowAllElement(List L)
{
    Position P;
    P = First(L);
    while(P!=NULL)
    {
        printf("%d->",P->Element);
        P = P->Next;
    }
    printf("\n*************\n");
}
//下面为第一题
List Merge(List L1,List L2)
{
    //考虑两个表是否为空
    if (IsEmpty(L1))
    {
        if (IsEmpty(L2))
        {
            return L1;
        }
        return L2;
    }else if (IsEmpty(L2))
    {
        return L1;
    }
    List MergeList = L1;
    Position P1 = L1->Next;
    Position P2 = L2->Next;
    Position PreP;
    //确定第一个非空节点
    if (P1->Element>P2->Element)
    {
        MergeList->Next =  PreP = P2;
        P2 = P2->Next;
    }else if (P1->Element==P2->Element)
    {
        MergeList->Next =  PreP = P1;
        P1 = P1->Next;
        P2 = P2->Next;
    }
    else
    {
        MergeList->Next = PreP = P1;
        P1 = P1->Next;
        
    }
    //循环完成合并
    while (P1!=NULL&&P2!=NULL)
    {
    if (P1->Element>P2->Element)
    {
        PreP =  PreP->Next = P2;
        P2 = P2->Next;
    }else if(P1->Element==P2->Element)
    {
        PreP = PreP->Next = P1;
        P1 = P1->Next;
        P2 = P2->Next;
    }
    else
    {
        PreP = PreP->Next = P1;
        P1 = P1->Next;
    }
    }
    //当其中一表为空时将另一表剩下元素全部合并
    if(P1==NULL)
    {
        if (P2!=NULL)
        {
            PreP->Next = P2;
        }
    }else if (P2==NULL)
    {
        if (P1!=NULL)
        {
            PreP->Next = P1;
        }
    }
    return MergeList;
}
//第二题
List Merge2(List L1,List L2)
{
    //考虑两个表是否为空
    if (IsEmpty(L1))
    {
        if (IsEmpty(L2))
        {
            return L1;
        }
        return Reverse(L2);
    }else if (IsEmpty(L2))
    {
        return Reverse(L1);
    }
    List MergeList = L1;
    Position P1 = L1->Next;
    Position P2 = L2->Next;
    Position Tmp,PreP = NULL;
    //循环完成合并
    while (P1!=NULL&&P2!=NULL) {
     if(P1->Element<P2->Element) {
        //在完成新节点的插入时也不丢失下个待插入节点
        Tmp = P1->Next;
        P1->Next = PreP;
        PreP = P1;
        MergeList->Next = P1;
        P1 = Tmp;
     }else
     {
         Tmp = P2->Next;
         P2->Next = PreP;
         PreP = P2;
         MergeList->Next = P2;
         P2 = Tmp;
     }
    }
    //当其中一表为空时将另一表剩下元素全部合并
    if (P1==NULL) {
        if (P2==NULL) {
            return MergeList;
        }else
        {
            while (P2!=NULL) {
                Tmp = P2->Next;
                P2->Next = PreP;
                PreP = P2;
                MergeList->Next = P2;
                P2 = Tmp;
            }
        }
    }else if(P2 == NULL)
    {
        while (P1!=NULL) {
            Tmp = P1->Next;
            P1->Next = PreP;
            PreP = P1;
            MergeList->Next = P1;
            P1 = Tmp;
        }
    }
    return MergeList;
}
//下面两个函数为第三题的两种解法
//第一种的关键是设置一个int类型的变量Max保存当前已循环的节点中的最大值
Position FindMax(List L){
    Position P;
    ElementType Max = 0;
    P = L;
    if (P->Next!=NULL)
    {
        Max = P->Next->Element;
    }else
    {
        return NULL;
    }
    while (P->Next!=NULL)
    {
        P = P->Next;
        Max = P->Element>Max?P->Element:Max;
    }
    return P;
}
//第二种即通过设置一个指针指向已遍历的节点中的最大节点
Position FindMaxByPoint(List L)
{
    Position MaxPoint = NULL;
    while (L->Next!=NULL) {
        L = L->Next;
        if (MaxPoint==NULL) {
            MaxPoint = L;
        }else if(L->Element>MaxPoint->Element){
            MaxPoint = L;
        }
    }
    return MaxPoint;
}
//如下为第四题，从首元结点开始，逐个地把链表L的当前结点p插入新的链表头部
List Reverse(List L)
{
    List NewList = MakeEmpty(NewList);
    Position P = L;
    while (P->Next != NULL) {
        P = P->Next;
        Insert(P->Element, NewList,NewList);
        
    }
    return NewList;
}
void ChooseSort(List L)
{
    Position P1 = L->Next;
    Position P2,Tmp,PreviousOfP1 = NULL,PreviousOfTmp,PreviousOfP2 = NULL;
    while (P1 != NULL) {
        P2 = P1->Next;
        Tmp = P1;
        PreviousOfTmp = P1;
        PreviousOfP2 = P1;
        while (P2 != NULL) {
        if ( P2->Element < Tmp->Element) {
            PreviousOfTmp = PreviousOfP2;
            Tmp = P2;
            }
            PreviousOfP2 = P2;
            P2 = P2->Next;
        }
        if (Tmp != P1) {
            Position P = Tmp->Next;
            if (P1->Next == Tmp) {
                Tmp->Next = P1;
            } else {
                Tmp->Next = P1->Next;
                PreviousOfTmp->Next = P1;
            }
            PreviousOfP1->Next = Tmp;
            P1->Next = P;
        }
        PreviousOfP1 = Tmp;
        P1 = Tmp->Next;
    }
}
//int main(int argc, char const *argv[])
//{
//    List L1 = MakeEmpty(L1);
//    for (int i = 0; i<3; i++) {
//        Insert(i, L1, FindLast(L1));
//    }
//    Insert(1, L1, FindLast(L1));
//    Insert(0, L1, FindLast(L1));
//    ShowAllElement(L1);
//    ChooseSort(L1);
//    ShowAllElement(L1);
////    DeleteList(L1);
//    return 0;
//}




