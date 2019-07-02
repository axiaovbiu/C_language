#define _CRT_SECURE_NO_WARNINGS 1
/*两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入 : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
输出 : [2, 2]
	 示例 2 :

 输入 : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
  输出 : [4, 9]
	   说明：

	   输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
	   我们可以不考虑输出结果的顺序 */

//解题思路：利用qsort函数排序，定义双指针遍历两个数组，在堆上开辟新的空间存放新的数组。
	   int Mycmp(const void *a, const void *b)//自定义排序方式
	   {
		   return *(int *)a>*(int *)b;
	   }
	 int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

		 int i = 0;
		 int j = 0;
		 int *result = (int *)malloc(sizeof(int)*nums1Size);
		 qsort(nums1, nums1Size, sizeof(int), Mycmp);
		 qsort(nums2, nums2Size, sizeof(int), Mycmp);
		 *returnSize = 0;
		 while (i<nums1Size&&j<nums2Size){
			 if (nums1[i]<nums2[j]){
				 i++;
			 }
			 else if (nums1[i]>nums2[j]){
				 j++;
			 }
			 else{
				 result[(*returnSize)++] = nums1[i];
				 i++;
				 j++;
			 }
		 }
		 return result;
	 }