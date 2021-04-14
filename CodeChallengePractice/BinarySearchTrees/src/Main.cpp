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
	bool identicalTree(BinaryTreeNode* other_tree);
private:
	bool identicalTreeHelper(BinaryTreeNode* first, BinaryTreeNode* second);
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

bool BST::identicalTree(BinaryTreeNode* other_tree)
{
	return identicalTreeHelper(this->head, other_tree);
}

bool BST::identicalTreeHelper(BinaryTreeNode* first, BinaryTreeNode* second)
{
	if (first == nullptr && second == nullptr)
		return true;
	if ((first && second) && (first->data_ == second->data_))
	{
		bool left_subtree = identicalTreeHelper(first->left_, second->left_);
		bool right_subtree = identicalTreeHelper(first->right_, second->right_);
		return (left_subtree && right_subtree);
	}
	return false;
}

int main()
{
	BST bst1;
	bst1.BST_Insert(bst1.head, 10);
	bst1.BST_Insert(bst1.head, 20);
	bst1.BST_Insert(bst1.head, 18);
	bst1.BST_Insert(bst1.head, 6);
	bst1.BST_Insert(bst1.head, 5);
	bst1.BST_Insert(bst1.head, 7);

	BST bst2;
	bst2.BST_Insert(bst2.head, 10);
	bst2.BST_Insert(bst2.head, 20);
	bst2.BST_Insert(bst2.head, 8);
	bst2.BST_Insert(bst2.head, 6);
	bst2.BST_Insert(bst2.head, 5);
	bst2.BST_Insert(bst2.head, 7);

	std::cout << bst1.identicalTree(bst2.head);
	return 0;
}