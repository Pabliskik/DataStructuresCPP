#include <iostream>
#include <vector>

void merge(int* array, int leftIndex, int middleIndex, int rightIndex) {

    // Separate into two arrays
    const int leftArraySize = middleIndex - leftIndex + 1;
    const int rightArraySize = rightIndex - middleIndex;

    //int leftArray[leftArraySize];
    std::vector<int> leftArray;
    std::vector<int> rightArray;
    //int rightArray[rightArraySize];

    for (int i = 0; i < leftArraySize; i++) {
        int val = array[leftIndex + i];
        leftArray.push_back(val);
    }

    for(int i = 0; i < rightArraySize; i++) {
        rightArray.push_back(array[middleIndex + 1 + i]);
    }

    // Merge
    int index = leftIndex;
    int i = 0;
    int j = 0;

    while(i < leftArraySize && j < rightArraySize) {
        if(leftArray.at(i) <= rightArray.at(j)) {
            array[index] = leftArray.at(i);
            i++;
            index++;
        } else {
            array[index] = rightArray.at(j);
            j++;
            index++;
        }
    }

    while (i < leftArraySize)
    {
        array[index] = leftArray.at(i);
        index++;
        i++;
    }

    while (j < rightArraySize) {
        array[index] = rightArray.at(j);
        index++;
        j++;
    }
    
}

void mergeSort(int array[], int leftIndex, int rightIndex) {
    if(leftIndex>= rightIndex) return;

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex+1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}

int main() {
    int array[] = {3, 1, 4, 2};

    int size = sizeof(array) / sizeof(array[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;

    mergeSort(array, leftIndex, rightIndex);

    for (int value: array) {
        std::cout << value << " ";
    }

    return 0;
}