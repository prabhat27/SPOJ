#include<iostream>
#include<stack>
using namespace std;

void pushbottom(stack<int>&st,int a)
{
	if(st.empty())
	st.push(a);
	else
    {
	int t=st.top();
	st.pop();
	pushbottom(st,a);
	st.push(t);
    }
}
void reverse(stack<int>&st)
{
	if(!st.empty())
	{
	 int t=st.top();
	 st.pop();
	 reverse(st);
	 pushbottom(st,t);
	}
}
int main()
{
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	reverse(st);
	while(!st.empty())
    {
	cout<<st.top()<<" ";
	st.pop();
	}
	
	return 0;
}
