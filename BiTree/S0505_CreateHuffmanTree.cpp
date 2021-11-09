/*
 * @Description:题目:构造哈夫曼树和哈夫曼编码
 * @Author: HailayLin
 * @Date: 2021-11-09 19:41:06
 * @LastEditTime: 2021-11-09 19:51:25
 * @FilePath: \Algorithm\BiTree\S0505_CreateHuffmanTree.cpp
 */

/**
 * @brief
题目内容：
构造哈夫曼树，输出其根结点权值。
例1（第1、2行为输入）：
8
5 29 7 8 14 23 3 11
HT[7]=3,HT[1]=5
HT[3]=7,HT[4]=8
HT[9]=8,HT[8]=11
HT[5]=14,HT[10]=15
HT[11]=19,HT[6]=23
HT[2]=29,HT[12]=29
HT[13]=42,HT[14]=58
100

例2（第1、2行为输入）：
2
5 6
HT[1]=5,HT[2]=6
11

 请注意，main()函数必须按如下所示编写：
int main()
{
    HuffmanTree T;
    int n;
    cin>>n;
    CreateHuffmanTree(T,n); //创建哈夫曼树
    cout<<T[2*n-1].weight<<endl; //哈夫曼树根结点权值

    return 0;
}

题目内容：
在S0506的基础修改程序，根据权值设计其对应的哈夫曼编码。
例（前2行为输入）：
8
5 29 7 8 14 23 3 11
5-->0001
29-->10
7-->1110
8-->1111
14-->110
23-->01
3-->0000
11-->001

 请注意，main()函数必须按如下所示编写：
int main()
{
    HuffmanTree T;
    HuffmanCode HC;
    int n;
    cin>>n;
    CreateHuffmanTree(T,n); //创建哈夫曼树
    CreatHuffmanCode(T,HC,n); //设计哈夫曼编码
    for(int i=1;i<=n; i++)
    {
        cout<<T[i].weight<<"-->"<<HC[i]<<endl; //输出哈夫曼编码
    }

    return 0;
}
 *
 */

#include<iostream>
#include<string.h>
using namespace std;

// 哈夫曼编码的存储表示
typedef char **HuffmanCode;

typedef struct HTNode{
    int weight; // 节点权值
    int parent,lchild, rchild;  // 节点双亲、左右孩子
}HTNode, *HuffmanTree;


/**
 * @brief 查找哈夫曼树中最小的两个数的数组下标
 * @param HT
 * @param n 哈夫曼树的叶子节点数
 * @param s1 返回最小的数组下标
 * @param s2 返回第二小的数组下标
 */
void Select(HuffmanTree &HT, int len, int &s1, int &s2)
{
    s1 = s2 = 0;
    int min1, min2;
    min1 = min2 = 1000;
    for(int i=1; i<=len; i++)
    {
        if(HT[i].parent != 0) continue;
        int weight = HT[i].weight;
        // 最小的
        if(min1 > weight && min2 > weight ){
            min2 = min1;
            min1 = weight;
            s2 = s1;
            s1 = i;
        }   // 使用else if排除多次选择的情况
        else if(min1 <= weight && min2 > weight){ // 相同的权值29不会被选到min2，问题出在这
            min2 = weight;
            s2 = i;
        }
    }
}

void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
    HC = new char*[n+1];    // 字符指针数组HC
    char *cd = new char[n]; // 字符指针数组元素存的哈夫曼编码
    cd[n-1]='\0';
    for(int i=1; i<=n; i++)
    {
        int start = n-1;
        int child = i;
        int parent = HT[i].parent;
        while(parent != 0)
        {
            --start;
            if(HT[parent].lchild == child) cd[start] = '0';
            else cd[start] = '1';
            child = parent;
            parent = HT[parent].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i], &cd[start]);
    }
    delete cd;
}

void ShowHMTree(HuffmanTree &HT,int n)
{
    // 遍历输出表的值
    for(int i=1; i<=2*n-1; i++)
    {
        cout << "i=" << i << "\tWeight=" << HT[i].weight << "\tParent=" << HT[i].parent << "\tLeftChild=" <<HT[i].lchild << "\tRightChild=" << HT[i].rchild << endl;
    }
}

/**
 * @brief Create a Huffman Tree object
 *
 * @param HT
 * @param n 叶子结点个数
 */
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    // 初始化
    if(n<=1) return ;
    int m = 2*n-1;
    HT = new HTNode[m+1];   // 不用0节点，多生成一个
    for(int i=0; i<=m; i++)   // 所有节点初始化
    {
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(int i=1;i<=n;i++)
        cin >> HT[i].weight;

    // 2.创建树
    // 2.1 从森林中选择双亲为0且权值最小的两个树根节点并返回根节点在表中位置
    int s1, s2;
    for(int i=n+1; i<=m; i++)
    {
        Select(HT, i-1, s1, s2);
        // 2.2 设定值
        HT[s1].parent=i; HT[s2].parent=i;
        HT[i].lchild=s1; HT[i].rchild=s2;
        //printf("HT[%d]=%d,HT[%d]=%d\n", s1, HT[s1].weight, s2, HT[s2].weight);
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void ShowHMCode(HuffmanTree HT, HuffmanCode HC, int n)
{
    for (int i=1; i<=n; i++)
    {
        cout << HT[i].weight << "编码为" << HC[i] << endl;
    }
}

int main()
{
    HuffmanTree T;
    int n;
    cin>>n;
    CreateHuffmanTree(T,n); //创建哈夫曼树
    cout<<T[2*n-1].weight<<endl; //哈夫曼树根结点权值

    return 0;
}