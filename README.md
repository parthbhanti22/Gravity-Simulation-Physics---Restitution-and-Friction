# Ball Physics Simulation

This project demonstrates a simple 2D ball physics simulation using GLFW and OpenGL. The ball bounces off the walls and floor, exhibiting gravity, restitution (bounciness), and friction.

## Video Demonstration

[video.webm](video.webm)

## Physics Explained

The simulation incorporates several fundamental physics principles:

### 1. Gravity

Gravity constantly accelerates the ball downwards. In the code, this is represented by:

```c
vy += gravity * deltaTime;
