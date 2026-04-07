# SFML-anims
https://github.com/user-attachments/assets/450d9622-e7cd-48bb-b648-10ad6ae99eb8

Simple SFML based animations/physics models
Made using SFML (Simple and Fast Multimedia library), an animation library for C++

Easiest way to run these would be on a Linux machine or a virtual Linux system

**Linux (Ubuntu/Debian):**
```bash 
sudo apt-get update
sudo apt-get install libsfml-dev
```
**Linux (Fedora):**
```bash
sudo dnf install SFML-devel
```
**Give the animating file execution permission**
```bash
chmod +x animate
```

**Run**
```bash
./animate 3bodyprob.cpp
./animate blackanim.cpp
```

**N-body Sim**

A 2D N-body gravitational simulation implemented in C++ using the Simple and Fast Multimedia Library (SFML). It models the chaotic orbital mechanics of three mutually interacting masses.
Calculates pairwise gravitational acceleration using a modified inverse-square law. 

Integrates a distance softening parameter (+ 300000 in the denominator) to prevent infinite acceleration spikes and simulation instability during near-collisions.

Utilizes Euler integration to continuously update velocity and position vectors across a fixed time step (dt = 0.00166) ie its technically running on 600fps for smoother movement.

Three coordinate bodies instantiate from rest (zero initial velocity), driven entirely by mutual gravitational attraction.

**"Black-hole" Simulation**

A 2D particle system that visually simulates an accretion disk around a central massive object. It renders 5,000 independent bodies subjected to a central gravitational well, utilizing SFML for high-performance graphics.

Particles are spawned at random radii and calculated to have perfectly balanced tangential velocities ($v = \sqrt{GM/r}$) to achieve stable circular orbits upon initialization.

The physics engine calculates continuous centripetal acceleration for all 5,000 particles directed exclusively toward the origin point using the inverse-square law.

Instead of executing a hard screen clear each frame, the render loop draws a semi-transparent black overlay (alpha = 10). This creates continuous motion blur and visualizes the orbital paths without storing historical position data in memory.

Utilizes Euler integration with a granular time step (dt = 0.0001666) to maintain orbital stability and minimize numerical drift over time.
