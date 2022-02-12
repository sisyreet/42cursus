#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	binary_search(int *arr, int length, int item)
{
	int low = 0;
	int	high = length - 1;
	int mid;
	int guess;
	int count;

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

int main(int argc, char **argv)
{
	int arr[argc - 1];
	int	i;
	int	num;

	printf("Type number and I find it very quickly:\n");
	scanf("%d", &num);
	i = 0;
	while (i < argc - 1)
	{
		arr[i] = atoi(argv[i + 1]);
		i++;
	}
	binary_search(arr, argc - 1, num);
}