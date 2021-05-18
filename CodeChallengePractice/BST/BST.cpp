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
    bool contains(int val);

private:
    TreeNode* root;
    std::string subTreeAsString(TreeNode* node); //Helper func for print()
    void insert(int val, TreeNode*& node); // Helper func for insert()
    bool contains(int val, TreeNode*& node); // Helper func for contains()
};

int main()
{
    BSTree myTree{};
    myTree.insert(5);
    myTree.insert(4);
    myTree.insert(6);

    std::cout << std::boolalpha << myTree.contains(4) << std::endl;
    std::cout << std::boolalpha << myTree.contains(2) << std::endl;
    

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
    this->insert(val, this->root);
}

bool BSTree::contains(int val)
{
    return contains(val, this->root);
}

std::string BSTree::subTreeAsString(TreeNode* node)
{
    std::string leftString = (node->left == nullptr) ? "{}" : subTreeAsString(node->left);
    std::string rightString = (node->right == nullptr) ? "{}" : subTreeAsString(node->right);
    std::string result = "{" + std::to_string(node->data) + ", " + leftString + ", " + rightString + "}";
    return result;
}

void BSTree::insert(int val, TreeNode*& node)
{
    if (node == nullptr) 
    {
        // Case: node is a nullptr
        // Make a new TreeNode for it to point to
        node = new TreeNode(val);
    }
    else 
    {
        if (val < node->data) 
        {
            // Case: val is < node's data
            this->insert(val, node->left);
        }
        else if (val > node->data) 
        {
            // Case: val is > node's data
            this->insert(val, node->right);
        }
        else 
        {
            // Case: val is equal to node's data
            std::cout << "Warning: Value already exists, so nothing will be done." << std::endl;
        }
    }
}

bool BSTree::contains(int val, TreeNode*& node)
{
    if (node == nullptr)
    {
        return false;
    }
    else if (val == node->data)
    {
        return true;
    }
    else if (val < node->data)
    {
        return this->contains(val, node->left);
    }
    else
    {
        return this->contains(val, node->right);
    }
}
