#include "Animal.h"

CANIMAL::CANIMAL() : mX(0), mY(0), animal_table(NULL), width(0), height(0), text_color(WHITE), bg_color(BLACK){}

CANIMAL::~CANIMAL()
{
	mX = mY = 0;
	width = height = 0;
	text_color = bg_color = 0;
}

void CANIMAL::RemoveMoving(bool direct)
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	if (direct)
	{
		//Object qua phai
		//Truong hop binh thuong
		if (mX + width <= GAMEPLAY_W)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 1; j < width; ++j)
				{
					//Kiem tra xem ky tu ben trai co phai la ky tu ' ' khong, neu phai thi xoa
					if (animal_table[i][j] != ' ' && animal_table[i][j - 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}
		}
		//Truong hop object toi bien
		else if (mX + width > GAMEPLAY_W)
		{
			//Chia object ra lam 2 part, part 1 la phan con lai cua xe ben man hinh cu, part 2 la phan moi qua khoi man hinh
			int part2_length = (mX + width) - GAMEPLAY_W;
			int part1_length = width - part2_length;


			//Xu ly part1
			for (int i = 0; i < height; ++i)
			{
				for (int j = 1; j < part1_length; ++j)
				{
					//Kiem tra xem ky tu co khac ' ' va ben trai co phai la ky tu ' ' khong, neu dung thi xoa
					if (animal_table[i][j] != ' ' && animal_table[i][j - 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}

			// Xu ly part2
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < part2_length; ++j)
				{
					//Kiem tra xem ky tu co khac ' ' va ben trai co phai la ' ', neu dung thi xoa 
					if (animal_table[i][part1_length + j] != ' ' && animal_table[i][part1_length + j - 1] == ' ')
					{
						GotoXY(0 + j, mY + i);
						cout << " ";
					}
				}
			}
		}

		//Xoa ki tu cuoi cung khi object di chuyen
		for (int i = 0; i < height; ++i)
		{
			//Xoa neu ky tu do khong phai ' '
			if (animal_table[i][0] != ' ')
			{
				GotoXY(mX, mY + i);
				cout << " ";
			}
		}
	}
	else
	{
		//Object qua trai
		//Truong hop binh thuong
		if (mX + width <= GAMEPLAY_W)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width - 1; ++j)
				{
					//Kiem tra xem ky tu co khac ' ' va ben phai co phai la ' ', neu dung thi xoa 
					if (animal_table[i][j] != ' ' && animal_table[i][j + 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}

			//Xoa ki tu cuoi cung khi object di chuyen
			for (int i = 0; i < height; ++i)
			{	//Xoa neu ky tu do khong phai ' '
				if (animal_table[i][width - 1] != ' ')
				{
					GotoXY(mX + width - 1, mY + i);
					cout << " ";
				}
			}
		}
		//Truong hop object toi bien
		else if (mX + width > GAMEPLAY_W)
		{
			//Chia object ra lam 2 part, part 2 la phan con lai cua xe ben man hinh cu, part 1 la phan moi qua khoi man hinh
			int part2_length = (mX + width) - GAMEPLAY_W;
			int part1_length = width - part2_length;

			//Xu ly part 1
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < part1_length; ++j)
				{
					if (animal_table[i][j] != ' ' && animal_table[i][j + 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}
			//Xu ly part 2
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < part2_length - 1; ++j)
				{
					if (animal_table[i][part1_length + j] != ' ' && animal_table[i][part1_length + j + 1] == ' ')
					{
						GotoXY(0 + j, mY + i);
						cout << " ";
					}
				}
			}
			//Xoa ki tu cuoi cung khi object di chuyen
			for (int i = 0; i < height; ++i)
			{
				if (animal_table[i][width - 1] != ' ')
				{
					GotoXY(0 + part2_length - 1, mY + i);
					cout << " ";
				}
			}
		}
	}
}

void CANIMAL::Remove()
{
	//Get color of object
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	// If the full object is in the lane
	if (mX >= 0 && mX + width <= GAMEPLAY_W)
	{
		//replace all char of object by char ' '
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << string(width, ' ');
		}
	}// If haft of the object is at the end of the line 
	 // and the other is at the beginning of the line
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			//replace all char of the first half object by char ' '
			GotoXY(mX, iy);
			cout << string(part1_length, ' ');
		}

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			//replace all char of the second half object by char ' '
			GotoXY(0, iy);
			cout << string(part2_length, ' ');
		}
	}
}

void CANIMAL::Draw()
{
	//Get color of object
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	// If the full object is in the lane
	if (mX + width <= GAMEPLAY_W)
	{
		// print each char of object' s shape
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; ++j)
			{
				if (animal_table[i][j] != ' ') // No need to print ' ' char
				{
					GotoXY(mX + j, mY + i);
					cout << animal_table[i][j];
				}
			}
		}
	}// If haft of the object is at the end of the line 
	 // and the other is at the beginning of the line
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;
		// print each char of object' s first haft shape
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < part1_length; ++j)
			{
				if (animal_table[i].substr(0, part1_length)[j] != ' ') // No need to print ' ' char
				{
					GotoXY(mX + j, mY + i);
					cout << animal_table[i].substr(0, part1_length)[j];
				}
			}
		}
		// print each char of object' s second haft shape
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < part2_length; ++j)
			{
				if (animal_table[i].substr(part1_length, part2_length)[j] != ' ') // No need to print ' ' char
				{
					GotoXY(0 + j, mY + i);
					cout << animal_table[i].substr(part1_length, part2_length)[j];
				}
			}		
		}
	}
}

int CANIMAL::X()
{
	return mX;
}

int CANIMAL::Y()
{
	return mY;
}

int CANIMAL::getHeight()
{
	return height;
}

int CANIMAL::getWidth()
{
	return width;
}

string* CANIMAL::getFigure()
{
	return animal_table;
}



void CANIMAL::setX(int x)
{
	mX = x;
}

void CANIMAL::setY(int y)
{
	mY = y;
}

void CANIMAL::setXY(int x, int y)
{
	mX = x;
	mY = y;
}

void CANIMAL::setColor(int _text_color, int _bg_color)
{
	text_color = _text_color;
	bg_color = _bg_color;
}