#pragma once
#include "NodeCommon.h"
#include <cassert>
namespace DS
{
template <class T>
class LoopLinkedList
{
  private:
    using Node = NodeCommon<T>;
    Node *head = {};
    Node *tail = {};
    static void CorrectTail(LoopLinkedList* lll)
    {
        lll->tail->next = lll->head;
    }

  public:
    ~LoopLinkedList()
    {
        //avoid recursive deletion
        if(tail)
            tail->next = nullptr;
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
            tail = head = new Node(data);
            CorrectTail(this);
        }
        else
        {
            auto real_head = new Node(data, head);
            head = real_head;

            CorrectTail(this);
        }
    }
    void AddToTail(const T &data)
    {
        if (Empty())
        {
            tail = head = new Node(data);
            CorrectTail(this);
        }
        else
        {
            auto real_tail = new Node(data);
            tail->next = real_tail;
            tail = real_tail;

            CorrectTail(this);
        }
    }
    bool DeleteFromHead(T &result)
    {
        if (Empty())
            return false;
        else
        {
            auto result_node = head;
            result = result_node->data;
            if (head == tail)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
                CorrectTail(this);
            }
            NodeCommon<T>::DeleteSingleNode(result_node);
        }
    }
    bool DeleteFromTail(T &result)
    {
        if (Empty())
            return false;
        else
        {
            Node *pre_tail = head;
            while (pre_tail &&(pre_tail!=tail) && (pre_tail->next != tail))
            {
                pre_tail = pre_tail->next;
            }

            if (pre_tail == tail)
            {
                result = tail->data;
                NodeCommon<T>::DeleteSingleNode(tail);
                head = tail = nullptr;
            }
            else
            {
                if(!pre_tail)
                    assert(!pre_tail);
                pre_tail->next = nullptr;
                result = tail->data;
                
                NodeCommon<T>::DeleteSingleNode(tail);
                tail = pre_tail;

                CorrectTail(this);
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
            if(cur_node==tail)
                next_node = nullptr;
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
            if(!Empty())
                CorrectTail(this);
            NodeCommon<T>::DeleteSingleNode(cur_node);
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
            if(tmp==tail)
            {
                return false;
            }
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
            if(tmp==tail)
                break;
        }
        return os;
    }
};
} // namespace DS