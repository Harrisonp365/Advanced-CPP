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
    TreeNode foo(5);

    // Print info about foo
    std::cout <<
        "data: " << foo.data <<
        ", left: " << foo.left <<
        ", right: " << foo.right <<
        std::endl;
}
