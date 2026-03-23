# 🎮 so_long

A small 2D game in C using MiniLibX, developed as part of the 42 curriculum.

## 📖 About

`so_long` is a core project of the 42 curriculum. The goal of this project is to build a simple 2D game using the MiniLibX graphics library, handling map parsing, player movement, collectibles, and win conditions.

## 🎮 Gameplay

The player (chicken) must collect all collectibles (eggs) on the map and then reach the exit (nest) to win.

Controls:
- `↑` — move up
- `↓` — move down
- `←` — move left
- `→` — move right
- `ESC` — close the game

The exit only becomes usable after collecting all items.

## 🧩 What’s Included

This project includes:

- map parsing and validation
- path and map winnability checks
- player movement handling
- window creation and event hooks
- 2D rendering with MiniLibX
- texture and asset usage
- simple sprite animation in the bonus part

## 🗂️ Project Structure

```text
so_long/
├── Makefile
├── README.md
├── .gitignore
├── inc/
│   └── so_long.h
├── src/
│   ├── so_long.c
│   ├── map_convert.c
│   ├── map_validity.c
│   └── ...
├── maps/
│   └── map.ber
├── textures/
│   └── ...
├── libft/
│   └── ...
├── ft_printf/
│   └── ...
├── get_next_line/
│   └── ...
└── mlx_linux/
    └── ...
```

## 🚀 Usage

Clone the repository and move into the project folder:

```bash
git clone https://github.com/bde-luce/so_long.git
cd so_long
```

Compile the project:

```bash
make
```

After compilation, the project generates the `so_long` executable.

Run the program with a valid map file:

```bash
./so_long maps/map.ber
```

## ⚙️ Makefile Rules

The Makefile supports the following commands:

- `make` or `make all` — compiles the project

- `make clean` — removes object files

- `make fclean` — removes object files and the executable

- `make re` — rebuilds everything from scratch


## 📝 Notes

This project is part of the 42 School curriculum. The repository was later reorganized for clearer structure and presentation.
