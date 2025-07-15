# ShipStabilityLib 🚢

A **C++ library for ship stability calculations** based on core naval architecture principles.  

It provides ready-to-use functions for **weight, buoyancy, equilibrium, metacentric height (GM), and more**, making it easier to integrate stability checks into your simulation or maritime software.

---

## Features

- Compute buoyant force using Archimedes' principle  
- Evaluate equilibrium difference (floating/sinking states)  
- Extendable modular design for future stability chapters  
- Tested with basic unit tests  

---

## Installation

```bash
git clone https://github.com/alviansm/ShipStabilityLib.git
cd ShipStabilityLib
mkdir build && cd build
cmake ..
make
sudo make install
