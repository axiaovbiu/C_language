#define _CRT_SECURE_NO_WARNINGS 1
/*�����ظ�

����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

����κ�ֵ�������г����������Σ��������� true�����������ÿ��Ԫ�ض�����ͬ���򷵻� false��

	ʾ�� 1:

���� : [1, 2, 3, 1]
��� : true

	ʾ�� 2 :

 ���� : [1, 2, 3, 4]
  ��� : false

	ʾ�� 3 :

   ���� : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
	��� : true*/
//����һ�������ⷨ
//˼·��˫ָ�룬һһ�Ա�

bool containsDuplicate(int* nums, int numsSize){
	int i = 0;
	int j = 0;
	for (i = 0; i< numsSize; i++)
	{
		for (j = 1 + i; j<numsSize; j++)
		{
			if (nums[i] == nums[j])
			{
				return true;
			}
		}
	}
	return false;
}

//��������
//˼·������qsort���������ٲ���

int My_Cmp(const void* a, const void* b)//�Զ���ȽϺ���
{
	return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize){
	int i = 1;
	if (numsSize == 0)
	{
		return false;
	}
	qsort(nums, numsSize, sizeof(int), My_Cmp);//��������
	for (i = 1; i<numsSize; i++)
	{
		if (nums[i] == nums[i - 1])//�Ƚ�
		{
			return true;
		}
	}
	return false;
}
