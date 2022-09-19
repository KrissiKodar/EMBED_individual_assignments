#include <fifo.h>

Fifo::Fifo()
{

}

int Fifo::get()
{
    int front_item = buffer[front];
    front = (front + 1) % FIFO_SIZE;
    return front_item;
}

void Fifo::put(int item)
{
    buffer[back] = item;
    back = (back + 1) % FIFO_SIZE;
}

bool Fifo::is_empty()
{
    return front == back;
}

bool Fifo::is_full()
{
    return (back + 1) % FIFO_SIZE == front;
}

void Fifo::reset()
{
    front = 0;
    back = 0;
}