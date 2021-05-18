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
    void insert(int val);

private:
    TreeNode* root;
    std::string subTreeAsString(TreeNode* node); //Helper func for print
    void insert(int val, TreeNode* node); // Helper func for insert
};

int main()
{
    //create and empty tree
    BSTree myTree{};
    myTree.print();
   
    myTree.insert(5);
    myTree.print();

    myTree.insert(4);
    myTree.print();

    myTree.insert(6);
    myTree.print();

    return 0;
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

void BSTree::insert(int val)
{
    if (root == nullptr)
        this->root = new TreeNode(val);
    else
        this->insert(val, this->root);
}

std::string BSTree::subTreeAsString(TreeNode* node)
{
    std::string leftString = (node->left == nullptr) ? "{}" : subTreeAsString(node->left);
    std::string rightString = (node->right == nullptr) ? "{}" : subTreeAsString(node->right);
    std::string result = "{" + std::to_string(node->data) + ", " + leftString + ", " + rightString + "}";
    return result;
}
//Insert a new node into subtree starting at node
void BSTree::insert(int val, TreeNode* node)
{
    //Check if new nodes value = val if so warn and exit func
    if (val == node->data)
    {
        std::cout << "warning val already exists, will now exit function";
        return;
    }

    if (val < node->data)
    {
        if (node->left == nullptr)
        {
            //make a new node as the left child of this node
            node->left = new TreeNode(val);
        }
        else
        {
            //recursively call insert() on nodes left child
            this->insert(val, node->left);
        }
    }
    else
    {
        if (node->right == nullptr)
        {
            node->right = new TreeNode(val);
        }
        else
        {
            this->insert(val, node->right);
        }
    }
}
