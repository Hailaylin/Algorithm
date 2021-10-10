/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-10-10 14:53:42
 * @LastEditTime: 2021-10-10 17:07:32
 * @FilePath: \Algorithm\ccpc2021\2.cpp
 */

/**
Kanade Doesn't Want to Learn CG
Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 262144/262144 K (Java/Others)
Total Submission(s): 1786    Accepted Submission(s): 374


Problem Description
Computational geometry and computer graphics are such hard parts of computer science that Kanade can't manage them. So she doesn't want to learn CG anymore. She goes to play basketball instead.

The only essential equipment in a basketball game is the ball and the hoop — a flat, rectangular backboard with a basket. We describe the hoop with a side view. Ignoring the thickness, the backboard is considered as a segment parallel to the y-axis, and the basket is considered as a segment parallel to the x-axis. The right end of the basket is connected to the backboard.

To simplify the model, we consider a basketball as a mass point. Taking only gravity into consideration, if we ignore the basket and the backboard, the trajectory of basketball will be a parabola y=ax2+bx+c with a<0. But the basketball is likely to hit the backboard, resulting in a change in trajectory. We consider the collision between a basketball and the backboard (including the endpoints) as a perfectly elastic collision, which means the velocity on the x-axis of the basketball will be reversed, and the velocity on the y-axis will remain the same. We ignore the court floor in this problem.

If the basketball passes through the basket (excluding the endpoints) from top to bottom, we consider the shoot is a goal. Once the basketball touches either of the endpoints of the basket, which means it hits the rim, the basketball will be bounced away and cannot make a goal. In addition, according to the rule, a basketball cannot pass through the basket from bottom to top, or it is a violation and cannot be counted as a goal.

Kanade knows the value of a,b,c and the position of the backboard and basket. She would like to know whether the shoot will be a goal if the basketball starts from x=−1145141919810 and moves in the positive direction of the x-axis.
 

Input
The first line of input contains one integer T (1≤T≤500), indicating the number of test cases.

For each test case, the first line contains three integers a,b,c (a<0), indicating the parameters of the parabola.

The second line of each test case contains five integers x0,x1,y0,y1,y2 (x0<x1,y1<y0<y2), indicating that the two endpoints of the basket are (x0,y0) and (x1,y0), and the two endpoints of the backboard are (x1,y1) and (x1,y2).

It is guaranteed that the absolute value of all integers in the input won't exceed 104.
 

Output
For each test case, if the shoot is a goal, output Yes in a single line, otherwise output No in a single line.
 

Sample Input
4
-1 4 5
3 5 6 5 8
-2 -3 3
-1 0 2 1 4
-1 -9 19
8 10 6 5 8
-1 9 19
8 10 4 3 6
 

Sample Output
Yes
Yes
No
No
 

Hint
The samples are shown as follows. Segment AB represents the basket, and segment CD represents the backboard.
 * 
 */

#include<iostream>
using namespace std;

int a, b, c;
int x0, x1, y0, y1, y2;

int y(int x)
{
    return a*x*x + b*x + c;
}

/**
 * @brief （x,y）点附近斜率，1向上，0向下；输入
 * 
 * @param xx 
 * @param yy 
 * @return true 
 * @return false 
 */
bool k(int xx, int yy)
{
    if ( (y(xx) - y(xx+0.01)) / (0.01)) return true;
    else false;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        scanf("%d %d %d %d %d", &x0, &x1, &y0, &y1, &y2);
        //1. 在A点上，抛物线在上面
        if ( y(x0) > y0 )
        {
            // IV情况：超过D点，投得太远
            if ( y(x1) > y2 )
                cout << "NO" << endl;
            // I情况：穿心投进
            if ( y(x1) < y0 ) 
                cout << "Yes" << endl;
            // II情况：反弹侧击
            if ( y(x1) < y2 && y(x1) > y0 )
            {
                //反弹后移动的x
                int xf0 = x0- 2*(-b/ (2*a));
                int h = -b/(2*a);
                int k = (4*a*c - b*b)/(4*a);
                int yf0 = a*(xf0-h)*(xf0-h) + k;
                //1. 反弹后曲线进框，端点不行
                if ( yf0 < y0) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
            // 打中篮筐不行
            if (y0 == y(x0)) cout << "NO" << endl;
        }
        //2. 曲线在A点下
        else if ( y(x0) < y0 )
        {
            // III情况：曲线在A点下且下降
            cout << "NO" << endl;
        }
        //3. 蓝球打框不行
        else cout << "NO" << endl;
    }
}