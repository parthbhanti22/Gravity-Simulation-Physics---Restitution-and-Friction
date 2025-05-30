# 🏀 Ball Physics Simulation using C++ | OpenGL + GLFW

A smooth real-time physics simulation of a ball bouncing with **gravity**, **friction**, and **energy loss** — rendered using OpenGL and controlled using GLFW.

> ⚙️ Physics + 🔺 Graphics = 🚀 Pure nerdy satisfaction.

---

## 🎥 Demo

https://user-images.githubusercontent.com/your-username/video.webm  
*(Or use `video.webm` locally if uploading alongside this repo)*

```html
<!-- Optional: Embed video for GitHub Pages -->
<video width="700" controls>
  <source src="video.webm" type="video/webm">
  Your browser does not support the video tag.
</video>


🧪 Simulation Details
Language: C++

Libraries: GLFW, OpenGL

Type: 2D Physics simulation (bouncing ball)

Features:

Frame-rate independent motion

Realistic gravity and restitution

Friction slows down horizontal motion

Ball comes to rest naturally

Wall and ceiling collision handling

🧠 Physics in Code
Concept	Formula	Code Snippet
Gravity	v = v + g * Δt	vy += gravity * deltaTime;
Position	s = s + v * Δt	x += vx * deltaTime; y += vy * deltaTime;
Bounce	v = -v * restitution	vy *= -restitution;
Friction	v = v * friction	vx *= friction;
Stopping Logic	`if (	v

📦 Code Preview
Here’s the core logic in main.cpp:

cpp
Copy code
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
        if (fabs(vy) < 5.0f) vy = 0;
    }

    // Wall collisions
    if (x - radius <= 0 || x + radius >= 800)
        vx *= -restitution;

    // Clear & draw
    glClear(GL_COLOR_BUFFER_BIT);
    drawBall(x, y, radius);
    glfwSwapBuffers(window);
    glfwPollEvents();
}
📂 File Structure
css
Copy code
.
├── main.cpp         # Simulation source code
├── video.webm       # Demo video (use .gif for GitHub preview)
└── README.md        # This file
🔧 Setup & Build
Requirements
C++ compiler (g++, clang, MSVC)

OpenGL and GLFW installed

🛠️ Compile Commands
Windows (MinGW)
bash
Copy code
g++ main.cpp -o BallSim.exe -lglfw3 -lopengl32 -lgdi32
BallSim.exe
Linux
bash
Copy code
g++ main.cpp -o ball_sim -lglfw -lGL
./ball_sim
macOS
bash
Copy code
g++ main.cpp -o ball_sim -lglfw -framework OpenGL
./ball_sim
🎮 Controls
No keyboard/mouse input needed – it's fully automatic.
Just launch and enjoy the bounce loop.

💡 Enhancements (TODO Ideas)
Add multiple balls with collision response

Custom terrain with slopes

Sound effects on impact

UI sliders to control gravity & restitution

Add rotation / torque mechanics

🔥 Showcase Your Version
Feel free to fork, tweak gravity or friction, and upload your own video.webm or .gif for a cool GitHub portfolio project. You’ll understand 10x more about physics this way than you ever did in class.

👨‍💻 Author
Parth Bhanti
🚀 Computational Physics + Code Enthusiast
🎓 2nd Year CSE @ VIT Bhopal
🔗 LinkedIn | 🧠 Particle Pulse

🪪 License
MIT License.
Use, modify, break, remix — just don't claim you invented Newton.
