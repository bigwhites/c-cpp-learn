#include <cstdio>
#include<cstdlib>

//数据结构定义：
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

//函数声明：
void createBiTree_pre(TREE*& T);//由先序序列建立二叉树
void preorder(TREE* T);        //先序遍历二叉树
void push(QUE& q, TREE* T);    //将树的节点压入队尾
TREE* pop(QUE& q);             //对头元素出队
bool isEmpty(QUE q);           //队列判空
void levelOreder(TREE* T);     //层序遍历二叉树
TREE* createBiTree_level(void);//层序创建二叉树
void  swapChild(TREE*& T);      //交换左右子树
void showTree(TREE* T);        //凹入表显示二叉树
void getLevel(TREE* T, TREE* key, int* lev, int floor);

//测试函数
int main()
{
    /*
    测试用先序序列：
        abdh##i##e##cfj##k##gl###
        abc##de#g##f###

    测试用层序序列：
        a#bc##de#f##g##
        abcdefghi##jkl################
    */
    TREE* T = NULL;
    printf("输入先序序列(空节点用#表示)：");
    createBiTree_pre(T);
    printf("\n先序序列为：");
    preorder(T);
    fflush(stdin);
    printf("\n层序序列为：");
    levelOreder(T);
    printf("\n");
    showTree(T);

    printf("\n\n\n\n");
    TREE* BT = NULL;
    printf("请输入层序序列（空节点用#表示）：");
    BT = createBiTree_level();
    printf("\n先序序列为：");
    preorder(BT);
    printf("\n交换左右子树后：");
    swapChild(BT);
    preorder(BT);
    printf("\n\n\n\n");
    return 0;
}

//函数定义：
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
