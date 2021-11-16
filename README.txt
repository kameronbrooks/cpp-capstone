Chess (kindof)

==== Building the project ====
this project requires cmake and make
from the project directory, navigate to the build directory with cd build
execute the following commands to build the project:
cmake ..
make

==== Playing the game ====
execute ./chess from the build directory

The player will be playing as the white team and the ai will be playing as the black team
The player will take turns making moves based on the (simplified) rules of chess
https://en.wikipedia.org/wiki/Rules_of_chess

There are a few changes to the normal rules in this version of the game:
1. There is no check, or checkmate. The game is over when a team runs out of moves to make or their king is captured
2. There is no castling move
3. There is no en-passant move
4. There are no time limits
5. Pawns promote automatically to queens when reaching the end of the board

==== Each Turn ====
When your turn starts, select one of your pieces. The selected piece will be highlighted green
Your selected piece will show blue orb icons for cells that it can move to. Click one of the available cells to move the selected piece There
Wait for the AI to make its move. You can see the AI thinking as a purple highlight indicator.

If you win, your window will turn green
If you lose, your window will turn red
