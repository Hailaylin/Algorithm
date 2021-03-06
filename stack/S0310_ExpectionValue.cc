/*
 * @Description: 表达式求值
 * @Author: HailayLin
 * @Date: 2021-11-12 16:47:01
 * @LastEditTime: 2021-11-13 19:54:07
 * @FilePath: \Algorithm\stack\S0310_ExpectionValue.cc
 */
/**
 * 	题号：S0310        题目:表达式的值        得分：0  
  
作业提交截止时间：2022/1/20 0:00:00	 
 	
题目内容：
在S0306的基础上修改程序，求表达式的值（表达式中的数值在[0,9]范围）。
例：
（1）输入：#3*4# 输出：12
（2）输入：#2*(5+6) 输出：22

 请注意，main()函数必须按如下所示编写：
int main()
{
    string str;
    getline(cin,str);
    cout<<EvalueateExpression(str)-'0'<<endl; //计算表达式的值 
    return 0;
}
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

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

char Operator(char a, char theta, char b)
{
    switch(theta) {
    case '+':
        return (a - '0') + (b - '0') + '0';
    case '-':
        return (a - '0') - (b - '0') + '0';
    case '*':
        return (a - '0') * (b - '0') + '0';
    case '/':
        return (a - '0') / (b - '0') + '0';
    }
    return '0';
}

/**
 * @brief 计算表达式的值
 * 
 * @param str 需要运算表达式，比如 #3*(7-2)# ,以#为表达式开始、结束符
 * @return char 返回ANSII码表示的字符
 */
char EvalueateExpression(string str)
{
    stack<char> OPTR;   // 寄存运算符
    stack<char> OPND;    // 寄存操作数或运算结果
    
    char a, b;
    char theta;
    OPTR.push('#');
    str.erase(str.begin());
    char ch = str[0];
    while(ch != '#' || OPTR.top() != '#')
    {
        ch = str[0];
        if (!IsOperate(ch))
        {
            OPND.push(ch);
            if(!str.empty()) str.erase(str.begin());
            else break;
        }
        else
        {
            switch (Precede(OPTR.top(), ch))    // 栈顶和目前元素比较优先级
            {
            case '<':
                OPTR.push(ch);
                str.erase(str.begin());
                break;
            case '>':
                theta = OPTR.top(); OPTR.pop();
                a = OPND.top();
                OPND.pop();
                b = OPND.top();
                OPND.pop();
                OPND.push(Operator(a, theta, b));
                break;
            case '=':
                OPTR.pop();
                str.erase(str.begin());
                break;
            }
        }
    }
    return OPND.top();
}

int main()
{
    string str;
    getline(cin,str);
    cout<<EvalueateExpression(str)-'0'<<endl; //计算表达式的值 
    return 0;
}