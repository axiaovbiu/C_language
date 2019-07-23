#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
void QueueInit(Queue* pq)
{
	pq->_front = NULL;
	pq->_rear = NULL;
	pq->size = 0;
}
void QueueDestory(Queue* pq)
{
	pq->_front = NULL;
	pq->_rear = NULL;
	pq->size = 0;
	free(pq);
}
QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
	tmp->_data = x;
	return tmp;
}
void QueuePush(Queue* pq, QUDataType x)//尾插
{
	Queue *tmp = BuyQueueNode(x);
	if (pq->size == 0)
	{
		pq->_front = tmp;
		pq->_rear = tmp;
		pq->size++;
		return;
	}
	pq->_rear->_next = tmp;
	pq->_rear = pq->_rear->_next;
	pq->size++;
	return;
	
}
void QueuePop(Queue* pq)//头删
{
	if (pq ->size == 0)
	{
		return;
	}
	pq->_front = pq->_front->_next;
	pq->size--;
	return;
}
QUDataType QueueFront(Queue* pq)//队首的元素
{
	if (pq->size == 0)
	{
		printf("链表为空\n");
		return NULL;
	}
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)//返回队尾的元素
{
	if (pq->size == 0)
	{
		return NULL;
	}
	return ((pq->_rear )->_data);
}
int QueueEmpty(Queue* pq)
{
	if (pq->size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}
int QueueSize(Queue* pq)
{
	return pq->size;
}