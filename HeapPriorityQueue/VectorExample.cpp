#include <iostream>
#include <vector>


using namespace std;


int main(){

	vector<int> V(1);
	
	cout << V.size() << endl;
	cout << V.at(0) << endl;


	V.push_back(1);
	V.push_back(2);
	V.push_back(3);
	V.push_back(4);
	V.push_back(5);
	V.push_back(6);

	for(vector<int>::iterator it = V.begin(); it != V.end(); it++)
		cout << *it << endl;

	cout << V.end() - V.begin() << endl;
	return 0;
}
