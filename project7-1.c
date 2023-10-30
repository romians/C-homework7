#include <stdio.h>

//���� ��ȯ �Լ�
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//�ִ� �� ���ϴ� �Լ�
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //���� ����Ʈ�� �� �� �ִ� ��ȯ
    if (left < n && arr[left] > arr[largest])
        largest = left;

    //������ ����Ʈ�� �� �� �ִ� ��ȯ
    if (right < n && arr[right] > arr[largest])
        largest = right;

    //�ִ��� i ���� �ƴ� ���
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//�� ����
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //�� �����ϴ� �κ� ���
    for (int i = 0; i < n; i++) {
        printf("Step %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        //2���� ���� ����
        swap(&arr[0], &arr[n - i - 1]);
        heapify(arr, n - i - 1, 0);
    }
}

int main() {
    //���� �� ����Ʈ ����
    int arr[] = { 34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 34, 85, 29, 78, 41, 56, 86 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("�� ����\n");
    heapSort(arr, n); //�� ����

    printf("\n");
    printf("�� ���� �� �迭: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}