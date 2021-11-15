/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-11-15 10:37:10
 * @LastEditTime: 2021-11-15 11:07:09
 * @FilePath: \Algorithm\6_grath\S0602.cc
 */

/**
 * 题号：S0602        题目:无向图的广度优先搜索遍历（邻接矩阵）        得分：0  
  
作业提交截止时间：2021/11/15 12:00:00	 
 	
题目内容：
在S0305与S0601的基础上修改程序，使用邻接矩阵完成无向图的广度优先搜索遍历。

例1（最后2行为输出，其他为输入）：
8 8
ABCDEFGH
AF 1
BA 2
BC 3
CG 4
BD 5
BE 6
GH 7
DH 8
ABFCDEGH
BACDEFGH

例2（最后2行为输出）：
5 4
BACDE
AB 1
BC 2
BD 3
DE 4
BACDE
ABCDE

例3（最后1行为输出）：
1 0
A
A

请注意，main()函数必须按如下所示编写：
int main()
{
    AMGraph G;
    CreateUDN(G);  //创建无向图的邻接矩阵 
    BFS(G,0); //广度优先搜索遍历图 
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    if(G.vexnum>1) BFS(G,1); 
    cout<<endl;
    return 0;
}

*/

#include<iostream>
#include<queue>
using namespace std;

/** 网的相关信息、限制 **/
#define MaxInt 32767    // 等价无穷大值
#define MVNum 100   // 最大顶点数
typedef char VertexTpye;    // 顶点用char存，可能是ABCD字符
typedef int ArcTpye;    // 边的权值

/* 返回状态标识 */
typedef int Status; // 返回状态
#define OK 1
#define ERROR 0

/* 用邻接表存储网的结构体定义 */
typedef struct AMGraph{
    // 顶点集
    VertexTpye vexs[MVNum];
    // 邻接矩阵
    ArcTpye arcs[MVNum][MVNum];
    // 网当前节点数
    int vexnum;
    // 网当前弧数
    int arcNum;
}AMGraph;

/**
 * @brief 获取顶点数组下标
 *
 * @param G
 * @param v 要寻找的顶点
 * @return int 顶点下标，从0开始
 */
int LocateVex(AMGraph &G, VertexTpye &v)
{
    for (int i=0; i<G.vexnum; i++)
    {
        if(v == G.vexs[i]) return i;
    }
    return ERROR;
}

/* 邻接矩阵表示创建无向网G */
Status CreateUDN(AMGraph &G)
{
    //cout << "// 0.输入节点数边数" << endl;
    cin >> G.vexnum >> G.arcNum;

    //cout << "// 1.存顶点信息到顶点表" << endl;
    for (int i=0; i<G.vexnum; i++)
        cin >> G.vexs[i];

    //cout << "// 2.初始化邻接矩阵" << endl;
    for(int i=0; i<G.vexnum; i++)
        for(int j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j]=0;
        }

   // cout << "// 3.构建邻接矩阵"<< endl;
    VertexTpye v1, v2;
    ArcTpye weight;
    for(int k=0; k<G.arcNum; k++)
    {
        //cout << "// 3.1 输入一条边依附的顶点v1 v2 w权值:";
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G.arcs[j][i] = G.arcs[i][j] = weight;
    }

    return 0;
}

/**
 * @brief 输出矩阵图
 */
Status ShowUDN(AMGraph &G)
{
    for(int i=0; i<G.vexnum; i++)
    {
        for(int j=0; j<G.vexnum; j++)
            cout << G.arcs[i][j] << "\t";
        cout << endl;
    }
    return OK;
}


bool visited[MVNum];
/**
 * @brief 邻接矩阵的深度优先遍历
 *
 * @param G
 * @param v 访问元素节点下标
 */
void DFS_AM(AMGraph G, int v)
{
    // 输出访问的节点
    cout << G.vexs[v];
    visited[v]=true;
    // 递归深度遍历
    for(int w=0; w<G.vexnum; w++)
    {
        if( G.arcs[v][w]!=0 && !visited[w])
            DFS_AM(G, w);
    }
}

// 广度优先遍历
void BFS(AMGraph G, int v)
{
    // 访问最初元素+队列进队
    cout << G.vexs[v];
    visited[v] = true;
    queue<int> Q;
    Q.push(v);

    // 2.广度优先遍历
    int u;
    while (!Q.empty())
    {
        // 2.1 队头元素u出队
        u = Q.front();
        Q.pop();

        // 2.2 依次检查u的所有邻接点，若没访问过，就访问w,设置已访问，w入队
        for (int w = 0; w < G.vexnum; w++)
        {
            if (G.arcs[u][w] != 0 && !visited[w])
            {
                cout << G.vexs[w];
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}


int main()
{
    AMGraph G;
    CreateUDN(G);  //创建无向图的邻接矩阵 
    BFS(G,0); //广度优先搜索遍历图 
    cout<<endl;
    for(int i=0;i<G.vexnum;i++) visited[i]=0;
    if(G.vexnum>1) BFS(G,1); 
    cout<<endl;
    return 0;
}