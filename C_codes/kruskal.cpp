#include<iostream>
using namespace std;
struct ksk
{
  int u,v,w;
}; 

void insertion(ksk arr[],int n)
{
for(int i=1;i<n;i++)
{
  int key=arr[i].w;
  int l=arr[i].u,m=arr[i].v;
  int j=i-1;
while(j>=0&&arr[j].w>key)
 {
   arr[j+1].w=arr[j].w;
   arr[j+1].u=arr[j].u;
   arr[j+1].v=arr[j].v;
   j--;
  }
arr[j+1].w=key;
arr[j+1].u=l;
arr[j+1].v=m;
}
}
void push(int a,int &t,int stack[])
{
  t++;
  stack[t]=a;
}
int pop(int &t,int stack[])
{
 int a=t;
 t--;
 return (stack[a]);
}
  
int check(int u,int v,int *out,int n)
{
int tarr[n],stack[n],top=-1,p=u,m=7,t;
for(int i=0;i<n;i++)
tarr[i]=-1;

while(1)
{
for(int i=0;i<n;i++)
{
    push(p,top,stack);
   if(*(out+n*p+i)!=0&&i!=u)
    push(i,top,stack);  
} 
//cout<<"top"<<top;    //CHECK TOP
//cout<<"RAM";
while(top)
{
   t=pop(top,stack);
  if(t==v)   
   return 1;
  else
   {
     if(tarr[t]!=-5)
       tarr[t]=t;
   }
}
tarr[pop(top,stack)]=-5;

for(int i=0;i<n;i++)
{
  if(tarr[i]==i)
  { t=i;
     break;
  }
  else if(tarr[i]==-5||tarr[i]==-1) 
  {
      t=100;
   }
}
if(t==100)
 return 0;
else
 p=t;
}
}
int main()
{
int n;
cin>>n;
int graph[n][n],output[n][n];
for(int i=0;i<n;i++)
for(int j=0; j<n;j++)
{
  cin>>graph[i][j];
  output[i][j]=0;
}

 ksk tarr[(n*n)/2];
int k=0;

for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++)
{
  if(graph[i][j]!=0)
   {
     tarr[k].w=graph[i][j];
     tarr[k].u=i;
     tarr[k].v=j;
     k++;
   }
} 
insertion(tarr,k);
for(int i=0;i<k;i++)
{
  cout<<tarr[i].u<<","<<tarr[i].v<<"  "<<tarr[i].w<<endl;
}
for(int i=0;i<k;i++)
{
  int c=-1;
  c=check(tarr[i].u,tarr[i].v,&output[0][0],n);
  cout<<c<<"  ";
  if(c==0)
   {
     output[tarr[i].u][tarr[i].v]=tarr[i].w;
     output[tarr[i].v][tarr[i].u]=tarr[i].w;
   }
}
cout<<endl;
for(int i=0;i<n;i++)
{
for(int j=0; j<n;j++)
cout<<output[i][j]<<" ";
cout<<endl;  
}
/*for(int i=0;i<n;i++)
{for(int j=0; j<n;j++)
  cout<<graph[i][j]<<"  ";
 cout<<endl;
}
for(int i=0;i<n;i++)
{for(int j=0; j<n;j++)
  cout<<graph[i][j];
cout<<endl;}
cout<<check(2,0,&graph[0][0],n);*/

return 0;
}
