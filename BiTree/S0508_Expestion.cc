/*
 * @Description: 表达式求值
 * @Author: HailayLin
 * @Date: 2021-11-10 19:03:26
 * @LastEditTime: 2021-11-13 20:41:37
 * @FilePath: \Algorithm\BiTree\S0508_Expestion.cc
 */
/**
 * 题号：S0508        题目:表达式的值        得分：0

作业提交截止时间：2021/11/14 0:00:00

题目内容：
练习书上算法5.12、5.13，计算表达式的值。
注：由于EXPT与OPTR两个栈中的数据不一致，可使用系统提供的栈类（#include <stack>）。

例：
（1）输入：3+2# 输出：5
（2）输入：3+2*4 # 输出：11
（3）输入：3*(4+2)# 输出：18


 请注意，main()函数必须按如下所示编写：
int main()
{
    BiTree T;
    InitExpTree(T); //先序遍历顺序创建二叉树
    //PreOrderTraverse(T); cout<<endl; //先序遍历
    cout<<EvaluateExpTree(T)<<endl; //计算表达式的值
    return 0;
}
*/
#include<iostream>
#include<stack>
using namespace std;

#define OK 1
#define ERROR 0 
typedef int Status;
typedef char TElemType;
// 创建节点
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

const char oper[7] = {
    '+',
    '-',
    '*',
    '/',
    '(',
    ')',
    '#'
};

bool IsOperate(char ch)
{
    for(int i=0; i<7; i++)
    {
        if(ch == oper[i]) return true;
    }
    return false;
}

// 创建树节点
void CreateExpTree(BiTree &T, BiTree lchild, BiTree rchild, char ch)
{
    T = new BiTNode;
    T->lchild = lchild;
    T->rchild = rchild;
    T->data = ch;
}

/**
 * @brief 比较a, b运算符运算顺序
 * 
 * @param a 
 * @param b 
 * @return char 输出< > =
 */
char Precede(char theta1, char theta2)
{
    if( (theta1 == '(' && theta2 == ')' ) || (theta1 == '#' && theta2 == '#') )
        return '=';
    else if (theta1 == '(' || theta1 == '#' || theta2 == '(' || (theta1
			== '+' || theta1 == '-') && (theta2 == '*' || theta2 == '/'))
		return '<';
	else 
        return '>'; 
}

// 先序遍历创建二叉树
void InitExpTree(BiTree &T)
{
    char ch, thetha;
    BiTree a, b;
    stack<BiTree> EXPT;    // 存放表达式
    stack<char> OPTR;   // 存放运算符
    OPTR.push('#');
    cin >> ch;
    while(ch != '#' || OPTR.top() != '#')
    {
        if(!IsOperate(ch))
        {
            CreateExpTree(T, NULL, NULL, ch);   // 创建节点
            EXPT.push(T);
            cin >> ch;
        }
        else
        {
            switch (Precede(OPTR.top(), ch))
            {
            case '<':
                OPTR.push(ch);
                cin >> ch;
                break;
            case '>':
                thetha = OPTR.top();
                OPTR.pop();
                a = EXPT.top();
                EXPT.pop();
                b = EXPT.top();
                EXPT.pop();
                CreateExpTree(T, a, b, thetha);
                EXPT.push(T);
                break;
            case '=':
                OPTR.pop();
                cin >> ch;
                break;
            default:
                break;
            }
        }
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


int GetValue(char theta, int lvalue, int rvalue)
{
    switch(theta) {
    case '+':
        return lvalue + rvalue;
    case '-':
        return lvalue - rvalue;
    case '*':
        return lvalue * rvalue;
    case '/':
        return lvalue / rvalue;
    }
    return '0';
}

//计算表达式的值
int EvaluateExpTree(BiTree T)
{
    int lvalue=0, rvalue = 0;
    if(T->lchild == NULL && T->rchild == NULL)
    {
        return T->data-'0';
    }
    else {
        lvalue = EvaluateExpTree(T->lchild);
        rvalue = EvaluateExpTree(T->rchild);
        return GetValue(T->data, lvalue, rvalue);
    }
}

int main()
{
    BiTree T;
    InitExpTree(T); //先序遍历顺序创建二叉树
    //PreOrderTraverse(T); cout<<endl; //先序遍历
    cout<<EvaluateExpTree(T)<<endl; //计算表达式的值
    return 0;
}