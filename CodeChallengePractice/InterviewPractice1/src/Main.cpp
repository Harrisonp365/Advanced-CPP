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

	void DeleteNodeByInt(int delete_int)
	{
		Node* temp = head;
		Node* prev = head;
		if (!head)
			return;
		if (head->data == delete_int)
		{
			head = temp->next;
			delete(temp);
			return;
		}
		while (temp != nullptr && temp->data != delete_int)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			std::cout << "int to delete does not exist\n";
			return;
		}
		
		prev->next = temp->next;
		std::cout << delete_int << " was found and deleted\n";
		delete(temp);
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

	void loopDetection()
	{
		Node* slowPtr = head;
		Node* fastPtr = head;
		while (slowPtr && fastPtr && fastPtr->next)
		{
			slowPtr = slowPtr->next;
			fastPtr = fastPtr->next->next;
			if (slowPtr == fastPtr)
			{
				std::cout << "There is a loop in this list\n";
				return;
			}
		}
		std::cout << "The middle of the list is: " << slowPtr->data;
	}
};

int main()
{
	LinkedList myList;
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	myList.AddNodeWithNode(n1);
	myList.AddNodeWithNode(n2);
	myList.AddNodeWithNode(n3);
	myList.AddNodeWithNode(n4);
	myList.AddNodeWithNode(n5);
	myList.loopDetection();
	n5->next = n2;
	std::cout << "\n";
	myList.loopDetection();

	return 0;
}