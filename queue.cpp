// queue.cpp -- Queue and Customer methods
#include "queue.h"
#include <cstdlib>

//  Queue methods
Queue::Queue(int qs):qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node * temp;
    while(front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}


bool Queue::isempty()const
{
    return items == 0;
}

bool Queue::isfull() const
{
    return items == qsize;
}


int Queue::queueCount() const
{
    return items;
}

// add item to queue
bool Queue::enqueue(const Item & item)
{
    if(isfull())
        return false;
    Node * add = new Node; // create node
    // on failure,new throw std::bad_alloc exception
    add->item = item;
    add->next = nullptr;
    items++;
    if(front == nullptr)
        front = add; // place item at front
    else
        rear->next =add; // else place at rear
    rear = add; // have rear point to new node
    return true;
}

bool Queue::dequeue(Item & item)
{
    if(front == nullptr)
        return false;
    item = front->item; // set item to first item in queue
    items--;
    Node * temp = front; // save location of first item
    front = front->next; // reset front to next item
    delete temp; // delete former first item
    if(items == 0)
        rear = nullptr;
    return true;

}

// time set to a random value in the range 1-3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1; // random generate wait time 1 - 3
    arrive = when;
}


