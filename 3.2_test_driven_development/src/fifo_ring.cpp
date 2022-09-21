#include <fifo_ring.h>

Fifo_ring::Fifo_ring()
{

}

int Fifo_ring::get()
{
    int front_item = buffer[front];
    if (front_item != 0)
    {
        front = (front + 1) % FIFO_SIZE;
        full_check--;
    }
    return front_item;
}

void Fifo_ring::put(int item)
{
    if ((back == front) && (full_check != 0))
    {
        front = (front + 1) % FIFO_SIZE;
    }
    else
    {
        full_check++;
    }
    buffer[back] = item;
    back = (back + 1) % FIFO_SIZE;
}

bool Fifo_ring::is_empty()
{
    return full_check == 0;
}

bool Fifo_ring::is_full()
{
    return full_check == FIFO_SIZE;
}

void Fifo_ring::reset()
{
    front = 0;
    back = 0;
    full_check = 0;
}