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

			const int value = c - '0';
			if (value > 9 || value < 1)
			{
				throw std::runtime_error("Bad number in file: " + c + '\n');
			}
			board[i] = value;
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

bool colValid(int pos, const std::vector<int>& board)
{
	const int col = pos % 9;

	for (int i = col; i < 81; i += 9)
	{
		if (i != pos && board[i] == board[pos])
		{
			return false;
		}
	}
	return true;
}

bool squareValid(int pos, const std::vector<int>& board)
{
	const int row = pos / 9;
	const int col = pos % 9;
	const int squareX = col / 3;
	const int squareY = row / 3;

	const int startPos = squareY * 27 + squareX * 3;

	for (int i = startPos; i < startPos + 3; i++)
	{
		for (int j = 0; j < 9 * 3; j += 9)
		{
			if (i + j != pos && board[i + j] == board[pos])
			{
				return false;
			}
		}
	}
	return true;
}

bool numberValid(int pos, const std::vector<int>& board)
{
	return rowValid(pos, board) && colValid(pos, board) && squareValid(pos, board);
}

int findEmpty(const std::vector<int>& board)
{
	return 1;
}

bool solve(std::vector<int>& board)
{
	return true;
}

int main()
{
	std::vector<int> board(81, 0);

	loadBoard("board.txt", board);
	printBoard(board);

}