//
//  main.cpp
//  Sort
//
//  Created by 徐 BOWEI on 15/10/2.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
typedef int  ElementType;
void Shellsort(ElementType A[],int N)
{
    int i,j,Increment;
    ElementType Tmp;
    
    for (Increment = N/2;Increment>0 ; Increment/=2) {
        for (i = Increment; i<N; i++) {
            Tmp = A[i];
            for (j = i; j>=Increment; j-=Increment) {
                if (Tmp<A[j-Increment]) {
                    A[j] = A[j - Increment];
                }else{
                    break;
                }
            }
            A[j] = Tmp;
        }
    }
}
#define LeftChild( i )  ( 2 * ( i ) + 1 )

void
Swap( ElementType *Lhs, ElementType *Rhs )
{
    ElementType Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
}
void
PercDown( ElementType A[ ], int i, int N )
{
    int Child;
    ElementType Tmp;
    
    /* 1*/      for( Tmp = A[ i ]; LeftChild( i ) < N; i = Child )
    {
        /* 2*/          Child = LeftChild( i );
        /* 3*/          if( Child != N - 1 && A[ Child + 1 ] > A[ Child ] )
        /* 4*/              Child++;
        /* 5*/          if( Tmp < A[ Child ] )
        /* 6*/              A[ i ] = A[ Child ];
        else
        /* 7*/              break;
    }
    /* 8*/      A[ i ] =Tmp;
}

void
Heapsort( ElementType A[ ], int N )
{
    int i;
    int j = 0;
    /* 1*/      for( i = N / 2; i >= 0; i-- )  /* BuildHeap */
    /* 2*/          PercDown( A, i, N );
    /* 3*/      for( i = N - 1; i > 0; i--,j++ )
    {
        printf("----------%d-----------\n",j);
        for (int i = 0; i < N; i++ ) {
            printf("%d\n",A[i]);
        }
        printf("**************\n");
        /* 4*/          Swap( &A[ 0 ], &A[ i ] );  /* DeleteMax */
        /* 5*/          PercDown( A, 0, i );
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int A[] = {12,2,16,30,28,10,16,20,6,18};
    Heapsort(A, 10);
    return 0;
}
