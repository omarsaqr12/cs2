#ifndef Point_H 
#define Point_H 
class Point { 
private:  
float x;
float y;
 public:
 Point();
 Point(float a ,float b);
void setX(float a); 
void setY(float b);
float getX();
float getY();
void Display();
float distance(Point a);
}; 
#endif
