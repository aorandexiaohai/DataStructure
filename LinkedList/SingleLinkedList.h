#pragma once
#include <iomanip>
#include "NodeCommon.h"
namespace DS
{
template <class T>
class SingleLinkedList
{
  private:
    using Node = NodeCommon<T>;
    Node *head = {};
    Node *tail = {};

  public:
    ~SingleLinkedList()
    {
        delete this->head;
    }
    bool Empty()
    {
        return head == nullptr;
    }
    void AddToHead(const T &data)
    {
        if (Empty())
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            auto real_head = new Node(data);
            real_head->next = head;
            head = real_head;
        }
    }
    void AddToTail(const T &data)
    {
        if (Empty())
        {
            head = new Node(data);
            tail = head;
        }
        else
        {
            auto real_tail = new Node(data);
            tail->next = real_tail;
            tail = real_tail;
        }
    }
    bool DeleteFromHead(T &result)
    {
        if (Empty())
            return false;
        else
        {
            auto result_node = head;
            if (!head->next)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
            }
            result = result_node->data;
            //avoid recursive deletion
            result_node->next = nullptr;
            delete result_node;
        }
    }
    bool DeleteFromTail(T &result)
    {
        if (Empty())
            return false;
        else
        {
            Node *pre_tail = head;
            while (pre_tail && (pre_tail->next != tail))
            {
                pre_tail = pre_tail->next;
            }
            if (!pre_tail)
            {
                result = tail->data;
                delete tail;
                head = tail = nullptr;
            }
            else
            {
                pre_tail->next = nullptr;
                result = tail->data;
                delete tail;
                tail = pre_tail;
            }
            return true;
        }
    }
    bool DeleteElement(const T &ele)
    {
        Node *pre_node = nullptr;
        Node *cur_node = nullptr;
        if (ElementIsIn(ele, &pre_node, &cur_node))
        {
            auto next_node = cur_node->next;
            if (pre_node)
            {
                pre_node->next = next_node;
                if(!next_node)
                {
                    tail = pre_node;
                }
            }
            else
            {
                if(!next_node)
                {
                    head = tail = nullptr;
                }
                else
                {
                    head = next_node;
                }
            }
            cur_node->next = nullptr;
            delete cur_node;
            return true;
        }
        return false;
    }
    bool ElementIsIn(const T &ele, Node **pre_node_ptr = nullptr, Node **cur_node_ptr = nullptr)
    {
        if (pre_node_ptr)
            *pre_node_ptr = nullptr;
        if (cur_node_ptr)
            *cur_node_ptr = nullptr;
        auto tmp = head;
        while (tmp && tmp->data != ele)
        {
            if (pre_node_ptr)
                *pre_node_ptr = tmp;
            tmp = tmp->next;
        }
        if (tmp)
        {
            if (cur_node_ptr)
                *cur_node_ptr = tmp;
            return true;
        }
        return false;
    }
    std::ostream &show(std::ostream &os, const std::string &spliter = " ")
    {
        auto tmp = head;
        while (tmp)
        {
            os << tmp->data << spliter;
            tmp = tmp->next;
        }
        return os;
    }
};
} // namespace DS
