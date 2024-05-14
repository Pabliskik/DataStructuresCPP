#include <iostream>

void swap(int array[], int firstIndex, int secondIndex) {
    int tmp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = tmp;
}

int pivot(int array[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for(int i = pivotIndex + 1;i <= endIndex; i++) {
        int a = array[i];
        int b = array[pivotIndex];
        if (array[i] < array[pivotIndex]) {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
    if(leftIndex >= rightIndex) return;
    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex-1);
    quickSort(array, pivotIndex+1, rightIndex);
}

int main() {
    int myArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    quickSort(myArray, 0, size-1);

    for(int value: myArray) {
        std::cout << value << " ";
    }

    return 0;
}