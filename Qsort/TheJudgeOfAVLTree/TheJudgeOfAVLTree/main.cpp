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

void DrawTree(std::vector<Tree> T)
{
    int n =2 * (int)T.size();
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

int absoluteDifference(ElementType A,ElementType B)
{
    int differenece = A - B;
    
    if (differenece < 0) {
        differenece = - differenece;
    }
    
    return differenece;
}

int Max(ElementType A, ElementType B)
{
    return A > B ? A : B;
}

#define IS_NOTAVLTREE -2

//判断过程中的递归部分，从判断主函数中抽离出来
//叶子高度此处定义为0
int IsAVLTree(Tree T)
{
    int leftHeigh,rightHeight;
    
    if (T == NULL) {
        return -1;
    } else {
        leftHeigh = IsAVLTree(T->LeftSon);
        rightHeight = IsAVLTree(T->RightSon);
    }
    if (leftHeigh == IS_NOTAVLTREE || rightHeight == IS_NOTAVLTREE) {
        return IS_NOTAVLTREE;
    } else if (absoluteDifference(leftHeigh, rightHeight) > 1) {
        return IS_NOTAVLTREE;
    } else {
        return Max(leftHeigh,rightHeight) + 1;
    }
}

//判断是否为AVL函数的主函数
void JudgeAVL(Tree T)
{
    if (IsAVLTree(T) == IS_NOTAVLTREE) {
        std::cout<<"The tree is not AVLTree."<<std::endl;
    } else{
        std::cout<<"The tree is AVLTree."<<std::endl;
    }
}

//随机生成数组内容
void RandArray(ElementType A[ ], int Length)
{
    srand((unsigned int)time(0));//设置随机数种子
    for (int i  = 0; i < Length; i++) {
        A[i] = rand()%1000;
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Tree T = NULL;
    int numbers[100] = {0};
    RandArray(numbers, 100);
    for (int i = 0; i < sizeof(numbers)/sizeof(int); i++) {
        T = Insert(T, numbers[i]);
    }
    std::vector<Tree> T2 = {T};
    JudgeAVL(T);
    DrawTree(T2);
    MakeEmpty(T);
    return 0;
}
