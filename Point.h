#ifndef CS2_POINT_H
#define CS2_POINT_H

class Point {
public:
    Point();
    Point(float x, float y);

    void setX(float x);
    void setY(float y);
    float getX() const;
    float getY() const;
    void Display() const;
    float distance(const Point& other) const;

private:
    float x;
    float y;
};

#endif  // CS2_POINT_H
