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
void QueuePush(Queue* pq, QUDataType x)//β��
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
void QueuePop(Queue* pq)//ͷɾ
{
	if (pq ->size == 0)
	{
		return;
	}
	pq->_front = pq->_front->_next;
	pq->size--;
	return;
}
QUDataType QueueFront(Queue* pq)//���׵�Ԫ��
{
	if (pq->size == 0)
	{
		printf("����Ϊ��\n");
		return NULL;
	}
	return pq->_front->_data;
}
QUDataType QueueBack(Queue* pq)//���ض�β��Ԫ��
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