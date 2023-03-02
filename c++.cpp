#include <bits/stdc++.h>      
using namespace std;    
#include "Point.h" 
#include "Point.cpp" 
Point Center(Point *C,int n){
    Point a; double sum1=0,sum2=0;Point b;
    for (int i = 0; i < n; i++)
    {
  b=*(C+i);
  sum1+=b.getX();
  sum2+=b.getY();
    }
    a.setX(sum1/n);
    a.setY(sum2/n);
    return a;
}
void close(Point p,Point (*func)(Point*,int), Point *A, Point *B, int n){
    Point s= func(A,n);
    Point d=func(B,n);
    if(p.distance(s)>p.distance(d)){cout<<"B";}
    else{cout<<"A";}
}
int main() { 
srand(time(NULL));    int n;n=200;
 Point *C=new Point[n];
Point *A=new Point[n];
 Point *B=new Point[n];
 Point *ran=new Point[n];
 Point Ra;
for (int i = 0; i < n; i++)
{
 Ra.setX(rand()%21+70);
 Ra.setY(rand()%21+70);
 *(A+i)=Ra;
Ra.setX(rand()%21+20);
Ra.setY(rand()%21+20);
*(B+i)=Ra;
if(i<20){
    Ra.setX(rand()%96+5);
Ra.setY(rand()%96+5);
*(ran+i)=Ra;
}
}
for (int i = 0; i <20; i++)
{
    Point q=*(ran+i);
    close(q,&Center,A,B,n);
}

}
