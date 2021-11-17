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
Repeat this until the game ends.

If you win, your window will turn green
If you lose, your window will turn red



==== Project Layout ====
main.cpp starts the application
it creates a stack allocated Game object
calling game.startLoop() loads the neccessary game data and starts the game loop

The game object contains a owns a pointer to a heap-allocated GameState object which contains data about the current state of the game.
The game object also contains a Renderer class which handles all of the rendering and an InputController which handles input.
The input controller polls input each frame and calls appropriate methods on a InputControllerTarget object. The Game class is derived from the
InputControllerTarget class, so that the input controller can control the game.

The game state has references to the board class and to Piece class instances. Each piece instance holds a pointer to a PieceType object 
which determines how the piece operates during gameplay.
Each type of piece Pawn, Knight, Bishop, Rook, Queen, King is derived from the PieceType class.



==== Rubrick Points ====
- Loops Functions I/O 
    The entire project has control structures and loops. Look at the piece files such as piece_queen.cpp in the calculateMoves methods

    Project reads data from a file in renderer.cpp:43 LoadSprite methods

    The input controller class accepts user input input_controller.cpp

- Object Oriented Programming
    Every file is a class. 
    
    Initialization lists (game.cpp:7)

    Each type of piece Pawn, Knight, Bishop, Rook, Queen, King is derived from the PieceType class. All derived piece types override virtual methods.

    Renderer encapulates internal behaviour (renderer.cpp)

    InputControllerTarget base class abstracts implementation details from rest of Programming

    relation_matrix.h is a template class

    Overloaded methods: GameState::addAction(Piece* piece, int x, int y) -and- GameState::addAction(Piece* piece, Cell* cell)

- Memory Management

    Pass by reference (ai.h:18 ) AI::randomize, (renderer.h:32) Renderer::drawRect

    Destructor (sprite.cpp:34) Sprite::~Sprite. Releases SDL resources when destroyed

    Game class uses RAII to contol the creation and cleanup of the Renderer instance

    Sprite class is an example of rule of 5

    game.cpp:23 Uses move semantics to avoid copying a lval string

    Game class uses unique_ptr to handle allocation and deallocation of GameState* 

- Concurrency

    multiple threads are run in Game::loadGameData in game.cpp:19

    use promise and futures in method Pawn::loadSprites in piece_pawn.cpp:12

    mutex is used inside all Renderer class methods that interact with SDL. Example in Renderer::LoadSprite (renderer.cpp:43)
