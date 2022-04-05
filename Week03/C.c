#include <stdio.h>
#include <stdlib.h>
#define VertexType char //顶点的数据类型（char） 
#define VertexMax 20 //最大顶点个数 
int visited[VertexMax];               //设置全局数组，记录标记顶点是否被访问过
typedef struct ArcNode//边表 
{
 int adjvex;//存储的是该顶点在顶点数组即AdjList[]中的位置 
 struct ArcNode *nextarc;
}ArcNode;
 
typedef struct VNode //单个顶点 
{
 char data;
 struct ArcNode *firstarc;
}VNode;
 
typedef struct //顶点表 
{
 VNode AdjList[VertexMax];//由顶点构成的结构体数组 
 int vexnum,arcnum; //顶点数和边数 
 int kind; //记录图的类型 
}ALGraph;
 
void CreateDG(ALGraph *G)
{
  int i,j;
  int flag;
  //1.输入顶点数和边数 
  scanf("%d%d",&G->vexnum,&G->arcnum);
  scanf("%d",&flag);
  getchar();
  //2.顶点表数据域填值初始化顶点表指针域 
  for(i=0;i<G->vexnum;i++)
  {
    scanf("%c",&G->AdjList[i].data);
    G->AdjList[i].firstarc=NULL;
    getchar();
  }
  //3.输入边信息构造邻接表 
  int v1,v2;
  ArcNode *p1,*p2;
  for(i=0;i<G->arcnum;i++)
  {   //输入边信息，并确定v1和v2在G中的位置，即顶点在AdjList[]数组中的位置（下标）  
   scanf("%d%d",&v1,&v2);
   if(flag==0){
      p1=(ArcNode *)malloc(sizeof(ArcNode));
    p1->adjvex=v2;//填上坐标 
    p1->nextarc=G->AdjList[v1].firstarc;//改链（头插法）  
    G->AdjList[v1].firstarc=p1;
      p2=(ArcNode *)malloc(sizeof(ArcNode));//无向图的对称 
    p2->adjvex=v1;
    p2->nextarc=G->AdjList[v2].firstarc;
    G->AdjList[v2].firstarc=p2;
     }
   else{
      p1=(ArcNode *)malloc(sizeof(ArcNode));
    p1->adjvex=v2;//填上坐标 
    p1->nextarc=G->AdjList[v1].firstarc;//改链（头插法）  
    G->AdjList[v1].firstarc=p1;
     }
 }
} 
  
void BFS(ALGraph G,int v){
 int q[100];
 int l=0,r=0;
 printf("%c ",G.AdjList[v].data);
 visited[v]=1;
 q[r++]=v;
 ArcNode * t;
 while(l<r){
  t=G.AdjList[q[l++]].firstarc;
  while(t){
   int index=t->adjvex;
   if(!visited[index]){
    visited[index]=1;
    printf("%c ",G.AdjList[index].data);
    q[r++]=index;
   }
   t=t->nextarc;
  }
 }
} 
//广度优先搜索
void BFSTraverse(ALGraph G){//
    int v;
    //将用做标记的visit数组初始化为0
    for( v = 0; v < G.vexnum; ++v){
        visited[v] = 0;
    }
    //对于每个标记为false的顶点调用广度优先搜索函数
    for( v = 0; v < G.vexnum; v++){
        //如果该顶点的标记位为false，则调用广度优先搜索函数
        if(!visited[v]){
            BFS( G, v);
        }
    }
}
int main() 
{
  ALGraph G;
  CreateDG(&G);
  BFSTraverse(G);
  return 0;
}
