#ifndef FIFO_RING_H
#define FIFO_RING_H

const int FIFO_SIZE = 5;

class Fifo_ring
{
public:
    Fifo_ring();
    int get();
    void put(int item);
    bool is_empty();
    bool is_full();
    void reset();
private:
    int buffer[FIFO_SIZE];
    // add variables pointing to the front and back of the buffer
    int front = 0;
    int back = 0;
    int full_check = 0;
};

#endif // FIFO_RING_H