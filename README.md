# Two-Player Tic-Tac-Toe  

## Project Description  
This project is a classic **Tic-Tac-Toe** game designed for two players, implemented in the C programming language. Players take turns marking positions on a 3x3 grid with their respective symbols, `X` and `O`. The first player to align three symbols horizontally, vertically, or diagonally wins the game.  

---

## Features  
- **Game Initialization**:  
  - Random selection of the starting player.  
  - A 3x3 grid with numbered positions (1-9) for easy move selection.  
- **Turn-Based Gameplay**:  
  - Player 1 uses the symbol `X`.  
  - Player 2 uses the symbol `O`.  
- **Input Validation**:  
  - Ensures players only enter numbers between 1 and 9.  
  - Prevents overwriting already marked positions.  
- **Winner Detection**:  
  - Checks for horizontal, vertical, and diagonal alignments.  
- **Draw Scenario**:  
  - Declares a draw if all positions are filled and no player has won.  
- **Replay Option**:  
  - Prompts players to continue or exit after each round.  

---

## How to Run  

1. Clone this repository:  
   ```bash
   git clone https://github.com/yourusername/two-player-tic-tac-toe.git
   cd two-player-tic-tac-toe
