/*
 * @Description: 
 * @Author: HailayLin
 * @Date: 2021-12-14 17:13:09
 * @LastEditTime: 2021-12-14 20:32:19
 * @FilePath: \Algorithm\02 DFS.cpp
 */
/* 2 1

5 4

1 0

4 4
*/

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

typedef int Status;
typedef char VerTexType;
typedef int ArcType;
#define OK 1
#define ERROR 0

#define MXNum 100
#define MaxInt 32767

typedef struct AMGraph {
	VerTexType vexs[MXNum];
	ArcType arcs[MXNum][MXNum];
	int vexnum;
	int arcnum;
}AMGraph;

int LocateVex(AMGraph G,const VerTexType &vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == vex) return i;
	}
}

Status CreateUDN(AMGraph &G) {	
	cin >> G.vexnum >> G.arcnum;
	// input vex
	for (int i = 0 ; i < G.vexnum; i++) {
		cin >> G.vexs[i];	
	}

	// init arcs
	for (int i = 0; i < G.arcnum ; i++) {
		for (int j = 0; j < G.arcnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	
	// input arc
	for (int i = 0; i < G.arcnum; i++) {
		VerTexType vex1, vex2;
		int weight;
		cin >> vex1 >> vex2 >> weight;
		int cow = LocateVex(G, vex1);
		int column = LocateVex(G, vex2);
		G.arcs[cow][column] = G.arcs[column][cow] = weight;
	}
	return OK;
}

void show(AMGraph G) {
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			cout << G.arcs[i][j] << "\t";
		}
		cout << endl;
	}
}

bool visited[MXNum];
Status DFS_AM(AMGraph G, int v) {
	cout << G.vexs[v];
	visited[v] = true;
	for(int w = 0; w < G.arcnum; w++) {
		if (G.arcs[v][w]!=MaxInt && visited[w] == false) {
			DFS_AM(G, w);	
		}
	}
}

int main() {
	AMGraph G;
	CreateUDN(G);  //创建无向图的邻接矩阵 
	//show(G);
	DFS_AM(G,0); //深度优先搜索遍历图 
	cout<<endl;
	for(int i=0;i<G.vexnum;i++) visited[i]=0;
	if(G.vexnum>1) DFS_AM(G,1);
	cout<<endl;
	return 0;
}
