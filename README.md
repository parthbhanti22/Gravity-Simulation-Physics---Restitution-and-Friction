# ⚙️ Ball Physics Simulation using OpenGL & GLFW

This project simulates a simple 2D ball bouncing under the influence of gravity, friction, and elastic collisions using **OpenGL** and **GLFW**. It's a physics-based animation rendered in real-time with frame-capped timing using V-Sync.

> **Demo Video** 📽️  
> ![Video Demo](video.webm)

---

## 🚀 Features

- Realistic ball motion using basic physics equations
- Gravity acceleration, energy loss via restitution, and horizontal velocity decay through friction
- Boundary collision detection and response (floor, ceiling, and walls)
- Frame rate independence using `deltaTime`

---

## 🧪 Physics Concepts Used

This simulation is a tribute to classical mechanics. Here's the breakdown:

### 1. **Gravity**
- **Equation**:  
  `vy += gravity * deltaTime`
- **Explanation**:  
  Constant gravitational acceleration (`g = 980 px/s²`) pulls the ball downward every frame. It updates the vertical velocity `vy` over time.

### 2. **Position Update**
- **Equations**:  
  `x += vx * deltaTime`  
  `y += vy * deltaTime`
- **Explanation**:  
  Positions in X and Y directions are updated using the current velocities. Ensures real-time motion with consistent speed regardless of frame rate.

### 3. **Collision with Floor and Ceiling**
- **Restitution** (bounciness):
  ```cpp
  vy *= -restitution;
Coefficient of restitution e = 0.7 simulates energy loss after bounce. Negative sign reverses the direction of motion.

Friction on horizontal motion:

cpp
Copy code
vx *= friction;
Horizontal velocity gradually reduces after every floor bounce, simulating energy loss due to surface contact.

4. Wall Collision
Similar logic to floor/ceiling, but only affects the X-axis:

cpp
Copy code
vx *= -restitution;
5. Stopping Condition
Prevents infinite tiny bounces:

cpp
Copy code
if(fabs(vy) < 5.0f && y + radius >= 600) vy = 0;
If the vertical velocity is negligible and the ball touches the ground, it is stopped manually to simulate rest.

🧑‍💻 Code Breakdown
cpp
Copy code
// Gravity-based vertical velocity update
vy += gravity * deltaTime;

// Horizontal and vertical position update
x += vx * deltaTime;
y += vy * deltaTime;

// Collision checks
if (y + radius >= 600) { /* Floor bounce */ }
if (x - radius <= 0 || x + radius >= 800) { /* Wall bounce */ }
🛠️ Dependencies
GLFW – window creation and input

OpenGL – for rendering

GLU / GLEW – not directly used here, but often required in larger OpenGL projects

📦 How to Run
🧱 Prerequisites
GLFW installed (e.g., via vcpkg or manually)

OpenGL development environment set up (MinGW, MSVC, etc.)

🔧 Build & Run
bash
Copy code
g++ main.cpp -o ball_sim -lglfw3 -lopengl32 -lgdi32
./ball_sim
Adjust link flags based on your OS and how GLFW/OpenGL is set up.

📂 File Structure
bash
Copy code
.
├── main.cpp            # Ball simulation source code
├── video.webm          # Demo video file
└── README.md           # This file
