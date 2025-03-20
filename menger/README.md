# Menger Sponge

This project implements a Menger Sponge, a 3D fractal structure. The Menger Sponge is a recursive geometric shape that is constructed by subdividing a cube into smaller cubes and removing certain parts based on a specific pattern.

## Description

The Menger Sponge is a fascinating fractal that demonstrates self-similarity and recursion. It is often used in computer graphics and mathematical visualizations.

## Features

- Recursive generation of the Menger Sponge.
- Adjustable levels of recursion to control the complexity of the sponge.

## Usage

1. Clone the repository:
	```
	git clone <repository_url>
	```
2. Compile the code using `gcc`:
	```
	gcc -o menger menger.c
	```
3. Run the program:
	```
	./menger <level>
	```
	Replace `<level>` with the desired level of recursion (e.g., 0, 1, 2, etc.).
