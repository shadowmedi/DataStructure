#define _CRT_SECURE_NO_WARNINGS
//ע�⣺ջ��˳�������һ����ջ����ֱ�ӱ���
#include "stack.h"
void testStack()
{
	SK stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	while (!StackEmpty(&stack))//ջҪ������ζ��ͬʱ��ջ������
	{                                            //ջֻ��ȡջ�������ݣ�Ҫȡ��������ݱ����ȳ�ջ��������
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}
	//��˲�Ҫ���ױ���ջ
	StackDestory(&stack);
}
int main()
{
	testStack();
	return 0;
}