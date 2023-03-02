#include "Point.h" 
#include<iostream>
#include<math.h>
using namespace std; 
Point::Point(){x=0;
y=0;}
Point::Point(float a, float b){x=a;y=b;}
void Point::setX(float a){
  x=a;
}
void Point::setY(float b){
y=b;
}
float Point::getX(){
  return x;
}
float  Point::getY(){
  return y;
}
void Point::Display(){cout<<"("<<x<<", "<<y<<")";}
float Point::distance(Point a){
  return sqrt(pow(x-a.getX(),2)+  pow(y-a.getY(),2));
}

