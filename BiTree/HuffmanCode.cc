/*
 * @Description:哈夫曼编码实现
 * @Author: HailayLin
 * @Date: 2021-11-08 10:26:16
 * @LastEditTime: 2021-11-08 19:40:10
 * @FilePath: \Algorithm\BiTree\HuffmanCode.cc
 */

/**
 * @测试用例1
 * 8
 * 5 29 7 8 14 23 3 11
 * @测试用例2
请输入不同字符的个数:5
请输入字符出现的频率:9 5 1 4 6
9编码为11
5编码为00
1编码为010
4编码为011
6编码为10
 */

#include<iostream>
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
    HuffmanTree HT;
    HuffmanCode HC;
    int n;
    cout << "请输入不同字符的个数:";
    cin >> n;
    cout << "请输入字符出现的频率:";
    CreateHuffmanTree(HT, n);
    CreateHuffmanCode(HT, HC, n);
    ShowHMCode(HT, HC, n);
}