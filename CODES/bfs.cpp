#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
	int n,e,u,v;
	//cout<<"enter number of vertices:";
	cin>>n;
	int arr[n][n];
	//cout<<"enter number of edges:";
	cin>>e;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	arr[i][j]=0;

	for(int i=0;i<e;i++)
   {
	cin>>u>>v;
	arr[u][v]=1;
   }
   bool visited[n];
/*
   queue<int>que;
   int s;
   //cout<<"enter the starting node:";
   //cin>>s;
   s=1;
   que.push(s);
   visited[s]=true;
   while(!que.empty())
   {
	s=que.front();
	cout<<s<<" ";
	que.pop();
   for(int i=0;i<n;i++)
   {
	if(!visited[i]&&arr[s][i]!=0)
	 { que.push(i); visited[i]=true; }
   } 
   }
*/
for(int i=0;i<n;i++)
visited[i]=false;

  stack<int>st;
 int s;
 s=0;
 st.push(s);
 visited[s]=true;
 while(!st.empty())
 {
	s=st.top();
	cout<<s<<" ";
	st.pop();
	for(int i=n-1;i>=0;i--)
	if(!visited[i]&&arr[s][i]!=0)
	{ st.push(i); visited[i]=true; }
 }

}
