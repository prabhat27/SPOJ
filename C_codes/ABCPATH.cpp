#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include<queue>
using namespace std;

int main()
{
    int r,c,x,y,i,j,t=1;
	char s[59][59];
	int a[59][59],v[59][59];
	int m1[]={-1,0,1,1,1,0,-1,-1};
	int m2[]={-1,-1,-1,0,1,1,1,0};
	int m;
	queue<pair<int,int> > q;
	pair <int,int> p;
	scanf("%d%d",&r,&c);
	while(r!=0 || c!=0)
	{
		m=0;
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		for(i=0;i<r;i++)
			scanf("%s",&s[i]);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(s[i][j]=='A') 
				{	a[i][j]=1; m=1;
					q.push(make_pair(i,j));
				}
			}
		}
		
		while(!q.empty())
		{
			p=q.front(); q.pop();
			for(i=0;i<8;i++)
			{
				x=m1[i]+p.first; y=m2[i]+p.second;

				if(x>=0 && x<r && y>=0 && y<c && (s[x][y]==(1+s[p.first][p.second])))
				{
					if(v[x][y]==0)
					{
						a[x][y]=(1+a[p.first][p.second]);
						v[x][y]=1;
						if(m<a[x][y]) m=a[x][y];
						q.push(make_pair(x,y));
					}
				}
			}
		}
 
		printf("Case %d: %d\n",t,m);
		scanf("%d%d",&r,&c);
		t++;
	}
	//system("pause");
	return 0;
  
}
