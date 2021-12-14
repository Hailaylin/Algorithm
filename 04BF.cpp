/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-14 17:18:50
 * @LastEditTime: 2021-12-14 18:46:49
 * @FilePath: \Algorithm\04BF.cpp
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


void InitSString(SString s1) {
    string str;
    cin >> str;
    int i = 0;
    for (i = 0; i<str.length(); i++)
    {
        s1.ch[i] = str[i];
    }
    s1.ch[i] ='\n';
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