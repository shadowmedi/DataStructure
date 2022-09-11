#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef int BTDataType;

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

//ǰ�����
void preOrder(BTNode* root);

//�������
void inOrder(BTNode* root);

//��������
void postOrder(BTNode* root);

//�������������
int binaryTreeSize(BTNode* root);

//�������ĵ�k��Ľ����
int treeKLevel(BTNode* root, int k);

//�����������
int treeDepth(BTNode* root);

