#define _CRT_SECURE_NO_WARNINGS 1
/*��������Ľ��� II
�����������飬��дһ���������������ǵĽ�����

ʾ�� 1:

���� : nums1 = [1, 2, 2, 1], nums2 = [2, 2]
��� : [2, 2]
	 ʾ�� 2 :

 ���� : nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
  ��� : [4, 9]
	   ˵����

	   ��������ÿ��Ԫ�س��ֵĴ�����Ӧ��Ԫ�������������г��ֵĴ���һ�¡�
	   ���ǿ��Բ�������������˳�� */

//����˼·������qsort�������򣬶���˫ָ������������飬�ڶ��Ͽ����µĿռ����µ����顣
	   int Mycmp(const void *a, const void *b)//�Զ�������ʽ
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