/*
 * @Description: 4 Primality Test
 * @Author: HailayLin
 * @Date: 2021-10-10 12:20:05
 * @LastEditTime: 2021-10-10 12:42:57
 * @FilePath: \Algorithm\ccpc2021\4_PrimalityTest.cpp
 */

/**
 * @brief Problem Description
A positive integer is called a prime if it is greater than 11 and cannot be written as the product of two smaller positive integers. A primality test is an algorithm for determining whether an input number is a prime. For example, the Miller-Rabin primality test is a probabilistic primality test. This problem is precisely the one about the primality test.

Let's define the function f(x)f(x) as the smallest prime which is strictly larger than xx. For example, f(1)=2f(1)=2, f(2)=3f(2)=3, and f(3)=f(4)=5f(3)=f(4)=5. And we use \lfloor x \rfloor⌊x⌋ to indicate the largest integer that does not exceed xx.

Now given xx, please determine whether g(x)g(x) is a prime.

g(x)=\left\lfloor\dfrac{f(x)+f(f(x))}{2}\right\rfloor
g(x)=⌊ 
2
f(x)+f(f(x))
​
 ⌋

Input
The first line of the input contains an integer TT (1 \le T \le 10^51≤T≤10 
5
 ), indicating the number of test cases.

Each test case contains an integer xx (1 \le x \le 10^{18}1≤x≤10 
18
 ) in a single line.

Output
For each test case, if g(x)g(x) is a prime, output \texttt{YES}YES in a single line. Otherwise, output \texttt{NO}NO in a single line.

Sample Input
2
1
2
Sample Output
YES
NO
Hint
When x=1x=1, f(x)=2f(x)=2, f(f(x))=f(2)=3f(f(x))=f(2)=3, then g(x)=\left\lfloor\dfrac{2+3}{2}\right\rfloor=2g(x)=⌊ 
2
2+3
​
 ⌋=2, which is a prime. So the output is \texttt{YES}YES.

When x=2x=2, f(x)=3f(x)=3, f(f(x))=f(3)=5f(f(x))=f(3)=5, then g(x)=\left\lfloor\dfrac{3+5}{2}\right\rfloor=4g(x)=⌊ 
2
3+5
​
 ⌋=4, which is not a prime. So the output is \texttt{NO}NO.
 * 
 */

#include<iostream>
#include<math.h>
using namespace std;

/**
 * @brief 判断素数
 * 
 * @param num 
 * @return true 
 * @return false 
 */
bool isPrime(int num)
{
    int m = sqrt(num);
    if (num <=1) return false;
    for (int i = 2; i <= m; i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

/**
 * @brief f(x)，取小且大于x的素数
 * 
 * @param x 
 * @return int 
 */
int f(int x)
{
    while(!isPrime(++x)) {}
    return x;
}

/**
 * @brief g(x)= 算式后向下取整后判断是不是素数
 * 
 * @param x 
 * @return bool
 */
bool g(int x)
{
    int gx = ( ( f(x) + f(f(x)) ) /2 );
    return isPrime(gx);
}

int main()
{
    int i = 0;
    cin >> i;
    for (int j = 0; j < i; j++){
        int x;
        cin >> x;
        if ( g(x) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}