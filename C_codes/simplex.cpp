/*   SIMPLEX CODE BY PRABHAT KUAMR (RIT2010043) */
/* DUE TO APPROXIMATION SOME VALUE WHICH MUST BE 0 BY LOGIC CAN BE LEFT WITH SOME VALUE WHICH IS VERY VERY SMALL SO CONSIDER IT AS 0 
INPUT FORMAT
2
4
a b c d
x y a b c d 
6 4 1 0 0 0 24
1 2 0 1 0 0 6
-1 1 0 0 1 0 1
0 1 0 0 0 1 2
-5 -4 0 0 0 0 0 
*/
#include<iostream>
using namespace std;
int main()
{
int v,bv;
cin>>v;                    //NUMBER OF NON BASIC VARIABLES
cin>>bv;                   //NUMBER OF BASIC VARIABLES
char BV[bv],V[bv+v];
for(int i=0;i<bv;i++)
cin>>BV[i];                //NAME OF BASIC VARIABLES

for(int i=0;i<bv+v;i++)
cin>>V[i];                 //NAME OF ALL VARIABLES (NON BASIC + BASIC )

float matrix[bv+1][bv+v+1];

for(int i=0;i<bv+1;i++)
for(int j=0;j<bv+v+1;j++)
cin>>matrix[i][j];         //MATRIX INPUT, Z-ROW IN THE LAST

while(1)
{
int c=100,i,r; 
float k=0.0;
for(i=0;i<bv+v+1;i++)
{
  if(matrix[bv][i]+0.005<k)   // 0.005 IS ADDED TO APPROXIMATE TOO SMALL NUMBER eg -0.00005
   {
     k=matrix[bv][i];
     c=i;                  // COLUMN TO BE REPLACED
    }
}
if(c==100)  break;

k=1000.0;
for(i=0;i<bv;i++)
{
  if(matrix[i][c]>0){
  if(matrix[i][bv+v]/matrix[i][c]<k)
   {
      k=matrix[i][bv+v]/matrix[i][c];
      r=i;              //ROW TO BE REPLACED
    }
                     }
}
float pe=matrix[r][c];
BV[r]=V[c];
for(i=0;i<bv+v+1;i++)
matrix[r][i]=matrix[r][i]/pe;

for(i=0;i<bv+1;i++)
{
  if(i!=r)
  {
    float q=matrix[i][c];
    for(int j=0;j<bv+v+1;j++)
       matrix[i][j]=matrix[i][j]-(q*(matrix[r][j]));     
       
   }
}

}
for(int i=0;i<bv+1;i++) {
for(int j=0;j<bv+v+1;j++)
cout<<matrix[i][j]<<"  ";
cout<<endl;             }
for(int i=0;i<bv;i++)
{
 cout<<"\nvalue of variable "<<BV[i]<<" is "<<matrix[i][bv+v];    //VALUE OF ALL VARIABLE LEFT IN BASIC VAR COLUMNN AT OPTIMAL CONDITION
} 
cout<<"\noptimal solution is :"<<matrix[bv][bv+v];
return 0;
}


