#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
	//函数输入参数包含指针
	//函数返回指针
	int *a = (int*)malloc(2 * sizeof(int));
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; (j < numsSize && j != i); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				a[0] = i;//数组与指针
				a[1] = j;
			}
		}
	}
	return a;
}

int main()
{
	int a[10];
	int b[2];
	int *p = b;
	int numsize, target;
	printf("Input array count: ");
	scanf("%d",&numsize);
	printf("Input target value:");
	scanf("%d",&target);
	printf("Input array value:\n");
	for (int i = 0; i < numsize; i++)
		scanf("%d",&a[i]);
	p = twoSum(a, numsize, target);
	printf("%d %d \n",*p,*(p+1));
	system("pause");
	return 0;
}

