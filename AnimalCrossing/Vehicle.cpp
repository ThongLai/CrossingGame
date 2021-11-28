#include "Vehicle.h"

CVEHICLE::CVEHICLE() : mX(0), mY(0), vehicle_table(NULL), width(0), height(0), text_color(WHITE), bg_color(BLACK) {}

CVEHICLE::~CVEHICLE()
{
	mX = mY = 0;
	width = height = 0;
	text_color = bg_color = 0;
}

void CVEHICLE::Tell()
{
	//ANIMAL CRYING SOUND HERE
}

//void CVEHICLE::RemoveMoving(bool direct)
//{
//	Status SavedStatus;
//	SetTextColor(SavedStatus.getColor());
//
//	if (direct)
//	{
//		for (int i = 0; i < height; ++i)
//		{
//			GotoXY(mX, mY + i);
//			cout << " ";
//		}
//
//		return;
//	}
//	else
//	{
//		if (mX + width <= GAMEPLAY_W)
//		{
//			for (int i = 0; i < height; ++i)
//			{
//				GotoXY(mX + width - 1, mY + i);
//				cout << " ";
//			}
//
//			return;
//		}
//		else if (mX + width > GAMEPLAY_W)
//		{
//			int part2_length = (mX + width) - GAMEPLAY_W;
//			int part1_length = width - part2_length;
//
//			for (int i = 0; i < height; ++i)
//			{
//				GotoXY(0 + part2_length - 1, mY + i);
//				cout << " ";
//			}
//
//			return;
//		}
//	}
//}

void CVEHICLE::RemoveMoving(bool direct)
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
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j - 1] == ' ')
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
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j - 1] == ' ')
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
						if (vehicle_table[i][part1_length + j] != ' ' && vehicle_table[i][part1_length + j - 1] == ' ')
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
			if (vehicle_table[i][0] != ' ')
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
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j + 1] == ' ')
					{
						GotoXY(mX + j, mY + i);
						cout << " ";
					}
				}
			}
			//Xoa ki tu cuoi cung khi object di chuyen
			for (int i = 0; i < height; ++i)
			{
				//Xoa neu ky tu do khong phai ' '
				if (vehicle_table[i][width - 1] != ' ')
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
					if (vehicle_table[i][j] != ' ' && vehicle_table[i][j + 1] == ' ')
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
					if (vehicle_table[i][part1_length + j] != ' ' && vehicle_table[i][part1_length + j + 1] == ' ')
					{
						GotoXY(0 + j, mY + i);
						cout << " ";
					}
				}
			}
				

			//Xoa ki tu cuoi cung khi object di chuyen
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
	Status SavedStatus;
	SetTextColor(SavedStatus.getColor());

	if (mX >= 0 && mX + width <= GAMEPLAY_W)
	{
		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << string(width, ' ');
		}
	}
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(mX, iy);
			cout << string(part1_length, ' ');
		}

		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
		{
			GotoXY(0, iy);
			cout << string(part2_length, ' ');
		}
	}
}

//void CVEHICLE::Draw()
//{
//	Status SavedStatus;
//	SetTextColor(DefineColor(text_color, bg_color));
//
//	if (mX >= 0 && mX + width <= GAMEPLAY_W)
//	{
//		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
//		{
//			GotoXY(mX, iy);
//			cout << vehicle_table[i];
//		};
//	}
//	else if (mX + width > GAMEPLAY_W)
//	{
//		int part2_length = (mX + width) - GAMEPLAY_W;
//		int part1_length = width - part2_length;
//
//		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
//		{
//			GotoXY(mX, iy);
//			cout << vehicle_table[i].substr(0, part1_length);
//		}
//
//		for (int i = 0, iy = mY; iy < mY + height; iy++, i++)
//		{
//			GotoXY(0, iy);
//			cout << vehicle_table[i].substr(part1_length, part2_length);
//		}
//	}
//}

void CVEHICLE::Draw()
{
	Status SavedStatus;
	SetTextColor(DefineColor(text_color, bg_color));

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
	}
	else if (mX + width > GAMEPLAY_W)
	{
		int part2_length = (mX + width) - GAMEPLAY_W;
		int part1_length = width - part2_length;

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