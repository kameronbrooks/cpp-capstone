#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <thread>

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

#define WINDOW_SIZE 800

#define TARGET_FRAME_RATE_MILIS 1000 / 60

enum PieceTeam {White = 0, Black = 1};
enum AIState {Waiting = 0, Calculating = 1};

const int PawnID = 1;
const int KnightID = 2;
const int BishopID = 3;
const int RookID = 4;
const int QueenID = 5;
const int KingID = 6;


#endif