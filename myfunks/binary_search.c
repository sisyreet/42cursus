#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	binary_search(int *arr, int length, int item)
{
	int	count;
	int	guess;
	int	high;
	int	low;
	int	mid;

	count = 0;
	high = length - 1;
	low = 0;
	while (low <= high)
	{
		count++;
		mid = (low + high) / 2;
		guess = arr[mid];
		if (guess == item)
			break ;
		if (guess > item)
			high = mid - 1;
		else
			low = mid + 1;
	}
	printf("\nYour number is %d and I found it for %d iterations\n", guess, count);
}

int	main(void)
{
	long long	length;
	long long	num;
	int			*array;
	int			i;

	printf("Type number of elements in array:\n");
	scanf("%lld", &length);
	if (length > 2147483647 || length < 0)
	{
		printf("Incorrect size of array, try number between 0 and 2147483647!\n");
		exit(-1);
	}
	array = (int *)malloc(sizeof(int) * length);
	if (!array)
	{
		printf("This size of array is too large! Try lesser size.\n");
		exit(-1);
	}
	i = 0;
	while(i < length)
	{
		array[i] = i + 1;
		i++; 
	}
	printf("Type number and I'll find it very quickly:\n");
	scanf("%lld", &num);
	if (num > 2147483647 || num < 0)
	{
		printf("Incorrect number, try number between 0 and 2147483647!\n");
		exit(-1);
	}
	binary_search(array, (int)length, num);
}