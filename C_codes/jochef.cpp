#include <iostream>
#include <cstdio>
#include <string.h>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int m,n,f;
char *str;
int A[4010][4010];

long long int findla(int hist[],int n)
{
   stack<int> height;
   stack<int> index;
   long long  lA=0;
   int li,lh;
   for(int i=0;i<n;i++)
   {
     
     if(height.empty()||hist[i]>height.top())
     {
       height.push(hist[i]);
       index.push(i);
     }
     else if(hist[i]<height.top())
     { 
       while(1)
       {
         if(height.empty()||hist[i]>=height.top())  break;
         
         li=index.top();
         lh=height.top();
         index.pop();
         height.pop();
         long long  tA=lh*(i-li)*1LL;
         if(tA>lA)
          lA=tA;
       }
       height.push(hist[i]);
       index.push(li);
     }
   }
    while(!height.empty())
    {
      li=index.top();
      lh=height.top();
      index.pop();
      height.pop();
      //cout<<lh<<li<<endl;
      
      long long  tA=lh*(n-li)*1LL;
         if(tA>lA)
          lA=tA;
    } 
    
    return lA;
}

int main()
{	
	str = new char[4010];
	while(1){
	        scanf("%d%d",&n,&m);
		if(m==0 && n==0)
			return 0;
		scanf("%d",&f);
	//	memset(str,'\0',sizeof(str));
		for(int i=0;i<n;i++){
			scanf("%s",str);
		//	int l = strlen(str);
			for(int j=0;j<m;j++){
				if(str[j]=='H')
					A[i][j] = 1;
				else
					A[i][j] = 0;
			} 
		}
		long long int ans=0;
		int tarr[4010];
		for(int i=0;i<n;i++)
		{
                     for(int j=0;j<m;j++)
                       {
                         if(i==0)
                         tarr[j]=A[i][j];
                         else
                          {
                             if(A[i][j]==1)
                              A[i][j]=tarr[j]=1+A[i-1][j];
                             else
                              tarr[j]=0;
                          }
                       }
                       
                       long long int t=findla(tarr,m);
                       if(t>ans)
                       ans=t;
                   }
                   
                      printf("%lld\n",(f*ans));   
                       }
                       
                       //system("pause");
                       return 0;
 }
                     
		
		


