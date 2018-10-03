#pragma once
namespace DS
{
template <class T>
struct NodeCommon
{
    T data = {};
    NodeCommon *next = {};
    ~NodeCommon()
    {
        delete this->next;
    }
    NodeCommon(const T &datapar) : data(datapar) {}
    NodeCommon(const T &datapar, NodeCommon* next_par) : data(datapar),next(next_par) {}

    static void DeleteSingleNode(NodeCommon *node)
    {
        node->next = nullptr;
        delete node;
    }
};
} // namespace DS