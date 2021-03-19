#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
using namespace std;

typedef vector <string>::const_iterator Line_iter;

class Message {
public:
	Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
	Line_iter begin() const { return first; }
	Line_iter end() const { return last; }
private:
	Line_iter first;
	Line_iter last;
};

using Mess_iter = vector<Message>::const_iterator;

struct Mail_file {
	string name; //file name
	vector<string> lines; // lines in order
	vector<Message> m; // messages in order

	Mail_file(const string& n); // read file n into lines

	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }

	bool find_from_addr(const Message* m, string& s);
	string find_subject(const Message* m);
};


int main()
{
	Mail_file mFile{ "my-mail-file.txt" };

	multimap<string, const Message*> sender;

	for (const auto& m : mFile)
	{
		string s;
		if (find_from_address(&m, s))
			sender.insert(make_pair(s, &m));
	}

	auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
	for (auto p == pp.first; p != pp.second; ++p)
		cout << find_subject(p->second) << "\n";

}

Mail_file::Mail_file(const string& n)
{

}

bool Mail_file::find_from_addr(const Message* m, string& s)
{
	return false;
}

string Mail_file::find_subject(const Message* m)
{
	return string();
}
