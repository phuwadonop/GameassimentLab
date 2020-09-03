#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int, int);
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void bullet_on(int , int);
void bullet_off(int , int );

int main()
{	
	int xb[5], yb[5],i=0;
	bool bullet_st[5] = { 0,0,0,0,0 },stop_ship=0;
	int ship_vec = 3;
	setcursor(0);
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a')
			{
				ship_vec = 0; stop_ship = 0;
			}
			if (ch == 'd')
			{
				ship_vec = 1; stop_ship = 0;
			}
			if (ch == 's') 
			{
				stop_ship = 1; ship_vec = 3;
			}
			if (ch == ' ' && bullet_st[i] == 0)
			{
				if (i <= 4)
				{
					bullet_st[i] = 1;
					xb[i] = x+2; yb[i] = y - 1;
					bullet_on(xb[i], yb[i]);
					++i;
				}
			}
			fflush(stdin);
		}
		if (ship_vec == 1)
		{
			if (x < 80)
			{
				erase_ship(x, y); draw_ship(++x, y);
			}
			else { erase_ship(x, y); draw_ship(80, y); }
		}
		if (ship_vec == 0)
		{
			if (x > 0)
			{
				erase_ship(x, y); draw_ship(--x, y);
			}
			else { erase_ship(x, y); draw_ship(0, y); }
		}
		if (stop_ship == 1)
		{
			erase_ship(x, y); draw_ship(x, y);
		}
		if (bullet_st[0] == 1 )
		{
			bullet_off(xb[0], yb[0]);
			if (yb[0] > 0)
			{
				bullet_on(xb[0], --yb[0]);
			}
			else { bullet_off(xb[0], yb[0]); bullet_st[0] = 0; --i; }
		}
		if (bullet_st[1] == 1)
		{
			bullet_off(xb[1], yb[1]);
			if (yb[1] > 0)
			{
				bullet_on(xb[1], --yb[1]);
			}
			else { bullet_off(xb[1], yb[1]); bullet_st[1] = 0; --i;}
		}
		if (bullet_st[2] == 1)
		{
			bullet_off(xb[2], yb[2]);
			if (yb[2] > 0)
			{
				bullet_on(xb[2], --yb[2]);
			}
			else { bullet_off(xb[2], yb[2]); bullet_st[2] = 0; --i;}
		}
		if (bullet_st[3] == 1)
		{
			bullet_off(xb[3], yb[3]);
			if (yb[3] > 0)
			{
				bullet_on(xb[3], --yb[3]);
			}
			else { bullet_off(xb[3], yb[3]); bullet_st[3] = 0; --i; }
		}
		if (bullet_st[4] == 1)
		{
			bullet_off(xb[4], yb[4]);
			if (yb[4] > 0)
			{
				bullet_on(xb[4], --yb[4]);
			}
			else { bullet_off(xb[4], yb[4]); bullet_st[4] = 0; --i; }
		}
		Sleep(100);
	} while (ch != 'x');
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	setcolor(2, 4);
	gotoxy(x, y);
	printf("<-0->");
}
void erase_ship(int x, int y)
{
	setcolor(2, 0);
	gotoxy(x, y);
	printf("       ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void bullet_on(int x, int y) 
{
	setcolor(6,0);
	gotoxy(x, y);
	printf("*");
}
void bullet_off(int x, int y) 
{
	setcolor(2, 0);
	gotoxy(x, y);
	printf(" ");
}	 

