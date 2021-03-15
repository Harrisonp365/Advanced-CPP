#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;
/*
//template<typename In, typename In2, typename T>
//requires input_iterator<In> && Input_iterator<In2> && Number<T> 
//T inner_product(In first, In last, In2 first2, T init)
//{
//	while (first != last)
//	{
//		init = init + (*first) * (*first2);
//		++first;
//		++first2;
//	}
//	return init;
//}

int main()
{
	map<string, int> words;

	for (string s; cin >> s; )
		++words[s];

	for (const auto& p : words)
		cout << p.first << " : " << p.second << "\n";

	return 0;
}

// using both map and also inner product dji average
*/
template<typename In, typename In2, typename T, typename BinOp, typename BinOp2>

T inner_product(In first, In last, In2 first2, T init, BinOp op, BinOp2 op2)
{
	while (first != last)
	{
		init = op(init, op2(*first, *first2));
		++first;
		++first2;
	}
	return init;
}


double weighted_value(const pair<string, double>& a, const pair<string, double>& b)
{
	return a.second * b.second;
}

int main()
{
	map<string, double> dow_price = {
		{"MMM", 81.86},
		{"AA", 34.46},
		{"MO", 54.45}
	};

	map<string, double> dow_weight = {
		{"MMM", 5.8549},
		{"AA", 2.4808},
		{"MO", 3.8940}
	};

	map<string, string> dow_name = {
		{"MMM", "3M Co."},
		{"AA", "Alcoa Inc."},
		{"MO", "Altria Group Inc."}
	};
	
	double alcoa_price = dow_price["AA"];
	//double boeing_price = dow_price["BA"];

	if (dow_price.find("INTC") != dow_price.end())
		cout << "Intel is in the dow\n";

	for (const auto& p : dow_price) {
		const string& symbol = p.first;
		cout << symbol << '\t' << p.second << '\t' << dow_name[symbol] << "\n";
	}

	//double dji_index = inner_product(dow_price.begin(), dow_price.end(),
	//	dow_weight.begin(), 0.0, plus<double>(), weighted_value);

	//cout << "DJI value: " << dji_index << std::endl;
	return 0;
}