/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-10-10 15:38:30
 * @LastEditTime: 2021-10-10 15:38:30
 * @FilePath: \Algorithm\ccpc2021\1.cpp
 */

/**
 * @brief Median Problem
Time Limit: 10000/5000 MS (Java/Others)    Memory Limit: 262144/262144 K (Java/Others)
Total Submission(s): 12    Accepted Submission(s): 0


Problem Description
We consider an integer x as the median of a set A containing n distinct integers if it meets the following conditions:

- x∈A
- There are at least ⌊n+12⌋ integers greater than or equal to x in set A.
- There are at least ⌊n+12⌋ integers less than or equal to x in set A.

⌊y⌋ means the largest integer that does not exceed y. For example, if A={1,3,4,5,7,9}, then either 4 or 5 is the median of set A.

Given a tree with n nodes rooted at node 1. Each node u has an associated value au, where a1,a2,…,an is a permutation of n (every integer from 1 to n occurs exactly once). Each node u has another value bu satisfying the following condition:

- bu is the median of the set {au}∪{bv∣node u is the parent of node v}. (The parent of node v is the node directly connected to v on the path to the root.)

Unfortunately, you forget some of ai and all bi except b1. Now you are wondering how many different permutations a1,a2,…,an that can match the ai and b1 you remember when the tree satisfies the condition above. We consider two permutations p1,p2,…,pn and q1,q2,…,qn different if there exists an index i satisfying pi≠qi.

You are required to calculate the number of different permutations a1,a2,…,an modulo 998244353, for each b1∈[1,n] respectively.
 

Input
The first line of the input contains an integer T (1≤T≤80), representing the number of test cases.

The first line of each test case contains an integer n (2≤n≤80), representing the number of nodes.

The second line of each test case contains n−1 integers p2,p3,…,pn (1≤pi<i), where pi represents the parent of node i.

The third line of each test case contains n integers a1,a2,…,an (0≤ai≤n), representing the value of each node. ai=0 means you forget ai. It is guaranteed that all non-zero ai are distinct.

It is guaranteed that there are at most 5 test cases satisfying n>10.
 

Output
For each test case, output a single line containing n integers, the k-th of which is the answer when b1=k.

Don't print any extra spaces at the end of each line.
 

Sample Input
2
4
1 1 1
0 0 0 2
5
1 1 2 2
0 0 1 5 0
 

Sample Output
0 6 6 0
0 2 4 0 0
 
 * 
 */