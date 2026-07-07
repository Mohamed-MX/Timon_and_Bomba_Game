# Timon & Bomba Arcade Game 🐗🦦

A retro 2D arcade-style 2-Player competitive shooting game 🕹️👾🎮 built from scratch in C++ using the OpenGL (GLUT) graphics library and the Windows Multimedia API for sound. Originally developed as a college computer graphics project, players control Timon and Bomba (Pumbaa) in a race to hunt bugs across the African savanna while avoiding penalty-triggering butterflies!

---

## 🎮 Gameplay Preview

https://github.com/user-attachments/assets/7c938b52-31d9-4f9a-ab34-b28838e4e189

---

## ✨ Features

* **Local 2-Player Versus:** Challenge a friend on a single keyboard in a race to reach the winning score first.
* **Risk vs. Reward Scoring:** * **Black Insects:** Target these for **+1 Point**.
  * **Butterflies:** Avoid shooting these! Hitting a butterfly results in a **-1 Point** penalty.
* **Procedural 2D Rendering:** All characters, scenery, trees, and projectiles are hand-coded using raw OpenGL geometric primitives (`GL_POLYGON`, `GL_QUADS`, and `GL_RECTF`).
* **Retro Audio Feedback:** Integrated audio cues for hits, misses, and game completion utilizing the native Windows `PlaySound` API.
* **60 FPS Game Loop:** Smooth entity animation and collision detection driven by GLUT timers.

---

## 🕹️ Controls

| Player | Character | Move Left | Move Right | Fire Projectile |
| :--- | :--- | :---: | :---: | :---: |
| **Player 1** | Timon | `A` | `D` | `W` |
| **Player 2** | Bomba | `J` | `L` | `I` |

---

## 🛠️ Prerequisites & Dependencies

To compile and run this project, your development environment must support the following:

1. **OS:** Windows (required for `<windows.h>` and `PlaySound` audio functionality).
2. **Compiler:** MSVC (Visual Studio) or MinGW with C++11 support.
3. **Graphics Library:** **OpenGL** and **GLUT** (or **FreeGLUT**).
4. **Audio Library:** **WinMM** (Windows Multimedia Library for `.wav` playback).

---

## 🚀 Setup & Compilation (Visual Studio)

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/yourusername/Timon_and_Bomba_Game.git](https://github.com/yourusername/Timon_and_Bomba_Game.git)
   cd Timon_and_Bomba_Game
