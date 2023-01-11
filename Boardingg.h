#pragma once
#include <iostream>
#include<fstream>
#include<cstring>

using namespace std;
class boarding {
private:
	int limit = 0;
	int weight = 0;
public:
	boarding() {}
	boarding(int x) {
		limit = x;
	}

	void baggage_limit() {
		limit = 20;
		srand(time(0));
		weight = (rand() % 10) + 20;
		if (weight > limit)
		{
			cout << "Your baggage weight is exceeding the limit" << endl;
		}
		else
			cout << "Your baggage weight is fine" << endl;
	}
};
