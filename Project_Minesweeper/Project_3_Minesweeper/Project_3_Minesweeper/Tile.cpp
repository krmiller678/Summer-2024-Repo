#include "Tile.h"

Tile::Tile() :
	_surroundingMines(0), _reveal(0), _mine(0), _flag(0)
{
}

void Tile::SetMine(unsigned int mine)
{
	_mine = mine;
}

void Tile::SetReveal(unsigned int reveal)
{
	_reveal = reveal;
}

void Tile::SetFlag(unsigned int flag)
{
	_flag = flag;
}

void Tile::SetSurrounding(unsigned int surroundingMines)
{
	_surroundingMines = surroundingMines;
}

unsigned int Tile::GetMine() const
{
	return _mine;
}

unsigned int Tile::GetReveal() const
{
	return _reveal;

}

unsigned int Tile::GetFlag() const
{
	return _flag;

}

unsigned int Tile::GetSurrounding() const
{
	return _surroundingMines;
}

void Tile::CalcSurrounding(const vector<Tile**>& board, unsigned int row, unsigned int col)
{
	_surroundingMines = 0;
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (board.at(row - 1 + i)[col - 1 + j] != nullptr)
			{
				if (board.at(row - 1 + i)[col - 1 + j]->GetMine() == 1)
					_surroundingMines++;
			}
		}
	}
	_surroundingMines -= GetMine();
}

void Tile::RecursiveReveal(vector<Tile**>& board, unsigned int row, unsigned int col)
{
	for (unsigned int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < 3; j++)
		{
			if (board.at(row - 1 + i)[col - 1 + j] != nullptr and !(i == 1 and j == 1))
			{
				if (board.at(row - 1 + i)[col - 1 + j]->GetMine() == 0 and board.at(row - 1 + i)[col - 1 + j]->GetReveal() == 0 and board.at(row - 1 + i)[col - 1 + j]->GetFlag() == 0)
				{
					board.at(row - 1 + i)[col - 1 + j]->SetReveal(1);
					if (board.at(row - 1 + i)[col - 1 + j]->GetSurrounding() == 0)
						board.at(row - 1 + i)[col - 1 + j]->RecursiveReveal(board, (row - 1 + i), (col - 1 + j));
				}
			}
		}
	}
}