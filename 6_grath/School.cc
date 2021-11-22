/*
 * @Description: 校园导航
 * @Author: HailayLin
 * @Date: 2021-11-22 10:22:23
 * @LastEditTime: 2021-11-22 11:13:42
 * @FilePath: \Algorithm\6_grath\School.cc
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

/* 用邻接矩阵存储网的结构体定义 */
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
            G.arcs[i][j]=MaxInt;
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
        if( G.arcs[v][w]!=MaxInt && !visited[w])
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
            if (G.arcs[u][w] != MaxInt && !visited[w])
            {
                cout << G.vexs[w];
                visited[w] = true;
                Q.push(w);
            }
        }
    }
}


void Show_DIJ(int Path[], int v0)
{
    if (Path[v0] == -1) cout << "无最短路径" << endl;
    int vi = v0;
    while (Path[vi])
    {
        printf("Path[%d]=%d ——> ", vi, Path[vi]);
        vi = Path[vi];
    }
    printf("\n");
}


/**
 * @brief Dijkstra算法 求单源最短路径
 * 
 * @param G 
 * @param v0 顶点
 */
void ShortestPath_DIJ(AMGraph G, int v0)
{
    // 1. 初始化
    int n = G.vexnum;
    bool S[n] = {false};
    int Path[MVNum] = {0};
    int D[MVNum] = {0};
    int v ;
    for (v = 0; v < n; v++)
    {
        S[v] = false;
        D[v] = G.arcs[v0][v];
        if (D[v] < MaxInt) Path[v] = v0;    // 有弧：v前驱为v0，下标
        else Path[v] = -1;  // 无弧 -1
    }
    S[v0] = true;
    D[v0] = 0;

    // 2. 每次求得v0到某个顶点v的最短路径，将v加到S集
    for (int i = 0; i < n; i++)
    {
        int min = MaxInt;
        for (int w = 0; w < n; w++)
        {
            if (!S[w] && D[w] < min)
            {
                v = w;
                min = D[w];
            }
        }

        S[v] = true;
        for (int w = 0; w < n; w++)
        {
            if (!S[w] && (D[v] + G.arcs[v][w] < D[w]))
            {
                D[w] = D[v] + G.arcs[v][w];
                Path[w] = v;
            }
        }
    }

    // 3. 输出最短路径
    Show_DIJ(Path, v0);
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
    cout << "输入要查看的最短路径的源点：" << endl;
    int n;
    cin >> n; 
    ShortestPath_DIJ(G, n);
    return 0;
}

/**
 * @brief 测试用例
 * 
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
 * 
 */