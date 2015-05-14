#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;

struct node
{
  int sum,ssum;
  queue<pair<int,int> >up;
};

long arr[100009];
node out[400009];

void construct(int l,int u,int k)
{
   if(l==u)
   {
     out[k].sum=arr[l];
     out[k].ssum=arr[l]*arr[l];
     return;
   }
  int L, R, M;
  L = k << 1; R = L + 1;int m= (l + u) >> 1;
construct(l,m,L);
construct(m+1,u,R);
out[k].sum=out[L].sum+out[R].sum;
out[k].ssum=out[L].ssum+out[R].ssum;
} 

void update(int l,int u,int k,int s,int e,int val,int type)
{
   //cout<<l<<" "<<u<<endl;
   int L = k << 1; int R = L + 1; int m= (l + u) >> 1;
   while(!out[k].up.empty())
   {
      //cout<<"RAM"<<endl;
      pair<int,int>p;
      p=out[k].up.front();
      out[k].up.pop();
      if(p.first==1)
      {
         out[k].ssum=out[k].ssum+(u-l+1)*p.second*p.second+2*p.second*out[k].sum;
         out[k].sum=out[k].sum+(u-l+1)*p.second;
      }
      if(p.first==0)
      {
         out[k].ssum=(u-l+1)*p.second*p.second;
         out[k].sum=(u-l+1)*p.second;
      }
      
      if(l!=u)
      {
        out[L].up.push(p);
        out[R].up.push(p);
      }
      
   }
   
   if(l > u || l > e || u < s) // Current segment is not within range [i, j]
     return;
   if(l >= s && u <= e) 
   { // Segment is fully within range
       //cout<<"SHYAM"<<l<<u<<endl;
     if(type==1)
       {
         out[k].ssum=out[k].ssum+(u-l+1)*val*val+2*val*out[k].sum;
         out[k].sum=out[k].sum+(u-l+1)*val;
       }
     if(type==0)
       {
         out[k].ssum=(u-l+1)*val*val;
         out[k].sum=(u-l+1)*val;
       }   
 
     if(l != u) {
          cout<<"RAM";
        out[L].up.push(make_pair(type,val));
        out[R].up.push(make_pair(type,val));
      }
    return;
   }  
   
   update(l,m,L,s,e,val,type);
   update(m+1,u,R,s,e,val,type); 
   
   out[k].ssum=out[L].ssum+out[R].ssum;
   out[k].sum=out[L].sum+out[R].sum;
   
}

int query(int l, int u,int k, int s, int e)
{
  cout<<l<<" "<<u<<endl;
  int L = k << 1; int R = L + 1;
  while(!out[k].up.empty())
   {
      pair<int,int>p;
      p=out[k].up.front();
      out[k].up.pop();
      if(p.first==1)
      {
         out[k].ssum=out[k].ssum+(u-l+1)*p.second*p.second+2*p.second*out[k].sum;
         out[k].sum=out[k].sum+(u-l+1)*p.second;
      }
      if(p.first==0)
      {
         out[k].ssum=(u-l+1)*p.second*p.second;
         out[k].sum=(u-l+1)*p.second;
      }
      
      if(l!=u)
      {
        out[L].up.push(p);
        out[R].up.push(p);
      }
   }
   
   if(s==l && e==u) 
   {
        cout<<l<<u<<k<<endl;
        while(!out[k].up.empty()){
      pair<int,int>p;
      p=out[k].up.front();
      out[k].up.pop();
      if(p.first==1)
      {
         out[k].ssum=out[k].ssum+(u-l+1)*p.second*p.second+2*p.second*out[k].sum;
         out[k].sum=out[k].sum+(u-l+1)*p.second;
      }
      if(p.first==0)
      {
         out[k].ssum=(u-l+1)*p.second*p.second;
         out[k].sum=(u-l+1)*p.second;
      }
      
      if(l!=u)
      {
        out[L].up.push(p);
        out[R].up.push(p);
      }
                                  }  
          return out[k].ssum;
   } 
   
   int m= (l + u) >> 1;
  
   if(e <= m)
    return query(l,m,L,s,e);
   else if(s > m)
    return query(m+1,u,R,s,e);
   else
    return query(l,m,L,s,m)+query(m+1,u,R,m+1,e);
}
     
          

int main()
{
  int t,m,n,q,v,x,y;
  scanf("%d",&t);
  for(int cs=1;cs<=t;cs++)
  {
    
    scanf("%d%d", &n,&q);
    for(int i=1;i<=n;i++)
    scanf("%d", &arr[i]);
    construct(1,n,1);
    printf("Case %d:\n",cs);
    while(q--)
    {
      scanf("%d",&m);
      if(m==2)
      {
       scanf("%d%d", &x,&y);
       printf("%lld\n", query(1,n,1,x,y));
      }
      else
      {
        scanf("%d%d%d", &x,&y,&v);
        update(1,n,1,x,y,v,m);
        cout<<out[6].up.front().first<<out[6].up.front().second<<endl;
        out[6].up.pop();
      }
    }
  }
  
  system("pause");
  return 0;
}
        
    
