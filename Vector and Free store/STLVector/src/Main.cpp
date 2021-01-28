#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<double> vd;
	for (double d; cin >> d;)
		vd.push_back(d); // grown vd to hold all elements

	vector<char> vc(100);
	int n;
	cin >> n;
	vc.resize(n); // make vc have n elements

	vector<double>* p = new vector<double>(10);
	int n = 0;
	for (double d; cin >> d;)
	{
		if (n == p->size())
		{
			vector<double>* q = new vector<dobule>(p->size() * 2);
			copy(p->begin, p->end(), q->begin());
			delete p;
			p = q;
		}
		(*p)[n] = d;
		++n;
	}

	return 0;
}