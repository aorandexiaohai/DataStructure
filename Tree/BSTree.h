#pragma once
#include <iostream>
#include <string>

#include "Queue.h"
#include "Stack.h"
namespace DS
{
template <class T>
struct BSNode
{
    T data = {};
    BSNode *left = {};
    BSNode *right = {};
    BSNode(const T &data_par)
        : data(data_par) {}
    BSNode(const T &data_par, BSNode *left_par, BSNode *right_par)
        : data(data_par), left(left_par), right(right_par) {}
    ~BSNode()
    {
        delete this->left;
        delete this->right;
    }
    static void DeleteSingleNode(BSNode *node)
    {
        node->left = nullptr;
        node->right = nullptr;
        delete node;
    }
    static void Visit(BSNode *p, const std::string& spliter=" ") const
    {
        std::cout  << p->data <<spliter << std::endl;
    }
};
template <class T>
class BSTree
{
  private:
    using Node = BSNode<T>;
    Node *root = {};

  public:
    ~BSTree()
    {
        delete root;
    }
    bool Empty()
    {
        return !root;
    }
    void PreOrder()
    {
        InnerPreOrder(root);
    }
    void InOrder()
    {
        InnerInOrder(root);
    }
    void AfterOrder()
    {
        InnerAfterOrder(root);
    }
    T *Search(const T &ele)
    {
        if (!root)
            return nullptr;
        auto p = root;
        while (p)
        {
            auto &data = p->data;
            if (data == ele)
                return &data;
            else if (data < ele)
                p = p->left;
            else
                p = p->right;
        }
        return nullptr;
    }
    void BreathFirst() const
    {
        if (!root)
            return;
        Queue<Node *> queue;
        queue.EnQueue(root);
        while (!queue.Empty())
        {
            auto ele = queue.DeQueue();
            Node::Visit(p);
            if (ele->left)
                queue.EnQueue(ele->left);
            if (ele->right)
                queue.EnQueue(ele->right);
        }
    }

    void IterativePreOrder();
    void IterativeInOrder();
    void IterativeAfterOrder();

    void MorrisInOrder();
    void Insert(const T &t);
    void DeleteByMerging(BSNode<T> *&);
    void FindAndDeleteByMerging(const T &);
    void DeleteByCopying(BSNode<T> *&);
    void Blance(T *, int, int);

  private:
    static void InnerPreOrder(Node *node)
    {
        if (!node)
            return;
        Node::Visit(p);
        InnerPreOrder(p->left);
        InnerPreOrder(p->right);
    }
    static void InnerInOrder()
    {
        if (!node)
            return;
        InnerPreOrder(p->left);
        Node::Visit(p);
        InnerPreOrder(p->right);
    }
    static void InnerAfterOrder()
    {
        if (!node)
            return;
        InnerPreOrder(p->left);
        InnerPreOrder(p->right);
        Node::Visit(p);
    }
};
} // namespace DS