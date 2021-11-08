/*
 * @Description:哈夫曼编码实现
 * @Author: HailayLin
 * @Date: 2021-11-08 10:26:16
 * @LastEditTime: 2021-11-08 11:46:19
 * @FilePath: \Algorithm\BiTree\HuffmanCode.cc
 */

#include<iostream>
using namespace std;

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
void Select2MinHMTree(HuffmanTree &HT, int n, int s1, int s2)
{
    s1 = s2 = 0;
    for(int i=1; i<n; i++)
    {
        int weight = HT[i].weight;
        if(HT[i].parent==0)
        {
            if(weight < HT[s2].weight)
            {
                if(weight > HT[s1].weight)
                {
                    s2 = i;
                }
                if(weight <= HT[s1].weight)
                {
                    s2 = s1;
                    s1 = i;
                }
            }
        }
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
    for(int i=0; i<=m+1; i++)   // 所有节点初始化
    {
        HT[i].weight=0;
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    cout << "顺序输入各叶子节点权重:";
    for(int i=1;i<=n;i++)
        cin >> HT[i].weight;
    // 2.创建树
    // 2.1 从森林中选择双亲为0且权值最小的两个树根节点并返回根节点在表中位置
    int s1, s2;
    for(int i=n+1; i<=m; i++)
    {
        Select2MinHMTree(HT, i-1, s1, s2);
        // 2.2 设定值
        HT[s1].parent=i; HT[s2].parent=i;
        HT[i].lchild=s1; HT[i].rchild=s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void ShowHMTree(HuffmanTree &HT,int n)
{
    // 遍历输出表的值
    for(int i=0; i<=2*n+1; i++)
    {
        cout << "i=" << i << "\tParent=" << HT[i].parent << "\tLeftChild=" <<HT[i].lchild << "\tRightChild=" << HT[i].rchild << endl;
    }
}

int main()
{
    HuffmanTree HT;
    int n;
    cout << "叶子结点个数:";
    cin >> n;
    CreateHuffmanTree(HT, n);
    ShowHMTree(HT,n);
}