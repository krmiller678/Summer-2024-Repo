#pragma once
#include "Tile.h"
#include <vector>
using std::vector;

class Board
{
private:
	unsigned int _width;
	unsigned int _height;
	unsigned int _mines;

public:
	
	vector<Tile**> vectOfRows; // vector contains an array of Tile* for each row

	// Constructor
	Board(unsigned int width = 0, unsigned int height = 0, unsigned int mines = 0); // Default

	// Destructor
	~Board(); // delete[] vector.at(i)

	// Setters (Mutators)
	void ResetBoard();
	void SetMines();

	// Getters (Accessors)
	unsigned int GetWidth() const;
	unsigned int GetHeight() const;
	unsigned int GetMines() const;

	// Copy Constructor
	Board(const Board& rhs);

	// Copy Assignment
	Board& operator=(const Board& rhs);

	// Operations
	void PrintBoard() const;
	void CalcSurrounding();
};