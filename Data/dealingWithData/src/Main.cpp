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

	double h = -1;
	double* jack_high; // point to higest val element
	double* jill_high; // point to highst val element

	for (int i = 0; i < jack_count; ++i)
	{
		if (h < jack_data[i])
		{
			jack_high = &jack_data[i]; // save address of larrgest elem
			h = jack_data[i]; // update largest elem
		}
	}

	h = -1;
	for (int i = 0; i < jill_data->size(); ++i)
	{
		if (h < (*jill_data)[i])
		{
			jill_high = &(*jill_data)[i]; // save address of larrgest elem
			h = (*jill_data)[i]; // update largest elem
		}
	}

	delete[] jack_data;
	delete jill_data;
}