//
//  main.cpp
//  HomeWork1
//
//  Created by 徐 BOWEI on 15/10/25.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef int ElementType;
void showArray(int array[],int size)
{
    for (int i = 0; i < size; i++) {
        std::cout<<array[i]<<" ";
    }
    std::cout<<std::endl;
}
int foo(int numbers[],int start,int end)
{
    int mid = ( start + end ) / 2;
    if (start > end) {
        return 0;
    }
    if (numbers[mid] == mid){
        return mid;
    } else if (start == end) {
        return 0;
    }else if (numbers[mid] > mid ) {
        return  foo(numbers, start, mid - 1);
    }else {
        return  foo(numbers, mid + 1,end);
    }
}

void maopao(int a[],int size)
{
    int i,j,t;
    showArray(a, size);
    for(j=0;j<size;j++)
    {
        for(i=0;i<size-j;i++)
            if(a[i]>a[i+1])	{t=a[i];a[i]=a[i+1];a[i+1]=t;}//交换
        showArray(a, size);
    }
}
/* This file contains a collection of sorting routines */


typedef int ElementType;

void
Swap( ElementType *Lhs, ElementType *Rhs )
{
    ElementType Tmp = *Lhs;
    *Lhs = *Rhs;
    *Rhs = Tmp;
}

/* START: fig7_2.txt */
void
InsertionSort( ElementType A[ ], int N )
{
    int j, P;
    ElementType Tmp;
    
    /* 1*/      for( P = 1; P < N; P++ )
    {
        /* 2*/          Tmp = A[ P ];
        /* 3*/          for( j = P; j > 0 && A[ j - 1 ] > Tmp; j-- )
        /* 4*/              A[ j ] = A[ j - 1 ];
        /* 5*/          A[ j ] = Tmp;
    }
}
/* END */

/* START: fig7_4.txt */
void
Shellsort( ElementType A[ ], int N )
{
    int i, j, Increment;
    ElementType Tmp;
    int n[]={5,3,1};
    /* 1*/      for( int q = 0;q < 3;  q++ )
    {
        Increment = n[q];
    /* 2*/          for( i = Increment; i < N; i++ )
    {
        /* 3*/              Tmp = A[ i ];
        /* 4*/              for( j = i; j >= Increment; j -= Increment )
        /* 5*/                  if( Tmp < A[ j - Increment ] )
        /* 6*/                      A[ j ] = A[ j - Increment ];
        else
        /* 7*/                      break;
        /* 8*/              A[ j ] = Tmp;
    }
     showArray(A, N);
    }
}
/* END */

/* START: fig7_8.txt */

#define LeftChild( i )  ( 2 * ( i ) + 1 )

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
    
    /* 1*/      for( i = N / 2; i >= 0; i-- )  /* BuildHeap */
    /* 2*/          PercDown( A, i, N );
    /* 3*/      for( i = N - 1; i > 0; i-- )
    {
        /* 4*/          Swap( &A[ 0 ], &A[ i ] );  /* DeleteMax */
        /* 5*/          PercDown( A, 0, i );
    }
}
/* END */

/* START: fig7_10.txt */
/* Lpos = start of left half, Rpos = start of right half */

void
Merge( ElementType A[ ], ElementType TmpArray[ ],
      int Lpos, int Rpos, int RightEnd )
{
    int i, LeftEnd, NumElements, TmpPos;
    
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;
    
    /* main loop */
    while( Lpos <= LeftEnd && Rpos <= RightEnd )
        if( A[ Lpos ] <= A[ Rpos ] )
            TmpArray[ TmpPos++ ] = A[ Lpos++ ];
        else
            TmpArray[ TmpPos++ ] = A[ Rpos++ ];
    
    while( Lpos <= LeftEnd )  /* Copy rest of first half */
        TmpArray[ TmpPos++ ] = A[ Lpos++ ];
    while( Rpos <= RightEnd ) /* Copy rest of second half */
        TmpArray[ TmpPos++ ] = A[ Rpos++ ];
    
    /* Copy TmpArray back */
    for( i = 0; i < NumElements; i++, RightEnd-- )
        A[ RightEnd ] = TmpArray[ RightEnd ];
}
/* END */

/* START: fig7_9.txt */
void
MSort( ElementType A[ ], ElementType TmpArray[ ],
      int Left, int Right )
{
    int Center;
    
    if( Left < Right )
    {
        Center = ( Left + Right ) / 2;
        MSort( A, TmpArray, Left, Center );
        MSort( A, TmpArray, Center + 1, Right );
        Merge( A, TmpArray, Left, Center + 1, Right );
        showArray(TmpArray,sizeof(A)/sizeof(int));
    }
}

void
Mergesort( ElementType A[ ], int N )
{
    ElementType *TmpArray;
    
    TmpArray = (int*)malloc( N * sizeof( ElementType ) );
    if( TmpArray != NULL )
    {
        MSort( A, TmpArray, 0, N - 1 );
        free( TmpArray );
    }
    else
        FatalError( "No space for tmp array!!!" );
}
/* END */

