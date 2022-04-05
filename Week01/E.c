/*�ö�Ѱ�ҵ�һ�����ظ����ַ�*/
/*
�������� Copy
abcdbef
������� Copy
0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1    // ����ֵΪ��
#define FALSE 0   // ����ֵΪ��
#define gets(S) fgets(S,sizeof(S),stdin)
typedef char Elementype;
typedef int Status; // �������ؽ������
typedef struct Node
{
	Elementype Element;
	struct Node *next;
}NODE , *Ptr;

typedef struct QNode
{
	Ptr front, rear;
}Queue;

void InitQueue(Queue *team)//��ʼ��һ������
{
	team->front = team->rear = (Ptr) malloc(sizeof(NODE));
	team->front=NULL;
	team->rear=NULL;
}

void InsertQueue(Queue *team,Elementype e)//��Ӻ���
{
	Ptr t = (Ptr) malloc(sizeof(NODE));
	t->Element=e;
	t->next=NULL;
	if(team->rear==NULL)
	{
		team->front=team->rear=t;
	}
	else 
	{
		team->rear->next=t;
		team->rear=t;
	}
}

Status DeleteQueue(Queue *team,Elementype *e)//���Ӻ���
{
	Ptr t;
	if(team->front==NULL)
		return FALSE;	
	if(team->front==team->rear)
		{
			*e=team->front->Element;
			t=team->front;
			team->front=team->rear=NULL;
		}
	else
		{
			*e=team->front->Element;
			t=team->front;
			team->front=team->front->next;
		}
	free(t);
	return TRUE;
}

Elementype Repetition(Queue team){
	Ptr t;
	int i=0,j,boolen;
	Elementype temp[20]; 
	t=team.front;
	while(t){
		temp[i]=t->Element;
		i++;
		t=t->next;
	}
    for(i=0; i<strlen(temp); i++){
        for(j=0, boolen = 0; j<strlen(temp); j++){
            if(i!=j && temp[i] == temp[j]){
                boolen = 1;
                break;
            }       
        }
        if(!boolen){
            printf("%d", i);
            break;
        }
    }
}

int main()
{
	Queue group;
	char a[20],c=0;
	int i,j;
	InitQueue(&group);
	gets(a);
	i=strlen(a);
	
	for(j=0;j<i;j++)
	{
		InsertQueue(&group,a[j]);
	}
	Repetition(group);
	for(j=0;j<i;j++)
	{
		DeleteQueue(&group,&c);
	}

	return 0;
}

