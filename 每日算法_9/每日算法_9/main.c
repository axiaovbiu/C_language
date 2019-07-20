#define _CRT_SECURE_NO_WARNINGS 
/*两数之和
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例 :

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回[0, 1]*/
#include<stdio.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i, j;
	int *result = (int*)malloc(sizeof(int)* 2);
	*returnSize = 2;
	for (i = 0; i<numsSize - 1; i++)
	{
		for (j = i + 1; j<numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return NULL;
}