#define _CRT_SECURE_NO_WARNINGS 1
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define MaxVertexNum 810
#define INF 0x7fffffff
//INF���������

typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct VNode {
	int data;
	ArcNode* firstarc;
}VNode, AdjList[MaxVertexNum];
typedef struct {
	AdjList vertices;//�ڽӱ�洢ͼ
	int vexnum, arcnum;
}ALGraph;
bool Visited[MaxVertexNum];//���������Ƕ����Ƿ񱻷���

typedef struct LinkNode {
	int Vertex;//ͼ�Ķ�����
	struct LinkNode* next;
}LinkNode;
typedef struct {
	LinkNode* front, * rear;//������
}LinkQueue;

void InitQueue(LinkQueue& Q) {
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode*));
	p->Vertex = -1;
	p->next = NULL;
	Q.front = Q.rear = p;//��ʼ������
	return;
}

bool Q_Is_Empty(LinkQueue Q) {//�����п�
	return Q.front == Q.rear ? true : false;
}

void EnQueue(LinkQueue& Q, int i) {//��Ԫ�����
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode*));
	p->Vertex = i;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return;
}

void DeQueue(LinkQueue& Q, int& x) {//��ͷԪ�س���
	LinkNode* p = Q.front->next;
	x = p->Vertex;
	Q.front->next = p->next;
	if (Q.rear == p)Q.rear = Q.front;
	free(p);
	return;
}

void Visit(int i) {
	printf("%d ", i);
	return;
}

//�󶥵�u��������������·��
void BFS_MIN_Distance(ALGraph G, LinkQueue& Q, int u) {
	int d[MaxVertexNum], path[MaxVertexNum], v;
	//d[i]��ʾ��u��i�������·����path[i]��ʾ����u������i�����·���ϣ�����i��ֱ��ǰ��
	memset(d, INF, sizeof(d));//��ʼ��·������Ϊ�����
	memset(path, -1, sizeof(path));//��ʼ�����ж����ֱ��ǰ��Ϊ-1
	Visited[u] = true, d[u] = 0;
	EnQueue(Q, u);
	while (!Q_Is_Empty(Q)) {//BFS������
		DeQueue(Q, u);//��ͷԪ�س���
		for (ArcNode* w = G.vertices[u].firstarc; w != NULL; w = w->nextarc) {
			//����u�������ڽӵ�
			v = w->adjvex;
			if (!Visited[v]) {//��δ����
				Visited[v] = true;//��Ƿ���
				d[v] = d[u] + 1;//·�����ȼ�1
				path[v] = u;//���·���У�Ӧ�Ǵ�u��v
				EnQueue(Q, v);//����w���
			}
		}
	}
	return;
}

/*
void BFS(ALGraph& G, LinkQueue& Q, int i) {//�����������������ͨ������
	Visit(i);//�ȷ���i
	Visited[i] = true;
	EnQueue(Q, i);
	int v, w;//v��¼����Ԫ�أ�w������ʱ��¼���ʵĶ���
	while (!Q_Is_Empty(Q)) {//�����в�Ϊ��ʱ
		DeQueue(Q, v);//����Ԫ�س���
		for (ArcNode* p = G.vertices[v].firstarc; p != NULL; p = p->nextarc) {
			//����v���е��ڽӶ���
			w = p->adjvex;
			if (!Visited[w]) {//������wδ�����ʹ�
				Visit(w);//���ʶ���w
				Visited[w] = true;//�Զ���w���ѷ��ʱ��
				EnQueue(Q, w);//����w���
			}
		}
	}
	return;
}

void BFSTraverse(ALGraph& G, LinkQueue& Q) {//��ͼG���й�����ȱ���
	for (int i = 1; i <= G.vexnum; ++i) {
		Visited[i] = false;//���ʱ�������ʼ��
		G.vertices[i].data = i;//��ʵ��һ��û��
	}
	InitQueue(Q);//��ʼ������
	for (int i = 1; i <= G.vexnum; ++i)//��1�Ŷ��㿪ʼ����
		if (!Visited[i])//��ÿ����ͨ��������һ��BFS()
			BFS(G, Q, i);//������v_iδ�����ʹ�����Ӷ���v_i����ʼ����BFS()
	return;
}
*/

int main() {
	
	return 0;
}