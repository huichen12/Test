#include <stdio.h>
#include <stdlib.h>
#define VertexType char //������������ͣ�char�� 
#define VertexMax 20 //��󶥵���� 
int visited[VertexMax];//����ȫ�����飬��¼��Ƕ����Ƿ񱻷��ʹ�
typedef struct ArcNode//�߱� 
{
    int adjvex;//�洢���Ǹö����ڶ������鼴AdjList[]�е�λ�� 
    struct ArcNode* nextarc;
}ArcNode;
 
typedef struct VNode //�������� 
{
    char data;
    struct ArcNode* firstarc;
}VNode;
 
typedef struct //����� 
{
    VNode AdjList[VertexMax];//�ɶ��㹹�ɵĽṹ������ 
    int vexnum, arcnum; //�������ͱ��� 
    int kind; //��¼ͼ������ 
}ALGraph;
void CreateDG(ALGraph* G)
{
    int i, j;
    int flag;
    //1.���붥�����ͱ��� 
    scanf("%d%d", &G->vexnum, &G->arcnum);
    scanf("%d", &flag);
    getchar();
    //2.�������������ֵ��ʼ�������ָ���� 
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->AdjList[i].data);
        G->AdjList[i].firstarc = NULL;
        getchar();
    }
    //3.�������Ϣ�����ڽӱ� 
    int v1, v2;
    ArcNode* p1, * p2;
    for (i = 0; i < G->arcnum; i++)
    {   //�������Ϣ����ȷ��v1��v2��G�е�λ�ã���������AdjList[]�����е�λ�ã��±꣩  
        scanf("%d%d", &v1, &v2);
        if (flag == 0) {
            p1 = (ArcNode*)malloc(sizeof(ArcNode));
            p1->adjvex = v2;//�������� 
            p1->nextarc = G->AdjList[v1].firstarc;//������ͷ�巨��  
            G->AdjList[v1].firstarc = p1;
            p2 = (ArcNode*)malloc(sizeof(ArcNode));//����ͼ�ĶԳ� 
            p2->adjvex = v1;
            p2->nextarc = G->AdjList[v2].firstarc;
            G->AdjList[v2].firstarc = p2;
        }
        else {
            p1 = (ArcNode*)malloc(sizeof(ArcNode));
            p1->adjvex = v2;//�������� 
            p1->nextarc = G->AdjList[v1].firstarc;//������ͷ�巨��  
            G->AdjList[v1].firstarc = p1;
        }
    }
}
 
void DFS(ALGraph G, int v) {
    printf("%c ", G.AdjList[v].data);
    visited[v] = 1;
    ArcNode* p = G.AdjList[v].firstarc;
    while (p) {
        if (!visited[p->adjvex])
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}
//�����������
void DFSTraverse(ALGraph G) {
    int v;
    //��������ǵ�visit�����ʼ��Ϊ0
    for (v = 0; v < G.vexnum; ++v) {
        visited[v] = 0;
    }
    //����ÿ�����Ϊfalse�Ķ���������������������
    for (v = 0; v < G.vexnum; v++) {
        //����ö���ı��λΪfalse����������������������
        if (!visited[v]) {
            DFS(G, v);
        }
    }
}
int main()
{
    ALGraph G;
    CreateDG(&G);
    DFSTraverse(G);
    return 0;
}
