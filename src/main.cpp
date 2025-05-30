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

    GLFWwindow* window = glfwCreateWindow(800, 600, "Ball Drop", NULL, NULL);
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
    float velocity = 0.0f;
    float gravity = 0.5f;

    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        glClear(GL_COLOR_BUFFER_BIT);

        drawBall(x, y, radius);

        // Apply gravity scaled by deltaTime
        velocity += gravity * deltaTime * 60.0f;  // multiplied by 60 to normalize gravity to approx 60 FPS
        y += velocity * deltaTime * 60.0f;

        if (y - radius > 600) {
            y = -radius;
            velocity = 0.0f;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
