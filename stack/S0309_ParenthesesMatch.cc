/*
 * @Description:
 * @Author: HailayLin
 * @Date: 2021-11-10 19:12:16
 * @LastEditTime: 2021-11-10 20:05:39
 * @FilePath: \Algorithm\stack\S0309_ParenthesesMatch.cc
 */

/**
 * @brief题号：S0309        题目:括号匹配        得分：0

作业提交截止时间：2022/1/20 0:00:00

题目内容：
在S0306的基础上修改程序，检查表达式中括号是否匹配。
例：
（1）输入：a*{b*[c+d+e/(f-g)]} 输出：True
（2）输入：a*{b*[c+d+e/(f-g)}] 输出：False


 请注意，main()函数必须按如下所示编写：
int main()
{
    string str;
    getline(cin,str);
    if(Matching(str)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}
 *
 */

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool Matching(string str)
{
    stack <char> parentheses;
    bool flag = true;  // 设定有没有不配成功
    while (str[0] != '\0' && flag)
    {
        char cd = str[0];
        switch(cd)
        {
        case '(':
        case '[':
        case '{':
            parentheses.push(cd);
            break;
        case ')':
            if (!parentheses.empty() && parentheses.top() == '(')
            {
                parentheses.pop();
            }
            else flag = false;
            break;
        case ']':
            if (!parentheses.empty() && parentheses.top() == '[')
            {
                parentheses.pop();
            }
            else flag = false;
            break;
        case '}':
            if (!parentheses.empty() && parentheses.top() == '{')
            {
                parentheses.pop();
            }
            else flag = false;
            break;
        }
        str.erase(str.begin());
    }
    if (parentheses.empty() && flag == true)
        return true;
    else return false;
}

int main()
{
    string str;
    getline(cin,str);
    if(Matching(str)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}