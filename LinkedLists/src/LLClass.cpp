
class Link {
public:
	string value;

	Link(const string& v, Link* p = nullptr, Link* s = nullptr):value{v}, prev{p}, succ{s}{}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s);
	const Link* find(const string& s) const;

	Link* advance(int n) const;
	Link* next() const { return succ; }
	Link* previous() const { return prev; }

private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n) //insert n before p and return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;//nothing to insert
	n->succ = this; //p comes after n
	if (prev) prev->succ = n; 
	n->prev = prev; //p's predecessor becomes n's predecessor
	prev = n; // n becomes p's predecessor
	return n;
}