#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <algorithm>
#include<vector>
using namespace std;

bool prime[1000001];
void sieve(int n)
{
   //boolean[] prime=new boolean[n+1];
   //Arrays.fill(prime,true);
   prime[0]=false;
   prime[1]=false;
   int m=(int)sqrt(n);

   for (int i=2; i<=m; i++)
      if (prime[i])
         for (int k=i*i; k<=n; k+=i)
            prime[k]=false;

   return ;
} 



struct node
{
  int val,up;
};
 
static int arr1[10009];
static node out[400000];

void construct(int l,int u,int k)
{
   if(l==u)
   {
        out[k].up=-1;
       if(prime[arr1[l]]==1)
        out[k].val=1;
       else
        out[k].val=0; 
       return;
   }
  int L, R, M;
  L = k << 1; R = L + 1;int m= (l + u) >> 1;
construct(l,m,L);
construct(m+1,u,R);
out[k].val=out[L].val+out[R].val;
out[k].up=-1;
} 

 
void update(int l, int u,int k, int s, int e,int v)
{
   //cout<<l<<" "<<u<<" "<<s<<" "<<e<<endl;
  int L = k << 1; int R = L + 1; int m= (l + u) >> 1;
   if(out[k].up != -1) { // This node needs to be updated
//tree[node] += lazy[node]; // Update it
 if(prime[out[k].up]==1)
   out[k].val=u-l+1;
 else
   out[k].val=0; 
 
if(l != u) {
out[L].up = out[k].up; // Mark child as lazy
out[R].up = out[k].up; // Mark child as lazy
}
 
out[k].up = -1; // Reset it
}
if(l > u || l > e || u < s) // Current segment is not within range [i, j]
return;
if(l >= s && u <= e) { // Segment is fully within range

if(prime[v]==1)
   out[k].val=u-l+1;
 else
   out[k].val=0; 
 
if(l != u) {
out[L].up = v; // Mark child as lazy
out[R].up = v; // Mark child as lazy
}
 
return;
}
 
update(l,m,L,s,e,v);
update(m+1,u,R,s,e,v);

 out[k].val=out[L].val+out[R].val;
   
}

 
int query(int l, int u,int k, int s, int e)
{
  //cout<<out[k].up<<endl;
  int L = k << 1; int R = L + 1;
  if(out[k].up != -1) { // This node needs to be updated
//tree[node] += lazy[node]; // Update it
 if(prime[out[k].up]==1)
   out[k].val=u-l+1;
 else
   out[k].val=0; 
 
if(l != u) {
out[L].up = out[k].up; // Mark child as lazy
out[R].up = out[k].up; // Mark child as lazy
}
}
  if(s==l && e==u) 
  {
    if(out[k].up!=-1)
    {
       if(prime[out[k].up]==1)
        out[k].val=u-l+1;
       else
        out[k].val=0;
        
       if(l != u)
       out[L].up=out[k].up, out[R].up=out[k].up; 
       
       out[k].up=-1;
       
       return out[k].val;
       
    } 
    return out[k].val;  
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
  memset(prime,true,sizeof(prime));
  sieve(1000009);

 int q, x,y,v,t,n,m;
 scanf("%d", &t);
 for(int cs=1;cs<=t;cs++){
  scanf("%d%d", &n,&q);
  
  for(int i=1;i<=n;i++)
  scanf("%d", &arr1[i]);
  
  construct(1,n,1);
  printf("Case %d:\n", cs);
   while(q--)
  {
    scanf("%d",&m);
    if(m==1)
    {
      scanf("%d%d", &x,&y);
      printf("%d\n", query(1,n,1,x,y));
    }
    else
    {
      scanf("%d%d%d", &x,&y,&v);
      update(1,n,1,x,y,v);
      // for(int i=1;i<=9;i++)
  //cout<<i<<" "<<out[i].val<<" "<<out[i].up<<endl;
      
    }
  }
  
 
            }
  //system("pause");
  return 0;
}

