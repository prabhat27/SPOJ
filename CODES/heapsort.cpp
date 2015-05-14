#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
     int t=*a;
     *a=*b;
     *b=t;
}
void maxheap(int arr[],int i)
{
     while(i>0)
     {
       if(arr[i]>arr[i/2])
        swap(&arr[i],&arr[i/2]);
       i=i/2;
     }
}
void maxheapdown(int arr[],int n)
{
     int i=1;
     while(2*i<=n)
     {
        if(arr[i]<arr[2*i]||arr[i]<arr[2*i+1])
        {
           if(arr[2*i]>arr[2*i+1])
            {
               swap(&arr[i],&arr[2*i]);
               i=2*i;
            }
            else
            {
               swap(&arr[i],&arr[2*i+1]);
               i=2*i+1;
            }
        }
        else
         break;
     }
}      
int main()
{
   int arr[100];
   int n=1,t=1;
   while(1)
   {
     cin>>n;
     if(n==0)
      break;
     arr[t]=n;
     maxheap(arr,t);
     t++;
   }
   /*
   for(int i=1;i<t;i++)
   cout<<arr[i]<<" ";
   */
   cout<<endl;
   while(t-1)
   {
     cout<<arr[1]<<" ";
     arr[1]=arr[t-1];
     t--;
     maxheapdown(arr,t);
   }
   
   system("pause");
   return 0;
}
     
   
