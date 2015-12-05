//
//  main.cpp
//  Tree
//
//  Created by 徐 BOWEI on 15/11/10.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Tree.h"
#include "StackADTbyArray.h"
int roads[20][20] = {{}};
int jishu = 0;
int ROW1 = 0;
int ROW2 = 0;
using namespace std;
vector<vector<int>> roads2 = {10,{}};
struct Node{
    ElementType Element;
    Position LeftSon;
    Position RightSon;
};

Tree MakeEmpty(Tree T)
{
    if (T != NULL) {
        MakeEmpty(T->LeftSon);
        MakeEmpty(T->RightSon);
        free(T);
    }
    return NULL;
}

Position Find(Tree T, ElementType X)
{
    if (T == NULL) {
        return NULL;
    }else if (X < T->Element) {
        return Find(T->LeftSon, X);
    }else if (X > T->Element) {
        return Find(T->RightSon, X);
    }else {
        return T;
    }
}

Position FindMin(Tree T)
{
    if (T == NULL) {
        return NULL;
    }else if (T->LeftSon == NULL) {
        return T;
    }
    
    return FindMin(T->LeftSon);
}

Tree Insert(Tree T, ElementType X)
{
    if (T == NULL) {
        T = (Tree)malloc(sizeof(struct Node));
        if (T == NULL) {
            FatalError("out of space!");
        }else {
            T->Element = X;
            T->LeftSon = NULL;
            T->RightSon = NULL;
        }
    }else if (X < T->Element) {
           T->LeftSon = Insert(T->LeftSon, X);
    }else if (X > T->Element){
           T->RightSon = Insert(T->RightSon, X);
    }
    //if x = element,we will do nothing!
    return T;
}

Tree Delete(Tree T, ElementType X)
{
    Position TmpCell;
    if (T == NULL) {
        Error("This element has been found!");
    }else if (X < T->Element) {
        Delete(T->LeftSon, X);
    }else if (X > T->Element) {
        Delete(T->RightSon, X);
    }else if (T->LeftSon && T->RightSon) {
        TmpCell = FindMin(T->RightSon);
        T->Element = TmpCell->Element;
        Delete(T->RightSon, T->Element);
    }else {
        TmpCell = T;
        if (T->LeftSon == NULL) {
            T = T->RightSon;
        }else if (T->RightSon == NULL) {
            T = T->LeftSon;
        }
        free(TmpCell);
    }
    
    return T;
}

int GetTheCountOfLeaves(Tree T)
{
    int count = 1;
    if (T == NULL) {
        return NULL;
    }
    if (T->LeftSon || T->RightSon) {
        count = 0;
    }
    count += GetTheCountOfLeaves(T->LeftSon);
    count += GetTheCountOfLeaves(T->RightSon);
    
    return count;
}
void DrawTree(std::vector<Tree> T)
{
    int n =2* T.size();
    vector<Tree> T2;
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
        if (e->LeftSon != NULL) {
            cout<<"/"<<" ";
            T2.push_back(e->LeftSon);
        }else
        {
            cout<<"  ";
        }
        if (e->RightSon != NULL) {
            cout<<"\\ ";
            T2.push_back(e->RightSon);
        }else
        {
            cout<<"  ";
        }
    }
    cout<<endl;
    if (T2.size()!=0)
        DrawTree(T2);
}
void PrintTree(Tree T)
{
    if (T!=NULL) {
        PrintTree(T->LeftSon);
        cout<<T->Element<<" ";
        PrintTree(T->RightSon);
    }
}
void ExchangeTheSon(Tree T)
{
    if (T == NULL) {
        return;
    }
    Position TmpCell;
    TmpCell = T->LeftSon;
    T->LeftSon = T->RightSon;
    T->RightSon = TmpCell;
    ExchangeTheSon(T->LeftSon);
    ExchangeTheSon(T->RightSon);
}
void GetTheRoadsFromAllLeavesToRoot(Tree T, Stack S)
{
        if(T != NULL)
        {
            Push(T->Element,S);
            if(!T->LeftSon&&!T->RightSon)
                PrintFromTop(S);
            else
            {
                GetTheRoadsFromAllLeavesToRoot(T->LeftSon,S);
                GetTheRoadsFromAllLeavesToRoot(T->RightSon,S);
            }
            Pop(S);
        }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Tree T = NULL;
//    for (int i = 0; i < 10; i++) {
//        T = Insert(T, i);
//    }
//    T = Insert(T, 1);
//    T = Insert(T, 5);
//    T = Insert(T, -2);
//    T = Insert(T, -1);
//    T = Insert(T, -3);
//    T = Insert(T, 6);
//    T = Insert(T, 4);
//    std::vector<Tree> T2 = {T};
//    DrawTree(T2);
////    ExchangeTheSon(T);
////    DrawTree(T2);
//    cout<<GetTheCountOfLeaves(T)<<endl;
//    int count = GetTheCountOfLeaves(T);
//    Stack S = CreateStack(100);
//    GetTheRoadsFromAllLeavesToRoot(T, S);
    int a[] = {12,7,17,11,16,2,13,9,21,4};
    for (int i = 0; i < sizeof(a)/sizeof(int); i++) {
        T = Insert(T, a[i]);
    }
    std::vector<Tree> T2 = {T};
    DrawTree(T2);
    return 0;
}
