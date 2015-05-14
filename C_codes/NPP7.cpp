/*
k largest elements in an array
*/

#include<iostream>
using namespace std;
int arr[]={4,3,2,5,6,7,1,78,43,12};//{2,3,6,5,1,4};//
int n=sizeof(arr)/sizeof(int);

void swap(int *a,int *b)
{
     int t=*a;
     *a=*b;
     *b=t;
}
int partition(int l,int h)
{
    
    int key=arr[h];
    int last=h;
    while(l<h)
    {
      while(key<arr[l])
       l++;
      while(key>=arr[h])
       h--;
       
       if(l<h)
        swap(&arr[l],&arr[h]);
    } 
    swap(&arr[l],&arr[last]);
    
    return l;
}
void quicksort(int l,int h)
{
   if(l<h)
   {
     int a=partition(l,h);
     quicksort(l,a-1);
     quicksort(a+1,h);
   }
}
   
     
int kthlargest(int k)
{
   if(k>=n) return -1;
   int l=0,h=n-1;
   while(1)
   {
     int i=partition(l,h);
     //cout<<i<<endl;
     if(i==k)
      return arr[i];
     if(k<i)
      h=i-1;
     else
      l=i+1;
   }
} 
void buildmaxheap()
{
  for(int i=1;i<n;i++)
  {
      int t=i;
      int p;
      while(t)
      {
        if(t%2==0)
        p=t/2-1;
        else
        p=t/2;
        if(arr[t]>arr[p])
         swap(&arr[t],&arr[p]);
         t=p;
      }
  }  
}
void maxheapdown(int arr[],int a)
{
     int i=0;
     while(2*i+1<=a||2*i+2<=a)
     {
        if(arr[i]<arr[2*i+1]||arr[i]<arr[2*i+2])
        {
           if(arr[2*i+1]>arr[2*i+2])
            {
               swap(&arr[i],&arr[2*i+1]);
               i=2*i+1;
            }
            else
            {
               swap(&arr[i],&arr[2*i+2]);
               i=2*i+2;
            }
        }
        else
         break;
     }
}      
void findklargest(int k)
{
     if(k>n) 
     {
       cout<<-1<<endl;
       return;
     }
      //QUICKSORT METHOD nlogn
      /*
      for(int i=0;i<k;i++)
      cout<<kthlargest(i)<<endl;
       */  
      //MAX HEAP METHOD 
      buildmaxheap();
      int t=n-1;
      for(int i=0;i<k;i++)
      {
        cout<<arr[0]<<endl;
        int m=arr[t];
        arr[t]=arr[0];
        arr[0]=m;
        maxheapdown(arr,--t);
      }
        
      //MIN HEAP METHOD
        
      
      
}      
int main()
{
    int k;
    
    while(1)
    {
      cin>>k;
      if(k==0) break;
      if(k<=n)
      findklargest(k);
      
      cout<<endl;
    }
    
    /*
    quicksort(0,n-1);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    */
    system("pause");
    return 0;
}

