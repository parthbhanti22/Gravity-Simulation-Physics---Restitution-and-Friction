#include <GLFW/glfw3.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void drawBall(float x, float y, float radius) {
    glColor3f(1.0f, 1.0f, 1.0f); // red ball
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        glVertex2f(x + cosf(angle) * radius, y + sinf(angle) * radius);
    }
    glEnd();
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ball Physics", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable V-sync, caps framerate to monitor refresh rate (~60Hz)


    // Setup 2D projection
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, -1, 1); // origin: top-left
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // gray background

    float x = 400.0f;
    float y = 100.0f;
    float radius = 20.0f;
    float vx = 150.0f;
    float vy = 0.0f;
    float gravity = 980.0f;
    float restitution = 0.7f;
    float friction = 0.98f;

    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        glClear(GL_COLOR_BUFFER_BIT);

        drawBall(x,y,radius);

        vy += gravity*deltaTime;  //vy = uy+gt  (initially uy=0)
        x += vx*deltaTime;  //pos = vel*time
        y += vy*deltaTime;  //pos = vel*time

        //Floor and ceiling collision
        if(y+radius >= 600){
            y = 600-radius;
            vy *= -restitution;  //vy  becomes by*e(coeffecient of restitution)
            vx *= friction; //vx becomes vx*u(coeffecient of friction)
        }

        else if(y-radius <= 0){
            y = radius;
            vy *= -restitution;
        }

        if(x-radius <= 0){
            x = radius;
            vx *= -restitution;
        }
        else if(x+radius >=800){
            x = 800-radius;
            vx *= restitution;
        }

        if(fabs(vy)<5.0f && y+radius>=600){
            vy = 0;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}
