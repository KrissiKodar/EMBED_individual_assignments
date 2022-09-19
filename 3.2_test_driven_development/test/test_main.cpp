#include <avr/delay.h>
#include <unity.h>

#include <fifo.h>
//#include <fifo_ring.h>

void test_reset(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);
    f.put(2);
    f.reset();

    // 2-3 Execute and validate
    TEST_ASSERT_TRUE(f.is_empty());

    // 4 Cleanup
}

void test_put(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);

    // 2-3 Execute and validate
    TEST_ASSERT_EQUAL(1, f.get());

    // 4 Cleanup
}

void test_empty(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);
    f.put(2);
    f.put(3);
    f.put(4);
    f.put(5);

    // 2-3 Execute and validate
    TEST_ASSERT_TRUE(!f.is_empty());

    // 4 Cleanup
}

void test_normal_flow(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);
    f.put(2);
    f.get();
    f.put(3);

    // 2-3 Execute and validate
    TEST_ASSERT_EQUAL(2, f.get());
    TEST_ASSERT_EQUAL(3, f.get());

    // 4 Cleanup
}

void test_underflow(void)

{
    // 1 Setup
    Fifo f;
    //f.get();
    f.put(1);
    f.put(2);
    f.get();
    f.get();

    // 2-3 Execute and validate
    TEST_ASSERT_TRUE(f.is_empty());

    // 4 Cleanup
}

void test_overflow(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);
    f.get();
    f.put(2);
    f.put(3);
    f.put(4);
    f.get();
    f.put(5);
    f.put(6);
    f.put(7);

    // 2-3 Execute and validate
    TEST_ASSERT_TRUE(f.is_full());

    // 4 Cleanup
}

void test_overwrite(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);
    f.put(2);
    f.put(3);
    f.put(4);
    f.put(5);
    // it wants to put 6 here, but the buffer is full
    // 
    f.put(6);
    f.put(7);


    // 2-3 Execute and validate
    TEST_ASSERT_TRUE(f.is_full());
    TEST_ASSERT_EQUAL(1, f.get());
    TEST_ASSERT_EQUAL(2, f.get());
    TEST_ASSERT_EQUAL(3, f.get());
    TEST_ASSERT_EQUAL(4, f.get());
    TEST_ASSERT_EQUAL(5, f.get());
    TEST_ASSERT_TRUE(f.is_empty());

    // 4 Cleanup
}

void test_a_lot(void)
{
    // 1 Setup
    Fifo f;
    f.put(1);
    f.put(2);
    f.put(3);
    f.put(4);
    f.put(5);
    f.get();
    f.get();
    // it wants to put 6 here, but the buffer is full
    // 
    f.put(6);
    f.put(7);

    // 2-3 Execute and validate
    TEST_ASSERT_TRUE(f.is_full());
    TEST_ASSERT_EQUAL(3, f.get());
    TEST_ASSERT_EQUAL(4, f.get());
    TEST_ASSERT_EQUAL(5, f.get());
    TEST_ASSERT_EQUAL(6, f.get());
    TEST_ASSERT_EQUAL(7, f.get());
    TEST_ASSERT_TRUE(f.is_empty());

    // 4 Cleanup
}

int main()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    _delay_ms(2000);

    UNITY_BEGIN(); // IMPORTANT LINE!

    
    RUN_TEST(test_normal_flow);
    RUN_TEST(test_underflow);
    // Add more unit tests here
    RUN_TEST(test_reset);
    RUN_TEST(test_overflow);
    RUN_TEST(test_overwrite);
    RUN_TEST(test_put);
    RUN_TEST(test_empty);
    RUN_TEST(test_a_lot);

    UNITY_END(); // stop unit testing
}