#include <iostream>

class Node
{
public:
	int data;
	Node* next;
	Node(int d, Node* n = nullptr) : data{d}, next{n}{}
};

class LinkedList
{
public:
	Node* head;
	LinkedList() { head = nullptr; }
	void addNodeWithInt(int intData)
	{
		Node* newNode = new Node(intData);
		Node* temp = head;
		if (!head)
		{
			head = newNode;
			return;
		}

		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = newNode;
		return;
	}  
	
	void addNodeWithNode(Node* nodeToAdd)
	{
		Node* temp = head;
		if (!head)
		{
			head = nodeToAdd;
			return;
		}
		while (temp->next)
			temp = temp->next;
		temp->next = nodeToAdd;
		return;
	}

	void deleteNodeByInt(int intToDelete)
	{
		Node* temp = head;
		Node* prev = head;
		if (!head)
			return;
		if (head->data == intToDelete)
		{
			head = temp->next;
			delete(temp);
			return;
		}
		while (temp != nullptr && temp->data != intToDelete)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == nullptr)
		{
			std::cout << intToDelete << " does not exist\n";
			return;
		}

		prev->next = temp->next;
		std::cout << intToDelete << " has been delted\n";
		delete(temp);
	}

	void printList()
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
			std::cout << temp->data << "  ";
		}
		std::cout << "\n";
	}
};

int main()
{
	LinkedList myList;
	myList.addNodeWithInt(1);
	Node* n1 = new Node(2);
	myList.addNodeWithNode(n1);
	myList.addNodeWithInt(777);
	myList.addNodeWithInt(125);
	myList.printList();
	myList.deleteNodeByInt(7);
	myList.deleteNodeByInt(2);
	myList.printList();
	return 0;
}