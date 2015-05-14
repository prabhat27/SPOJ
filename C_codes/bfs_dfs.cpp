#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
	int arr[][4]={0,1,1,0,0,0,1,0,1,0,0,1,1,0,0,0};
	bool visited[4];

	for(int j=0;j<4;j++)
	visited[j]=false;
	//DFS
	int s=3,c=0;
	stack<int>st;
	st.push(s);
	visited[s]=true;
	cout<<"DFS: ";
	while(!st.empty())
	{
	int s=st.top();
	st.pop();
	cout<<s<<" ";
	for(int i=0;i<4;i++)
	if(arr[s][i]!=0&&visited[i]==false)
	 { st.push(i); visited[i]=true; }

	}
	//BFS
	for(int j=0;j<4;j++)
	visited[j]=false;
	cout<<endl<<"BFS: ";
	queue<int>que;
	que.push(s);
	visited[s]=true;
    while(!que.empty())
	{
	int s=que.front();
	que.pop();
	cout<<s<<" ";
	for(int i=0;i<4;i++)
	if(arr[s][i]!=0&&visited[i]==false)
	 { que.push(i); visited[i]=true; }
	  
	}
	return 0;

}
