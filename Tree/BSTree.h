#pragma once
namespace DS
{
    template<class T>
    struct BSNode
    {
        T data ={};
        BSNode* left ={};
        BSNode* right ={};
        BSNode(const T& data_par)
            :data(data_par){}
        BSNode(const T& data_par, BSNode*left_par, BSNode*right_par)
            :data(data_par), left(left_par),right(right_par){}
        ~BSNode(){
            delete this->left;
            delete this->right;
        }
        void DeleteSingleNode(BSNode* node)
        {
            node->left = nullptr;
            node->right = nullptr;
            delete node;
        }
    };
    template<class T>
    class BSTree
    {
    private:
        BSNode* root = {};
    public:
        ~BSTree()
        {
            delete root;
        }
        bool Empty()
        {
            return !root;
        }
        void PreOrder();
        void InOrder();
        void AfterOrder();
        const T* Search(const T& ele) const;
        void BreathFirst();
        void IterativePreOrder();
        void IterativeInOrder();
        void IterativeAfterOrder();
        void MorrisInOrder();
        void Insert(const T& t);
        void DeleteByMerging(BSNode<T>* &);
        void FindAndDeleteByMerging(const T&);
        void DeleteByCopying(BSNode<T>* &);
        void Blance(T*, int, int);
    };
}