#include <fifo.h>

Fifo::Fifo()
{

}

int Fifo::get()
{
    if (is_empty())
    {
        return 0;
    }
    // if buffer is not empty, return the first item in the buffer
    else
    {
        out_item = buffer[0];
        // move all items in the buffer one step forward
        for (int i = 0; i < back_of_buffer; i++)
        {
            buffer[i] = buffer[i + 1];
        }
        buffer[FIFO_SIZE-1] = 0;
        // decrease the back_of_buffer by 1
        back_of_buffer--;
        return out_item;
    }
    
}

void Fifo::put(int item)
{
    // if buffer is full, overwrite the first item in the buffer
    if (is_full())
    {
        // move all items in the buffer one step forward
        for (int i = 0; i < FIFO_SIZE-1; i++)
        {
            buffer[i] = buffer[i + 1];
        }
        buffer[FIFO_SIZE-1] = item;
    }
    // if buffer is not full, add the item to the end of the buffer
    else
    {
        buffer[back_of_buffer] = item;
        back_of_buffer++;
    }
    
}

bool Fifo::is_empty()
{
    return back_of_buffer == 0;
}

bool Fifo::is_full()
{
    return back_of_buffer == FIFO_SIZE;
}

void Fifo::reset()
{
    for (int i = 0; i < FIFO_SIZE; i++)
    {
        buffer[i] = 0;
    }
    back_of_buffer = 0;
}