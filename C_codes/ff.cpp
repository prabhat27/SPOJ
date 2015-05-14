#include<iostream>
using namespace std;
class complex
{
      float x,y;
      public:
             complex(){}
             complex(float i,float j)
             { x=i; y=j; }
       complex sum(complex,complex);
      friend void show(complex);
};
complex complex:: sum(complex c1,complex c2)
{
        complex c3;
        c3.x=c1.x+c2.x;
        c3.y=c1.y+c2.y;
        return c3;
}
void show(complex c)
{
     cout<<c.x<<"+j"<<c.y;
}

int main()
{
    complex A(2.3,3.5);
    complex B(2.1,3);
    complex C;
    C.sum(A,B);
    cout<<"A: ";show(A);
    cout<<"\nB: ";show(B);
    cout<<"\nC: ";show(C);
    
    system("pause");   
    return 0;
}
