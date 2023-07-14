# Reversi-using-c
In my Reversi project, implemented in C, I have created a command-line program that allows players to engage in the game of Reversi. The program utilizes a two-dimensional array to represent the game board and includes various functions to handle game logic and player moves.

I start by including necessary C libraries and defining custom functions such as positionInBounds, which checks if a given position is within the bounds of the game board. This ensures that moves are made within the valid range of the board.

To determine the validity of a move in a specific direction, I implemented the checksecond function. It counts the number of opponent pieces in a given direction from a specified position, aiding in capturing the opponent's pieces.

The flipthecolor function plays a crucial role in updating the board after a move is made. It flips the color of the opponent's pieces in the relevant directions, capturing them and ensuring that the player's own color is displayed correctly on the board.

To validate a move, I developed the checkMove function, which checks if a move is legal for a particular color by searching through available move arrays. This ensures that players can only make valid moves according to the game rules.

The printBoard function displays the current state of the game board, providing a visual representation for players to track their progress and make informed decisions.

Additional functions such as checkLegalInDirection and checkLegalInDirectionw determine if a move is legal in a specific direction for black and white pieces, respectively. This ensures that players cannot make illegal moves that violate the game rules.

The makeMove function updates the game board after a move is made and returns the number of opponent pieces captured as a result of that move. It plays a pivotal role in maintaining the game state and enabling the capture of opponent pieces.

Finally, the Wining function calculates the final score of the game and determines the winner based on the number of pieces each player has captured. It provides a conclusive outcome for the game.

In the main function, I prompt the players to input the board size and the color of the computer player. I then initiate the game loop, allowing players to take turns making valid moves until there are no more valid moves available for both players or the board is fully occupied. At the end of the game, the program determines the winner based on the final scores and displays the result accordingly.

Overall, my Reversi project demonstrates my understanding of the game's rules and showcases an interactive game-playing experience through the command-line interface. Players can enjoy the challenge of Reversi and test their strategic skills against either another player or the computer opponent.
