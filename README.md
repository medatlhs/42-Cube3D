# Raycasting Renderer in C

Cub3D is a 3D visualization project built using raycasting.  
It renders a 3D environment from a 2D map, inspired by Wolfenstein 3D.

## Overview

This project was developed as part of the 42 curriculum, focusing on low-level graphics and how 3D like scenes can be simulated without a real 3D engine.

It demonstrates how perspective, depth, and walls can be rendered using only mathematical calculations and a 2D grid.

## Features

- Player movement (WASD)
- Camera rotation (left/right)
- Wall rendering using raycasting
- Map parsing from `.cub` files
- Collision detection
- Distance-based wall scaling
- Texture mapping and rendering
  
## Built With

- C
- MiniLibX
- trigonometry

## Usage

```bash
git clone https://github.com/yourusername/cub3d.git
cd cub3d
make
./cub3D maps/map.cub
```

## What I Learned

- How raycasting works in practice
- Translating math into visual output
- Handling rendering loops and performance in C
- Managing memory and structures in a graphics context

## Notes

This project is a simplified renderer and not a full 3D engine.  
Its purpose is to understand the fundamentals of rendering and perspective.

---

> "A 3D illusion built from a 2D world."
