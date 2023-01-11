#pragma once
#include <iostream>
#include<fstream>
#include<cstring>
#include<time.h>
using namespace std;



class covid_testing {
private:
	int test_result = 0;
public:
	covid_testing() {
	}
	covid_testing(int x) {
		test_result = x;
	}
	void set_result() {
		srand(time(0));
		int test_result = (rand() % 10) + 1;
		cout << test_result << endl;
		if (test_result <= 5) {
			cout << "You are covid negative" << endl;
		}
		else if (test_result > 5) {
			cout << "You are covid positive you can not board this flight" << endl;
		}
	}
};
