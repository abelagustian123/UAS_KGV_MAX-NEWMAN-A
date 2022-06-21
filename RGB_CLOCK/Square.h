#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Square : public Shape
{
public:
    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Square();

    void draw();

private:
    float vertices[16] = {
       0.5f, 0.5f, 0.75f, 0.25f,
       -0.5f, 0.5f, 0.25f, 0.25,
       -0.5f, -0.5f, 0.25f, 0.75f,
       0.5f, -0.5f, 0.75f, 0.75f
    };

    unsigned int indexArr[6] = {
        0,1,2,
        0,2,3
    };
};

