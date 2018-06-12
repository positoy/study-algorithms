#include <iostream>

int arr[] = { 10,9,5,2,3,5,6,123,76,2134,13,6,123,123,124,531,312 }, len = 17;

void mergeSort(int arr[], int left, int right, int half) {
	if (left == right) return;
	mergeSort(arr, left, half, (left + half) / 2);
	mergeSort(arr, half + 1, right, (half + right + 1) / 2);

	int *arr2 = new int[right - left + 1];
	int i = left, j = half + 1, k = 0;
	while (i <= half && j <= right) {
		if (arr[i] < arr[j]) arr2[k++] = arr[i++];
		else arr2[k++] = arr[j++];
	}
	while (i <= half) arr2[k++] = arr[i++];
	while (j <= right) arr2[k++] = arr[j++];

	for (int i = left, j = 0; i <= right; i++, j++) arr[i] = arr2[j];
	delete[] arr2;
}

int main()
{
	// sort!
	mergeSort(arr, 0, 16, 8);
	for (int i = 0; i<17; i++) std::cout << i << ":" << arr[i] << ' ';
	std::cout << std::endl;
}