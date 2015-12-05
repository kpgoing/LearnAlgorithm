//
//  main.cpp
//  AVLTree
//
//  Created by 徐 BOWEI on 15/9/1.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include <vector>
#include "AVLTree.h"
#include <assert.h>


using namespace std;
struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

AvlTree MakeEmpty(AvlTree T)
{
    if ( T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    T = (AvlTree)malloc(sizeof(struct AvlNode));
    if (T == NULL) {
        FatalError("OUT OF SPACE!");
    }
    T->Left = T->Right = NULL;
    return NULL;
}
Position Find(ElementType X,AvlTree T)
{
    if (T == NULL) {
        return NULL;
    }
    if (X<T->Element) {
        return  Find(X,T->Left);
    }
    if (X>T->Element) {
        return Find(X,T->Right);
    }
    else
        return T;
}
Position FindMin(AvlTree T)
{
    if (T == NULL) {
        return NULL;
    }
    else if (T->Left == NULL)
    {
        return T;
    }
    else
    {
        return FindMin(T->Left);
    }
}

Position FindMax(AvlTree T)
{
    if (T == NULL) {
        return NULL;
    }
    else while(T->Right != NULL)
    {
        T = T->Right;
    }
    return T;
}

static  int Height(Position P)
{
    if (P == NULL) {
        return -1;
    }
    return P->Height;
}

static int Max(int Lhs,int Rhs)
{
    return Lhs>Rhs ? Lhs:Rhs;
}

static Position SinglerRotateWithLeft(Position K2)
{
    Position K1;
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = Max(Height(K2->Left), Height(K2->Left)) + 1;
    K1->Height = Max(Height(K1->Left), K2 ->Height) + 1;
    return K1;
}

static Position SinglerRotateWithRight(Position K1)
{
    Position K2;
    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(K1 ->Height, Height(K2->Right)) + 1;
    return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SinglerRotateWithRight(K3->Left);
    return SinglerRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K1)
{
    K1->Right = SinglerRotateWithLeft(K1->Right);
    return SinglerRotateWithRight(K1);
}


Position Insert(ElementType X,AvlTree T)
{
    if (T == NULL)  
    {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL)
        {
            FatalError("out of space!");
        }else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
            T->Height = 0;
        }
    }
    if(X<T->Element)
    {
        T->Left = Insert(X,T->Left);
        if(Height(T->Left)-Height(T->Right) == 2)
        {
            if(X<T->Left->Element)
            {
                T = SinglerRotateWithLeft(T);
            }else
            {
                T = DoubleRotateWithLeft(T);
            }
        }
    }
    if(X>T->Element)
    {
        T->Right = Insert(X,T->Right);
        if(Height(T->Right) - Height(T->Left) == 2)
        {
            if(X<T->Right->Element)
            {
                T = DoubleRotateWithRight(T);
            }else
            {
                T = SinglerRotateWithRight(T); 
}

        }
    }
    T->Height = Max(Height(T->Left),Height(T->Right)) + 1;
    return T;
}


ElementType Retrieve( Position P )
    {
        if (P == NULL) {
            return -1;
        }
        return P->Element;
    }

void DrawTree(std::vector<AvlTree> T)
{
    int n =2* T.size();
    vector<AvlTree> T2;
    string space =  "                                                                   ";
    cout<<space.substr(n);
    for(auto e:T)
    {
        cout<<e->Element<<" ";
    }
    cout<<space.substr(n)<<endl;
    cout<<space.substr(n);
    for(auto e:T)
    {
        if (e->Left != NULL) {
            cout<<"/"<<" ";
            T2.push_back(e->Left);
        }else
        {
            cout<<"  ";
        }
        if (e->Right != NULL) {
            cout<<"\\ ";
            T2.push_back(e->Right);
        }else
        {
            cout<<"  ";
        }
    }
    cout<<endl;
    if (T2.size()!=0)
    DrawTree(T2);
}
void PrintTree(AvlTree T)
{
    if (T!=NULL) {
        PrintTree(T->Left);
        cout<<T->Element<<" ";
        PrintTree(T->Right);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    AvlTree T ;
    T = Insert(1, T);
    if (T == NULL) {
        cout<<"wooo!"<<endl;
    }
    for (int i = 2; i<10; i++) {
          T = Insert(i, T);
    }
//    vector<AvlTree> t ;
//    t.push_back(T);
    PrintTree(T);
    return 0;
}
