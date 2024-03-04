#include <iostream>
#include <limits.h>
using namespace std;

class MaxHeap{
    int* arr;
    int maxSize;
    int heapSize;
    public:
        MaxHeap(int maxSize);
        void MaxHeapify(int);
        int parent(int i){
          return (i - 1)/2;
        }

        int lchild(int i){
            return 2*i + 1;
        }

        int rchild(int i){
            return 2*i + 2;
        }

        int removeMax();

        void increaseKey(int i, int newVal);

        int getMax(){
            return arr[0];
        }

        int curSize(){
            return heapSize;
        }

        void deleteKey(int i);

        void insertKey(int x);
};

MaxHeap::MaxHeap(int totSize){
    heapSize = 0;
    maxSize = totSize;
    arr = new int[totSize];
}

void MaxHeap::insertKey(int x){
    if (heapSize == maxSize){
        cout << "\n Overflow: Couldnot insert key";
    }

    heapSize++;
    // insert element at the last location.
    // O(1) operation
    int i = heapSize -1;
    arr[i] = x;

    // now sort the elements with parents.
    while(i != 0 && arr[parent(i)] < arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int i, int newVal){
    arr[i] = newVal;
    while(i != 0 && arr[parent(i)] < arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::removeMax(){
    if (heapSize <= 0)
            return INT_MIN;
    if (heapSize == 1){
        heapSize--;
        return arr[0];
    }

    // get the max element
    int  root = arr[0];
    // fill the top element with last element
    arr[0] = arr[heapSize - 1];
    // reduce the size
    heapSize--;
    MaxHeapify(0);
    return root;
}

void MaxHeap::deleteKey(int i){
    // the key we want to delete
    // made it the max and then deleted it.
    // so the whole heap is still in order.
    increaseKey(i, INT_MAX);
    removeMax();
}

void MaxHeap::MaxHeapify(int i){
    int l = lchild(i);
    int r = rchild(i);
    int largest = i;
    if (l < heapSize && arr[r] > arr[largest])
        largest = l;
    if(r < heapSize && arr[l] > arr[largest])
        largest = r;
    if (largest != i){
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}

int main(){
    MaxHeap h(15);
    int k, i, n = 6, arr[10];
    cout << " Entered keys" << endl;
    h.insertKey(3);
    h.insertKey(10);
    h.insertKey(12);
    h.insertKey(8);
    h.insertKey(2);
    h.insertKey(14);

    cout << " The current size of the heap is " << h.curSize() << endl;
    cout << " Maximum element in heap = "<< h.getMax() << endl;

    h.deleteKey(2);
    cout << "The current size of the heap is " << h.curSize() << endl;
    h.insertKey(15);
    h.insertKey(5);
    cout << " The current size of the heap is " << h.curSize() << endl;
    cout << " Curren maximum = " << h.getMax() << endl;
    return 0;
}
