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
	//�� ���� �Լ� ���
	QuickSort(arr, 0, N - 1);
	//������ �Ŀ� �迭�� ���¸� ���
	for (i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	return 0;
}
//������ �˰���
void QuickSort(int arr[], int start, int end)
{
	int index;

	if (start < end)
	{
		index = partition(arr, start, end); //���� �Լ��� ���� pivot�� ��ġ�� �ޱ�
		QuickSort(arr, start, index - 1); //pivot���� ���� ������ ����
		QuickSort(arr, index + 1, end); //pivot���� ū ������ ����
	}
	else
		return;
}

int partition(int arr[], int start, int end) //���� �Լ�.
{
	int i, tmp, random, index = start, pivot;

	random = start + (rand() % (end - start + 1));

	tmp = arr[random];
	arr[random] = arr[end];
	arr[end] = tmp;

	pivot = arr[end];

	for (i = start; i < end; i++)
	{//pivot���� ���� ������ pivot�� ���ʿ� ��ġ��Ű�� ����
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