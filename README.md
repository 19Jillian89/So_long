# so_long 🎮

![Language](https://img.shields.io/badge/language-C-blue)  ![Score](https://img.shields.io/badge/score-100%2F100-brightgreen)  ![Status](https://img.shields.io/badge/status-complete-success)  ![Bonus](https://img.shields.io/badge/bonus-in%20progress-yellow)  ![42](https://img.shields.io/badge/42-common%20core-black)

A simple 2D game built with [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) as part of the 42 curriculum.  
The goal of the project is to practice graphics programming, map parsing, and event handling.

---

## 📸 Demo

Here’s a preview of the game in action:

![so_long demo](so_long_demo.gif)

---

## 📝 Mandatory Part

- The number of movements must be displayed in the shell.

- The map must be rectangular. Here is a simple valid map:

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```  
- The map must be enclosed/surrounded by walls. If it is not, the program must
return an error.

- Pressing ESC or clicking the close button should quit the program.

- The map can be composed of only these 5 characters:

0 → Empty space

1 → Wall

C → Collectible (at least one required)

E → Exit (at least one required)

P → Player starting position (only one)

---

## 🎮 Controls:

| Key             | Action       |
|-----------------|--------------|
| **W** / **↑**   | Move up      |
| **A** / **←**   | Move left    |
| **S** / **↓**   | Move down    |
| **D** / **→**   | Move right   |
| **ESC**         | Quit the game|

- The W, A, S, and D keys must be used to move the main character.
- The player should be able to move in these four directions: up, down, left, and
right.
- You are required to use **MiniLibX** for this project.

---

## ▶️ How to compile

- The program should be compiled and executed using:

```bash
./so_long map.ber
./so_long_bonus map.ber
```
---

## 📄 License

This project is for educational purposes only and is part of the 42 Common Core curriculum. [42 Common Core curriculum](https://www.42network.org/),

---

🔗 If you found this project helpful or interesting, consider supporting it by starring ⭐️ or forking.
