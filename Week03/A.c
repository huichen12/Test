//【数据结构与算法】(week03-01) 图的邻接矩阵存储
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef char VertexType; //顶点类型应由用户定义
typedef int EdgeType; //边上的权值类型应由用户定义
typedef struct graph {
    VertexType vexs[MAXSIZE];//顶点表
    EdgeType arc[MAXSIZE][MAXSIZE];//邻接矩阵
    int numNodes, numEdges;
}Graph;
void CreateGraph(Graph* graph);
int main()
{
    Graph graph;
    CreateGraph(&graph);
    //打印邻接矩阵
    int i, j;
    for (i = 0; i < graph.numNodes; ++i) {
        for (j = 0; j < graph.numNodes; ++j) {
            printf("%d", graph.arc[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void CreateGraph(Graph* graph) {
    int i, j, x;
    //邻接矩阵置0(0表示没边，1表示有边)
    for (i = 0; i < graph->numNodes; ++i) {
        for (j = 0; j < graph->numNodes; ++j) {
            graph->arc[i][j] = 0;
        }
    }
    //输入顶点数, 边数;
    scanf("%d %d", &graph->numNodes, &graph->numEdges);
    getchar(); //消除空白符
    scanf("%d", &x);//0为无向图，1为有向图
    for (i = 0; i < graph->numNodes; ++i) {
        //输入顶点;
        scanf("%c", &graph->vexs[i]);
        getchar();//消除空白符
    }
    int start, end;
    for (i = 0; i < graph->numEdges; ++i) {
        //输入起点， 终点
        scanf("%d %d", &start, &end);
        getchar(); //消除空白符
        int startIndex, endIndex;
        for (j = 0; j < graph->numNodes; ++j) {//找到起始点,终点
            if (start == j) { //遍历找到起点的下标
                startIndex = j;
            }
            if (end == j) { //遍历找到终点的下标
                endIndex = j;
            }
        }
        graph->arc[startIndex][endIndex] = 1;
        //如果是无向图，需要双向保存
        if (x == 0) {
            graph->arc[endIndex][startIndex] = 1;
        }
    }
}
