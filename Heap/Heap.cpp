#include <iostream>
#include <vector>
#include <climits>

class Heap {
private:
    std::vector<int> heap;

    int leftChild(int index) {
        return 2*index+1;
    }

    int rightChild(int index) {
        return 2*index+2;
    }

    int parent(int index) {
        return (index-1) / 2;
    }

    void swap(int index1, int index2) {
        int tmp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = tmp;
    }

    void sinkDown(int index) {
        int maxIndex = index;
        while(true) {
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            if(leftIndex < heap.size() && heap[leftIndex] >heap[rightIndex]) {
                maxIndex = leftIndex;
            } 
            if(rightIndex < heap.size() && heap[rightIndex] >heap[rightIndex]) {
                maxIndex = rightIndex;
            }

            if(maxIndex != index) {
                swap(index, maxIndex);
                index = maxIndex;
            } else {
                return;
            }
        }
    }

public:

    void printHeap() {
        std::cout << "\n[";
        for(size_t i = 0; i < heap.size(); i++) {
            std::cout << heap[i];
            if(i < heap.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    void insert(int value) {
        heap.push_back(value);
        int current = heap.size() - 1;

        while(true) {
            int parentIndex = parent(current);
            if(heap[current] > heap[parentIndex]) {
                swap(current, parentIndex);
                current = parent(current);
            } else {
                break;
            }
        }
    }

    int remove() {
        if(heap.empty()) {
            return INT_MIN;
        }

        int maxValue= heap.front();

        if (heap.size() == 1) {
            heap.pop_back();
        } else {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return maxValue;
    }
};

int main() {

    Heap* myHeap = new Heap();

    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);

    myHeap->printHeap();

    myHeap->insert(100);
    myHeap->printHeap();

    myHeap->insert(75);
    myHeap->printHeap();

    myHeap->remove();
    myHeap->printHeap();

    return 0;
}