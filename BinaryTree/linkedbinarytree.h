#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

/*
*文件名称：				linkedbitree.h
*项目名称：				树结构及其应用
*创建者：				    刘健涵
*创建时间：				2022.7.1
*最后修改时间：			2022.6.28
*功能：					链式二叉树遍历和创建操作及二叉树结点的实现
*文件中的函数：           打印函数，删除节点函数
*文件中的类与结构体：	二叉树结点结构体和链式二叉树类
*与其他文件的依赖关系：	具体使用在mainwindow.cpp文件中
*/


//结构体名称：        链式二叉树结点结构体
//定义该结构体的目的：组成链式二叉树
template <typename T>
struct BinaryTreeNode
{
    T data;//数据域
    BinaryTreeNode<T>* left, * right;//指针域
};

//函数名称：打印函数
//功能描述：作为visit函数之一用于输出node的值
//预备条件：node指向结点不为空
//参数列表：结点指针node
//后置条件：输出node的值
template<typename T>
void printNode(BinaryTreeNode<T>*& node)
{

    if (node != nullptr)
    {
        std::cout << node->data;
    }
}

//函数名称：删除结点函数
//功能描述：作为visit函数之一用于释放node的空间
//预备条件：node指向结点不为空
//参数列表：结点指针node
//后置条件：释放node的空间
template<typename T>
void deleteNode(BinaryTreeNode<T>*& node)
{
    if (node != nullptr)
    {
        delete(node);
    }
}

//类名称：		  链式二叉树类
//定义该类的目的：进行二叉树的相关操作
//私有属性和函数：
//  根结点root
//1.先序创建函数：创建一个二叉树
//2.先序遍历函数：先序遍历二叉树
//3.中序遍历函数：中序遍历二叉树
//4.后续遍历函数：后续遍历二叉树
//公有属性和函数：
//  枚举常量：先序，中序，后序
//1.构造函数与析构函数：创建空树与释放二叉树空间
//2.创建函数：调用先序创建函数
//3.遍历函数：调用私有函数遍历二叉树
template <typename T>
class LinkedBiTree
{
private:
    int index = 0;
    BinaryTreeNode<T>* root;//根节点

    BinaryTreeNode<T>* PreCreate(T*& preorder);
    void PreOrderTraverse(BinaryTreeNode<T>*& node, void (*visit)(BinaryTreeNode<T>*& node));
    void InOrderTraverse(BinaryTreeNode<T>*& node, void (*visit)(BinaryTreeNode<T>*& node));
    void PostOrderTraverse(BinaryTreeNode<T>*& node, void (*visit)(BinaryTreeNode<T>*& node));

    string NRPreOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node));
    string NRInOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node));
    string NRPostOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node));
public:
    enum { PREORDER = 1, INORDER = 2, POSTORDER = 3 };
    LinkedBiTree() { root = nullptr; }//构造函数
    ~LinkedBiTree() {  }//析构函数
    void MakeEmpty() {root = nullptr; }//清空二叉树
    void create(T* preorder) { root = nullptr; root = PreCreate(preorder); }//二叉树只能创建一次
    void Traverse(int mode = PREORDER, void (*visit)(BinaryTreeNode<T>*& node) = printNode);//默认前序遍历
    string NonRecursiveTraverse(int mode = PREORDER, void (*visit)(BinaryTreeNode<T>*& node) = printNode);
};

#endif // LINKEDBINARYTREE_H

//函数名称：先序创建函数
//功能描述：根据先序序列递归创建一个二叉树
//预备条件：存在一个先序序列，空结点用空格表示
//参数列表：先序序列
//返回值  ：二叉树的根结点指针
//后置条件：堆区二叉树创建
template<typename T>
BinaryTreeNode<T>* LinkedBiTree<T>::PreCreate(T*& preorder)
{
    if (preorder != nullptr)
    {
        if (preorder[index]==' ')
        {
            index++;//验证之后指针才能移动
            return nullptr;
        }

        BinaryTreeNode<T>* node = new BinaryTreeNode<T>;
        node->data = preorder[index++];
        node->left = PreCreate(preorder);
        node->right = PreCreate(preorder);
        return node;
    }
    return nullptr;
}

//函数名称：先序遍历函数
//功能描述：从node结点开始递归先序遍历它的子结点
//预备条件：有visit函数可用且node结点不为空
//参数列表：对结点的操作函数visit，结点指针node
//后置条件：先序遍历使用visit函数
template<typename T>
inline void LinkedBiTree<T>::PreOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
{
    if (node != nullptr)
    {
        visit(node);
        PreOrderTraverse(node->left, visit);
        PreOrderTraverse(node->right, visit);
    }
}

