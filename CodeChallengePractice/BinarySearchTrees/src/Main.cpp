#include <iostream>
using namespace std;

class BinaryTreeNode {
public:
	int data_;
	BinaryTreeNode* left_;
	BinaryTreeNode* right_;

	BinaryTreeNode(int D, BinaryTreeNode* L, BinaryTreeNode* R ) : data_{D}, left_{L}, right_{R} {}
};

class BST {
public:
	BST() {}
	BinaryTreeNode* head;
	void BST_Insert(BinaryTreeNode*& head, int data);
	BinaryTreeNode*& BST_Search(BinaryTreeNode*& root, int key);
	void DeleteNode(int data);
	int SmallestRightSubtree(BinaryTreeNode* rightNode);
};

void BST::BST_Insert(BinaryTreeNode*& head, int data)
{
	if (head == nullptr)
	{
		head = new BinaryTreeNode(data, nullptr, nullptr);
		return;
	}
		
	if (data > head->data_)
		BST_Insert(head->right_, data);
	else
		BST_Insert(head->left_, data);
}

BinaryTreeNode*& BST::BST_Search(BinaryTreeNode*& root, int key)
{
	if (root == nullptr || root->data_ == key)
		return root;
	if (key > root->data_)
		return BST_Search(root->right_, key);
	return BST_Search(root->left_, key);
}

void BST::DeleteNode(int data)
{
	BinaryTreeNode* &del_node = BST_Search(head, data);
	if (del_node->right_ == nullptr && del_node->left_ == nullptr) //leaf
	{
		delete del_node;
		del_node == nullptr;
		return;
	}
	if (del_node->left_ == nullptr) //  right child
	{
		BinaryTreeNode* temp = del_node;
		del_node = del_node->right_;
		delete temp;
		return;
	}
	if (del_node->right_ == nullptr) //  left child
	{
		BinaryTreeNode* temp = del_node;
		del_node = del_node->left_;
		delete temp;
		return;
	}
	else
	{
		del_node->data_ == SmallestRightSubtree(del_node->right_); //two childs
	}
}

int BST::SmallestRightSubtree(BinaryTreeNode* rightNode)
{
	if (rightNode && !rightNode->left_)
	{
		int temp = rightNode->data_;
		BinaryTreeNode* tempNode = rightNode;
		rightNode = rightNode->right_;
		delete tempNode;
		return temp;
	}
}

int main()
{
	BST bst;
	bst.BST_Insert(bst.head, 3);
	bst.BST_Insert(bst.head, 5);
	bst.BST_Insert(bst.head, 1);
	bst.BST_Insert(bst.head, 2);

	bst.DeleteNode(1);

	BinaryTreeNode* found_1 = bst.BST_Search(bst.head, 1);
	std::cout << found_1->data_ << "  " << found_1->left_ << "  " << found_1->right_;
	return 0;
}