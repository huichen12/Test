/*
��Dijkstra�㷨�����·��
*/
#include <stdio.h>
#include <stdlib.h>
#define VertexMax 100 //��󶥵���Ϊ20
#define MaxInt 32767 //��ʾ�����������ʾ �� 

typedef int VertexType; //ÿ��������������Ϊ�ַ��� 

typedef struct{
	VertexType Vertex[VertexMax];//��Ŷ���Ԫ�ص�һά���� 
	int AdjMatrix[VertexMax][VertexMax];//�ڽӾ����ά���� 
	int vexnum,arcnum;//ͼ�Ķ������ͱ���  
}MGraph;

int LocateVex(MGraph *G,VertexType v){//����Ԫ��v��һά���� Vertex[] �е��±꣬�������±� 
	int i;
	for(i=0;i<G->vexnum;i++){
		if(v==G->Vertex[i]){
			return i; 
		} 
	 } 
	 return -1;
}
int CreateDN(MGraph *G) {
	int i,j,start;
	//���붥�����ͱ��� 
	scanf("%d",&G->vexnum);
	scanf("%d",&G->arcnum);
	scanf("%d",&start);
	//����Ԫ�� 
	for(i=0;i<G->vexnum ;i++){
		G->Vertex [i] =i;
	}
	//�����ʼ��
	for(i=0;i<G->vexnum;i++) 
	 for(j=0;j<G->vexnum;j++){
	    	G->AdjMatrix[i][j]=MaxInt;
		}
	 //�����ڽӾ���
	 int n,m;
	 VertexType v1,v2;
	 int w;//1->v2��Ȩֵ 
	 for(i=0;i<G->arcnum;i++){
	 	scanf("%d%d%d",&v1,&v2,&w);
	 	n=LocateVex(G,v1); //��ȡv1����Ӧ����Vertex�����е����� 
	 	m=LocateVex(G,v2); //��ȡv2����Ӧ����Vertex�����е�����
	 	if(n==-1||m==-1){
		 	return 0 ;
		  } 
	   G->AdjMatrix[n][m]=w;
	 }
	 return start;
}
void displayPath(int dist[],int path[],MGraph *G,VertexType start){
	int i,k,j=0;
	int temp[VertexMax];//��ʱ���� 
	int loc=0; 
	
	for(i=0;i<VertexMax;i++)
	temp[i]=-1;
	for(i=0;i<G->vexnum;i++){
		loc=i;
		j=0;
		while(loc!=-1){
    		temp[j]=loc;
    		loc=path[loc];
    		j++;
		}
		if(j-1==0&&G->Vertex[temp[j-1]]==start){
			}
			else if(j-1==0&&G->Vertex[temp[j-1]]!=start)	{
			}
			else	{
				printf("%d ",dist[i]);
				for(j=j-1;j>=0;j--){
					printf("%d ",G->Vertex[temp[j]]);
				}
				printf("\n"); 
			}
	    for(k=0;k<20;k++)
	    temp[k]=-1; 
	}
}
int FindMinDist(int dist[],int s[],int vexnum) {
	int i;
	int loc;
	int min=MaxInt+1;
	for(i=0;i<vexnum;i++){
		if(s[i]==0){//ֻ��s[i]=0�Ķ�����в��� 
			if(dist[i]<min){
				min=dist[i];
				loc=i;
			}
		}
	}
	return loc;//����dist����СԪ�ص��±� 
}
void ShortestPath_Dijkstra(MGraph *G,VertexType start){
	int i,num;
	int loc;
	int min;
	int dist[VertexMax];//���·���������� 
	int path[VertexMax];//���·������ 
	int s[VertexMax];//������S��1����ö����Ѵ������ڼ���S��0����ö���δ���������ڼ���S�����ڼ���V-S�� 
	//��ʼ��dist��path���� 
	loc=LocateVex(G,start);//��ȡԴ����±�λ�� 
	for(i=0;i<G->vexnum;i++){
		dist[i]=G->AdjMatrix[loc][i];
		if(dist[i]!=MaxInt){
			path[i]=loc;
		}
		else{
			path[i]=-1;
		}	  
	} 
    //��ʼ��S���飨s���飺������S��1�����Ԫ�����ڼ���S(�Ѵ���Ķ���)��0��Ԫ�ز����ڼ���S(δ����Ķ���)�� 
    for(i=0;i<G->vexnum;i++){
		s[i]=0;
	} 
	s[loc]=1;//������ʼ��(Դ��)�Դ������ 
	num=1;
	while(num<G->vexnum){
		min=FindMinDist(dist,s,G->vexnum);//��dist�����в������Ӧs[i]=0����δ�������СֵԪ�� 
		s[min]=1;//���ҵ�����̱�����Ӧ�ĵĶ�����뼯��S
		
		for(i=0;i<G->vexnum;i++){//�����µĶ���󣬸���dist��path���� 
		
			if((s[i]==0)&&(dist[i]>dist[min]+G->AdjMatrix[min][i])){
				dist[i]=dist[min]+G->AdjMatrix[min][i];
				path[i]=min;//min->i
			}
		}
	    num++;	
	} 
    displayPath(dist,path,G,start);//չʾdist���顢path���鼰���·�� 
    
} 
int main() {
	MGraph G;
	VertexType start;
	start=CreateDN(&G);
	ShortestPath_Dijkstra(&G,start); 
	return 0;
}

