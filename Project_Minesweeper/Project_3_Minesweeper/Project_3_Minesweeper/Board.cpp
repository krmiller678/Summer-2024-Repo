#include "Board.h"
#include <iostream>
#include "RNG.h"

Board::Board(unsigned int width, unsigned int height, unsigned int mines) :
	_width(width), _height(height), _mines(mines)
{
	for (unsigned int i = 0; i < _height + 2; i++)
	{
		vectOfRows.push_back(new Tile * [_width + 2]);
		if (i == 0 or i == _height+1)
		{
			for (unsigned int j = 0; j < _width + 2; j++)
				vectOfRows.at(i)[j] = nullptr;
		}
		else
		{
			vectOfRows.at(i)[0] = nullptr;
			vectOfRows.at(i)[_width + 1] = nullptr;
			for (unsigned int j = 1; j < _width + 1; j++)
				vectOfRows.at(i)[j] = new Tile;
		}
	}
	SetMines();
}

Board::~Board()
{
	for (unsigned int i = 0; i < _height + 2; i++)
	{
		for (unsigned int j = 0; j < _width + 2; j++)
			delete vectOfRows.at(i)[j];
		delete[] vectOfRows.at(i);
	}
}

void Board::ResetBoard()
{
	Board newBoard(_width, _height, _mines); // Board to be copy assigned
	*this = newBoard;
}

Board::Board(const Board& rhs)
{
	_width = rhs._width;
	_height = rhs._height;
	_mines = rhs._mines;
	for (unsigned int i = 0; i < _height + 2; i++)
	{
		vectOfRows.push_back(new Tile * [_width + 2]);
		if (i == 0 or i == _height + 1)
		{
			for (unsigned int j = 0; j < _width + 2; j++)
				vectOfRows.at(i)[j] = nullptr;
		}
		else
		{
			vectOfRows.at(i)[0] = nullptr;
			vectOfRows.at(i)[_width + 1] = nullptr;
			for (unsigned int j = 1; j < _width + 1; j++)
			{
				vectOfRows.at(i)[j] = new Tile;
				// Copy Tile
				vectOfRows.at(i)[j]->SetFlag(rhs.vectOfRows.at(i)[j]->GetFlag());
				vectOfRows.at(i)[j]->SetMine(rhs.vectOfRows.at(i)[j]->GetMine());
				vectOfRows.at(i)[j]->SetReveal(rhs.vectOfRows.at(i)[j]->GetReveal());
				vectOfRows.at(i)[j]->SetSurrounding(rhs.vectOfRows.at(i)[j]->GetSurrounding());
			}
		}
	}
}

Board& Board::operator=(const Board& rhs)
{
	for (unsigned int i = 0; i < _height + 2; i++)
	{
		for (unsigned int j = 0; j < _width + 2; j++)
			delete vectOfRows.at(i)[j];
		delete[] vectOfRows.at(i);
	}
	vectOfRows.clear();

	_width = rhs._width;
	_height = rhs._height;
	_mines = rhs._mines;
	for (unsigned int i = 0; i < _height + 2; i++)
	{
		vectOfRows.push_back(new Tile * [_width + 2]);
		if (i == 0 or i == _height + 1)
		{
			for (unsigned int j = 0; j < _width + 2; j++)
				vectOfRows.at(i)[j] = nullptr;
		}
		else
		{
			vectOfRows.at(i)[0] = nullptr;
			vectOfRows.at(i)[_width + 1] = nullptr;
			for (unsigned int j = 1; j < _width + 1; j++)
			{
				vectOfRows.at(i)[j] = new Tile;
				// Copy Tile
				vectOfRows.at(i)[j]->SetFlag(rhs.vectOfRows.at(i)[j]->GetFlag());
				vectOfRows.at(i)[j]->SetMine(rhs.vectOfRows.at(i)[j]->GetMine());
				vectOfRows.at(i)[j]->SetReveal(rhs.vectOfRows.at(i)[j]->GetReveal());
				vectOfRows.at(i)[j]->SetSurrounding(rhs.vectOfRows.at(i)[j]->GetSurrounding());
			}
		}
	}
	return *this;
}

unsigned int Board::GetWidth() const
{
	return _width;
}
unsigned int Board::GetHeight() const
{
	return _height;
}
unsigned int Board::GetMines() const
{
	return _mines;
}

void Board::PrintBoard() const
{
	for (unsigned int i = 0; i < _height + 2; i++)
	{
		for (unsigned int j = 0; j < _width + 2; j++)
		{
			if (vectOfRows.at(i)[j] != nullptr)
				std::cout << vectOfRows.at(i)[j]->GetMine();
			else
				std::cout << 'x';
		}
		std::cout << std::endl;
	}

	for (unsigned int i = 0; i < _height + 2; i++)
	{
		for (unsigned int j = 0; j < _width + 2; j++)
		{
			if (vectOfRows.at(i)[j] != nullptr)
				std::cout << vectOfRows.at(i)[j]->GetSurrounding();
			else
				std::cout << 'x';
		}
		std::cout << std::endl;
	}
}

void Board::SetMines()
{
	unsigned int i = 0;
	while (i < _mines)
	{
		int randomMineY = RNG::Int(1,_height);
		int row = randomMineY;

		int randomMineX = RNG::Int(1, _width);
		int col = randomMineX;
		
		if (vectOfRows.at(row)[col]->GetMine() == 0)
		{
			vectOfRows.at(row)[col]->SetMine(1);
			i++;
		}
	}
	CalcSurrounding();
}

void Board::CalcSurrounding()
{
	for (unsigned int i = 1; i < _height + 1; i++)
	{
		for (unsigned int j = 1; j < _width + 1; j++)
		{
			vectOfRows.at(i)[j]->CalcSurrounding(vectOfRows,i,j);
		}
	}
}