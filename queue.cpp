#include<iostream>
using namespace std;

class Queue
{
private:
  int* data;
  int* front;
  int* rear;
  int size;
public:
  Queue(int maxSize)
  {
    data = new int[maxSize];
    front = new int;
    rear = new int;
    size = 0;
    *front = -1;
    *rear = -1;
  }
  ~Queue()
  {
    delete[]data;
    delete front;
    delete rear;
  }
  void enQueue(int value)
  {
    if (size == this->size)
    {
      cout << "Queue is full!" << endl;
      return;
    }
    *(rear + 1) = value;
    rear++;
    size++;
  }
  int deQueue()
  {
    if (size == 0)
    {
      cout << "Queue is empty!" << endl;
      return -1;
    }
    int value = *(front);
    front++;
    size--;
    return value;
  }
  int getSize()
  {
    return size;
  }
};

int main()
{
  Queue q(5);
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(17);
  q.enQueue(18);
  q.enQueue(23);
  q.enQueue(24);

  cout << "Size: " << q.getSize() << endl;
  cout << "Dequeue: " << q.deQueue() << endl;
  cout << "Dequeue: " << q.deQueue() << endl;

  return 0;
}