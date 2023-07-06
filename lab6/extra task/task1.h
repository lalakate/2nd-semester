#ifndef LAB6_DOP_TASK1_H
#define LAB6_DOP_TASK1_H

#include <iostream>

using namespace std;

class Vector2f{
    float x, y;
public:
    Vector2f(float first = 0, float second = 0){
        x = first;
        y = second;
    }

    Vector2f friend operator+(Vector2f a, Vector2f b);
    Vector2f friend operator-(Vector2f a, Vector2f b);
    Vector2f friend operator*(Vector2f a, Vector2f b);
    Vector2f friend operator/(Vector2f a, Vector2f b);
    Vector2f friend operator+=(Vector2f a, Vector2f b);
    Vector2f friend operator-=(Vector2f a, Vector2f b);
    Vector2f friend operator*=(Vector2f a, Vector2f b);
    Vector2f friend operator/=(Vector2f a, Vector2f b);
    void friend print(Vector2f a);
};

void task1();

#endif //LAB6_DOP_TASK1_H
