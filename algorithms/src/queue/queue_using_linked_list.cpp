#include <cstdio>
#include <iostream>
#include <limits.h>

struct Node {
  Node *next;
  int val;
  Node(int val, Node *n) {
    this->next = n;
    this->val = val;
  };
};

class Queue {
public:
  Node *front;
  Node *rear;
  int size;
  signed capacity;
  Queue(int capacity) {
    this->capacity = capacity;
    front = nullptr;
    rear = nullptr;
    size = 0;
  }

  bool isEmpty() { return (this->size == 0); }

  bool isFull() { return (this->size == this->capacity); }

  void enqueue(int e) {
    if (isFull()) {
      std::cout << "Buffer overflow \n";
      return;
    }
    // connect current rear to new node
    Node *n = new Node(e, nullptr);
    if (rear==nullptr && front==nullptr)
      front = rear = n;

    rear->next = n;
    rear =n;
     // update size
     size = size + 1;
  }

  int dequeue() {
    if (isEmpty()) {
      std::cout << " Buffer underflow \n";
      return -1;
    }

    int e = front->val;
    front = front->next;
    size = size - 1;
    return e;
  }

  int queueFront() {
    if (isEmpty()) {
      std::cout << "Queue empty, no front" << std::endl;
    }

    return front->val;
  }

  int queueRear() {
    if (isEmpty()) {
      std::cout << "Queue empty, no rear" << std::endl;
    }

    return rear->val;
  }
};

int main() {
  srand(time(0));
  Queue q(10);
  for (int i = 0; i < 10; i++) {
    int n = rand();
    std::cout << n << ",";
    q.enqueue(n % INT_MAX);
  }
  printf("\n");
  std::cout << "queue size = " << q.size << std::endl;
  q.dequeue();
  std::cout << "queue size = " << q.size << std::endl;
  q.dequeue();
  std::cout << "queue size = " << q.size << std::endl;
  std::cout << " Queue front : " << q.queueFront()
            << " , and rear = " << q.queueRear() << "\n";
  std::cout << " Queue elements are: \n";
  int init_size = q.size;
  for (int i = 0; i <= init_size; i++) {
    std::cout << "size = " << q.size << std::endl;
    int element = q.dequeue();
    std::cout << element << ",";
  }
  printf("\n");
}
