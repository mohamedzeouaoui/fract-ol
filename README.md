*This project has been created as part of the 42 curriculum by mzeouaou.*

<h1 align="center">fract-ol</h1>

<p align="center">
  <em>Explore the infinite beauty of fractals.</em><br>
  A fractal explorer written in C with the MiniLibX graphics library.
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/language-C-blue">
  <img alt="Norm" src="https://img.shields.io/badge/norminette-passing-brightgreen">
  <img alt="42" src="https://img.shields.io/badge/school-42-black">
</p>

---

## Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [The Fractals](#the-fractals)
- [Project Structure](#project-structure)
- [How It Works](#how-it-works)
- [Error Handling](#error-handling)
- [Author](#author)
- [Resources](#resources)

---

## Description

**fract-ol** is a 42 graphics project. It renders fractals in a window and lets you zoom into them endlessly. It is a great introduction to **complex numbers**, **pixel-level rendering** and **event handling** with the **MiniLibX** library.

## Installation

### Requirements

- A UNIX-like system (Linux or macOS)
- `cc` or `gcc`
- `make`
- MiniLibX dependencies (X11 and Xext on Linux)

On Debian/Ubuntu:

```bash
sudo apt-get install build-essential xorg libxext-dev libx11-dev libbsd-dev
```

### Build

```bash
git clone https://github.com/mohamedzeouaoui/fract-ol.git
cd fract-ol
make
```

### Makefile rules

| Rule          | Description                              |
|---------------|------------------------------------------|
| `make`        | Compile the project                      |
| `make clean`  | Remove object files                      |
| `make fclean` | Remove object files and the executable   |
| `make re`     | Recompile from scratch                   |

## Usage

```bash
./fractol <fractal> [parameters]
```

| Command                          | Description                                  |
|----------------------------------|----------------------------------------------|
| `./fractol mandelbrot`           | Display the Mandelbrot set                   |
| `./fractol julia <real> <imag>`  | Display a Julia set for the constant `c = real + imag·i` |

Examples:

```bash
./fractol mandelbrot
./fractol julia -0.8 0.156
./fractol julia 0.285 0.01
./fractol julia -0.4 0.6
```

## Controls

| Input              | Action                                   |
|--------------------|------------------------------------------|
| Mouse wheel up     | Zoom in (towards the cursor)             |
| Mouse wheel down   | Zoom out                                 |
| Arrow keys         | Move the view                            |
| `ESC`              | Quit the program                         |
| Window close button| Quit the program                         |

> Update this table to match your own controls (color change, iterations, etc.).

## The Fractals

### Mandelbrot set

The set of complex numbers `c` for which the sequence below does not escape to infinity:

```text
z(0) = 0
z(n+1) = z(n)² + c
```

### Julia set

Same formula, but `c` is **fixed** (given in the command line) and the starting value `z(0)` is the pixel's position. Each value of `c` gives a different shape.

### Coloring

A point is colored depending on **how many iterations** it takes for `|z|` to exceed 2. Points that never escape (within the maximum number of iterations) belong to the set and use the base color.

## Project Structure

```text
fract-ol/
├── Makefile
├── fractol.h             # Structures and prototypes
├── main.c                # Entry point and argument handling
├── ...                   # Rendering, fractal math, events, utils
└── minilibx/             # MiniLibX (if included)
```

> Adjust this tree to match your own files.

## How It Works

1. **Parse**: the arguments choose the fractal and, for Julia, the constant `c`. Invalid input prints a usage message and exits.
2. **Init**: a MiniLibX window and an image buffer are created.
3. **Map pixels to the complex plane**: each pixel `(x, y)` is converted to a complex number depending on the current zoom and offset.
4. **Iterate**: the fractal formula is repeated until `|z| > 2` or the maximum number of iterations is reached.
5. **Color**: the iteration count selects the color of the pixel, written directly into the image buffer.
6. **Display**: the whole image is pushed to the window at once with `mlx_put_image_to_window`, which is much faster than drawing pixel by pixel.
7. **Events**: key, mouse and close events are handled through MiniLibX hooks. Zooming recomputes the view around the cursor and redraws the image.
8. **Cleanup**: on exit, the image, the window and the display are destroyed, and all memory is freed.

## Error Handling

When the arguments are wrong, the program prints the list of valid parameters and exits cleanly:

```text
Usage: ./fractol <fractal> [parameters]
Available fractals:
  mandelbrot
  julia <real> <imag>
```

## Author

- **Mohamed Zeouaoui**: [@mohamedzeouaoui](https://github.com/mohamedzeouaoui)

## Resources

- [Mandelbrot set (Wikipedia)](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia set (Wikipedia)](https://en.wikipedia.org/wiki/Julia_set)
- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- The 42 Norm

### Use of AI

> Describe here how AI was used in this project (which tasks, which parts), and what you checked and understood yourself.
