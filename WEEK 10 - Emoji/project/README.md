# TIC TAC TOE GAME
## Video Demo :https://youtu.be/6rrYM5mfVmg?feature=shared
## Description:
This C program implements a simple Tic-Tac-Toe game where the computer plays against a human. The computer uses the Minimax algorithm to determine the best possible move, making it a challenging opponent.

## FEATURES
**Minimax Algorithm:** The computer's move is determined using the Minimax algorithm, which evaluates all possible moves to find the optimal one.

**Human vs. Computer:** The game is designed for a single player, where the human plays against the computer.

**Dynamic Game Board:** The game board is displayed after each move, showing the current state of the game.

**Winner Declaration:** The game declares the winner (Human or Computer) or a draw if no more moves are left.


## How It Works
**Game Board Setup:** The game board is a 3x3 grid, initially empty. The human player uses the symbol X, and the computer uses the symbol O.

**Move Selection:** The human player selects a move by entering a number from 1 to 9 corresponding to the cells on the grid.
The computer calculates its best move using the Minimax algorithm, which considers all possible future moves and selects the one that maximizes its chances of winning or minimizes the human's chances of winning.

**Game Loop:** The game alternates between the human and the computer until there is a winner or the game ends in a draw.

**End of Game:** The game checks for a winner after each move. If there's a winner, it is declared; otherwise, the game continues until all cells are filled, resulting in a draw.

## Usage
To run the game, compile the C code and execute the program. The game will start with the computer making the first move. Follow the on-screen instructions to play the game.

```bash
gcc tic_tac_toe.c -o tic_tac_toe
./tic_tac_toe
```

<hr/>

![Screenshot 2024-08-12 223424](https://github.com/user-attachments/assets/b530a391-8aa0-4742-b240-8b09b9dfa4e7)
<br/>
![Screenshot 2024-08-13 184213](https://github.com/user-attachments/assets/d8ad3976-2095-4912-ba69-08ae66c7a9f8)
<br/>
![Screenshot 2024-08-13 184239](https://github.com/user-attachments/assets/e9110132-e9f2-4c9b-8c1a-acfb7865dc7a)
<br/>
![Screenshot 2024-08-13 184253](https://github.com/user-attachments/assets/7f1ecc4b-0e02-47a5-9cc7-286127dae372)
<br/>

## Conclusion
This Tic-Tac-Toe game showcases the power of the Minimax algorithm in creating a strong AI opponent. With the computer's ability to evaluate all possible moves and select the optimal one, this implementation provides a challenging and engaging experience for players. Whether you're looking to improve your C programming skills or explore game development and AI algorithms, this project offers a solid foundation. Contributions and suggestions for enhancements are welcome to further refine the game and its features.
