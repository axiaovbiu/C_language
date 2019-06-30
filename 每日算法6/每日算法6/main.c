#define _CRT_SECURE_NO_WARNINGS 1
/*加一

给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入 : [1, 2, 3]
输出 : [1, 2, 4]
解释 : 输入数组表示数字 123。
	  示例 2 :

输入 : [4, 3, 2, 1]
输出 : [4, 3, 2, 2]
解释 : 输入数组表示数字 4321。*/

//解题思路：判断数组是否全为9，若全为9，则数组大小要+1，若全不为9，找出第一个为9的位置的前一个位置，以此分为两部分，分别赋值。

int* plusOne(int* digits, int digitsSize, int* returnSize){
	int *result = (int *)malloc((digitsSize + 1)*sizeof(int));//在堆上开辟空间
	int count = 0;
	int i;
	int j = digitsSize - 1;
	for (i = 0; i<digitsSize; i++){
		if (digits[i] == 9){
			count++;//若数组元素为9，count++
		}
	}
	if (count == digitsSize){//若count = 数组大小，则全为9
		*returnSize = digitsSize + 1;
		result[0] = 1;
		for (i = 1; i<digitsSize; i++){
			result[i] = 0;
		}
		return result;
	}
	else{
		*returnSize = digitsSize;
		while (digits[j] == 9){//找出第一个为9的数字的前一个位置
			j--;
		}
		for (i = 0; i<j; i++){//前半部分不变
			result[i] == digits[i];
		}
		result[j] = digits[j] + 1;//中间位置数组+1
		for (i = j + 1; i<digitsSize; i++){//后半部分赋0
			result[i] == 0;
		}
		return result;
	}
}


		 ​