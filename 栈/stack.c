#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
void StackInit(SK* stack)
{
	assert(stack);
	SKDataType* tmp = (SKDataType*)malloc(sizeof(SKDataType) * InitialCapacity);
	assert(tmp);
	stack->data = tmp;
	stack->capacity = InitialCapacity;
	stack->top = 0;
}

void StackDestory(SK* stack)
{
	assert(stack);
	free(stack->data);
	stack->data = NULL;
	stack->top = stack->capacity = 0;
}

void StackPush(SK* stack, SKDataType x)
{
	assert(stack);
	if (stack->top == stack->capacity)
	{
		//扩容
		//内存块的大小记得乘以类型大小
		SKDataType* tmp = (SKDataType*)realloc(stack->data, stack->capacity * 2 * sizeof(SKDataType));
		assert(tmp);
		stack->capacity *= 2;
		stack->data = tmp;
	}
	stack->data[stack->top] = x;
	stack->top++;
}

void StackPop(SK* stack)
{
	assert(stack);
	assert(!StackEmpty(stack));
	stack->top--;
}

SKDataType StackTop(SK* stack)//取栈顶的元素
{
	assert(stack);
	assert(!StackEmpty(stack));
	return stack->data[stack->top - 1];
}

bool StackEmpty(SK* stack)
{
	assert(stack);
	return stack->top == 0;
}

int StackSize(SK* stack)
{
	assert(stack);
	return stack->top;
}