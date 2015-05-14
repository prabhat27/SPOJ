#include<iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include<vector>
#include<algorithm>
using namespace std;

int find(vector< pair<int,char> > select,char ch,int si,vector< pair<int,char> > aux,int ai)
{
    //cout<<select[si].first<<endl;
    
    if(si<0) return 0;
    
    if(ch=='B')
    {
      if(select[si].second=='C')
       {  return select[si].first+find(aux,'C',ai,select,si-1); }
      if(select[si].second=='B')
       {  return select[si].first+find(select,'B',si-1,aux,ai); }
    }
    if(ch=='C')
    {
       if(select[si].second=='B')
       { return select[si].first+find(aux,'B',ai,select,si-1); }
      if(select[si].second=='C')
       { return select[si].first+find(select,'C',si-1,aux,ai); }
    }
    
   return 0;
}

int main()
{
  vector< pair<int,char> > TBarr;
  vector< pair<int,char> > TCarr;
  vector< pair<int,char> > QBarr;
  vector<pair<int,char> >  QCarr;
  int n,b=0,c=0;
  scanf("%d",&n);
  char str[101];
  while(n--)
  {
    scanf("%s",&str);
    int l=strlen(str);
    if(str[0]=='B')
     {
        if(str[l-1]=='B')
        TBarr.push_back(make_pair(l,str[l-1]));
        else
        QBarr.push_back(make_pair(l,str[l-1]));
        b++;
     }
    else
    {
        if(str[l-1]=='C')
        TCarr.push_back(make_pair(l,str[l-1]));
        else
        QCarr.push_back(make_pair(l,str[l-1]));
        c++;
    }
    
  }
 sort(QBarr.begin(), QBarr.end());
 sort(QCarr.begin(), QCarr.end());
 
 vector< pair<int,char> > Barr;
 vector< pair<int,char> > Carr;
 //cout<<b<<c<<endl;

 for(int i=0;i<b;i++)
  {
    if(i<QBarr.size())
     Barr.push_back(QBarr[i]);
    else
     Barr.push_back(TBarr[i-QBarr.size()]); 
 }
 
 for(int i=0;i<c;i++)
  {
    if(i<QCarr.size())
     Carr.push_back(QCarr[i]);
    else
     Carr.push_back(TCarr[i-QCarr.size()]); 
 }
 
 //for(int i=0;i<Carr.size();i++)
 //cout<<Carr[i].first<<" "<< Carr[i].second<<endl;
  
 printf("%d\n",max(find(Barr,'B',b-1,Carr,c-1),find(Carr,'C',c-1,Barr,b-1)));
 
  
  //system("pause");
  return 0;
}
