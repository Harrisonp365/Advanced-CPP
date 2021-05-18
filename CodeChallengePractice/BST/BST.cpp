#include <iostream>
#include <string>   

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BSTree
{
public:
    //constructors
    BSTree() : root(nullptr) {}
    BSTree(TreeNode* rootNode): root(rootNode) {}

    void print();

private:
    TreeNode* root;
    std::string subTreeAsString(TreeNode* node); //Helper func for print
};

int main()
{
    //create and empty tree
    BSTree emptyTree{};
    emptyTree.print();
    //create a tree with 4 left child and 6 right child

    TreeNode root(5);
    TreeNode leftChild(4);
    TreeNode rightChild(6);

    //connect Nodes
    root.left = &leftChild;
    root.right = &rightChild;

    BSTree myTree{ &root };
    myTree.print();

}

void BSTree::print()
{
    if (this->root == nullptr)
    {
        std::cout << "{}" << std::endl;
    }
    else
    {
        std::cout << this->subTreeAsString(this->root) << std::endl;
    }
}

std::string BSTree::subTreeAsString(TreeNode* node)
{
    std::string leftString = (node->left == nullptr) ? "{}" : subTreeAsString(node->left);
    std::string rightString = (node->right == nullptr) ? "{}" : subTreeAsString(node->right);
    std::string result = "{" + std::to_string(node->data) + ", " + leftString + ", " + rightString + "}";
    return result;
}
