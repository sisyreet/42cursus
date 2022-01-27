#include <stdio.h>

int	*bubble(int *arr, int n)
{
	int	temp;
	int	i;
	int	count;

	count = 1;
	while (count)
	{
		i = 0;
		count = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				count++;
			}
			i++;
		}
	}
	return (arr);
}

int	main(void)
{
	int	arr[] = {5, 123, 34, 454, 23, 1, 111, 234, 12, 45, 78, 59, 37, 19, 743, 99, 74, 1, 32, 6};
	int	n;
	int	i;

	n = *(&arr + 1) - arr;
	printf("INPUT:\n");
	i = 0;
	while (i < n)
		printf("%d ", arr[i++]);
	printf("\n");
	printf("\n");
	bubble(arr, n);
	i = 0;
	printf("OUTPUT:\n");
	while (i < n)
		printf("%d ", arr[i++]);
	return (0);
}
