
# Random Walk Simulation

A colorful visualization of random walkers using SFML ,C++.





https://github.com/user-attachments/assets/6cab4543-5051-4de0-b3db-39fbbfabf1fb




## Features

- Multiple agents performing random walks simultaneously
- Each agent has a unique, randomly generated color
- Smooth movement with configurable number of agents
- Real-time visualization using SFML
- Cross-platform compatibility (Windows, Linux, macOS)

## Prerequisites

- C++17 or later
- CMake 3.10 or later
- SFML 2.5.1 or later 

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/random-walk.git
   cd random-walk
   ```

2. Create a build directory and compile:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

## Usage

Run the program with the following command:

```bash
./RandomWalk [number_of_agents]
```

- `number_of_agents` (optional): Number of random walkers (default: 5)

### Example

To run with 10 agents:
```bash
./RandomWalk 10
```

## How It Works

The simulation creates multiple agents that move randomly in one of four cardinal directions (up, down, left, right) at each step. Each agent leaves a trail of its movement, creating interesting patterns over time.

### Key Components

- **Agents**: Each agent is represented by a small square that moves randomly
- **Colors**: Each agent is assigned a unique, random color using HSV color space for better visual distinction
- **Movement**: At each step, an agent randomly chooses a direction and moves in that direction

## Customization

You can modify the following parameters in the source code:

- `#define HEIGHT 800` - Window height
- `#define WIDTH 600` - Window width
- `window.setFramerateLimit(60)` - Frame rate limit
## Acknowledgments

- [SFML](https://www.sfml-dev.org/) - Simple and Fast Multimedia Library 

---

