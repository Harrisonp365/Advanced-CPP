#include <iostream>

using namespace std;
//Linked lists
struct Link {
	string value;
	Link* prev;
	Link* succ;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr) 
		:value{ v }, prev{ p }, succ{ s }{}
};

Link* insert(Link* p, Link* n)
{
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	n->succ = p;
	if (p->prev) p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}

Link* add(Link* p, Link* n)
{
	if (n == nullptr) return p;
	if (p == nullptr) return n;
	n->succ = p;
	if (p->prev) p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}

Link* erase(Link* p)
{
	if (p == nullptr)return nullptr;
	if (p->succ)p->succ->prev = p->prev;
	if (p->prev)p->prev->succ = p->succ;
	return p->succ;
}

Link* find(Link* p, const string& s)
{
	while (p)
	{
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* advance(Link* p, int n)
{
	if (p == nullptr)return nullptr;
	if (0 < n)
	{
		while (n--)
		{
			if (p->prev == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0)
	{
		while (n++)
		{
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p)
	{
		cout << p->value;
		if (p = p->succ) cout << ",";
	}
	cout << "}";
}

int main() {
	// first version of linking
	//Link* norse_gods = new Link{ "Thor", nullptr, nullptr };
	//norse_gods = new Link{ "Odin", nullptr, norse_gods };
	//norse_gods->succ->prev = norse_gods;
	//norse_gods = new Link{ "Freia", nullptr, norse_gods };
	//norse_gods->succ->prev = norse_gods;
	

	//Second version
	Link* norse_gods = new Link{ "Thor" };
	norse_gods = insert(norse_gods, new Link{ "Odin" });
	norse_gods = insert(norse_gods, new Link{ "Zeus" }); //intentional mistake to fix with functions
	norse_gods = insert(norse_gods, new Link{ "Freia" });

	Link* greek_gods = new Link{ "Hera" };
	greek_gods = insert(greek_gods, new Link{ "Athena" });
	greek_gods = insert(greek_gods, new Link{ "Mars" }); // intention mistake to fix with functions
	greek_gods = insert(greek_gods, new Link{ "Poseidon" });

	Link* p = find(greek_gods, "Mars");
	if (p) p->value = "Ares";

	Link* p = find(norse_gods, "Zeus");
	if (p)
	{
		if (p==norse_gods) norse_gods = p->succ;
		erase(p);
		greek_gods = insert(greek_gods, p);
	}

	

	print_all(norse_gods);
	cout << "\n";
	print_all(greek_gods);
	cout << "\n";
	return 0;
}