//函数名称：中序遍历函数
//功能描述：从node结点开始递归中序遍历它的子结点
//预备条件：有visit函数可用且node结点不为空
//参数列表：对结点的操作函数visit，结点指针node
//后置条件：中序遍历使用visit函数
template<typename T>
inline void LinkedBiTree<T>::InOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
{
    if (node != nullptr)
    {
        InOrderTraverse(node->left, visit);
        visit(node);
        InOrderTraverse(node->right, visit);
    }
}

//函数名称：后序遍历函数
//功能描述：从node结点开始递归后序遍历它的子结点
//预备条件：有visit函数可用且node结点不为空
//参数列表：对结点的操作函数visit，结点指针node
//后置条件：后序遍历使用visit函数
template<typename T>
inline void LinkedBiTree<T>::PostOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
{
    if (node != nullptr)
    {
        PostOrderTraverse(node->left, visit);
        PostOrderTraverse(node->right, visit);
        visit(node);
    }
}

//函数名称：遍历函数
//功能描述：从root结点开始递归遍历它的子结点（默认先序遍历）
//预备条件：有visit函数可用且根结点不为空，mode不超过范围
//参数列表：遍历的方式mode（默认先序遍历），对结点的操作函数visit(默认为printNode)
//后置条件：使用visit函数进行遍历
template<typename T>
inline void LinkedBiTree<T>::Traverse(int mode, void(*visit)(BinaryTreeNode<T>*& node))
{
    switch (mode)
    {
    case PREORDER:PreOrderTraverse(root, visit); break;//先序遍历
    case INORDER:InOrderTraverse(root, visit); break;//中序遍历
    case POSTORDER:PostOrderTraverse(root, visit); break;//后续遍历

    default:
        break;
    }
}

//函数名称：非递归遍历树
template<typename T>
string LinkedBiTree<T>::NonRecursiveTraverse(int mode, void(*visit)(BinaryTreeNode<T>*& node))
{
    switch (mode)
    {
    case PREORDER:return NRPreOrderTraverse(root, visit);break;
    case INORDER:return NRInOrderTraverse(root, visit);break;
    case POSTORDER:return NRPostOrderTraverse(root, visit);break;
    }
}

//非递归前序遍历
template <typename T>
string LinkedBiTree<T>::NRPreOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
{
    string str = "";
    stack<BinaryTreeNode<T>*> s;
    BinaryTreeNode<T> *p=root;
    while(p!=NULL || !s.empty())
    {
        while(p!=NULL)
        {
            str+=p->data;  //入栈前输出节点的值
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            p=p->right;
        }
    }
    return str;
}

//非递归中序遍历
template <typename T>
string LinkedBiTree<T>::NRInOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
{
    string str = "";
    BinaryTreeNode<T> *p=root;
    stack<BinaryTreeNode<T>*> s;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p=s.top();
            str+=p->data;  //出栈前输出栈顶节点的值
            s.pop();
            p=p->right;
        }
    }
    return str;
}

//非递归后序遍历
template <typename T>
string LinkedBiTree<T>::NRPostOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
{
    string str = "";
    if (root == NULL)
        return str;
    stack<BinaryTreeNode<T>*> s;
    //pCur:当前访问节点，pLastVisit:上次访问节点
    BinaryTreeNode<T>* pCur, *pLastVisit;
    pCur = root;
    pLastVisit = NULL;
    //先把pCur移动到左子树最下边
    while (pCur)
    {
        s.push(pCur);
        pCur = pCur->left;
    }
    while (!s.empty())
    {
        //走到这里，pCur都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子)
        pCur = s.top();
        s.pop();
        //一个根节点被访问的前提是：无右子树或右子树已被访问过
        if (pCur->right == NULL || pCur->right == pLastVisit)
        {
            str+=pCur->data;
            //修改最近被访问的节点
            pLastVisit = pCur;
        }
        /*这里的else语句可换成带条件的else if:
        else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
        因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
        */
        else
        {
            //根节点再次入栈
            s.push(pCur);
            //进入右子树，且可肯定右子树一定不为空
            pCur = pCur->right;
            while (pCur)
            {
                s.push(pCur);
                pCur = pCur->left;
            }
        }
    }
    return str;
}


