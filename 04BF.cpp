/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-14 17:18:50
 * @LastEditTime: 2021-12-14 23:24:22
 * @FilePath: \Algorithm\04BF.cpp
 */

/**
4、编程题4（共20 分,你的分数为0 分）
练习BF算法，通过模式匹配进行子串查找。
例1(前2行为输入)：
abcdef adf
bcd
2
例2(前2行为输入)：
abcd efg
bcde
0
注：SString定义如下所示
#define MAXLEN 255
typedef struct
{
char ch[MAXLEN];
int length;
}SString;
请注意，main()函数或函数调用必须按如下所示编写：
int main()
{
SString s1,s2;
InitSString(s1); //初始化字符串，以回车结束
InitSString(s2);
//BF算法：s2若为s1的子串，返回匹配的开始位置，否则返回0
cout<<Index_BF(s1,s2,1)<<endl;
return 0;
}

 */

/**
 * @单词翻译
 * 模式串  patternStr
 * 主串 mainStr
 */

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

#define MAXlength 255
typedef struct
{
    char ch[MAXlength];
    int length;
}SString;

// 下标都从1开始找
int Index_BF(SString S,SString T,int pos)
{//返回模式T在主串S中第pos个字符开始第一次出现的位置。若不存在，则返回值为0 
 //其中，T非空，1≤pos≤Strlengthgth(S) 
    int i,j;
    i=pos; j=1;   
    while(i<=S.length&&j<=T.length)
    { 
       if(S.ch[i]==T.ch[j]){++i;++j;}	//继续比较后继字符 
       else{i=i-j+2;j=1;}	//指针后退重新开始匹配
    }   
    if(j>T.length) return i-T.length;   
    else return 0;   
} 


void InitSString(SString &sstr) {
    // sstr 初始化
    for (int j = 0; j < MAXlength; j++) {
        sstr.ch[j] = 0;
    }
    sstr.length = 0;
    // 读取
    string line_str;
    getline(cin, line_str);
    // 转移
    int i = 1;
    for ( i = 1; i < line_str.length(); i++)
    {
        sstr.ch[i] = line_str[i];
        sstr.length++;
    }
    sstr.ch[i] ='\n';
    return ;
}

int main()
{
    SString s1,s2;
    InitSString(s1); //初始化字符串，以回车结束
    InitSString(s2);
    
    //BF算法：s2若为s1的子串，返回匹配的开始位置，否则返回0
    cout<<Index_BF(s1,s2,1)<<endl;  
    return 0;
}