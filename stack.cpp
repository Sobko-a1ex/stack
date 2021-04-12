#include "stack.h"

stack::stack()
{
    this->m_bufferSize = sizeof(m_buffer) / sizeof(m_buffer[0]);
    this->m_getIndex = 0;
    this->m_putIndex = 0;
    this->m_dataLength = 0;
}

void stack::push(int elem)
{
    if (this->m_dataLength != 0) {
        if (this->m_putIndex == this->m_getIndex) {
            this->m_getIndex++;
            this->m_dataLength--;
            if (this->m_getIndex == this->m_bufferSize)
                this->m_getIndex = 0;
        }
    }
    this->m_buffer[this->m_putIndex++] = elem;
    if (this->m_putIndex == this->m_bufferSize)
        this->m_putIndex = 0;
    this->m_dataLength++;
}

int stack::pop()
{
    int byte;
    if (m_dataLength == 0) {

        return false;
    }

    byte = this->m_buffer[this->m_getIndex++];
    if (this->m_getIndex == this->m_bufferSize)
        this->m_getIndex = 0;
    this->m_dataLength--;

    return byte;
}

void stack::multiPop(int N)
{
    bool l_flag = false;

    int length = 0;
    if (this->m_dataLength == 0) {
        return;
    }

    uint32_t dataLength = this->m_dataLength;

    if (this->m_getIndex > dataLength)
        this->m_getIndex = dataLength;

    for (uint32_t i = 0; i < m_getIndex; i++) {

        l_flag = this->pop();
        length++;

        if (l_flag == false) {

            break;
        }
    }
}

void stack::show()
{
    for (int i = 0; i < this->m_bufferSize; i++)
    {
        std::cout << this->m_buffer[this->m_getIndex] << std::endl;
    }
}

bool stack::isEmpty()
{
    if (this->m_dataLength == 0)
    {
        std::cout << "Buffer is empty" << std::endl;
        return true;
    }
    return false;
}
