#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Pentagon : public Shape
{
public:
    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Pentagon();

    void draw();

private:
    float vertices[20] = {
       -1.0f,  0.3f, 0.0f , 0.35f,
       -0.7f, -1.0f, 0.15f, 1.0f ,
        0.7f, -1.0f, 0.85f, 1.0f ,
        1.0f,  0.3f, 1.0f , 0.35f,
        0.0f,  1.0f, 0.5f , 0.0f
    };

    unsigned int indexArr[9] = {
        0,1,2,
        0,2,3,
        0,3,4
    };
};

