#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "queue.h"
typedef char BTDataType;

typedef struct binaryTreeNode
{
	struct binaryTreeNode* left;//ָ�����ӽ��
	struct binaryTreeNode* right;//ָ���Һ��ӽ��
	BTDataType val;
}BTNode;

//������������½��
BTNode* buyBinaryTreeNewNode(BTDataType x);

//�ִ���������Ķ�����
BTNode* createBinaryTree1();

//ͨ��ǰ������ַ���������������
BTNode* createBinaryTree2(char* str, int* index);

//������������
void BinaryTreeDestroy(BTNode* root);

//ǰ�����
void preOrder(BTNode* root);

//�������
void inOrder(BTNode* root);

//��������
void postOrder(BTNode* root);

//�����������Ҫ���У�
void levelOrder(BTNode* root);

//�������������
int binaryTreeSize(BTNode* root);

//�������ĵ�k��Ľ����
int treeKLevel(BTNode* root, int k);

//�����������
int treeDepth(BTNode* root);

//�ж��Ƿ�����ȫ������
bool isCompleteTree(BTNode* root);

