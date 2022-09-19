#include <fifo.h>

Fifo::Fifo()
{

}

int Fifo::get()
{
    // shift all items in buffer forward by one
    // return the first item in the buffer
    // decrement the back_of_buffer variable
    if (is_empty())
    {
        // if buffer is empty return 0 
        return 0;
    }
    else
    {
        out_item = buffer[0];
        for (int i = 0; i < FIFO_SIZE - 1; i++)
        {
            buffer[i] = buffer[i + 1];
        }
        buffer[FIFO_SIZE - 1] = 0;
        back_of_buffer--;
        return out_item;
    }
    
}

void Fifo::put(int item)
{
    // put item at the back of the buffer
    // increment the back_of_buffer variable
    if (back_of_buffer < FIFO_SIZE)
    {
        buffer[back_of_buffer] = item;
        back_of_buffer++;
    }
    else
    {
        // do nothing
    }
}

bool Fifo::is_empty()
{
    return buffer[0] == 0;
}

bool Fifo::is_full()
{
    return buffer[FIFO_SIZE - 1] != 0;
}

void Fifo::reset()
{
    for (int i = 0; i < FIFO_SIZE; i++)
    {
        buffer[i] = 0;
    }
    back_of_buffer = 0;
}