#include<cstdio>
#include<cstdlib>
#define InitSize 10
using namespace std;

typedef struct {
	int* data;
	int MaxSize;
	int length;
}SeqList;

void InitList(SeqList& L) {//��ʼ����&��ʾ����
	L.data = (int*)malloc(InitSize * sizeof(int));
	//malloc��������һ��Ƭ�����Ĵ洢�ռ䣬��sizeof(��������)��ʼ�������Գ���һ����ʼֵ
	//֮��malloc�᷵��һ��ָ�룬�����ָ������ת���ɺͱ���ʼ��������ͬ�����ͣ��ٸ�ֵ��data
	//����dataָ��L.data[0]
	L.length = 0;
	L.MaxSize = InitSize;
	return;
}

void IncreaseSize(SeqList& L, int len) {
	int* p=L.data;
	L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
	//malloc���䵱ǰ�洢�����ټ���len�Ĵ洢�ռ�
	//dataָ���·������һƬ�ռ�
	for (int i = 0; i < L.length; ++i) {
		L.data[i] = p[i];//����ǰ������ת�ƹ���
	}
	L.MaxSize += len;
	free(p);
	return;
}//realloc����Ҳ��ʵ�֣������Ƽ���ѧ��ʹ��

int main() {
	SeqList L;
	InitList(L);
	IncreaseSize(L, 5);
	return 0;
}