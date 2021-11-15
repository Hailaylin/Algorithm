/*
 * @Description: 邻接表建立图
 * @Author: HailayLin
 * @Date: 2021-11-07 14:36:20
 * @LastEditTime: 2021-11-15 11:09:41
 * @FilePath: \Algorithm\6_grath\0602_AdjacencyList.cpp
 */

#include<iostream>
using namespace std;

/** 网的相关信息、限制 **/
#define MaxInt 32767    // 等价无穷大值
#define MVNum 100   // 最大顶点数
typedef char VertexTYPE;    // 顶点用char存，可能是ABCD字符
typedef int ArcTYPE;    // 边的权值
typedef int OtherINFO;

/* 返回状态标识 */
typedef int Status; // 返回状态
#define OK 1
#define ERROR 0

/* 边节点 */
typedef struct ArcNode{
    int adjvex; // 该边（弧）指向的顶点vi下标i
    struct ArcNode *arcNext;    // 下一条还连在vex上的边
    OtherINFO info;
}ArcNode;

/* 顶点信息 */
typedef struct VexNode{
    VertexTYPE data;    // 节点的名字
    ArcNode *firstArc;  // 节点连接的第一条边
}VexNode, AdjList[MVNum];   // 构建表头节点表

/* 邻接表结构体 */
typedef struct ALGraph{
    AdjList vertices;   // 表头节点表
}

