//
//  main.cpp
//  MatrixChain
//
//  Created by 徐 BOWEI on 15/12/15.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string str = "";
int n = 0;
typedef int TwoDimArray[ 5 ][ 5 ];
void OptMatrix( const int C[ ], int N,
          TwoDimArray M, TwoDimArray lastChange )
{
    int i, k, Left, Right;
    int ThisM;
    
    for( Left = 1; Left <= N; Left++ )
        M[ Left ][ Left ] = 0;
    for( k = 1; k < N; k++ )
        for( Left = 1; Left <= N - k; Left++ )
        {
            Right = Left + k;
            M[ Left ][ Right ] = INT16_MAX;
            for( i = Left; i < Right; i++ )
            {
                ThisM = M[ Left ][ i ] + M[ i + 1 ][ Right ]
                + C[ Left - 1 ] * C[ i ] * C[ Right ];
                if( ThisM < M[ Left ][ Right ] )
                {
                    M[ Left ][ Right ] = ThisM;
                    lastChange[ Left ][ Right ] = i;
                }
            }
        }
}

void FindTheWay(TwoDimArray lastChange,int start, int end)
{
    int X = lastChange[start][end];
    if (!X) {
        cout<<str[start - 1];
    }else {
        cout<<"(";
        FindTheWay(lastChange, start, X);
        FindTheWay(lastChange, X + 1, end);
        cout<<")";
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int C[ ] = { 50, 10, 40, 30, 5 };
    for (char c = 'A'; c < 'A' + sizeof(C)/sizeof(int) - 1; c++) {
        str.push_back(c);
    }
    int M[ 5 ][ 5 ] = {{0}}, LastChange[ 5 ][ 5 ] = {{0}};
    int i, j;
    OptMatrix( C, 4, M, LastChange );
       for( i = 1; i <= 4; i++ )
    {
        for( j = 1; j <= 4; j++ )
            printf( "%14d", M[ i ][ j ] );
        printf( "\n" );
    }
    printf("***********************\n");
    for( i = 1; i <= 4; i++ )
    {
        for( j = 1; j <= 4; j++ )
            printf( "%14d", LastChange[ i ][ j ] );
        printf( "\n" );
    }
    cout<<str<<endl;
    FindTheWay(LastChange, 1, 4);
    cout<<endl;
    return 0;
}
