#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"
int main()
{
	Queue head;
	QueueInit(&head);
	QueuePush(&head, 1);
	QueuePush(&head, 2);
	QueuePush(&head, 3);
	QueuePush(&head, 4);
	QueuePush(&head, 5);
	QueuePop(&head);
	QueuePop(&head);
	printf("%d \n", QueueFront(&head));
	printf("%d \n", QueueBack(&head));
	return 0;
}