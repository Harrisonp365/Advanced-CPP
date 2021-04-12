#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int d, Node* n = nullptr) : data{d}, next{n} {}
};

class LinkedList
{
public:
	Node* head;
	LinkedList() { head = nullptr; }

	void AddNodeByIntToEnd(int int_data)
	{
		Node* new_node = new Node(int_data);
		Node* temp = head;
		if (!head)
		{
			head = new_node;
			return;
		}
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new_node;
		return;
	}
	
	void AddNodeWithNode(Node* node_to_add)
	{
		Node* temp = head;
		if (!head)
		{
			head = node_to_add;
			return;
		}
		while (temp->next)
			temp = temp->next;
		temp->next = node_to_add;
		return;
	}
	void PrintList()
	{
		if (!head)
		{
			std::cout << "List is empty\n";
			return;
		}
		Node* temp = head;
		std::cout << "Printing list\n";
		for (; temp != nullptr; temp = temp->next)
		{
			std::cout << temp->data << " ";
		}
		std::cout << "\n";
	}
};

int main()
{
	LinkedList myList;
	myList.AddNodeByIntToEnd(1);
	Node* n1 = new Node(2);
	myList.AddNodeWithNode(n1);
	myList.AddNodeByIntToEnd(999);
	myList.PrintList();
	return 0;
}