#include <fifo_ring.h>

Fifo_ring::Fifo_ring()
{

}

int Fifo_ring::get()
{
    int front_item = buffer[front];
    front = (front + 1) % FIFO_SIZE;
    full_check--;
    return front_item;
}

void Fifo_ring::put(int item)
{
    if (full_check < FIFO_SIZE)
    {
        buffer[back] = item;
        back = (back + 1) % FIFO_SIZE;
        full_check++;
    }
    else
    {
        // do nothing
        // the buffer is full
        // therefore the item is not added
        // it is overwritten
    }
}

bool Fifo_ring::is_empty()
{
    return full_check == 0;
}

bool Fifo_ring::is_full()
{
    // check if the buffer is full
    return full_check == FIFO_SIZE;
}

void Fifo_ring::reset()
{
    front = 0;
    back = 0;
    full_check = 0;
}