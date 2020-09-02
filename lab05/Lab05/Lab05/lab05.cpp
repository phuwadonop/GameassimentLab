#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ON 1
#define OFF 0

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
	bool left[5] = { 0,0,0,0,0 }, right[5] = { 0,0,0,0,0 }, bullet_st[5] = { 0,0,0,0,0 };
	setcursor(0);
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a') {
				if (x > 0) 
				{ 
					erase_ship(x, y);  draw_ship(--x, y); 
					if (i <= 4) 
						if (bullet_st[i] == 0) { left[i] = 1; right[i] = 0; } 
				}
				else { erase_ship(x, y); draw_ship(0, y); }
			}
			if (ch == 'd') {
				if (x < 80) 
				{ 
					erase_ship(x, y); draw_ship(++x, y); 
					if (i <= 4) 
						if (bullet_st[i] == 0) { left[i] = 0; right[i] = 1; }
				}
				else { erase_ship(x, y); draw_ship(80, y); }
			}
			if (ch == 's') {
				if (y < 20) { erase_ship(x, y); draw_ship(x, ++y); }
				else { draw_ship(x, 20); }
			}
			if (ch == 'w') {
				if (y > 0) { erase_ship(x, y); draw_ship(x, --y); }
				else { draw_ship(x, 0); }
			}
			if (ch == ' ' && bullet_st[i] == 0 )
			{
				if (i <= 4) 
				{
					bullet_st[i] = 1;
					if (right[i] == 1)
					{
						xb[i] = x + 5; yb[i] = y;
						bullet_on(xb[i], yb[i]);
					}
					if (left[i] == 1)
					{
						xb[i] = x - 5; yb[i] = y;
						bullet_on(xb[i], yb[i]);
					}
					if (left[i] == 0 && right[i] == 0)
					{
						xb[i] = x + 5; yb[i] = y;
						bullet_on(xb[i], yb[i]);
						right[i] = 1;
					}
					i++;
				}
			}
			fflush(stdin);
		}
		if (bullet_st[0] == 1 )
		{
			bullet_off(xb[0], yb[0]);
			if (xb[0] < 80 && xb[0] > 0)
			{
				if (left[0] == 1) { bullet_off(xb[0], yb[0]); bullet_on(--xb[0], yb[0]); }
				if (right[0] == 1) { bullet_off(xb[0], yb[0]); bullet_on(++xb[0], yb[0]); }
			}
			else { bullet_st[0] = 0; i--; }
		}
		if (bullet_st[1] == 1)
		{
			bullet_off(xb[1], yb[1]);
			if (xb[1] < 80 && xb[1] > 0)
			{
				if (left[1] == 1) { bullet_off(xb[1], yb[1]); bullet_on(--xb[1], yb[1]); }
				if (right[1] == 1) { bullet_off(xb[1], yb[1]); bullet_on(++xb[1], yb[1]); }
			}
			else { bullet_st[1] = 0; i--;}
		}
		if (bullet_st[2] == 1)
		{
			bullet_off(xb[2], yb[2]);
			if (xb[2] < 80 && xb[2] > 0)
			{
				if (left[2] == 1) { bullet_off(xb[2], yb[2]); bullet_on(--xb[2], yb[2]); }
				if (right[2] == 1) { bullet_off(xb[2], yb[2]); bullet_on(++xb[2], yb[2]); }
			}
			else { bullet_st[2] = 0; i--;}
		}
		if (bullet_st[3] == 1)
		{
			bullet_off(xb[3], yb[3]);
			if (xb[3] < 80 && xb[3] > 0)
			{
				if (left[3] == 1) { bullet_off(xb[3], yb[3]); bullet_on(--xb[3], yb[3]); }
				if (right[3] == 1) { bullet_off(xb[3], yb[3]); bullet_on(++xb[3], yb[3]); }
			}
			else { bullet_st[3] = 0; i--; }
		}
		if (bullet_st[4] == 1)
		{
			bullet_off(xb[4], yb[4]);
			if (xb[4] < 80 && xb[4] > 0)
			{
				if (left[4] == 1) { bullet_off(xb[4], yb[4]); bullet_on(--xb[4], yb[4]); }
				if (right[4] == 1) { bullet_off(xb[4], yb[4]); bullet_on(++xb[4], yb[4]); }
			}
			else { bullet_st[4] = 0; i--; }
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
	printf("-");
}
void bullet_off(int x, int y) 
{
	setcolor(2, 0);
	gotoxy(x, y);
	printf(" ");
}	 

