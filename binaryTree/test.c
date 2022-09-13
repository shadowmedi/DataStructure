#define _CRT_SECURE_NO_WARNINGS
#include "binaryTree.h"
int main()
{
	char str[15] = { 0 };
	int index = 0;
	scanf("%s", str);
	BTNode* root = createBinaryTree2(str, &index);
	/*preOrder(root);
	putchar('\n');
	inOrder(root);
	putchar('\n');
	postOrder(root);
	putchar('\n');
	printf("%d ", binaryTreeSize(root));*/
	//levelOrder(root);
	bool flag = isCompleteTree(root);
	printf("%d", flag);
	BinaryTreeDestroy(root);
	return 0;
}