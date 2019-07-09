#define _CRT_SECURE_NO_WARNINGS 1
/*移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例 :

输入 : [0, 1, 0, 3, 12]
输出 : [1, 3, 12, 0, 0]
 说明 :

	1.必须在原数组上操作，不能拷贝额外的数组。
	2.尽量减少操作次数。*/
//解题思路：将数组遍历，把非0元素按原顺序前置，其余位置置0

void moveZeroes(int* nums, int numsSize){
	int i;
	int j;
	int k = 0;
	for (i = 0; i<numsSize; i++){//遍历找出非0元素
		if (nums[i]){
			nums[k] = nums[i];
			k++;
		}

	}
	for (j = k; j < numsSize; j++){//将其余位置置0
		nums[j] = 0;
	}
}

