*This project has been created as part of the 42 curriculum by eeravci and mafzal.*

# cub3D

## Description

cub3D is a simple 3D graphics engine inspired by the classic game Wolfenstein 3D. The project was developed using the MiniLibX graphical library and the raycasting technique.

The goal of the project is to render a three-dimensional first-person view from a two-dimensional map described in a `.cub` configuration file.

The project includes:

* Parsing and validation of `.cub` files
* Texture loading and management
* Floor and ceiling color rendering
* Player movement and rotation
* Collision detection
* Raycasting using the DDA algorithm
* Textured wall rendering
* Resource cleanup and memory management

The engine transforms a 2D map into a real-time 3D environment by casting rays from the player's position and calculating wall intersections.

---

## Features

### Map Parsing

The parser supports:

* North texture (`NO`)
* South texture (`SO`)
* West texture (`WE`)
* East texture (`EA`)
* Floor color (`F`)
* Ceiling color (`C`)
* Map data

Example:

```text
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0
```

### Map Validation

The program verifies:

* Valid `.cub` extension
* Presence of all required identifiers
* Valid RGB color format
* Valid texture paths
* Exactly one player position
* Valid map characters
* Closed map boundaries
* No invalid content after the map

### Rendering

The renderer uses:

* Raycasting
* DDA (Digital Differential Analyzer)
* Texture mapping
* Perspective projection

### Controls

| Key | Action        |
| --- | ------------- |
| W   | Move forward  |
| S   | Move backward |
| A   | Strafe left   |
| D   | Strafe right  |
| ←   | Rotate left   |
| →   | Rotate right  |
| ESC | Exit game     |

---

## Instructions

### Compilation

```bash
make
```

### Rebuild

```bash
make re
```

### Clean object files

```bash
make clean
```

### Full clean

```bash
make fclean
```

### Run

```bash
./cub3D maps/example.cub
```

Example:

```bash
./cub3D maps/good/cheese_maze.cub
```

---

## Project Structure

```text
cub3D/
├── includes/
├── libft/
├── maps/
├── minilibx-linux/
├── src/
│   ├── parsing/
│   ├── rendering/
│   ├── player/
│   └── utils/
├── textures/
├── Makefile
└── README.md
```

---

## Technical Choices

### Raycasting

The project uses the raycasting technique to simulate a 3D environment from a 2D map.

For each screen column:

1. A ray is generated.
2. The DDA algorithm searches for a wall hit.
3. The wall distance is calculated.
4. The wall height is projected.
5. Texture pixels are drawn.

### Collision Detection

Player movement is validated before position updates to prevent movement through walls.

### Texture Mapping

Wall textures are loaded from XPM files and sampled directly from image memory.

### Memory Management

The project frees:

* Parsed map data
* Texture paths
* Loaded textures
* Images
* Windows
* MLX resources

Memory usage was verified using Valgrind.

---

## Resources

### Documentation

* MiniLibX Documentation

  * https://harm-smits.github.io/42docs/libs/minilibx

* MiniLibX Linux

  * https://github.com/42Paris/minilibx-linux

* 42 cub3D Subject

### Articles and Tutorials

* Lode's Computer Graphics Tutorial

  * https://lodev.org/cgtutor/raycasting.html

* Permadi Ray Casting Tutorial

  * https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

* Wolfenstein 3D Black Book

  * https://fabiensanglard.net/gebbwolf3d/

### AI Usage

Artificial intelligence tools were used as learning and debugging assistants during development.

AI assistance was used for:

* Understanding raycasting concepts
* Understanding DDA calculations
* Debugging parsing and validation logic
* Memory leak investigation using Valgrind
* Refactoring functions to satisfy Norminette requirements
* Improving code documentation and comments

All design decisions, implementation, testing, debugging, and final code integration were performed and verified manually by the project author.

---
