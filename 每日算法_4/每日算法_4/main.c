#define _CRT_SECURE_NO_WARNINGS 1
/*存在重复

给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

	示例 1:

输入 : [1, 2, 3, 1]
输出 : true

	示例 2 :

 输入 : [1, 2, 3, 4]
  输出 : false

	示例 3 :

   输入 : [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]
	输出 : true*/
//方法一：暴力解法
//思路：双指针，一一对比

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

//方法二：
//思路：利用qsort函数排序再查找

int My_Cmp(const void* a, const void* b)//自定义比较函数
{
	return (*(int*)a - *(int*)b);
}
bool containsDuplicate(int* nums, int numsSize){
	int i = 1;
	if (numsSize == 0)
	{
		return false;
	}
	qsort(nums, numsSize, sizeof(int), My_Cmp);//排序数组
	for (i = 1; i<numsSize; i++)
	{
		if (nums[i] == nums[i - 1])//比较
		{
			return true;
		}
	}
	return false;
}
