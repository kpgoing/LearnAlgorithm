//
//  main.cpp
//  MaxSonString
//
//  Created by 徐 BOWEI on 15/12/16.
//  Copyright © 2015年 徐 BOWEI. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define SIZE 10
void MaxSonString(string str)
{
    int N = (int)str.size();
    int MAX = 1;
    int MAXid = 0;
    vector<int>lengthOfEachChar(N,0);//用于存放f(i)值；
    lengthOfEachChar[0] = 1;//以第a1为末元素的最长递增子序列长度为1；
    for(int i = 1;i<N;i++)//循环n-1次
    {
        lengthOfEachChar[i]=1;//f[i]的最小值为1；
        for(int j=0;j<i;j++)//循环i 次
        {
            if(str[j]<str[i]&&lengthOfEachChar[j]>lengthOfEachChar[i]-1)
                lengthOfEachChar[i]=lengthOfEachChar[j]+1;//更新f[i]的值。
            if(lengthOfEachChar[i] > MAX){
                MAX = lengthOfEachChar[i];
                MAXid = i;
            }
            
        }
    }
    cout<<MAX<<endl;
    cout<<str.substr(MAXid - MAX + 1 ,MAX)<<endl;
}


int main(int argc, const char * argv[]) {
    string str = "abcacacacacacacabcdefaaaa";
    cout<<str<<endl;
    MaxSonString(str);
    return 0;
}
