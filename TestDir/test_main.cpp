#include "SingleLinkedList.h"
#include "DoubleLinkedList.h"
#include "LoopLinkedList.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <algorithm>

#include "ParameterParse.h"

#define SHOW_LIST(arr)        \
    std::cout << #arr << ":"; \
    arr.show(std::cout);      \
    std::cout << std::endl;

#define SHOW(value)             \
    std::cout << #value << ":"; \
    std::cout << value;         \
    std::cout << std::endl;
static char *CommandList[] = {
    "AddToHead",
    "DeleteFromHead",
    "AddToTail",
    "DeleteFromTail",
    "DeleteElement"};
#define CONFIG_STR_DEFINE(str) \
    const std::string str = "--" #str;
int main(int argc, char **argv)
{
    CONFIG_STR_DEFINE(test_case);
    CONFIG_STR_DEFINE(test_range);

    CONFIG_STR_DEFINE(enable_all_case);
    CONFIG_STR_DEFINE(enable_single_linked_list);
    CONFIG_STR_DEFINE(enable_double_linked_list);
    CONFIG_STR_DEFINE(enable_looped_linked_list);

    DS::global_config.RegValue(test_case, 100);
    DS::global_config.RegValue(test_range, 100);
    DS::global_config.RegValue(enable_all_case, "TRUE");
    DS::global_config.RegValue(enable_single_linked_list, "TRUE");
    DS::global_config.RegValue(enable_double_linked_list, "TRUE");
    DS::global_config.RegValue(enable_looped_linked_list, "TRUE");

    DS::global_config.Init(argc, argv);

    DS::global_config.ShowDefault(std::cout);

    int TestCase = DS::global_config.GetAnyValue(test_case);
    int TestRange = DS::global_config.GetAnyValue(test_range);
    bool EnableAllCase = DS::global_config.GetAnyValue(enable_all_case);
    bool benable_single_linked_list = DS::global_config.GetAnyValue(enable_single_linked_list);
    bool benable_double_linked_list = DS::global_config.GetAnyValue(enable_double_linked_list);
    bool benable_looped_linked_list = DS::global_config.GetAnyValue(enable_looped_linked_list);

    // SHOW(TestCase);
    // SHOW(TestRange);
    // SHOW(EnableAllCase);

    // SHOW(benable_single_linked_list);
    // SHOW(benable_double_linked_list);
    // SHOW(benable_looped_linked_list);

    std::srand(std::time(nullptr));

    if(!EnableAllCase) return 0;
    
    if(benable_single_linked_list)
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

    if(benable_double_linked_list)
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

    if(benable_looped_linked_list)
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