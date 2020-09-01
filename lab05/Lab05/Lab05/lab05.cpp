#include<stdio.h>
#include<windows.h>
#include<conio.h>
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
int main()
{	
	char direction;
	setcursor(0);
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a') { direction = ch; } // เดินไปทางซ้าย
			if (ch == 'd') { direction = ch; } // เดินไปทางขวา
			if (ch == 's') { direction = ch; } // หยุด
		}
		if (direction == 'a') {
			while (x != 0) { erase_ship(x, y); draw_ship(--x, y); Sleep(1000); }
		}
		fflush(stdin);
		Sleep(100);
	} while (ch != 'x');
}