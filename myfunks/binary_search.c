#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	binary_search(int *arr, int length, int item)
{
	int	low;
	int	high;
	int mid;
	int guess;
	int count;

	low = 0;
	high = length - 1;
	count = 0;
	while (low <= high)
	{
		count++;
		mid = (low + high) / 2;
		guess = arr[mid];
		if (guess == item)
			break;
		if (guess > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	printf("\nYour number is %d and I found it for %d iterations\n", guess, count);
	return (mid);
}

int main(void)
{
	int	*array;
	long long length;
	int	i;
	int	num;

	printf("Type quantity of elements in array:\n");
	scanf("%lld", &length);

	array = (int *)malloc(sizeof(int) * length);
	if (!array)
	{
		printf("This array too large!\n");
		exit(-1);
	}
	i = 0;
	while(i < length)
	{
		array[i] = i + 1;
		i++; 
	}
	printf("Type number and I'll find it very quickly:\n");
	scanf("%d", &num);
	binary_search(array, length, num);
}