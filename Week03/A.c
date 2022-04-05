#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef char VertexType; //��������Ӧ���û�����
typedef int EdgeType; //���ϵ�Ȩֵ����Ӧ���û�����
typedef struct graph {
    VertexType vexs[MAXSIZE];//�����
    EdgeType arc[MAXSIZE][MAXSIZE];//�ڽӾ���
    int numNodes, numEdges;
}Graph;
void CreateGraph(Graph* graph);
int main()
{
    Graph graph;
    CreateGraph(&graph);
    //��ӡ�ڽӾ���
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
    //�ڽӾ�����0(0��ʾû�ߣ�1��ʾ�б�)
    for (i = 0; i < graph->numNodes; ++i) {
        for (j = 0; j < graph->numNodes; ++j) {
            graph->arc[i][j] = 0;
        }
    }
    //���붥����, ����;
    scanf("%d %d", &graph->numNodes, &graph->numEdges);
    getchar(); //�����հ׷�
    scanf("%d", &x);//0Ϊ����ͼ��1Ϊ����ͼ
    for (i = 0; i < graph->numNodes; ++i) {
        //���붥��;
        scanf("%c", &graph->vexs[i]);
        getchar();//�����հ׷�
    }
    int start, end;
    for (i = 0; i < graph->numEdges; ++i) {
        //������㣬 �յ�
        scanf("%d %d", &start, &end);
        getchar(); //�����հ׷�
        int startIndex, endIndex;
        for (j = 0; j < graph->numNodes; ++j) {//�ҵ���ʼ��,�յ�
            if (start == j) { //�����ҵ������±�
                startIndex = j;
            }
            if (end == j) { //�����ҵ��յ���±�
                endIndex = j;
            }
        }
        graph->arc[startIndex][endIndex] = 1;
        //���������ͼ����Ҫ˫�򱣴�
        if (x == 0) {
            graph->arc[endIndex][startIndex] = 1;
        }
    }
}
