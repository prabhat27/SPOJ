#include <iostream>
#include <new>
#include<vector>
using namespace std;
int main()
{
int t;
cin>>t;
while(t-->0)
{
    int m,n,less;
    cin>>m>>n;
    std::vector<int> arr(n-m+1,1);
    for(int i=2;i*i<=n;i++)
    {
        less=m/i;
        less=less*i;
        if(i%2==0 && i>2 && i<=n);
        else
        {
        for(int j=less;j<=n;j+=i)
        {
            if(j!=i && j>=m)
            {
              arr[j-m]=0;
            }
        }
        }
    }
    cout<<endl;
    for(int i=0;i<n-m+1;i++)
    {
        if(arr[i]==1 && i+m!=1)
        {
          cout<<i+m<<endl;
        }
    }
    if(t)
    cout<<endl;
}
  system("pause");
}
