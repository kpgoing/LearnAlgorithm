//
//  main.cpp
//  Qsort
//
//  Created by 徐 BOWEI on 15/10/9.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#define Cutoff ( 3 )

typedef int ElementType;

void Swap( ElementType *Lhs, ElementType *Rhs )
{
    ElementType Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
}

ElementType Median3( ElementType A[ ], int Left, int Right )
{
    int Center = ( Left + Right ) / 2;
    
    if( A[ Left ] > A[ Center ] )
        Swap( &A[ Left ], &A[ Center ] );
    if( A[ Left ] > A[ Right ] )
        Swap( &A[ Left ], &A[ Right ] );
    if( A[ Center ] > A[ Right ] )
        Swap( &A[ Center ], &A[ Right ] );
    
    //A[ Left ] <= A[ Center ] <= A[ Right ]
    
    Swap( &A[ Center ], &A[ Right - 1 ] );
    return A[ Right - 1 ];                /* 返回轴点 */
}

void
InsertionSort( ElementType A[ ], int N )
{
    int j, P;
    ElementType Tmp;
    
    for( P = 1; P < N; P++ )
    {
        Tmp = A[ P ];
        for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
            A[ j ] = A[ j - 1 ];
        A[ j ] = Tmp;
    }
}
void
Qsort( ElementType A[ ], int Left, int Right )
{
    int i, j;
    ElementType Pivot;
    
    if( Left + Cutoff <= Right )
    {
        Pivot = Median3( A, Left, Right );//选取更合适的中轴点，学习于《算法与数据结构:C语言描述》
        i = Left; j = Right - 1;
        for( ; ; )
        {
            while( A[ ++i ] < Pivot ){ }
            while( A[ --j ] > Pivot ){ }
            if( i < j )
                Swap( &A[ i ], &A[ j ] );
            else
                break;
        }
        Swap( &A[ i ], &A[ Right - 1 ] );
        
        Qsort( A, Left, i - 1 );
        Qsort( A, i + 1, Right );
    }
    else  //如果分部小到一定程度直接采取插入排序
        InsertionSort( A + Left, Right - Left + 1 );
}
void RandArray(ElementType A[ ], int Length)
{
    srand((unsigned int)time(0));//设置随机数种子
    for (int i  = 0; i < Length; i++) {
        A[i] = rand();
    }

}
void PrintArray(ElementType A[ ], int Length)
{
    for (int i = 0; i<Length; i++) {
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int numbers[10] = {0};
    RandArray(numbers,10);
    std::cout<<"before sorting:";
    PrintArray(numbers, 10);
    Qsort(numbers, 0, 9);
    std::cout<<"after sorting:";
    PrintArray(numbers, 10);
    std::cout<<std::endl;
    return 0;
}
