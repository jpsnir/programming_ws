#include <iostream>
#include <limits.h>
#include <time.h>
class Queue{
public:
    int front, rear, size;
    unsigned capacity;
    int* array;
};

Queue* createQueue(unsigned capacity){
    Queue* queuePtr = new Queue();
    queuePtr->capacity = capacity;
    queuePtr->front = queuePtr->size = 0;
    queuePtr->rear = capacity - 1;
    queuePtr->array = new int[capacity];
    std::cout << " Queue created, capacity = " << capacity << std::endl;
    return queuePtr;
}

bool isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue){
    return (queue->size == 0);
}

bool enqueue(Queue *q, int e){
    if (isFull(q)){
        std::cout<< " Queue overflow" << std::endl;
        return false;
    }
    q->array[q->rear+1] = e;
    q->rear = (q->rear + 1) % (q->capacity);

    q->size = q->size + 1;
    return true;
}

int deque(Queue *q){
    if (isEmpty(q)){
        std::cout << " Queue underflow" << std::endl;
        return INT_MIN;
    }
    int element = q->array[q->front];
    // no copy operations in inplace only change the
    // location of front - O(1)
    q->front = (q->front + 1)%(q->capacity);
    q->size = q->size - 1;
    return element;
}

int front(Queue *q){
    if(isEmpty(q))
        return INT_MIN;
    return q->array[q->front];
}

int back(Queue *q){
    if(isEmpty(q))
        return INT_MIN;
    return q->array[q->rear];
}

int main(){
    srand(time(0));
    Queue* queue = createQueue(10);
    for(int i = 0; i < 12; i ++){
        enqueue(queue, rand()%INT_MAX);
    }
    std::cout << " front = " << front(queue) << std::endl;
    std::cout << " Is empty?  = " << isEmpty(queue) << std::endl;

    for (int i = 0; i < 14; i++){
        std::cout << " queue dequeed = " << deque(queue) << std::endl;
    }
    std::cout << " Queue empty? = " << isEmpty(queue) << std::endl;


}
