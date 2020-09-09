#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>

using namespace std;

#define elif else if
int random_number(int, int);
void setcolor(int, int);
void gotoxy(int, int);
void draw_ship(int, int);
void erase_ship(int, int);
void setcursor(bool);
void bullet_on(int , int);
void bullet_off(int , int );
void star_random();
char cursor(int, int);
void printScore(int);
void star_destroy(int , int );

typedef struct Bullet {
	bool bullet_st;
	int coord_x;
	int coord_y;
} Bullet;

bool COORD_star[5][71];
int score = 0;

int main()
{	

	printScore(0);

	Bullet bullet[5] ;

	for (int i = 0; i < 5; i++)
	{
		bullet[i].bullet_st = 0;
	}

	srand(time(NULL ));	

	for (int y = 0; y < 5;y++)
	{
		for (int x = 0; x < 71;x++)
		{
			COORD_star[y][x] = 0;
		}
	}
	for (int i = 0; i < 20; i++)
	{
		star_random();
	}
	bool stop_ship = 0; int ship_vec = 3;
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
			if (ch == ' ')
			{
				if (bullet[0].bullet_st == 0) 
				{
					bullet[0].bullet_st = 1;
					bullet[0].coord_x = x + 2; bullet[0].coord_y = y - 1;
					bullet_on(bullet[0].coord_x, bullet[0].coord_y);
				}
				elif (bullet[1].bullet_st == 0)
				{
					bullet[1].bullet_st = 1;
					bullet[1].coord_x = x + 2; bullet[1].coord_y = y - 1;
					bullet_on(bullet[1].coord_x, bullet[1].coord_y);
				}
				elif (bullet[2].bullet_st == 0)
				{
					bullet[2].bullet_st = 1;
					bullet[2].coord_x = x + 2; bullet[2].coord_y = y - 1;
					bullet_on(bullet[2].coord_x, bullet[2].coord_y);
				}
				elif (bullet[3].bullet_st == 0)
				{
					bullet[3].bullet_st = 1;
					bullet[3].coord_x = x + 2; bullet[3].coord_y = y - 1;
					bullet_on(bullet[3].coord_x, bullet[3].coord_y);
				}
				elif (bullet[4].bullet_st == 0)
				{
					bullet[4].bullet_st = 1;
					bullet[4].coord_x = x + 2; bullet[4].coord_y = y - 1;
					bullet_on(bullet[4].coord_x, bullet[4].coord_y);
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
		if (bullet[0].bullet_st == 1) 
		{
			bullet_off(bullet[0].coord_x, bullet[0].coord_y);
			if (bullet[0].coord_y > 0)
			{	
				if (cursor(bullet[0].coord_x, bullet[0].coord_y - 1) == '*')
				{	
					bullet[0].bullet_st = 0;
					star_destroy(bullet[0].coord_x, bullet[0].coord_y - 1);
					Beep(1000, 100);
					printScore(score);
				}
				else
				{
					bullet_on(bullet[0].coord_x, --bullet[0].coord_y);
				}
			}
			else
			{
				bullet_off(bullet[0].coord_x, bullet[0].coord_y);  bullet[0].bullet_st = 0;
			}
		}
		if (bullet[1].bullet_st == 1)
		{
			bullet_off(bullet[1].coord_x, bullet[1].coord_y);
			if (bullet[1].coord_y > 0)
			{
				if (cursor(bullet[1].coord_x, bullet[1].coord_y - 1) == '*')
				{
					bullet[1].bullet_st = 0;
					star_destroy(bullet[1].coord_x, bullet[1].coord_y - 1);
					Beep(1000, 100);
					printScore(score);
				}
				else
				{
					bullet_on(bullet[1].coord_x, --bullet[1].coord_y);
				}
			}
			else
			{
				bullet_off(bullet[1].coord_x, bullet[1].coord_y);  bullet[1].bullet_st = 0;
			}
		}
		if (bullet[2].bullet_st == 1)
		{
			bullet_off(bullet[2].coord_x, bullet[2].coord_y);
			if (bullet[2].coord_y > 0)
			{
				if (cursor(bullet[2].coord_x, bullet[2].coord_y - 1) == '*')
				{
					bullet[2].bullet_st = 0;
					star_destroy(bullet[2].coord_x, bullet[2].coord_y - 1);
					Beep(1000, 100);
					printScore(score);
				}
				else
				{
					bullet_on(bullet[2].coord_x, --bullet[2].coord_y);
				}
			}
			else
			{
				bullet_off(bullet[2].coord_x, bullet[2].coord_y);  bullet[2].bullet_st = 0;
			}
		}
		if (bullet[3].bullet_st == 1)
		{
			bullet_off(bullet[3].coord_x, bullet[3].coord_y);
			if (bullet[3].coord_y > 0)
			{
				if (cursor(bullet[3].coord_x, bullet[3].coord_y - 1) == '*')
				{
					bullet[3].bullet_st = 0;
					star_destroy(bullet[3].coord_x, bullet[3].coord_y - 1);
					Beep(1000, 100);
					printScore(score);
				}
				else
				{
					bullet_on(bullet[3].coord_x, --bullet[3].coord_y);
				}
			}
			else
			{
				bullet_off(bullet[3].coord_x, bullet[3].coord_y);  bullet[3].bullet_st = 0;
			}
		}
		if (bullet[4].bullet_st == 1)
		{
			bullet_off(bullet[4].coord_x, bullet[4].coord_y);
			if (bullet[4].coord_y > 0)
			{
				if (cursor(bullet[4].coord_x, bullet[4].coord_y - 1) == '*')
				{
					bullet[4].bullet_st = 0;
					star_destroy(bullet[4].coord_x, bullet[4].coord_y - 1);
					Beep(1000, 100);
					printScore(score);
				}
				else
				{
					bullet_on(bullet[4].coord_x, --bullet[4].coord_y);
				}
			}
			else
			{
				bullet_off(bullet[4].coord_x, bullet[4].coord_y);  bullet[4].bullet_st = 0;
			}
		}
		if (bullet[0].bullet_st == 1 || bullet[1].bullet_st == 1 || bullet[2].bullet_st == 1 || bullet[3].bullet_st == 1 || bullet[4].bullet_st == 1)
		{

		}
		else 
		{ 
			Sleep(100); 
		}
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
	setcolor(3,0);
	gotoxy(x, y);
	printf("^");
}
void bullet_off(int x, int y) 
{
	setcolor(2, 0);
	gotoxy(x, y);
	printf(" ");
}	
int random_number(int min, int max) 
{
	int r = (rand() / (float)RAND_MAX) * (max+1) + min;
	return r > max ? max: r ;
}
void star_random() 
{
	while(1)
	{
		int x = random_number(10,70);
		int y = random_number(2, 5);
		if (COORD_star[y][x] == 0) 
		{
			setcolor(6,0);
			COORD_star[y][x] = 1;
			gotoxy(x, y);
			printf("*");
			break;
		}
	}
}
char cursor(int x, int y) 
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
		return '\0';
	else
		return buf[0];
}
void printScore(int x) 
{
	gotoxy(75, 0);
	printf("      ");
	int Num[6] = {0,0,0,0,0,0};
	string point = to_string(x);
	int L = point.size();
	int i = 0;
	while (i != L) 
	{	
		int q = 0;
		Num[5 - i] += point[L - i - 1]-48;
		q = Num[5 - i] / 10;
		Num[5 - i] = Num[5 - i] % 10;
		if (q != 0) 
		{
			Num[5 - i - 1] += q;
		}
		i++;
	}
	gotoxy(75, 0);
	setcolor(7, 0);
	for (int i = 0; i < 6;i++) 
	{
		printf("%d", Num[i]);
	}
}
void star_destroy(int x, int y)
{
	gotoxy(x, y);
	printf(" ");
	COORD_star[y][x] = 0;
	star_random();
	score += 100;
}



