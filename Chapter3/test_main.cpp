#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

const int TestSize = 10;
const int TestCase = 100;
const int TestRange = 100;
#define SHOW_LIST(arr)        \
    std::cout << #arr << ":"; \
    arr.show(std::cout);      \
    std::cout << std::endl;

#define SHOW(value)             \
    std::cout << #value << ":"; \
    std::cout << value;         \
    std::cout << std::endl;
int main()
{

    std::srand(std::time(nullptr));

    {
        DS::SingleLinkedList<int> slli;
        SHOW_LIST(slli);

        for (int index = 0; index < TestCase; index++)
        {
            auto command = std::rand() % 5;
            if (command == 0)
            {
                slli.AddToHead(std::rand() % TestRange);
                SHOW_LIST(slli);
            }
            else if (command == 1)
            {
                auto delete_result = 0;
                auto delete_state = slli.DeleteFromHead(delete_result);
                SHOW_LIST(slli);
            }
            else if (command == 2)
            {
                slli.AddToTail(std::rand() % TestRange);
                SHOW_LIST(slli);
            }
            else if (command == 3)
            {
                auto delete_result = 0;
                auto delete_state = slli.DeleteFromTail(delete_result);
                SHOW_LIST(slli);
            }
            else if (command == 4)
            {
                slli.DeleteElement(std::rand() % TestRange);
                SHOW_LIST(slli);
            }
        }
    }

    {
        DS::DoubleLinkedList<int> dlli;
        SHOW_LIST(dlli);

        for (int index = 0; index < TestCase; index++)
        {
            auto command = std::rand() % 5;
            if (command == 0)
            {
                dlli.AddToHead(std::rand() % TestRange);
                SHOW_LIST(dlli);
            }
            else if (command == 1)
            {
                auto delete_result = 0;
                auto delete_state = dlli.DeleteFromHead(delete_result);
                SHOW_LIST(dlli);
            }
            else if (command == 2)
            {
                dlli.AddToTail(std::rand() % TestRange);
                SHOW_LIST(dlli);
            }
            else if (command == 3)
            {
                auto delete_result = 0;
                auto delete_state = dlli.DeleteFromTail(delete_result);
                SHOW_LIST(dlli);
            }
            else if (command == 4)
            {
                dlli.DeleteElement(std::rand() % TestRange);
                SHOW_LIST(dlli);
            }
        }
    }
}