#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

int find(char** s)
{
    //cout<<*(*s)<<endl;
   if (*((*s)++) == 'l') {
        return 0;
    }
    return max(find(s), find(s)) + 1;
  
} 
  
int main()
{
    int t;
    //char arr[12345];
    char* arr = (char*)malloc(12345);
    scanf("%d",&t);
    while(t--)
    {
        cin>>arr;
        cout<<find(&arr)<<endl;
    }
    
    //system("pause");
    return 0;
}      

