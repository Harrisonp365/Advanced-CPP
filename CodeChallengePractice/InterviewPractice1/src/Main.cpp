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

	void LoopDetection()
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

	Node* MergeList(Node* sorted_list)
	{
		Node* result = new Node(0);
		Node* iterator = result;
		Node* current_list = this->head;

		while (current_list && sorted_list)
		{
			if (current_list->data < sorted_list->data)
			{
				iterator->next = current_list;
				current_list = current_list->next;
			}
			else
			{
				iterator->next = sorted_list;
				sorted_list = sorted_list->next;
			}
			iterator = iterator->next;
		}
		iterator->next = ( current_list != nullptr ) ? current_list : sorted_list;
		return result->next;
	}

	friend void PrintListV2(Node* head);
};

void PrintListV2(Node* head)
{
	while (head)
	{
		std::cout << head->data << "  ";
		head = head->next;
	}
}

int main()
{
	/*
	LinkedList list1;
	Node* n1 = new Node(2);
	Node* n2 = new Node(4);
	Node* n3 = new Node(6);
	Node* n4 = new Node(8);
	Node* n5 = new Node(10);
	list1.AddNodeWithNode(n1);
	list1.AddNodeWithNode(n2);
	list1.AddNodeWithNode(n3);
	list1.AddNodeWithNode(n4);
	list1.AddNodeWithNode(n5);
	

	LinkedList list2;
	Node* n1 = new Node(1);
	Node* n2 = new Node(3);
	Node* n3 = new Node(5);
	Node* n4 = new Node(7);
	Node* n5 = new Node(9);
	list2.AddNodeWithNode(n1);
	list2.AddNodeWithNode(n2);
	list2.AddNodeWithNode(n3);
	list2.AddNodeWithNode(n4);
	list2.AddNodeWithNode(n5);
	*/
	LinkedList* List1 = new LinkedList();
	List1->AddNodeByIntToEnd(1);
	List1->AddNodeByIntToEnd(3);
	List1->AddNodeByIntToEnd(5);
	List1->AddNodeByIntToEnd(7);
	List1->AddNodeByIntToEnd(9);

	LinkedList* List2 = new LinkedList();
	List2->AddNodeByIntToEnd(2);
	List2->AddNodeByIntToEnd(4);
	List2->AddNodeByIntToEnd(6);
	List2->AddNodeByIntToEnd(8);
	List2->AddNodeByIntToEnd(10);

	Node* result_list = List1->MergeList(List2->head);
	PrintListV2(result_list);

	return 0;
}