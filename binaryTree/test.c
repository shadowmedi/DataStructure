#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"
int main()
{
	BTNode* root = createBinaryTree1();
	preOrder(root);
	putchar('\n');
	inOrder(root);
	putchar('\n');
	postOrder(root);
	return 0;
}