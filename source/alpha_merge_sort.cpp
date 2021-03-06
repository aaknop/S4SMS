#include <vector>
#include <stack>
#include <iostream>

#include "alpha_merge_sort.h"

using namespace std;

alpha_merge_sort::alpha_merge_sort(double alpha) : m_alpha(alpha) {
}

double alpha_merge_sort::operator()(vector<int> array) {
	double result = 0;

	vector<int> stack;

	run z(&stack, 0);
	run y(&stack, 1);
	run x(&stack, 2);


	for (int i = 0; i < array.size(); i++) {
		stack.push_back(array[i]);

		while((*y) <= m_alpha * (*z) || (*x) <= m_alpha * (*y)) {
			if((*x) < (*z)) {
				result += (*x) + (*y);
	   		    merge(x, y);
			} else {
				result += (*y) + (*z);
	   		    merge(y, z);
			}
		}
	}

	while(stack.size() > 1) {
		result += (*y) + (*z);
		merge(y, z);
	}

	return result;
}
