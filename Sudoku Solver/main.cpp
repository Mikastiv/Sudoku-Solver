#include <fstream>
#include <vector>
#include <iostream>
#include <string>

void loadBoard(std::string filename, std::vector<int>& board)
{
	std::ifstream in(filename);

	if (in)
	{
		int i = 0;
		for (char c = in.get(); !in.fail(); c = in.get(), i++)
		{
			if (c == '\n')
			{
				i--;
				continue;
			}
			board[i] = c - '0';
		}
	}
}

void printBoard(std::vector<int>& board)
{
	for (size_t i = 0; i < board.size(); i++)
	{
		if (i % 27 == 0 && i != 0)
		{
			std::cout << "\n---------------------" << std::endl;
		}
		else if (i % 9 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
		else if (i % 3 == 0 && i != 0)
		{
			std::cout << "| ";
		}
		std::cout << board[i] << " ";	
	}
}

bool rowValid(int pos, const std::vector<int>& board)
{
	const int row = pos / 9;

	for (int i = row * 9; i < row * 9 + 9; i++)
	{
		if (i != pos && board[i] == board[pos])
		{
			return false;
		}
	}
	return true;
}

bool rowValid(int pos, const std::vector<int>& board)
{
	const int col = pos % 9;

	for (int i = col; i < col * 9 + 9; i += 9)
	{
		if (i != pos && board[i] == board[pos])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::vector<int> board(81, 0);

	loadBoard("board.txt", board);
	printBoard(board);
}