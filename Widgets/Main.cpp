#include <Simple_window.h>
#include <std_lib_facilities.h>
#include <FL/Fl.H>
#include <Graph.h>

#using namespace Graph_lib;
//Widget interface class
class Widget {
public:
	Widget(Point xy, int w, int h, const string& s, Callback cb);

	virtual void move(int dx, int dy);
	virtual void hide();
	virtual void show();
	virtual void attach(Window&) = 0;

	Point loc;
	int width;
	int height;
	string label;
	Callback do_it;

protected:
	Window* own;
	Fl_Widget* pw;
};

// Defining a button
struct Button : Widget {
	Button(Point xy, int w, int h, const string& label, Callback cb);
	void attach(Window&);
};

// Creating a button class inheriting from widget
class Button : public Widget {
public:
	Button(Point xy, int ww, int hh, const string &s, Callback cb):
		Widget{xy, ww, hh, s, cb}{}

	void attach(Window& win);
};

//Getting text in and out
struct InBox : Widget {
	InBox(Point xy, int w, int h, const string& s) : Widget{xy, w, h, s, 0}{}
	int getInt();
	string getString();

	void attach(Window& win);
};

struct OutBox : Widget {
	OutBox(Point xy, int w, int h, const string& s) : Widget{ xy, w, h, s, 0 } {}
	int put(int);
	string put(const String&);

	void attach(Window& win);
};

//Simple menu, A vector of buttons at a specific point
struct Menu : Widget {
	enum Kind {horizontal, vertical};
	Menu(Point xy, int w, int h, Kind kk, const string& label);
	VectorRef<Button>selection;
	Kind k;
	int offset;
	int attach(Button& b);
	int attach(Button* p);

	void show()
	{
		for (unsigned int i = 0; i < selection.size(); i++)
			selection[i].show();
	}

	void hide();
	void move(int dx, int dy);

	void attach(Window& win);
};


int main() {


	return 0;
}

//Having lots of problems with FLTK unable to get the code to work due to dependencies, 
// Managed to get everything to work on my mac. Have not bothered with the Window code to attach the widget as it also uses FLTK and does not work correctly.