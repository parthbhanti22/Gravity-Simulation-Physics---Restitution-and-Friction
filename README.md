
# 🧪 Ball Physics Simulation in C++ using OpenGL & GLFW

This project is a **real-time 2D physics simulation** of a ball bouncing under the effects of **gravity**, **restitution**, and **friction**, rendered using **OpenGL** and managed through the **GLFW** windowing system.

> 🎥 **Demo Video**  
> If GitHub doesn’t support `.webm`, convert it to `.gif` using `ffmpeg` (shown below).

---

## 🎬 Preview

Convert your video for GitHub preview:

```bash
ffmpeg -i video.webm demo.gif
```

Embed with:

```md
![Ball Physics Demo](demo.gif)
```

---

## 📐 Physics Concepts

### 🧲 Gravity

```cpp
vy += gravity * deltaTime;
```

Adds downward acceleration to simulate gravity.

---

### 🚀 Motion Update

```cpp
x += vx * deltaTime;
y += vy * deltaTime;
```

Moves the ball using current velocity.

---

### 🧱 Restitution (Bounce)

```cpp
vy *= -restitution;
```

Bounces the ball with energy loss.

---

### 🧊 Friction

```cpp
vx *= friction;
```

Reduces horizontal speed after bouncing.

---

### 🛑 Stop Condition

```cpp
if (fabs(vy) < 5.0f && y + radius >= 600) {
    vy = 0;
}
```

Stops bouncing when motion is negligible.

---

### ⛔ Boundary Collision

```cpp
if (x - radius <= 0 || x + radius >= 800)
    vx *= -restitution;

if (y - radius <= 0)
    vy *= -restitution;
```

Handles wall and ceiling collisions.

---

## 💻 Main Loop Snippet

```cpp
vy += gravity * deltaTime;
x += vx * deltaTime;
y += vy * deltaTime;

if (y + radius >= 600) {
    y = 600 - radius;
    vy *= -restitution;
    vx *= friction;
} else if (y - radius <= 0) {
    y = radius;
    vy *= -restitution;
}

if (x - radius <= 0) {
    x = radius;
    vx *= -restitution;
} else if (x + radius >= 800) {
    x = 800 - radius;
    vx *= restitution;
}

if (fabs(vy) < 5.0f && y + radius >= 600) {
    vy = 0;
}
```

---

## 🧾 Build Instructions

### 🪟 Windows

```bash
g++ main.cpp -o ball_sim -lglfw3 -lopengl32 -lgdi32
./ball_sim
```

### 🐧 Linux

```bash
g++ main.cpp -o ball_sim -lglfw -lGL
./ball_sim
```

### 🍎 MacOS

```bash
g++ main.cpp -o ball_sim -lglfw -framework OpenGL
./ball_sim
```

---

## 🧠 Learning Outcomes

- Delta time-based motion
- Classical physics application
- Real-time rendering with OpenGL
- Window control using GLFW

---

## 📂 File Structure

```
.
├── main.cpp
├── video.webm
├── demo.gif
└── README.md
```

---

## 🧑‍💻 Author

**Parth Bhanti**  
2nd Year CSE @ VIT Bhopal  
Passionate about computational physics + graphics

---

## 🏛️ License

MIT License.
Use, modify, break, remix — just don't claim you invented Newton.

---
