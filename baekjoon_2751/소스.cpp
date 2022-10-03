#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int partition(int arr[], int start, int end);
void QuickSort(int arr[], int start, int end);
int arr[1000000];

int main(void)
{
	int N, i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	//퀵 정렬 함수 사용
	QuickSort(arr, 0, N - 1);
	//정렬한 후에 배열의 상태를 출력
	for (i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	return 0;
}
//퀵정렬 알고리즘
void QuickSort(int arr[], int start, int end)
{
	int index;

	if (start < end)
	{
		index = partition(arr, start, end); //분할 함수를 통해 pivot의 위치를 받기
		QuickSort(arr, start, index - 1); //pivot보다 작은 값들을 정렬
		QuickSort(arr, index + 1, end); //pivot보다 큰 값들을 정렬
	}
	else
		return;
}

int partition(int arr[], int start, int end) //분할 함수.
{
	int i, tmp, random, index = start, pivot;

	random = start + (rand() % (end - start + 1));

	tmp = arr[random];
	arr[random] = arr[end];
	arr[end] = tmp;

	pivot = arr[end];

	for (i = start; i < end; i++)
	{//pivot보다 작은 값들은 pivot의 왼쪽에 위치시키는 과정
		if (arr[i] < pivot)
		{
			tmp = arr[index];
			arr[index] = arr[i];
			arr[i] = tmp;
			index++;
		}
	}

	tmp = arr[index];
	arr[index] = arr[end];
	arr[end] = tmp;

	return index;
}