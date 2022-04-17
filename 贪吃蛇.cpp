#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<Windows.h>
#include<conio.h>
#include<random>
#define show cout << "■"
struct SNAKE
{
	int x, y;
	SNAKE* next;
	SNAKE()
	{
		this->next = nullptr;
	}
};
enum{UP=72,DOWN=80,LEFT=75,RIGHT=77};

void startGame(void);//游戏开始界面
void _gotoxy(int x, int y);//移动光标
void createMap(void); //绘制地图
void initSnake(SNAKE*& snake_head);//初始化蛇
void runGame(SNAKE*& snake_head);//运行游戏
bool moveSnake(SNAKE*& snake_head,int direct);//移动蛇
bool checkSnake(SNAKE* point, int op);  //检查蛇头的位置 （是否碰到食物或墙）
void delSnake(SNAKE*& snake_head);  //删除蛇的所有节点
void showFood(void); //生成新的食物
using namespace std;

int score=0;
int food_x, food_y;
int T;
int main(void)
{
	SetConsoleTitle(TEXT("贪吃蛇v1.0 (制作者：刘家麒)")); //设置控制台标题
	
    //隐藏控制台光标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cci);
	startGame();
	
	SNAKE* snake_head = nullptr;
	int x = 1;
	while (x)
	{
		int choice;
		_gotoxy(50, 52);
		cout << "请选择速度 1.快速 2.中等 3.慢速<<<";
		cin >> choice;
		if (choice == 1)
		{
			T = 110;
			score = 5;
		}
		else if (choice == 2)
		{
			T = 220;
			score = 3;
		}
		else
		{
			T = 265;
			score = 0;
		}
		system("cls");
		createMap();
		initSnake(snake_head);
		runGame(snake_head);
		_gotoxy(50, 50);
		cout<<"输入0停止游戏 , 1重新开始<<<";
		cin >> x;
	}
	
	return 0;
}



void startGame(void)  //游戏开始界面
{
	system("mode con cols=150 lines=65"); //调整控制台大小 cols控制横向 lines纵向
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	_gotoxy(40, 25);
	cout << "==============-------------===================";
	_gotoxy(52, 27);
	cout << "欢迎来到贪吃蛇小游戏v1.0！";

	int y = 25;
	for (int i = 1; i <= 4; ++i)
	{
		_gotoxy(40, y);
		cout << "=";
		_gotoxy(86, y);
		cout << "=";
		++y;
	}
	_gotoxy(40, 29);
	cout << "==============-------------===================";
	_gotoxy(70, 30);
	system("pause");
	system("cls");
}

void _gotoxy(int x, int y)
{
	COORD pos = { x,y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos); //设置光标位置
}

void createMap(void) //绘制地图
{
	
	int x = 0;
	for (int i = 1; i < 60; ++i)
	{

		_gotoxy(x, 0);
		show;
		_gotoxy(x, 59);
		show;
		(++x)++;
	}
	int y = 0;
	for (int i = 1; i <= 60; i++)
	{
		_gotoxy(0, y);
		show;
		_gotoxy(58*2, y);
		show;
		++y;
	}
	_gotoxy(50,62 );
	cout << "提示:";
	_gotoxy(54, 63);
	cout << "使用 ↑↓ ← → 控制蛇,撞墙即失败！";
}


void initSnake(SNAKE*& snake_head) //初始化蛇
{
	auto p = new SNAKE;
	if (!snake_head)
	{
		p->x = 20;
		p->y = 15;
		snake_head = p;
		
	}
	auto temp = snake_head;
	for (int i = 1; i <= 3; ++i)
	{
		auto p = new SNAKE;
		p->x = 20 + 2 * i;
		p->y = 15;
		temp->next = p;
		temp = p;
	}
	for (auto p = snake_head; p; p = p->next)
	{
		_gotoxy(p->x, p->y);
		show;
	}
	_gotoxy(1, 64);
	cout << "当前分数为：" << score;
	showFood();
}


void runGame(SNAKE*& snake_head) //游戏运行
{
	char ch ;
	int direct = RIGHT;
	for (; 1;)
	{
		if (_kbhit()) //判断有没有输入 (有输入返回非0)
		{
			ch = _getch(); //获取输入
			if ((int)ch == RIGHT || (int)ch == DOWN || (int)ch == UP ||(int) ch == LEFT)
			{
				direct = (int)ch;
			}
		}
		bool GAMECONTINUE = moveSnake(snake_head, direct);
		if (!GAMECONTINUE) return;
		Sleep(T);
	}
}


bool moveSnake(SNAKE*& snake_head,int direct) //移动蛇
{
	//找到链表尾巴
	auto p = snake_head;
	for (; p && p->next; p = p->next);

	//在表尾加一个节点
	auto point = new SNAKE;
	if (direct == RIGHT)
	{
		point->x = p->x + 2;
		point->y = p->y;
	}
	else if (direct == LEFT)
	{
		point->x = p->x - 2;
		point->y = p->y;
	}
	else if (direct == UP)
	{
		point->x = p->x;
		point->y = p->y - 1;
	}
	else if (direct == DOWN)
	{
		point->x = p->x;
		point->y = p->y + 1;
	}
	
	//显示蛇 : 显示新插入表尾的节点 
	p->next = point;
	_gotoxy(point->x, point->y);
	show;
	_gotoxy(food_x, food_y);
	show;

	//检查是否撞墙 或吃到食物
	bool GAMECONTINUE = checkSnake(point,1); 
	bool ISEAT = checkSnake(point, 2);
	if (!GAMECONTINUE)
	{
		delSnake(snake_head);
		MessageBox(NULL, TEXT("你失败了！"), TEXT("游戏结束"), MB_OK);
		system("cls");
		return false;
	}
	if (ISEAT)
	{
		score++;
		_gotoxy(1,64);
		cout << "当前分数为：" << score;
		showFood();
	}
	else //擦除蛇尾 删除链表头（蛇尾）
		
	{ 
		_gotoxy(snake_head->x, snake_head->y);
		cout << "  ";
		auto temp = snake_head->next;
		delete snake_head;
		snake_head = temp;
		
	}
	return true;
	
}


bool checkSnake( SNAKE* point,int op)  //检查蛇头的位置 （是否碰到食物或墙）
{
	if (op == 1) //检查是否撞墙
	{
		if (point->y == 0 || point->y == 59)
		{
			return false;
		}
		if (point->x == 0 || point->x == 116)
		{
			return false;
		}
		return true;
	}
	if (op == 2) //检查是否碰到食物
	{
		if (point->x == food_x && point->y == food_y)
		{
			return true;
		}
		return false;
	}
}

void delSnake(SNAKE*& snake_head) //删除蛇的节点
{
	auto pSlow = snake_head;
	for (auto p = snake_head->next; p; p = p->next)
	{
		free(pSlow);
		pSlow = p;
	}
	snake_head = nullptr;
}

void showFood(void)
{
	random_device rd1;
	random_device rd2;
	default_random_engine generator_x(rd1());
	default_random_engine generator_y(rd2());

	uniform_int_distribution<int> dist_intx(3, 56);   //生成[min,max]之间的随机整数
	int x1 = dist_intx(generator_x);
	food_x = 2*x1;
	
	uniform_int_distribution<int> dist_inty(3, 56);   //生成[min,max]之间的随机整数
	food_y = dist_inty(generator_y);
	_gotoxy(food_x, food_y);
}

