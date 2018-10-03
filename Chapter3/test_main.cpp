#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "LoopLinkedList.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

int TestCase = 100;
int TestRange = 100;

#define SHOW_LIST(arr)        \
    std::cout << #arr << ":"; \
    arr.show(std::cout);      \
    std::cout << std::endl;

#define SHOW(value)             \
    std::cout << #value << ":"; \
    std::cout << value;         \
    std::cout << std::endl;
static char* CommandList[] = {
    "AddToHead",
    "DeleteFromHead",
    "AddToTail",
    "DeleteFromTail",
    "DeleteElement"
};
int main(int argc, char** argv)
{
    std::vector<std::string> par_vec;
    for(int index=1; index<argc; index++)
    {
        par_vec.push_back(argv[index]);
    }
    if(std::find(par_vec.begin(), par_vec.end(), "--longtest") != par_vec.end())
    {
        TestCase*=TestCase;
        TestRange=TestCase;
    }
    else if(std::find(par_vec.begin(), par_vec.end(), "--longlongtest") != par_vec.end())
    {
        TestCase*=(TestCase*10);
        TestRange=TestCase;
    }
    std::srand(std::time(nullptr));

    {
        DS::SingleLinkedList<int> slli;
        SHOW_LIST(slli);

        for (int index = 0; index < TestCase; index++)
        {
            auto command = std::rand() % 5;
            SHOW(CommandList[command]);
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
            SHOW(CommandList[command]);
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

    {
        DS::LoopLinkedList<int> llli;
        SHOW_LIST(llli);

        for (int index = 0; index < TestCase; index++)
        {
            auto command = std::rand() % 5;
            SHOW(CommandList[command]);
            if (command == 0)
            {
                llli.AddToHead(std::rand() % TestRange);
                SHOW_LIST(llli);
            }
            else if (command == 1)
            {
                auto delete_result = 0;
                auto delete_state = llli.DeleteFromHead(delete_result);
                SHOW_LIST(llli);
            }
            else if (command == 2)
            {
                llli.AddToTail(std::rand() % TestRange);
                SHOW_LIST(llli);
            }
            else if (command == 3)
            {
                auto delete_result = 0;
                auto delete_state = llli.DeleteFromTail(delete_result);
                SHOW_LIST(llli);
            }
            else if (command == 4)
            {
                llli.DeleteElement(std::rand() % TestRange);
                SHOW_LIST(llli);
            }
        }
    }

    std::cout << "over" << std::endl;
}