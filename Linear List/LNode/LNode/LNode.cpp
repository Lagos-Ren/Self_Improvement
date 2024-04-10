#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct LNode {//typedef�ؼ��֣��������ؼ��֣�ʹ��������
	//�˴��ȼ���typedef struct LNode LNode;
	int data;
	struct LNode* next;//ָ��ָ����һ���ڵ�
}LNode, *LinkList;//�˴��ȼ���typedef struct LNode *LinkList;

LNode* GetElem(LinkList L, int i) {//��λ����
	//LNode*ǿ������һ���ڵ㣬LinkListǿ������һ�������������ʵ�������д��������ǿ�ɶ���
	if (i == 0)return L;//ͷ�ڵ�ֱ�ӷ���
	if (i < 1)return NULL;//��i���Ϸ�����NULL
	int j=1;
	LNode* p = L->next;//��ʼֵΪͷ���
	while (p != NULL && j < i) {//��ͷ��λ�����β���
		p = p->next;
		++j;
	}
	return p;//���ض�Ӧλ��ڵ�
}

bool IsEmpty(LinkList& L) {//�жϵ������Ƿ�Ϊ��
	return L == NULL ? true : false;
}

bool NHInitList(LinkList& L);
bool NHListInsert(LinkList& L, int i, int e);
void Nohead();

bool InitList(LinkList& L) {//��ͷ���ĳ�ʼ���������������£�
	L = (LNode*)malloc(sizeof(LNode));//����һ��ͷ���
	if (L == NULL)return false;//�ڴ治�㣬����ʧ��
	L->next = NULL;//ͷ�ڵ�����޽ڵ�
	return true;//����ɹ�������ֵΪtrue
}

bool ListInsert(LinkList& L, int i, int e) {//��λ���룬�ڵ�i��λ�ò���Ԫ��e����ͷ��㣩
	if (i < 1)return false;//�ų����Ϸ���i
	LNode* p;//��ʱָ��
	int j = 0;//��ʾpָ���j�����
	p = L;//p��ʼ״̬��ͷ���ָ��ͬһλ�ã���������0����㣨�������ݣ�
	while (p != NULL && j < i - 1) {//ѭ���ҵ���i-1�����
		p = p->next;
		++j;
	}
//	�����while�ȼ��ڣ����Լ�Ϲд�ģ�
//	LNode* p = L;
//	for (int j = 0; p != NULL && j < i - 1; p = p->next, ++j);
//	����һ�ο���ֱ�ӵȼ�������һ�д��룺����ȻҪ��������庯����
//	return InsertNextNode(p,e);
	if (p == NULL)return false;//iֵ���Ϸ�
	LNode* s = (LNode*)malloc(sizeof(LNode));//����һ���½��
	s->data = e;//��ֵ
	s->next = p->next;//��p������һ��ָ�򴫸�s
	p->next = s;//Ȼ��pָ��s�����s�Ĳ���
	return true;
}

bool InsertNextNode(LNode* p, int e) {//�Ը��������к��������ں������һ�����ݣ�
	if (p == NULL)return false;//�жϽڵ��Ƿ�Ϸ�
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)return false;//�ڴ����ʧ��
	s->data = e;//�����߼�ͬ��λ����
	s->next = p->next;
	p->next = s;
	return true;
}

bool InsertPriorNode(LNode* p, int e) {//�Ը���������ǰ���������ǰ�����һ�����ݣ�
	if (p == NULL)return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)return false;
	s->next = p->next;//��s�ĺ��ָ��p�ĺ��
	p->next = s;//pָ��s����ɽ�s��������
	s->data = p->data;//��p�����ݸ���s
	p->data = e;//�ٰ���Ҫ�����ֵe����p���Ӷ���ɱ���ġ�ǰ�塱
	return true;
}

bool ListDelete(LinkList& L, int i, int& e) {//��λɾ����ɾ����iλ���Ԫ�أ�����e������ֵ
	if (i < 1)return false;
	LNode* p = L;
	for (int j = 0; p != NULL && j < i - 1; p = p->next, ++j);//ѭ�����ҵ�i-1����㣬�߼�ͬ��λ����
	if (p == NULL || p->next == NULL)return false;//����i-1�������޽��Ҳ�Ƿ�����������i��㣩
	LNode* q = p->next;//��qָ��ɾ�����
	e = q->data;//��e���ر�ɾ����ֵ
	p->next = q->next;//��p�ĺ�̼̳�q�ĺ�̣��Ӷ���q�������жϿ�
	free(q);//�ͷ��ڴ�ռ䣬���ɾ������
	return true;
}

bool DeleteNode(LNode* p) {//ɾ��ָ�����p
	if (p == NULL)return false;
	if (p->next != NULL) {//���p���Ǳ�β���
		LNode* q = p->next;//��qָ��p�ĺ�̽��
		p->data = q->data;//��p���������ú�̽������ݸ���
		p->next = q->next;//�ٽ�p�ĺ��ָ��p�ĺ�̵ĺ�̣��Ӷ�ʵ��q���ĶϿ�
		free(q);//��ʱp��λ��ʵ�����Ѿ���q��p�Ѿ���ɾ�������ͷ�q���ɣ�˼������ǰ�壩
	}else free(p);
	//���p�Ǳ�β�����ֱ���ͷ�p
	//���ǵ��������Ӧ��ϢҲҪ�仯������len--���������Ҫʹ��ȫ�ֱ������߽��������뺯��
	//����ʵ�ֿ��ܽ�Ϊ���ӣ����������
	return true;
}

int main() {
	LinkList L;//����ͷָ�루ָ�������һ������ָ�룩���ȼ���LNode *L;
	InitList(L);
	
	
	return 0;
}

bool NHInitList(LinkList& L) {//��ʼ������������ͷ��㣩
	L = NULL;
	return true;
}

bool NHListInsert(LinkList& L, int i, int e) {//����ͷ���İ�λ����
	if (i < 1)return false;
	if (i == 1) {//��Ҫ����Ϊ��1λ��Ľ�㿪��һ���߼����Ƚ��鷳
		LNode* s = (LNode*)malloc(sizeof(LNode));//�����½ڵ�
		s->data = e;//��ֵ
		s->next = L;//�½ڵ���ԭ��L
		L = s;//ͷ����Ϊs
		return true;
	}
	else return ListInsert(L, i-1, e);//����λ�õĲ���ͬ��ͷ���
}

void Nohead() {//����ͷ���ĵ�����
	//����ͷ��㣬L.data�д�����ݣ���ͷ��㣬L.data�в������ݣ�������Ϊ��0���ڵ�
	LinkList L;//����һ��ָ�������ָ��
	NHInitList(L);//��ʼ��һ���ձ�
	//����Ȼ����к�������
	return;
}