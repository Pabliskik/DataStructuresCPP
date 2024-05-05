#include <iostream>

void bubbleSort(int array[], int size) {
    for(int i = size - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}

void selectionSort(int array[], int size) {
    for(int i = 0; i < size-1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < size; j++) {
            if(array[j] < array[minIndex]) {
                minIndex = j;
            }
        }

        if(i == minIndex) continue;
        int tmp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tmp;
    }
}

//{ 10, 2, 8, 1, 11, 6};
void insertionSort(int array[], int size) {
    for(int i = 1; i < size; i++) {
        int tmp = array[i];
        int j = i - 1;
        while(j > -1 && tmp < array[j]) {
            array[j+1] = array[j];
            array[j] = tmp;
            j--;
        }
    }
}

int main() {

    int myArray[] = { 10, 2, 8, 1, 11, 6};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    bubbleSort(myArray, size);

    for(int value: myArray) {
        std::cout << value << " ";
    }

    std::cout<<std::endl;

    int myArray2[] = { 10, 2, 8, 1, 11, 6};
    int size2 = sizeof(myArray2) / sizeof(myArray2[0]);

    selectionSort(myArray2, size2);

    for(int value: myArray2) {
        std::cout << value << " ";
    }

    std::cout<<std::endl;

    int myArray3[] = { 10, 2, 8, 1, 11, 6};
    int size3 = sizeof(myArray3) / sizeof(myArray3[0]);

    insertionSort(myArray3, size3);

    for(int value: myArray3) {
        std::cout << value << " ";
    }

    return 0;
}