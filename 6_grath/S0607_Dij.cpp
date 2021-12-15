/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-15 10:03:27
 * @LastEditTime: 2021-12-15 13:59:31
 * @FilePath: \Algorithm\6_grath\S0607_Dij.cpp
 */
/*
题号：S0607        题目:最短路径（迪杰斯特拉算法）        得分：100  
  
作业提交截止时间：2041/7/24 0:00:00	 
 	
题目内容：
给定一个有向图，利用迪杰斯特拉算法求某一顶点到其他顶点的最短路径。
例（最后6行为输出，其中-1表示其前面两个顶点之间没有路径）：
6 8
ABCDEF
AC 10
AF 100
AE 30
BC 5
CD 50
DF 10
ED 20
EF 60
AA:0
AB:-1
AC:10
AD:50
AE:30
AF:60
 请注意，main()函数必须按如下所示编写：
int main()
{
    int vnum,anum; //顶点数与边数
    cin>>vnum>>anum;
    AMGraph G;
    CreateUDN(G,vnum,anum);  //创建无向图的邻接矩阵(至少两个顶点) 
    ShortestPath_DIJ(G,0);
    return 0;
}
*/

#include<iostream>
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
    int arcnum;
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
    cin >> G.vexnum >> G.arcnum;

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
    for(int k=0; k<G.arcnum; k++)
    {
        //cout << "// 3.1 输入一条边依附的顶点v1 v2 w权值:";
        cin >> v1 >> v2 >> weight;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        //G.arcs[j][i] =    // 要求有向图 
        G.arcs[i][j] = weight;
    }

    return 0;
}

/**
 * @brief 输出矩阵图
 */
Status ShowUDN(AMGraph &G)
{
    for(int i=0; i<G.vexnum; i++) {
        for(int j=0; j<G.vexnum; j++)
            if (G.arcs[i][j] == MaxInt) {
                cout << "∞\t";
            }
            else {
                cout << G.arcs[i][j] << "\t";
            }
        cout << endl;
    }
    return OK;
}

void DisplayPath(AMGraph G , int begin ,int temp );

// 记录当前节点与v0路径是否已是最短路径
bool isShort[MVNum] = {false};
// 当前最短路径前驱，初始值为-1, v0=-1
int prePath[MVNum];
// 当前最短路径长度
int ShortDis[MVNum] = {MaxInt};
void ShortestPath_DIJ(AMGraph &G, int v0) {
    /* ---- 初始化顶点、边与中间过程集合 --- */

    int v = 0;
    int n = G.vexnum;
    for(v = 0; v < n; v++) {
        isShort[v] = false;
        // 初始化v0到各顶点弧值为最小值
        ShortDis[v] = G.arcs[v0][v];
        // 如果顶点v0-v有边，就把直接前驱设置成v0，否则-1
        if (ShortDis[v] < MaxInt) {
            prePath[v] = v0;
        }
        else {
            prePath[v] = -1;
        }
    }
    isShort[v0] = true;
    ShortDis[v0] = 0;

    /* --- 从1到n-1寻找v0到某顶点vi的最短路径 ---- */
    for (int i = 1; i < n; i++) {
        // 标记 min 找v0到v[w]点的最小弧，记下v=w,并标记v点已为最小弧
        int min = MaxInt;
        for (int w = 0; w < n; w++)
            if (isShort[w] == false && ShortDis[w] < min) {
                v = w;
                min = ShortDis[w];
            }
        isShort[v] = true;
        // 从w出发更新各顶点的最短路径值
        for (int w = 0; w < n; w++) {
            if (isShort[w]==false && ShortDis[v]+G.arcs[v][w] < ShortDis[w]) {
                ShortDis[w] = ShortDis[v] + G.arcs[v][w];
                prePath[w] = v;
            }
        }
    }
    
    // /* --- 输出各点到源点的最短路径和长度 --- */
    // for (int i = 1; i < n; i++) {
    //     int u = i;
    //     int dis = 0;
    //     while(prePath[u] != -1) {
    //         printf(" -> prePath[%d]=%d", u, prePath[u]);
    //         dis = ShortDis[u];
    //         u = prePath[u];
    //     }
    //     printf(" dis=%d\n", dis);
    // }
    // printf("\n");
    for (size_t i = 0; i < n; i++)
    {
        cout << "A" << G.vexs[i] <<  ":";
        if (ShortDis[i] == MaxInt) cout << -1 << endl;
        else cout << ShortDis[i] << endl;
        DisplayPath(G, 0, i);
        cout << G.vexs[i] << endl;
    }
    
}

void DisplayPath(AMGraph G , int begin ,int temp ){
	//显示最短路
	if(prePath[temp] != -1){
		DisplayPath(G , begin ,prePath[temp]);
		cout << G.vexs[prePath[temp]] << "-->";
	}
}//DisplayPath

int main()
{
    int vnum,anum; //顶点数与边数
    AMGraph G;
    CreateUDN(G);  //创建无向图的邻接矩阵(至少两个顶点)
    ShowUDN(G);
    ShortestPath_DIJ(G,0);
    return 0;
}