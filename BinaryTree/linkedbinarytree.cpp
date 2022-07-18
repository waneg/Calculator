//#include "linkedbinarytree.h"

////函数名称：先序创建函数
////功能描述：根据先序序列递归创建一个二叉树
////预备条件：存在一个先序序列，空结点用空格表示
////参数列表：先序序列
////返回值  ：二叉树的根结点指针
////后置条件：堆区二叉树创建
//template<typename T>
//BinaryTreeNode<T>* LinkedBiTree<T>::PreCreate(T*& preorder)
//{
//    if (preorder != nullptr)
//    {
//        static int index = 0;//静态指针用于标记当前指向的序列元素
//        if (preorder[index] == " ")
//        {
//            index++;//验证之后指针才能移动
//            return nullptr;
//        }

//        BinaryTreeNode<T>* node = new BinaryTreeNode<T>;
//        node->data = preorder[index++];
//        node->left = PreCreate(preorder);
//        node->right = PreCreate(preorder);
//        return node;
//    }
//    return nullptr;
//}

////函数名称：先序遍历函数
////功能描述：从node结点开始递归先序遍历它的子结点
////预备条件：有visit函数可用且node结点不为空
////参数列表：对结点的操作函数visit，结点指针node
////后置条件：先序遍历使用visit函数
//template<typename T>
//inline void LinkedBiTree<T>::PreOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
//{
//    if (node != nullptr)
//    {
//        visit(node);
//        PreOrderTraverse(node->left, visit);
//        PreOrderTraverse(node->right, visit);
//    }
//}

////函数名称：中序遍历函数
////功能描述：从node结点开始递归中序遍历它的子结点
////预备条件：有visit函数可用且node结点不为空
////参数列表：对结点的操作函数visit，结点指针node
////后置条件：中序遍历使用visit函数
//template<typename T>
//inline void LinkedBiTree<T>::InOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
//{
//    if (node != nullptr)
//    {
//        InOrderTraverse(node->left, visit);
//        visit(node);
//        InOrderTraverse(node->right, visit);
//    }
//}

////函数名称：后序遍历函数
////功能描述：从node结点开始递归后序遍历它的子结点
////预备条件：有visit函数可用且node结点不为空
////参数列表：对结点的操作函数visit，结点指针node
////后置条件：后序遍历使用visit函数
//template<typename T>
//inline void LinkedBiTree<T>::PostOrderTraverse(BinaryTreeNode<T>*& node, void(*visit)(BinaryTreeNode<T>*& node))
//{
//    if (node != nullptr)
//    {
//        PostOrderTraverse(node->left, visit);
//        PostOrderTraverse(node->right, visit);
//        visit(node);
//    }
//}

////函数名称：遍历函数
////功能描述：从root结点开始递归遍历它的子结点（默认先序遍历）
////预备条件：有visit函数可用且根结点不为空，mode不超过范围
////参数列表：遍历的方式mode（默认先序遍历），对结点的操作函数visit(默认为printNode)
////后置条件：使用visit函数进行遍历
//template<typename T>
//inline void LinkedBiTree<T>::Traverse(int mode, void(*visit)(BinaryTreeNode<T>*& node))
//{
//    std::cout << "TRAVERSE" << std::endl;
//    switch (mode)
//    {
//    case PREORDER:PreOrderTraverse(root, visit); break;//先序遍历
//    case INORDER:InOrderTraverse(root, visit); break;//中序遍历
//    case POSTORDER:PostOrderTraverse(root, visit); break;//后续遍历

//    default:
//        break;
//    }
//}
