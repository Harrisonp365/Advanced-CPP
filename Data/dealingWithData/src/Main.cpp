#include <iostream>
#include <vector>
using namespace std;



int main()
{
	double* get_from_jack(int* count); //put double into array and return elem count
	vector<double>* get_from_jill(); // fill the vector

	cout << "Jill's max: " << *jill_high << "; Jack's max: " << *jack_high;
	return 0;
}

double* get_from_jack(int* count)
{
	return nullptr;
}

vector<double>* get_from_jill()
{
	return nullptr;
}

void fct()
{
	int jack_count = 0;
	double* jack_data = get_from_jack(&jack_count);

	vector<double>* jill_data = get_from_jill();

	double* jack_high = high(jack_data, jack_data + jack_count);
	vector<double>& v = *jill_data;
	double* jill_high = high(&v[0], &v[0] + v.size());

	/*
	for (int i = 0; i < jack_count; ++i)
	{
		if (h < jack_data[i])
		{
			jack_high = &jack_data[i]; // save address of larrgest elem
			h = jack_data[i]; // update largest elem
		}
	}

	h = -1;
	vector<double>& v = *jill_data;
	for (int i = 0; i < v.size(); ++i)
	{
		if (h < v[i])
		{
			jill_high = &v[i]; // save address of larrgest elem
			h = v[i]; // update largest elem
		}
	}
	delete[] jack_data;
	delete jill_data;
	*/
}

double* high(double* first, double* last)
// return a pointer to the element in [first,last] that has the highest value
{
	double h = -1;
	double* high;
	for(double * p = first; p != last; ++p)
		if (h < *p) { high = p; h = *p; }
	return high;
}