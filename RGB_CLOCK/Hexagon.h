#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Hexagon : public Shape
{
public:
    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Hexagon();

    void draw();

private:
    float vertices[24] = {
       -1.0f,  0.0f, 0.0f , 0.5f,
       -0.5f, -1.0f, 0.25f, 1.0f ,
        0.5f, -1.0f, 0.75f, 1.0f ,
        1.0f,  0.0f, 1.0f , 0.5f,
        0.5f,  1.0f, 0.75f , 0.0f,
        -0.5f,  1.0f, 0.25f , 0.0f
    };

    unsigned int indexArr[12] = {
        0,1,5,
        1,5,2,
        2,5,4,
        2,4,3
    };
};

