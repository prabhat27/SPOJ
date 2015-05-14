/*   SOLUTION OF LINEAR EQUATION CODE BY PRABHAT KUAMR (RIT2010043) 
INPUT FORMAT
3
1 3 -2
3 5 6
2 4 3 

5 7 8
*/
#include<iostream>
#include<math.h>
using namespace std;
void cof(int *arr,int *tarr,int s,int x,int y)
{
int l=0,m;
 for(int i=0;i<s;i++)
 {  if(i!=x)
     {  m=0;
       for(int j=0;j<s;j++)
         if(j!=y)
          { *(tarr+l*(s-1)+m)=*(arr+i*s+j);
              //cout<<*(tarr+l*(s-1)+m);
              m++;
          }
        l++;
      }
 }
}
int mode(int *arr,int s)
{
if(s==2)
return *arr**(arr+3)-*(arr+1)**(arr+2);
int sum=0;
for(int i=0;i<s;i++)
{  int tarr[s-1][s-1];
  cof(arr,&tarr[0][0],s,0,i);
  sum+=pow(-1,i)**(arr+i)*mode(&tarr[0][0],s-1);
  //cout<<mode(&tarr[0][0],s-1)<<endl; 
}
return sum;
}
int main()
{
int s,k=0;
cin>>s;                                          //NUMBER OF VARIABLES 
int arr[s][s],barr[s],sarr[s],tarr[s-1][s-1];
float save[s][s];
for(int i=0;i<s;i++)
for(int j=0;j<s;j++)
cin>>arr[i][j];                                  //INPUT COEFFICIENT MATRIX

for(int i=0;i<s;i++)
cin>>barr[i];                                    //B MATRIX

int m=mode(&arr[0][0],s);
for(int i=0;i<s;i++)
for(int j=0;j<s;j++)
{
  cof(&arr[0][0],&tarr[0][0],s,i,j);
  save[j][i]=float(pow(-1,i+j)*mode(&tarr[0][0],s-1))/float(m);
}

/*for(int i=0;i<s;i++)
{for(int j=0;j<s;j++)
 cout<<save[i][j]<<"  ";   
 cout<<endl;
}*/
for(int i=0;i<s;i++)
{  float sum=0.0;   
 for(int j=0;j<s;j++)
  sum+=float(save[i][j])*float(barr[j]);
 sarr[k]=sum;
 k++;
}
for(int i=0;i<s;i++)
cout<<sarr[i]<<"  ";
return 0;
}  
   
