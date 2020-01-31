#ifndef POINT2_H
#define POINT2_H


class Point2 {
    public:
    Point2(float x = 0.0, float y = 0.0);
    float DistanceBetween(Point2 other);
    int Quadrant();
    void Print();


    private:
    float x;
    float y;


};


#endif 