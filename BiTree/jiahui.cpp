#include<iostream>
#include<stack>
#include<string>
#define ERROR -1
#define MAXSIZE 100
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct{                   //树栈定义
	BiTree *base;
	BiTree *top;
	int stacksize;
}BiTreeStack;

void  InitBiTreeStack(BiTreeStack &S){             //树栈初始化
	S.base=new BiTree[MAXSIZE];
	if(!S.base) exit(-1);
	S.top=S.base;
	S.stacksize=MAXSIZE;
}

void PushBiTree(BiTreeStack &S,BiTree e)             //树栈入栈
{
	if(S.top-S.base==S.stacksize) return ;
	*S.top=e;
	S.top++;
}

void PopBiTree(BiTreeStack &S,BiTree &e)           //树栈出栈
{
	if(S.top==S.base) return;
	e=*--S.top;
}

char Precede(char t1,char t2) 
 { /* 根据教科书表3.1，判断两符号的优先关系 */
    char f;
    switch(t2)
    {
     case '+':if(t1=='('||t1=='#')
                f='<';
              else
                f='>';
              break;
     case '-':if(t1=='('||t1=='#')
                f='<';
              else
                f='>';
              break;
     case '*':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;
	case '/':if(t1=='*'||t1=='/'||t1==')')
                f='>';
              else
                f='<';
              break;
	case '(':if(t1!=')')
                f='<';
              break;
	case ')':if(t1=='(')
				f='=';
				else
					f='>';
				break;
	case '#':if(t1=='#')
				f='=';
		        else
			        f='>';
   }

   return f;
}

int In(char c)
{
    char a[7] = {'+','-','*','/','#','(',')'};
    for(int i = 0; i < 7; i++)
    {
        if(c==a[i]) return 1;
    }
    return 0;
}

int GetValue(char theta,int a,int b)     //进行运算的函数
{
	int c;
	switch(theta)
	{
		case '+':c=a+b;break;
		case '-':c=a-b;break;
		case '*':c=a*b;break;
		case '/':c=a/b;break;
		default:
			break;
	}
	return c;
}

void CreateExpTree(BiTree &T,BiTree a,BiTree b,char ch){           //简单二叉树的创建
	T=new BiTNode;
	T->data=ch;
	T->lchild=a;
	T->rchild=b;
}

void InitExpTree(BiTree &T)
{
    stack<char>OPTR;
    BiTreeStack EXPT;
    
    char ch,theta,x;
    BiTree a,b;
    InitBiTreeStack(EXPT);
    OPTR.push('#');
    cin >> ch;
    while (ch!='#'||OPTR.top()!='#')
    {
        if(!In(ch))
        {
            CreateExpTree(T,NULL,NULL,ch);
            PushBiTree(EXPT,T);
            cin >> ch;
        }
        else
            switch(Precede(OPTR.top(),ch))
            {
                case '<':
                    OPTR.push(ch);
                    cin >> ch;
                    break;
                case '>':
                    theta = OPTR.top();
                    OPTR.pop();
                    PopBiTree(EXPT,b);
                    PopBiTree(EXPT,a);
                    CreateExpTree(T,a,b,theta);
                    PushBiTree(EXPT,T);
                    break;
                case '=':
                    OPTR.pop();
                    cin >> ch;
                    break;
            }
    }
    
}

int EvaluateExpTree(BiTree T)
{
	int lvalue,rvalue;
	lvalue=rvalue=0;
	if(T->lchild==NULL&&T->rchild==NULL)
		return T->data-'0';
	else
    {
		lvalue=EvaluateExpTree(T->lchild);
		rvalue=EvaluateExpTree(T->rchild);
		return GetValue(T->data,lvalue,rvalue);    //运算函数
	}
}
// 前序遍历
void PreOrderTraverse(BiTree &T)
{
    if (T){
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
int main()
{
    BiTree T;
    InitExpTree(T); //先序遍历顺序创建二叉树 
    PreOrderTraverse(T); cout<<endl; //先序遍历 
    cout<<EvaluateExpTree(T)<<endl; //计算表达式的值 
    return 0;
}

