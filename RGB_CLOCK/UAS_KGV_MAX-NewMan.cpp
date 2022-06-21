// TrianglesWithModernOpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "util.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"
#include "Triangle.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Trapesium.h"

#include <vector>
float last_time = 0;
float current_time = 0;
float deltatime = 0;

float xBangunan = 0;
float yBangunan = 0;

vector<Square> square;
vector<Triangle> triangle;
vector<Trapesium> trapesium;
vector<Hexagon> hexagon;
vector<Pentagon> pentagon;
vector<Square> square2;
vector<Hexagon> hexagon2;
//3
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    Triangle t;
    Pentagon p;
    Trapesium tr;
    Hexagon h;
    Square s;
    Square s2;
    Hexagon h2;
    if (action == GLFW_PRESS)
    {
        if (key == GLFW_KEY_LEFT)  xBangunan -= 0.02f;
        if (key == GLFW_KEY_RIGHT) xBangunan += 0.02f;
        if (key == GLFW_KEY_DOWN)  yBangunan -= 0.02f;
        if (key == GLFW_KEY_UP)    yBangunan += 0.02f;
        //wall kiri
        s = Square();
        s.setTranslation(-0.75f + xBangunan, -0.7f + yBangunan, 0.0f);
        s.setScale(0.4f, 0.3f, 1.0f);
        s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
        square[0] = s;

        //benteng kiri
        s = Square();
        s.setTranslation(-0.75f + xBangunan, -0.375f + yBangunan, 0.0f);
        s.setScale(0.15f, 0.35f, 1.0f);
        s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
        square[1] = s;

        tr = Trapesium();
        tr.setTranslation(-0.75f + xBangunan, -0.13f + yBangunan, 0.0f);
        tr.setScale(0.23f, 0.2f, 1.0f);
        tr.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
        trapesium[0] = tr;

        h = Hexagon();
        h.setTranslation(-0.915f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[0] = h;

        h = Hexagon();
        h.setTranslation(-0.845f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[1] = h;

        h = Hexagon();
        h.setTranslation(-0.775f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[2] = h;

        h = Hexagon();
        h.setTranslation(-0.705f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[3] = h;

        h = Hexagon();
        h.setTranslation(-0.635f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[4] = h;

        h = Hexagon();
        h.setTranslation(-0.565f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[5] = h;

        h2 = Hexagon();
        h2.setTranslation(-0.86f + xBangunan, -0.028f + yBangunan, 0.0f);
        h2.setScale(0.035f, 0.035f, 1.0f);
        h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon2[0] = h2;

        h2 = Hexagon();
        h2.setTranslation(-0.79 + xBangunan, -0.028f + yBangunan, 0.0f);
        h2.setScale(0.035f, 0.035f, 1.0f);
        h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon2[1] = h2;

        h2 = Hexagon();
        h2.setTranslation(-0.72 + xBangunan, -0.028f + yBangunan, 0.0f);
        h2.setScale(0.035f, 0.035f, 1.0f);
        h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon2[2] = h2;

        h2 = Hexagon();
        h2.setTranslation(-0.65 + xBangunan, -0.028f + yBangunan, 0.0f);
        h2.setScale(0.035f, 0.035f, 1.0f);
        h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon2[3] = h2;


        //tiang panjang kiri
        s2 = Square();
        s2.setTranslation(-0.49f + xBangunan, -0.3f + yBangunan, 0.0f);
        s2.setScale(0.122f, 1.1f, 1.0f);
        s2.setColor(glm::vec4(0.984f, 1.0f, 0.239f, 1.0f));
        square2[0] = s2;

        //fondasi pintu
        s = Square();
        s.setTranslation(-0.238f + xBangunan, -0.658f + yBangunan, 0.0f);
        s.setScale(0.38f, 0.38f, 1.0f);
        s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
        square[2] = s;

        //tiang panjang kanan
        s = Square();
        s.setTranslation(0.0135f + xBangunan, -0.3f + yBangunan, 0.0f);
        s.setScale(0.122f, 1.1f, 1.0f);
        s.setColor(glm::vec4(0.984f, 1.0f, 0.239f, 1.0f));
        square[3] = s;

        //wall kanan
        s = Square();
        s.setTranslation(0.285f + xBangunan, -0.7f + yBangunan, 0.0f);
        s.setScale(0.42f, 0.3f, 1.0f);
        s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
        square[4] = s;

        h = Hexagon();
        h.setTranslation(0.11f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[6] = h;

        h = Hexagon();
        h.setTranslation(0.18f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[7] = h;

        h = Hexagon();
        h.setTranslation(0.25f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[8] = h;

        h = Hexagon();
        h.setTranslation(0.32f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[9] = h;

        h = Hexagon();
        h.setTranslation(0.39f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[10] = h;

        h = Hexagon();
        h.setTranslation(0.46f + xBangunan, -0.55f + yBangunan, 0.0f);
        h.setScale(0.035f, 0.035f, 1.0f);
        h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
        hexagon[11] = h;

        t = Triangle();
        t.setTranslation(-0.238f + xBangunan, -0.268f + yBangunan, 0.0f);
        t.setScale(0.1915f, 0.2f, 1.0f);
        t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        triangle[0] = t;

        //tiang kiri
        s = Square();
        s.setTranslation(-0.4899f + xBangunan, 0.48f + yBangunan, 0.0f);
        s.setScale(0.008f, 0.1f, 1.0f);
        s.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
        square[5] = s;

        t = Triangle();
        t.setTranslation(-0.49f + xBangunan, 0.352f + yBangunan, 0.0f);
        t.setScale(0.062f, 0.1f, 1.0f);
        t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        triangle[1] = t;

        //tiang kanan
        s = Square();
        s.setTranslation(0.0135f + xBangunan, 0.48f + yBangunan, 0.0f);
        s.setScale(0.008f, 0.1f, 1.0f);
        s.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
        square[6] = s;

        t = Triangle();
        t.setTranslation(0.013f + xBangunan, 0.352f + yBangunan, 0.0f);
        t.setScale(0.062f, 0.1f, 1.0f);
        t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        triangle[2] = t;

        //bendera kanan
        t = Triangle();
        t.setTranslation(0.07f + xBangunan, 0.518f + yBangunan, 0.0f);
        t.setScale(0.062f, 0.02f, 1.0f);
        t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        t.setRotation(60, glm::vec3(1.0f, 1.0f, 0.0f));
        triangle[3] = t;

        //bendera kiri
        t = Triangle();
        t.setTranslation(-0.433f + xBangunan, 0.518f + yBangunan, 0.0f);
        t.setScale(0.062f, 0.02f, 1.0f);
        t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
        t.setRotation(60, glm::vec3(1.0f, 1.0f, 0.0f));
        triangle[4] = t;

        //pintu
        p = Pentagon();
        p.setTranslation(-0.2393f + xBangunan, -0.7f + yBangunan, 0.0f);
        p.setScale(0.1f, 0.15f, 1.0f);
        p.setColor(glm::vec4(1.0f, 0.968f, 0.019f, 1.0f));
        pentagon[0] = p;

        s2 = Square();
        s2.setTranslation(-0.26f + xBangunan, -0.8f + yBangunan, 0.0f);
        s2.setScale(0.035f, 0.1f, 1.0f);
        s2.setColor(glm::vec4(0.949f, 0.850f, 0.811f, 1.0f));
        square2[1] = s2;

        s2 = Square();
        s2.setTranslation(-0.24f + xBangunan, -0.8f + yBangunan, 0.0f);
        s2.setScale(0.003f, 0.1f, 1.0f);
        s2.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
        square2[2] = s2;

        s2 = Square();
        s2.setTranslation(-0.222f + xBangunan, -0.8f + yBangunan, 0.0f);
        s2.setScale(0.035f, 0.1f, 1.0f);
        s2.setColor(glm::vec4(0.949f, 0.850f, 0.811f, 1.0f));
        square2[3] = s2;
    }
}




int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1200, 900, "Max-Newman-A", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    /*
        Dari kode diatas berfungsi membuat windows dengan kuran 640*480 dengan tulisan hellow world
    */

    /* Make the window's context current */
    glfwMakeContextCurrent(window); //disini membuat contextnya yang artinya menjalankan windowsnya

    //3
    glfwSetKeyCallback(window, keyCallback);

    GLenum err = glewInit();


    //2
    Triangle t;
    Pentagon p;
    Trapesium tr;
    Hexagon h;
    Square s;
    Square s2;
    Hexagon h2;

    //wall kiri
    s = Square();
    s.setTranslation(-0.75f, -0.7f, 0.0f);
    s.setScale(0.4f, 0.3f, 1.0f);
    s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
    square.push_back(s);

    //benteng kiri
    s = Square();
    s.setTranslation(-0.75f, -0.375f, 0.0f);
    s.setScale(0.15f, 0.35f, 1.0f);
    s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
    square.push_back(s);

    tr = Trapesium();
    tr.setTranslation(-0.75f, -0.13f, 0.0f);
    tr.setScale(0.23f, 0.2f, 1.0f);
    tr.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
    trapesium.push_back(tr);
    
    h = Hexagon();
    h.setTranslation(-0.915f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(-0.845f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(-0.775f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(-0.705f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(-0.635f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(-0.565f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h2 = Hexagon();
    h2.setTranslation(-0.86f, -0.028f, 0.0f);
    h2.setScale(0.035f, 0.035f, 1.0f);
    h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon2.push_back(h2);

    h2 = Hexagon();
    h2.setTranslation(-0.79, -0.028f, 0.0f);
    h2.setScale(0.035f, 0.035f, 1.0f);
    h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon2.push_back(h2);

    h2 = Hexagon();
    h2.setTranslation(-0.72, -0.028f, 0.0f);
    h2.setScale(0.035f, 0.035f, 1.0f);
    h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon2.push_back(h2);

    h2 = Hexagon();
    h2.setTranslation(-0.65, -0.028f, 0.0f);
    h2.setScale(0.035f, 0.035f, 1.0f);
    h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon2.push_back(h2);


    //tiang panjang kiri
    s2 = Square();
    s2.setTranslation(-0.49f, -0.3f, 0.0f);
    s2.setScale(0.122f, 1.1f, 1.0f);
    s2.setColor(glm::vec4(0.984f, 1.0f, 0.239f, 1.0f));
    square2.push_back(s2);

    //fondasi pintu
    s = Square();
    s.setTranslation(-0.238f, -0.658f, 0.0f);
    s.setScale(0.38f, 0.38f, 1.0f);
    s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
    square.push_back(s);

    //tiang panjang kanan
    s = Square();
    s.setTranslation(0.0135f, -0.3f, 0.0f);
    s.setScale(0.122f, 1.1f, 1.0f);
    s.setColor(glm::vec4(0.984f, 1.0f, 0.239f, 1.0f));
    square.push_back(s);
    
    //wall kanan
    s = Square();
    s.setTranslation(0.285f, -0.7f, 0.0f);
    s.setScale(0.42f, 0.3f, 1.0f);
    s.setColor(glm::vec4(0.713f, 0.709f, 0.666f, 1.0f));
    square.push_back(s);

    h = Hexagon();
    h.setTranslation(0.11f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(0.18f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(0.25f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(0.32f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(0.39f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    h = Hexagon();
    h.setTranslation(0.46f, -0.55f, 0.0f);
    h.setScale(0.035f, 0.035f, 1.0f);
    h.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    hexagon.push_back(h);

    t = Triangle();
    t.setTranslation(-0.238f, -0.268f, 0.0f);
    t.setScale(0.1915f, 0.2f, 1.0f);
    t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
    triangle.push_back(t);


    //tiang kiri
    s = Square();
    s.setTranslation(-0.4899f, 0.48f, 0.0f);
    s.setScale(0.008f, 0.1f, 1.0f);
    s.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    square.push_back(s);

    t = Triangle();
    t.setTranslation(-0.49f, 0.352f, 0.0f);
    t.setScale(0.062f, 0.1f, 1.0f);
    t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
    triangle.push_back(t);
    
    //tiang kanan
    s = Square();
    s.setTranslation(0.0135f, 0.48f, 0.0f);
    s.setScale(0.008f, 0.1f, 1.0f);
    s.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    square.push_back(s);

    t = Triangle();
    t.setTranslation(0.013f, 0.352f, 0.0f);
    t.setScale(0.062f, 0.1f, 1.0f);
    t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));  
    triangle.push_back(t);
    
    //bendera kanan
    t = Triangle();
    t.setTranslation(0.07f, 0.518f, 0.0f);
    t.setScale(0.062f, 0.02f, 1.0f);
    t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
    t.setRotation(60, glm::vec3(1.0f, 1.0f, 0.0f));
    triangle.push_back(t);

    //bendera kiri
    t = Triangle();
    t.setTranslation(-0.433f, 0.518f, 0.0f);
    t.setScale(0.062f, 0.02f, 1.0f);
    t.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
    t.setRotation(60, glm::vec3(1.0f, 1.0f, 0.0f));
    triangle.push_back(t);

    //pintu
    p = Pentagon();
    p.setTranslation(-0.2393f, -0.7f, 0.0f);
    p.setScale(0.1f, 0.15f, 1.0f);
    p.setColor(glm::vec4(1.0f, 0.968f, 0.019f, 1.0f));
    pentagon.push_back(p);

    s2 = Square();
    s2.setTranslation(-0.26f, -0.8f, 0.0f);
    s2.setScale(0.035f, 0.1f, 1.0f);
    s2.setColor(glm::vec4(0.949f, 0.850f, 0.811f, 1.0f));
    square2.push_back(s2);

    s2 = Square();
    s2.setTranslation(-0.24f, -0.8f, 0.0f);
    s2.setScale(0.003f, 0.1f, 1.0f);
    s2.setColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
    square2.push_back(s2);

    s2 = Square();
    s2.setTranslation(-0.222f, -0.8f, 0.0f);
    s2.setScale(0.035f, 0.1f, 1.0f);
    s2.setColor(glm::vec4(0.949f, 0.850f, 0.811f, 1.0f));
    square2.push_back(s2);


    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);


    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glUseProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    Shape* shape;
    /* Dibawah ini adalah loop penggambaran object */
    while (!glfwWindowShouldClose(window))
    {

        current_time = glfwGetTime();
        deltatime = (current_time - last_time);
        last_time = current_time;

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glClearColor(0.160f, 0.996f, 1.0f, 0.0);

        
        //2
        for (int i = 0; i < square.size(); i++)
        {
            glUniform4fv(uColor, 1, &square[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &square[i].getTransformationMat4x4()[0][0]);
            square[i].draw();
        }

        for (int i = 0; i < triangle.size(); i++)
        {
            glUniform4fv(uColor, 1, &triangle[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &triangle[i].getTransformationMat4x4()[0][0]);
            triangle[i].draw();
        }

        for (int i = 0; i < hexagon.size(); i++)
        {
            glUniform4fv(uColor, 1, &hexagon[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &hexagon[i].getTransformationMat4x4()[0][0]);
            hexagon[i].draw();
        }

        for (int i = 0; i < trapesium.size(); i++)
        {
            glUniform4fv(uColor, 1, &trapesium[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &trapesium[i].getTransformationMat4x4()[0][0]);
            trapesium[i].draw();
        }
        for (int i = 0; i < pentagon.size(); i++)
        {
            glUniform4fv(uColor, 1, &pentagon[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &pentagon[i].getTransformationMat4x4()[0][0]);
            pentagon[i].draw();
        }

        for (int i = 0; i < square2.size(); i++)
        {
            glUniform4fv(uColor, 1, &square2[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &square2[i].getTransformationMat4x4()[0][0]);
            square2[i].draw();
        }

        for (int i = 0; i < hexagon2.size(); i++)
        {
            glUniform4fv(uColor, 1, &hexagon2[i].getColor()[0]);
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &hexagon2[i].getTransformationMat4x4()[0][0]);
            hexagon2[i].draw();
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}