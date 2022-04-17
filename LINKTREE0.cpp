#include <cstdio>
#include<cstdlib>

//���ݽṹ���壺
typedef struct node1
{
    char data;
    node1* lchild, * rchild;
}TREE;
typedef struct node2
{
    TREE* pdata;
    struct node2* next;
}LINKLIST;
typedef struct node3
{
    LINKLIST* head = NULL;
    LINKLIST* tail = NULL;
}QUE;

//����������
void createBiTree_pre(TREE*& T);//���������н���������
void preorder(TREE* T);        //�������������
void push(QUE& q, TREE* T);    //�����Ľڵ�ѹ���β
TREE* pop(QUE& q);             //��ͷԪ�س���
bool isEmpty(QUE q);           //�����п�
void levelOreder(TREE* T);     //�������������
TREE* createBiTree_level(void);//���򴴽�������
void  swapChild(TREE*& T);      //������������
void showTree(TREE* T);        //�������ʾ������
void getLevel(TREE* T, TREE* key, int* lev, int floor);

//���Ժ���
int main()
{
    /*
    �������������У�
        abdh##i##e##cfj##k##gl###
        abc##de#g##f###

    �����ò������У�
        a#bc##de#f##g##
        abcdefghi##jkl################
    */
    TREE* T = NULL;
    printf("������������(�սڵ���#��ʾ)��");
    createBiTree_pre(T);
    printf("\n��������Ϊ��");
    preorder(T);
    fflush(stdin);
    printf("\n��������Ϊ��");
    levelOreder(T);
    printf("\n");
    showTree(T);

    printf("\n\n\n\n");
    TREE* BT = NULL;
    printf("������������У��սڵ���#��ʾ����");
    BT = createBiTree_level();
    printf("\n��������Ϊ��");
    preorder(BT);
    printf("\n��������������");
    swapChild(BT);
    preorder(BT);
    printf("\n\n\n\n");
    return 0;
}

//�������壺
void createBiTree_pre(TREE*& T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = (TREE*)malloc(sizeof(TREE));
        T->data = ch;
        createBiTree_pre(T->lchild);
        createBiTree_pre(T->rchild);
    }
}

void preorder(TREE* T)
{
    if (T == NULL)
    {
        return;
    }
    else  printf("%c ", T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}

void push(QUE& q, TREE* T)
{
    LINKLIST* p = (LINKLIST*)malloc(sizeof(LINKLIST));
    p->pdata = T;
    p->next = NULL;
    if (!q.head)
    {
        q.head = p;
        q.tail = p;
    }
    else
    {
        q.tail->next = p;
        q.tail = p;
    }
}

TREE* pop(QUE& q)
{
    TREE* p = (TREE*)malloc(sizeof(TREE));
    LINKLIST* ptemp = q.head;
    q.head = q.head->next;
    p = ptemp->pdata;
    return p;
}

bool isEmpty(QUE q)
{
    if (q.head == NULL || q.tail == NULL) return 1;
    return 0;
}

void levelOreder(TREE* T)
{
    QUE q;
    TREE* p;
    push(q, T);
    while (!isEmpty(q))
    {
        p = pop(q);
        printf("%c ", p->data);
        if (p->lchild != NULL)
        {
            push(q, p->lchild);
        }
        if (p->rchild != NULL)
        {
            push(q, p->rchild);
        }
    }

}

TREE* createBiTree_level(void)
{
    QUE Q;
    char Data;
    getchar();
    scanf("%c", &Data);
    if (Data == '#') return NULL;
    TREE* T, * BT;
    T = (TREE*)malloc(sizeof(TREE));
    T->data = Data;
    T->lchild = T->rchild = NULL;
    push(Q, T);
    while (!isEmpty(Q))
    {
        BT = pop(Q);
        scanf("%c", &Data);
        if (Data == '#') BT->lchild = NULL;
        else
        {
            BT->lchild = (TREE*)malloc(sizeof(TREE));
            BT->lchild->data = Data;
            BT->lchild->rchild = BT->lchild->lchild = NULL;
            push(Q, BT->lchild);
        }
        scanf("%c", &Data);
        if (Data == '#') BT->rchild = NULL;
        else
        {
            BT->rchild = (TREE*)malloc(sizeof(TREE));
            BT->rchild->data = Data;
            BT->rchild->rchild = BT->rchild->lchild = NULL;
            push(Q, BT->rchild);
        }

    }
    return T;
}

void  swapChild(TREE*& T)
{
    if (T == NULL) return;
    if (T->lchild != NULL && T->rchild != NULL)
    {
        TREE* temp = T->lchild;
        T->lchild = T->rchild;
        T->rchild = temp;
    }
    swapChild(T->lchild);
    swapChild(T->rchild);
}

void showTree(TREE* T)
{
    static const TREE const* _T = T;
    int* lev = new int;
    if (T != NULL)
    {
        getLevel((TREE*)_T, T, lev, 1);
        for (int i = 1; i <= *lev; ++i)
        {
            printf(" ");
        }
        printf("%c\n", T->data);
    }
    else
    {
        return;
    }
    showTree(T->lchild);
    showTree(T->rchild);
}

void getLevel(TREE* T, TREE* key, int* lev, int floor)
{
    if (T != NULL)
    {
        if (T == key)
        {
            *lev = floor;
        }
        getLevel(T->lchild, key, lev, floor + 1);
        getLevel(T->rchild, key, lev, floor + 1);
    }

}
