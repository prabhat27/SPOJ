#include<iostream>
#include<stack>
using namespace std;
int pow(int i,int k)
{
	int ans=1;
	for(int j=0;j<k;j++)
	ans=ans*i;
	return ans;
}
void f(int n)
{
  stack<int>st;
  int r,q;
  while(n>26)
  {
	r=n%26;
    if(r==0)
	{
	st.push(26);
	n=n/26;
	n--;
	}
   else
   {
   st.push(r);
   n=n/26;
   }
  }
  st.push(n);
while(!st.empty())
{ cout<<char('A'+st.top()-1); st.pop(); }
 cout<<endl;

}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	cin>>n;
	//int k;
	f(n);
	//cout<<ans<<endl;
	}
	return 0;
}
