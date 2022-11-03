#include <iostream>
#include "queue_link_array.h"

int main()
{
    Queue<int> q;

    for (int i = 0; i < 10; i++)
    {
        q.push(i);

    }
    std::cout << q.length();
}