/* START: fig7_13.txt */
/* Return median of Left, Center, and Right */
/* Order these and hide the pivot */

ElementType
Median3( ElementType A[ ], int Left, int Right )
{
    int Center = ( Left + Right ) / 2;
    
    if( A[ Left ] > A[ Center ] )
        Swap( &A[ Left ], &A[ Center ] );
    if( A[ Left ] > A[ Right ] )
        Swap( &A[ Left ], &A[ Right ] );
    if( A[ Center ] > A[ Right ] )
        Swap( &A[ Center ], &A[ Right ] );
    
    /* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */
    
    Swap( &A[ Center ], &A[ Right - 1 ] );  /* Hide pivot */
    return A[ Right - 1 ];                /* Return pivot */
}
/* END */

/* START: fig7_14.txt */
#define Cutoff ( 3 )

void
Qsort( ElementType A[ ], int Left, int Right )
{
    int i, j;
    ElementType Pivot;
    
    /* 1*/      if( Left + Cutoff <= Right )
    {
        /* 2*/          Pivot = Median3( A, Left, Right );
        /* 3*/          i = Left; j = Right - 1;
        /* 4*/          for( ; ; )
        {
            /* 5*/              while( A[ ++i ] < Pivot ){ }
            /* 6*/              while( A[ --j ] > Pivot ){ }
            /* 7*/              if( i < j )
            /* 8*/                  Swap( &A[ i ], &A[ j ] );
            else
            /* 9*/                  break;
        }
        /*10*/          Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */
        
        /*11*/          Qsort( A, Left, i - 1 );
        /*12*/          Qsort( A, i + 1, Right );
    }
    else  /* Do an insertion sort on the subarray */
    /*13*/          InsertionSort( A + Left, Right - Left + 1 );
}
/* END */

/* This code doesn't work; it's Figure 7.15. */
#if 0
/* START: fig7_15.txt */
/* 3*/          i = Left + 1; j = Right - 2;
/* 4*/          for( ; ; )
{
    /* 5*/              while( A[ i ] < Pivot ) i++;
    /* 6*/              while( A[ j ] > Pivot ) j--;
    /* 7*/              if( i < j )
    /* 8*/                  Swap( &A[ i ], &A[ j ] );
        else
        /* 9*/                  break;
}
/* END */
#endif

/* START: fig7_12.txt */
void
Quicksort( ElementType A[ ], int N )
{
    Qsort( A, 0, N - 1 );
}
/* END */

/* START: fig7_16.txt */
/* Places the kth smallest element in the kth position */
/* Because arrays start at 0, this will be index k-1 */
void
Qselect( ElementType A[ ], int k, int Left, int Right )
{
    int i, j;
    ElementType Pivot;
    
    /* 1*/      if( Left + Cutoff <= Right )
    {
        /* 2*/          Pivot = Median3( A, Left, Right );
        /* 3*/          i = Left; j = Right - 1;
        /* 4*/          for( ; ; )
        {
            /* 5*/              while( A[ ++i ] < Pivot ){ }
            /* 6*/              while( A[ --j ] > Pivot ){ }
            /* 7*/              if( i < j )
            /* 8*/                  Swap( &A[ i ], &A[ j ] );
            else
            /* 9*/                  break;
        }
        /*10*/          Swap( &A[ i ], &A[ Right - 1 ] );  /* Restore pivot */
        
        /*11*/          if( k <= i )
        /*12*/              Qselect( A, k, Left, i - 1 );
        /*13*/          else if( k > i + 1 )
        /*14*/              Qselect( A, k, i + 1, Right );
    }
    else  /* Do an insertion sort on the subarray */
    /*15*/          InsertionSort( A + Left, Right - Left + 1 );
}
/* END */

/* ROUTINES TO TEST THE SORTS */

void
Permute( ElementType A[ ], int N )
{
    int i;
    
    for( i = 0; i < N; i++ )
        A[ i ] = i;
    for( i = 1; i < N; i++ )
        Swap( &A[ i ], &A[ rand( ) % ( i + 1 ) ] );
}

void
Checksort( ElementType A[ ], int N )
{
    int i;
    for( i = 0; i < N; i++ )
        if( A[ i ] != i )
            printf( "Sort fails: %d %d\n", i, A[ i ] );
    printf( "Check completed\n" );
}

void
Copy( ElementType Lhs[ ], const ElementType Rhs[ ], int N )
{
    int i;
    for( i = 0; i < N; i++ )
        Lhs[ i ] = Rhs[ i ];
}

#define MaxSize 7000
int Arr1[ MaxSize ];
int Arr2[ MaxSize ];

int main(int argc, const char * argv[]) {

    int n[] = {12,2,16,30,28,10,16,20,6,18};
    Mergesort(n, sizeof(n)/sizeof(int));
    showArray(n, sizeof(n)/sizeof(int));
    return 0;
}
