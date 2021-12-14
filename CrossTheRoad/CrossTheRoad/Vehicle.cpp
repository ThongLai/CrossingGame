#include "Vehicle.h"

CVEHICLE::CVEHICLE() : mX(0), mY(0), vehicle_table(NULL), width(0), height(0), text_color(WHITE), bg_color(BLACK) {}

CVEHICLE::~CVEHICLE()
{
	mX = mY = 0;
	width = height = 0;
	text_color = bg_color = 0;
}

void CVEHICLE::RemoveMoving(bool direct)
{
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	// If direct is the right
	if (direct)
	{
		//In case that object is still at the middle of the line
		if (mX + width <= GAMEPLAY_W)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 1; j < width; ++j)
				{
					//Kiem tra xem ky tu ben trai co phai la ky tu ' ' khong, neu phai thi xoa
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j - 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}
		}
		
		//In case that object come to the end of the line
		else if (mX + width > GAMEPLAY_W)
		{
			// We divide the shape into two halves, the first haft of the object is at the   
			// end of the line and the other is at the beginning of the line
			int part2_length = (mX + width) - GAMEPLAY_W;
			int part1_length = width - part2_length;

			// Part1
			for (int i = 0; i < height; ++i)
			{
				for (int j = 1; j < part1_length; ++j)
				{
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j - 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
						}
					}
			}	
								
			// Part2
			for (int i = 0; i < height; ++i)
				{
					for (int j = 0; j < part2_length; ++j)
					{
						if (vehicle_table[i][part1_length + j] != ' ' && vehicle_table[i][part1_length + j - 1] == ' ')
						{
							GotoXY(0 + j, mY + i);
							cout << " ";
						}
					}
				}
	}

		//Delete the last char of object when moving
		for (int i = 0; i < height; ++i)
		{	
			if (vehicle_table[i][0] != ' ')
			{
				GotoXY(mX, mY + i);
				cout << " ";
			}
		}
	}
	// If direct is the left
	else
	{
		//In case that object is still at the middle of the line
		if (mX + width <= GAMEPLAY_W)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width - 1; ++j)
				{	
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j + 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}
			//Delete the last char of object when moving
			for (int i = 0; i < height; ++i)
			{
				if (vehicle_table[i][width - 1] != ' ')
				{
					GotoXY(mX + width - 1, mY + i);
					cout << " ";
				}
			}	
		}
		//In case that object come to the end of the line
		else if (mX + width > GAMEPLAY_W)
		{
			// We divide the shape into two halves, the first haft of the object is at the   
			// end of the line and the other is at the beginning of the line
			int part2_length = (mX + width) - GAMEPLAY_W;
			int part1_length = width - part2_length;

			//Part 1
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < part1_length; ++j)
				{
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j + 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}

			//Part 2
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < part2_length - 1; ++j)
				{
					if (vehicle_table[i][part1_length + j] != ' ' && vehicle_table[i][part1_length + j + 1] == ' ')
					{
						GotoXY(0 + j, mY + i);
						cout << " ";
					}
				}
			}
				
			//Delete the last char of object when moving
			for (int i = 0; i < height; ++i)
			{
				if (vehicle_table[i][width - 1] != ' ')
				{
					GotoXY(0 + part2_length - 1, mY + i);
					cout << " ";
				}
			}
		}
	}
}

void CVEHICLE::Remove()
{
	//Get color of object
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	// If the full object is in the lane
	if (mX >= 0 && mX + width <= GAMEPLAY_W)
	{
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
		//replace all char of the first half object by char ' '
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << string(part1_length, ' ');
		}
		//replace all char of the second half object by char ' '
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(0, iy);
			cout << string(part2_length, ' ');
		}
	}
}

void CVEHICLE::Draw()
{
	//Get color of object
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

	// If the full object is in the lane
	if (mX + width <= GAMEPLAY_W)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; ++j)
			{
				if (vehicle_table[i][j] != ' ')
				{
					GotoXY(mX + j, mY + i);
					cout << vehicle_table[i][j];
				}
			}	
		}		
	}// If haft of the object is at the end of the line 
	 // and the other is at the beginning of the line
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;
		// Print each char of object' s first haft shape
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < part1_length; ++j)
			{
				if (vehicle_table[i].substr(0, part1_length)[j] != ' ')
				{
					GotoXY(mX + j, mY + i);
					cout << vehicle_table[i].substr(0, part1_length)[j];
				}
			}			
		}
		// Print each char of object' s second haft shape
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < part2_length; ++j)
			{
				if (vehicle_table[i].substr(part1_length, part2_length)[j] != ' ')
				{
					GotoXY(0 + j, mY + i);
					cout << vehicle_table[i].substr(part1_length, part2_length)[j];
				}
			}
		}
	}
}

int CVEHICLE::X()
{
	return mX;
}

int CVEHICLE::Y()
{
	return mY;
}

int CVEHICLE::getHeight()
{
	return height;
}

int CVEHICLE::getWidth()
{
	return width;
}

string* CVEHICLE::getFigure()
{
	return vehicle_table;
}

void CVEHICLE::setX(int x)
{
	mX = x;
}

void CVEHICLE::setY(int y)
{
	mY = y;
}

void CVEHICLE::setXY(int x, int y)
{
	mX = x;
	mY = y;
}

void CVEHICLE::setColor(int _text_color, int _bg_color)
{
	text_color = _text_color;
	bg_color = _bg_color;
}