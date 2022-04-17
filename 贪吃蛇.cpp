#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<Windows.h>
#include<conio.h>
#include<random>
#define show cout << "��"
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

void startGame(void);//��Ϸ��ʼ����
void _gotoxy(int x, int y);//�ƶ����
void createMap(void); //���Ƶ�ͼ
void initSnake(SNAKE*& snake_head);//��ʼ����
void runGame(SNAKE*& snake_head);//������Ϸ
bool moveSnake(SNAKE*& snake_head,int direct);//�ƶ���
bool checkSnake(SNAKE* point, int op);  //�����ͷ��λ�� ���Ƿ�����ʳ���ǽ��
void delSnake(SNAKE*& snake_head);  //ɾ���ߵ����нڵ�
void showFood(void); //�����µ�ʳ��
using namespace std;

int score=0;
int food_x, food_y;
int T;
int main(void)
{
	SetConsoleTitle(TEXT("̰����v1.0 (�����ߣ�������)")); //���ÿ���̨����
	
    //���ؿ���̨���
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
		cout << "��ѡ���ٶ� 1.���� 2.�е� 3.����<<<";
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
		cout<<"����0ֹͣ��Ϸ , 1���¿�ʼ<<<";
		cin >> x;
	}
	
	return 0;
}



void startGame(void)  //��Ϸ��ʼ����
{
	system("mode con cols=150 lines=65"); //��������̨��С cols���ƺ��� lines����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	_gotoxy(40, 25);
	cout << "==============-------------===================";
	_gotoxy(52, 27);
	cout << "��ӭ����̰����С��Ϸv1.0��";

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
	SetConsoleCursorPosition(hOut, pos); //���ù��λ��
}

void createMap(void) //���Ƶ�ͼ
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
	cout << "��ʾ:";
	_gotoxy(54, 63);
	cout << "ʹ�� ���� �� �� ������,ײǽ��ʧ�ܣ�";
}


void initSnake(SNAKE*& snake_head) //��ʼ����
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
	cout << "��ǰ����Ϊ��" << score;
	showFood();
}


void runGame(SNAKE*& snake_head) //��Ϸ����
{
	char ch ;
	int direct = RIGHT;
	for (; 1;)
	{
		if (_kbhit()) //�ж���û������ (�����뷵�ط�0)
		{
			ch = _getch(); //��ȡ����
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


bool moveSnake(SNAKE*& snake_head,int direct) //�ƶ���
{
	//�ҵ�����β��
	auto p = snake_head;
	for (; p && p->next; p = p->next);

	//�ڱ�β��һ���ڵ�
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
	
	//��ʾ�� : ��ʾ�²����β�Ľڵ� 
	p->next = point;
	_gotoxy(point->x, point->y);
	show;
	_gotoxy(food_x, food_y);
	show;

	//����Ƿ�ײǽ ��Ե�ʳ��
	bool GAMECONTINUE = checkSnake(point,1); 
	bool ISEAT = checkSnake(point, 2);
	if (!GAMECONTINUE)
	{
		delSnake(snake_head);
		MessageBox(NULL, TEXT("��ʧ���ˣ�"), TEXT("��Ϸ����"), MB_OK);
		system("cls");
		return false;
	}
	if (ISEAT)
	{
		score++;
		_gotoxy(1,64);
		cout << "��ǰ����Ϊ��" << score;
		showFood();
	}
	else //������β ɾ������ͷ����β��
		
	{ 
		_gotoxy(snake_head->x, snake_head->y);
		cout << "  ";
		auto temp = snake_head->next;
		delete snake_head;
		snake_head = temp;
		
	}
	return true;
	
}


bool checkSnake( SNAKE* point,int op)  //�����ͷ��λ�� ���Ƿ�����ʳ���ǽ��
{
	if (op == 1) //����Ƿ�ײǽ
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
	if (op == 2) //����Ƿ�����ʳ��
	{
		if (point->x == food_x && point->y == food_y)
		{
			return true;
		}
		return false;
	}
}

void delSnake(SNAKE*& snake_head) //ɾ���ߵĽڵ�
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

	uniform_int_distribution<int> dist_intx(3, 56);   //����[min,max]֮����������
	int x1 = dist_intx(generator_x);
	food_x = 2*x1;
	
	uniform_int_distribution<int> dist_inty(3, 56);   //����[min,max]֮����������
	food_y = dist_inty(generator_y);
	_gotoxy(food_x, food_y);
}

