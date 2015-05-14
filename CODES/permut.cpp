#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;

bool mycomp(int a,int b)
{
	
	int base_a=log10(a);
	int base_b=log10(b);
	//cout<<base_a<<" "<<base_b;
	int fp_a=a/pow(10,base_a);
	int fp_b=b/pow(10,base_b);
	
	while(fp_a==fp_b)
	{
	base_a--;
	base_b--;
    fp_a=a/pow(10,base_a);
	fp_b=b/pow(10,base_b);
	}
	return (fp_a>fp_b);
}
void permut(int arr[],char *str,int n)
{
	//cout<<n<<endl;
    int l=strlen(str);
	if(n==0)
	{
	 for(int i=0;i<l;i++)
	  cout<<(int)(str[i]);
	cout<<endl;
    return;
	} 
	sort(arr,arr+n,mycomp);

	int temp[n];
	
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	temp[j]=arr[j];

	str[l]=(char)(arr[i]);
	str[l+1]='\0';
	temp[i]=temp[n-1];
	permut(temp,str,n-1);
	}
}
int main()
{
	int arr[]={ 12, 4, 66, 8, 9};
	int n=sizeof(arr)/sizeof(int);
	char temp[100];
	temp[0]='\0';
	permut(arr,temp,n);
	//cout<<(int)(char(3000));
	return 0;
}
