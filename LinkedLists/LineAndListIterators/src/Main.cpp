struct Document {
	list<Line>line;

	Text_iterator begin() { return Text_iterator(line.begin(), (*line.begin()).begin()); }
	
	Text_iterator end() { auto last = line.end(); --last; return Text_iterator(last, (*last).end());}
};



class Text_iterator { //keep track of line and character pos inside line
	list<Line>::iterator ln;
	Line::iterator pos;
public:
	//start iterator at line 2, character pos pp
	Text_iterator(list<Line>::iterator ll, Line::iterator pp) : ln{ll}, pos{pp}{}

	char& operator*() { return *pos; }
	Text_iterator& operator++();

	bool operator==(const Text_iterator& other) const 
	{ return In == other.In && pos == other.pos; }
	
	bool operator!=(const Text_iterator& other) const
	{ return !(*this == other); }

	//class no complete and is also meant to use code from a seperate template I built in a different project, this is purely just to show and have an example to learn from 
};

Text_iterator& Text_iterator::operator++()
{
	++pos;
	if (pos == (*ln).end())
	{
		++ln;
		pos = (*ln).begin();
	}
	return *this;
}
