#include<iostream>
using namespace std;

void rotate(int arr[][3],int a)
{
     
}
     
int main()
{
    int arr[][3]={1,2,3,4,5,6,7,8,9};
    
    rotate(arr,3);
    
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
    cout<<arr[i][j]<<" ";
    cout<<endl;         }
    
    system("pause");
    return 0;    
}
