#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;
 
//static int arr[131072];
//static int out[262144];
 
struct FastRead {
char *buff, *ptr;
FastRead(int size) {
buff = new char[size];
ptr = buff;
fread(buff, size, 1, stdin);
}
~FastRead() {
delete[] buff;
}
inline int nextInt() {
int ret = 0;
while(*ptr < '0' || *ptr > '9') ptr++;
do { ret = ret * 10 + *ptr++ - '0';
} while(*ptr >= '0' && *ptr <= '9');
return ret;
}
};
 
const int MAX = (1<<18);
struct NODE { int d[3], f; } out[MAX];
 int flag[MAX];
void construct(int l,int u,int k)
{
   if(l==u)
   {
       out[k].d[0]=1;
       out[k].f=0;
       return;
   }
  int L, R, M;
  L = k << 1; R = L + 1;int m= (l + u) >> 1;
construct(l,m,L);
construct(m+1,u,R);
out[k].d[0]=out[L].d[0]+out[R].d[0];
}
 
 
void update(int l, int u,int k, int s, int e)
{
   
  if(l==s&&u==e)
   {
      out[k].f++;
      int a=out[k].d[0];
      int b=out[k].d[1];
      out[k].d[0]=out[k].d[2];
      out[k].d[1]=a;
      out[k].d[2]=b;
      return;
   }
 
 int m= (l + u) >> 1;
 int L = k << 1; int R = L + 1; 
  
  if(l<=s&&e<=m)
    update(l,m,2*k,s,e);
      
  else if(s>m&&e<=u)
    update(m+1,u,2*k+1,s,e);
   
  else
   {
    
      update(l,m,L,s,m);
      update(m+1,u,R,m+1,e);
   }
 
  out[k].d[0] = out[L].d[0] + out[R].d[0];
  out[k].d[1] = out[L].d[1] + out[R].d[1];
  out[k].d[2] = out[L].d[2] + out[R].d[2];
  
  if(out[k].f%3==1)
   {
      int a=out[k].d[0];
      int b=out[k].d[1];
      out[k].d[0]=out[k].d[2];
      out[k].d[1]=a;
      out[k].d[2]=b;
   }
  if(out[k].f%3==2)
   {
      int a=out[k].d[0];
      int b=out[k].d[1];
      out[k].d[0]=b;
      out[k].d[1]=out[k].d[2];
      out[k].d[2]=a;
   }
   
  
}
 
int query(int l, int u,int k, int s, int e,int flip)
{
  if(s==l && e==u) 
  {
    int r=flip%3;
    if(r==1)
     return out[k].d[2];
    if(r==2)
     return out[k].d[1];
     
     return out[k].d[0];
  }
   int m= (l + u) >> 1;
   int L = k << 1; int R = L + 1;
   flip+=out[k].f;
   if(e <= m)
    return query(l,m,L,s,e,flip);
   else if(s > m)
    return query(m+1,u,R,s,e,flip);
   else
    return query(l,m,L,s,m,flip)+query(m+1,u,R,m+1,e,flip);
              
}
 
int main()
{
   int n,q, x,y,ch;
   //scanf("%d%d", &n,&q);
    FastRead r(4194304);
    n = r.nextInt(); q = r.nextInt();
    
   construct(0,n-1,1);
   
 
   while(q--)
    {
      
      //cin>>ch>>x>>y;
      
     ch=r.nextInt();
     x=r.nextInt();
     y=r.nextInt();
     
      if(ch==0)
      { update(0,n-1,1,x,y);
       // for(int i=1;i<=5;i++)
        //cout<<out[i].d[0]<< out[i].d[1]<<out[i].d[2]<<endl;
      } 
      else
      {
        printf("%d\n", query(0,n-1,1,x,y,0));
      }
    }
   
 //system("pause");   
 return 0;
}
