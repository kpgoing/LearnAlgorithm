//
//  main.cpp
//  PriorityQueue
//
//  Created by 徐 BOWEI on 15/9/17.
//  Copyright (c) 2015年 徐 BOWEI. All rights reserved.
//

#include "PriorityQueue.h"
#include <stdlib.h>
struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

#define MinHQSize 10
PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    
    if (MaxElements < MinHQSize) {
        Error("the size is too small!");
    }
    H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if (H==NULL) {
        FatalError("Out of space!");
    }
    H->Elements = (int*)malloc((MaxElements + 1 )*sizeof(ElementType));
    
    if (H->Elements) {
        FatalError("Out of space!");
    }
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = -1;
    return H;
}

void Insert(PriorityQueue H,ElementType X)
{
    int i;
    if (IsFull(H)) {
        Error("PriorityQueue is full!");
    }
    for ( i = ++H->Size; H->Elements[i/2]>X; i/=2) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H)
{
    int i;
    int Child;
    
    ElementType MinElement,LastElement;
    
    if (IsFull(H)) {
        Error("This Queue is full!");
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    
    for (i = 1; i*2<H->Size; i = Child) {
        Child = 2 * i;
        if (Child != H->Size && H->Elements[Child+1]<H->Elements[Child]) {
            Child++;
        }
        if (LastElement > H->Elements[Child]) {
            H->Elements[ i ] = H->Elements[ Child ];
        }
        else{
            break;
        }
    }
    H->Elements[i] = LastElement;
    
    return MinElement;
}
ElementType
FindMin( PriorityQueue H )
{
    if( !IsEmpty( H ) )
        return H->Elements[ 1 ];
    Error( "Priority Queue is Empty" );
    return H->Elements[ 0 ];
}

int
IsEmpty( PriorityQueue H )
{
    return H->Size == 0;
}

int
IsFull( PriorityQueue H )
{
    return H->Size == H->Capacity;
}

void
Destroy( PriorityQueue H )
{
    free( H->Elements );
    free( H );
}


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
