#define _CRT_SECURE_NO_WARNINGS
//注意：栈和顺序表链表不一样，栈不能直接遍历
#include "stack.h"
void testStack()
{
	SK stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	while (!StackEmpty(&stack))//栈要遍历意味这同时把栈给整空
	{                                            //栈只能取栈顶的数据，要取后面的数据必须先出栈顶的数据
		printf("%d ", StackTop(&stack));
		StackPop(&stack);
	}
	//因此不要轻易遍历栈
	StackDestory(&stack);
}
int main()
{
	testStack();
	return 0;
}