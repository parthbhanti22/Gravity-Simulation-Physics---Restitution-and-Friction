# 🧪 Ball Physics Simulation in C++ using OpenGL & GLFW

This project is a **real-time 2D physics simulation** of a ball bouncing under the effects of **gravity**, **restitution**, and **friction**, rendered using **OpenGL** and managed through the **GLFW** windowing system.

> 👀 **Demo Video**  
> 🎥 [Click here to view the demo](./video.webm) *(locally, if supported)*  
> Or embed a `.gif` for preview if you're planning to share it on GitHub (GitHub doesn't play `.webm` inline).

---

## 🖼️ Preview (Optional GIF version if needed)

If you'd like to embed a demo directly, convert `video.webm` to `demo.gif`:
```bash
ffmpeg -i video.webm demo.gif
```
![Ball Physics Simulation](demo.gif)

# 🧠 Motivation

This simulation was created to visually demonstrate **Newtonian mechanics** in a game-like environment, focusing on:

* How **gravity** affects objects over time.
* How **energy is conserved or lost** in collisions (via **restitution**).
* How surfaces apply **friction**, reducing velocity.


  # 📐 Physics Concepts in Depth

The core of this simulation is based on the fundamental laws of motion:

## 1. Gravity

**Physics Formula:**
$v_y = v_{y_0} + g \cdot \Delta t$

**Code:**
```cpp
vy += gravity * deltaTime;
```
## 2. Position Update
**Physics Formula:**
s = s + v * Δt

Code:

```cpp
x += vx * deltaTime;
y += vy * deltaTime;
```
Explanation:
The ball’s new position in X and Y is computed using the current velocity and time elapsed. This keeps the movement frame rate independent.

