#include <iostream>

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};


int main()
{
    //create a tree with 4 left child and 6 right child

    TreeNode root(5);
    TreeNode leftChild(4);
    TreeNode rightChild(6);

    //connect Nodes
    root.left = &leftChild;
    root.right = &rightChild;

    // Print info about foo
    std::cout << "data: " << root.data << ", left: " << root.left->data << ", right: " << root.right->data << std::endl;
}
