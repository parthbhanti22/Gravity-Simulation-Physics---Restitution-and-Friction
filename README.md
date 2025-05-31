# 🏀 Ball Physics Simulation using C++ | OpenGL + GLFW

A smooth real-time physics simulation of a ball bouncing with **gravity**, **friction**, and **energy loss** — rendered using OpenGL and controlled using GLFW.

> ⚙️ Physics + 🔺 Graphics = 🚀 Pure nerdy satisfaction.

---

## 🎥 Demo

https://user-images.githubusercontent.com/your-username/video.webm  
*(Or use `video.webm` locally if uploading alongside this repo)*




#  bouncing-ball-simulation

A simple yet engaging 2D physics simulation of a bouncing ball, built with C++, GLFW, and OpenGL.

---

## 🧪 Simulation Details

This project brings basic Newtonian physics to life in a 2D environment.

* **Language**: C++
* **Libraries**: GLFW, OpenGL
* **Type**: 2D Physics simulation (bouncing ball)

### Features:

* **Frame-rate independent motion**: Ensures consistent behavior across different hardware.
* **Realistic gravity and restitution**: The ball falls and bounces naturally.
* **Friction**: Horizontal motion slows down after floor impacts.
* **Natural resting state**: The ball eventually settles on the floor.
* **Collision handling**: Detects and responds to collisions with walls and the ceiling.

---

## 🧠 Physics in Code

Here's a breakdown of how core physics concepts are implemented in the code:

| Concept           | Formula             | Code Snippet                               |
| :---------------- | :------------------ | :----------------------------------------- |
| **Gravity** | $v = v_0 + g \cdot \Delta t$ | `vy += gravity * deltaTime;`               |
| **Position Update** | $s = s_0 + v \cdot \Delta t$ | `x += vx * deltaTime;`<br>`y += vy * deltaTime;` |
| **Bounce** | $v = -v_0 \cdot \text{restitution}$ | `vy *= -restitution;`                      |
| **Friction** | $v = v_0 \cdot \text{friction}$ | `vx *= friction;`                          |
| **Stopping Logic** | If $|v_y| < \text{threshold}$ and on ground | `if (fabs(vy) < 5.0f) vy = 0;`            |

---

## 📦 Code Preview

Here’s the core logic from `main.cpp` that drives the simulation:

```cpp
float x = 400.0f, y = 100.0f;
float vx = 100.0f, vy = 0.0f;
float gravity = 980.0f;
float restitution = 0.7f;
float friction = 0.98f;
float radius = 20.0f;

while (!glfwWindowShouldClose(window)) {
    float deltaTime = ...; // calculate time difference

    // Apply gravity
    vy += gravity * deltaTime;

    // Update position
    x += vx * deltaTime;
    y += vy * deltaTime;

    // Bounce off floor
    if (y + radius >= 600) {
        y = 600 - radius;
        vy *= -restitution;
        vx *= friction;
        if (fabs(vy) < 5.0f) vy = 0; // Resting state
    }

    // Wall and ceiling collisions
    if (y - radius <= 0) { // Ceiling
        y = radius;
        vy *= -restitution;
    }
    if (x - radius <= 0) { // Left Wall
        x = radius;
        vx *= -restitution;
    } else if (x + radius >= 800) { // Right Wall
        x = 800 - radius;
        vx *= -restitution; // Also apply restitution for wall bounces
    }

    // Clear & draw
    glClear(GL_COLOR_BUFFER_BIT);
    drawBall(x, y, radius);
    glfwSwapBuffers(window);
    glfwPollEvents();
}
🔗 LinkedIn | 🧠 Particle Pulse

🪪 License
MIT License.
Use, modify, break, remix — just don't claim you invented Newton.
