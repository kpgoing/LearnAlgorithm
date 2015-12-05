//
//  main.cpp
//  InsertionSort
//
//  Created by 徐 BOWEI on 15/9/27.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include "InsertioSort.h"

void Insert(ElementType A[],int N){
    int i,j;
    ElementType Tmp;
    for (i = 1; i<N; i++) {
        Tmp = A[i];
        for (j = i; j>0&&A[j-1]>Tmp; j--) {
            A[j] = A[j-1];
        }
        A[j] = Tmp;
    }
}
int main(int argc, const char * argv[]) {
    int a[] = {1,4,2,1,6,23,8567};
    Insert(a, 7);
    for(auto e:a)
    {
        std::cout<<e<<std::endl;
    }
    return 0;
}
