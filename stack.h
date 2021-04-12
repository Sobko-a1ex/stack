#pragma once
#include <iostream>

class stack
{
public:
    stack();
    void push(int elem);
    int pop();
    void multiPop(int  N);
    void show();
    bool isEmpty();

private:

    int m_buffer[512];
    int m_bufferSize;
    int m_putIndex;
    int m_getIndex;
    int m_dataLength;
};

