# Tetries

A simple Tetris-like game written in C to better understand low-level programming and C concepts.

---

## Description

Tetries is a minimal 2D block game that helps explore arrays, structs, rendering, and input handling in C.  
The game currently features:

- A 2D array grid representing the board
- A renderer using `ncurses` to display the grid
- An `animate_board` function to move the piece down automatically
- An input handler to move the piece left, right, or instantly down
- A `piece` struct holding the piece's position

---

## Status

- In development
- Core board rendering and piece movement implemented
- Input handling implemented
- Collision detection, multiple shapes, and win/lose logic not yet implemented

---

## Roadmap / TODOs

- [ ] Implement collision detection
- [ ] Support different piece shapes instead of single `#`
- [ ] Add win/lose condition checking

---

## Usage

*(Fill this section with basic usage instructions later, e.g., how to run the game and controls.)*

---

## Contributing

Feel free to fork the repo and submit pull requests.  
This project is meant as a learning tool for C and low-level programming, so all contributions to improve understanding are welcome.

---

## License

[MIT license](LICENSES)
