#pragma once
#include <vector>
using std::vector;

class Tile
{
private:
	unsigned int _surroundingMines;
	unsigned int _reveal;
	unsigned int _mine;
	unsigned int _flag;

public:
	// Constructor
	Tile(); // only need default

	// Setters (Mutators)
	void SetMine(unsigned int mine);
	void SetReveal(unsigned int reveal);
	void SetFlag(unsigned int flag);
	void SetSurrounding(unsigned int surroundingMines);

	// Getters (Accessors)
	unsigned int GetMine() const;
	unsigned int GetReveal() const;
	unsigned int GetFlag() const;
	unsigned int GetSurrounding() const;

	// Operations
	void CalcSurrounding(const vector<Tile**>& board,unsigned int row, unsigned int col);
	void RecursiveReveal(vector<Tile**>& board, unsigned int row, unsigned int col);
};