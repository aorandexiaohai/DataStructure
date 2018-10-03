#pragma once
namespace DS
{
template <class T>
class DoubleLinkedList
{
  private:
    struct Node
    {
        T data = {};
        Node * prev = {};
        Node * next = {};
        ~Node()
        {
            delete this->next;
        }
        Node(const T &datapar) : data(datapar) {}
    };
    Node *head = {};
    Node *tail = {};

  public:
    ~DoubleLinkedList()
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
            head->prev = real_head;
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
            auto real_tail  = new Node(data);
            tail->next      = real_tail;
            real_tail->prev = tail;
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
                head->prev = nullptr;
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
            auto result_node = tail;
            if(!tail->prev)
            {
                head = tail = nullptr;
            }
            else
            {
                tail = tail->prev;
                tail->next = nullptr;
            }

            result = result_node->data;

            //avoid recursive deletion
            result_node->next = nullptr;
            delete result_node;
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
                else
                {
                    next_node->prev = pre_node;
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
                    head->prev = nullptr;
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