/*
 Kruskal算法生成最小代价生成树
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXV 100
#define INF 32767
typedef char InfoType;


typedef struct
{
	int no;		
	InfoType info;	
}VertexType;	

typedef struct
{
	int edges[MAXV][MAXV];	
	int n, e;	
	VertexType vexs[MAXV];	
}MatGraph;

void createMat(MatGraph* g, int A[MAXV][MAXV], int n, int e)
{
	int i, j;
	g->n = n;
	g->e = e;
	for (i = 0; i < g->n; i++)
	{
		for (j = 0; j < g->n; j++)
		{
			g->edges[i][j] = A[i][j];
		}
	}
}

typedef struct
{
	int u;
	int v;
	int w;
} Edge;

void InsertSort(Edge* E, int n)
{
	int i, j;
	Edge temp;
	for(i = 1; i < n; i++)
	{
		temp = E[i];
		j = i - 1;
		while(j >= 0 && temp.w < E[j].w)
		{
			E[j+1] = E[j];
			j--;	
		}
		E[j+1] = temp;
	}
}

void kruskal(MatGraph g)
{
	int i,j,u1,v1,sn1,sn2,k;
	int totall = 0;
	int vset[MAXV];
	Edge E[MAXV];
	k = 0;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
		}
	}
	InsertSort(E,g.e);
	for(i=0;i<g.n;i++)
	{
		vset[i] = i;
	}
	k = 1;
	j = 0;
	while(k<g.n)
	{
		u1 = E[j].u;
		v1 = E[j].v;
		sn1 = vset[u1];
		sn2 = vset[v1];
		if(sn1 != sn2)
		{
			totall = totall + E[j].w;
			printf("%d %d %d\n",u1,v1,E[j].w);
			k++;
			for(i=0;i<g.n;i++)
			{
				if(vset[i] == sn2)
				{
					vset[i] = sn1;
				}
			}
		}
		j++;
	}
	printf("%d\n",totall);
}

int main()
{
	MatGraph g;
	int n, e, i, j;
	int A[MAXV][MAXV];
	scanf("%d%d", &n, &e);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
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
	for (i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		A[a][b] = c;
		A[b][a] = c;
	}
	createMat(&g, A, n, e);
	kruskal(g);
	return 1;
}
