#pragma once
#include "DoubleLinkedList.h"
namespace DS
{
    template<class T>
    class Queue : protected DoubleLinkedList<T>
    {
    public:
        Queue(){}
        void EnQueue(const T& ele){
            this->AddToTail(ele);
        }
        bool Empty() const
        {
            return this->DoubleLinkedList<T>::Empty();
        }
        T DeQueue()
        {
            T result;
            auto state = this->DeleteFromHead(result);
            return result;
        }
    };
}