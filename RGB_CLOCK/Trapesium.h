#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Trapesium : public Shape
{
public:
    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Trapesium();

    void draw();

private:
    float vertices[16] = {
       -0.5f, 0.5f, 0.25f, 0.25f,
       -0.4f, -0.5f, 0.3f, 0.75f,
       0.4f, -0.5f, 0.7f, 0.75f,
       0.5f, 0.5f, 0.75f, 0.25f
    };

    unsigned int indexArr[6] = {
        0,1,2,
        0,2,3
    };
};

