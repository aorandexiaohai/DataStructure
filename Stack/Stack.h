#pragma once
#include "DoubleLinkedList.h"
namespace DS
{
template <class T>
class Stack : protected DoubleLinkedList<T>
{
  public:
    Stack() {}
    void EnStack(const T &ele)
    {
        this->AddToTail(ele);
    }
    bool Empty() const
    {
        return this->DoubleLinkedList<T>::Empty();
    }
    T DeStack()
    {
        T result;
        auto state = this->DeleteFromTail(result);
        return result;
    }
}
} // namespace DS