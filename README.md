# SFML-anims
Simple SFML based animations/physics models
Made using SFML (Simple and Fast Multimedia library), an animation library for C++

Easiest way to run these would be on a Linux machine or a virtual Linux system

### 1. Install SFML

**Linux (Ubuntu/Debian):**
```bash 
sudo apt-get update
sudo apt-get install libsfml-dev
```
**Linux (Fedora):**
```bash
sudo dnf install SFML-devel
```
**macOS (using Homebrew):**
```bash
brew install sfml
```
### 2. Give Executing permissions to the animating bash script
```bash
chmod +x animate
```
### 3. Run
```bash
./animate 3bodyprob.cpp
./animate blackanim.cpp
```

**N-body Sim**

A 2D N-body gravitational simulation implemented in C++ using the Simple and Fast Multimedia Library (SFML). It models the chaotic orbital mechanics of three mutually interacting masses.

**Technical Implementation**
* **Physics Engine:** Calculates pairwise gravitational acceleration using a modified inverse-square law. 
* **Singularity Softening:** Integrates a distance softening parameter (`+ 300000` in the denominator) to prevent infinite acceleration spikes and simulation instability during near-collisions.
* **Numerical Integration:** Utilizes Euler integration to continuously update velocity and position vectors across a fixed time step (`dt = 0.00166`) ie its technically running on 600fps for smoother movement.
* **State Initialization:** Three coordinate bodies instantiate from rest (zero initial velocity), driven entirely by mutual gravitational attraction.

**"Black-hole" Simulation**

A 2D particle system that visually simulates an accretion disk around a central massive object. It renders 5,000 independent bodies subjected to a central gravitational well, utilizing SFML for high-performance graphics.

**Technical Implementation**
* **Orbital Initialization:** Particles are spawned at random radii and calculated to have perfectly balanced tangential velocities ($v = \sqrt{GM/r}$) to achieve stable circular orbits upon initialization.
* **Central Gravitational Well:** The physics engine calculates continuous centripetal acceleration for all 5,000 particles directed exclusively toward the origin point using the inverse-square law.
* **Motion Trails (Fade Effect):** Instead of executing a hard screen clear each frame, the render loop draws a semi-transparent black overlay (`alpha = 10`). This creates continuous motion blur and visualizes the orbital paths without storing historical position data in memory.
* **Numerical Integration:** Utilizes Euler integration with a granular time step (`dt = 0.0001666`) to maintain orbital stability and minimize numerical drift over time.
