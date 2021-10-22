/*
 * @Description: 乱码的原因探究
 * @Author: HailayLin
 * @Date: 2021-10-18 16:45:29
 * @LastEditTime: 2021-10-18 17:00:54
 * @FilePath: \Algorithm\charset_test.cc
 */

// #include<iostream>
// using namespace std;

// int main()
// {
//     const char *str = "码";
//     cout << str << endl;
//     printf("二进制:%02x ", str[0]);
//     return 0;
// }


#include <stdio.h>
int main(int argc, char **argv) 
{ 
	int i = 0;
	unsigned char str[8] = "1234中";
 
	while(str[i])
	{
		printf("%02x ",str[i]);
		i++;
	}
	printf("\n");
    printf("%s\n", str);
	return 0; 
}