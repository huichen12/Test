
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXV 100
#define INF 32767
typedef char InfoType;

//邻接矩阵类型
typedef struct
{
	int no;  //顶点编号
	InfoType info;  //顶点其他信息
}VertexType; //顶点类型

typedef struct
{
	int edges[MAXV][MAXV]; //邻接矩阵数组
	int n, c; //顶点数，边数
	VertexType vexs[MAXV]; //存放顶点信息
}MatGraph;


void createMat(MatGraph* g, int A[MAXV][MAXV], int n, int c)
{
	int i, j;
	g->n = n;
	g->c = c;
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			g->edges[i][j] = A[i][j];
		}
	}
}
void printMat(MatGraph g)
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (g.edges[i][j] != INF)
			{
				printf("%4d", g.edges[i][j]);
			}
			else
			{
				printf("%4s", "∞");
			}
		}
		printf("\n");
	}
}

void prim(MatGraph g, int v)
{
	int totall = 0;
	int lowcost[MAXV], closest[MAXV];
	int min, i, j, k;
	for (i = 0; i < g.n; i++)
	{
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for (i = 1; i < g.n; i++)
	{
		min = INF;
		for (j = 0; j < g.n; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j; //记录最近顶点编号
			}
		}
		totall = totall + min;
		printf("%d %d %d\n", closest[k], k, min);
		lowcost[k] = 0;
		for (j = 0; j < g.n; j++)
		{
			if (g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j])
			{
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
		}
	}
	printf("%d", totall);
}

int main()
{
	MatGraph g;
	int n, e;
	int A[MAXV][MAXV];
	scanf("%d%d", &n, &e);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				A[i][j] = 0;
			}
			else
			{
				A[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A[a][b] = c;
		A[b][a] = c;
	}
	createMat(&g, A, n, e);
	int v = 0;
	prim(g, v);
	return 1;
}
