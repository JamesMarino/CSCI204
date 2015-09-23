#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	vector<int> Test;
	vector<int>::iterator Iteration;
	
	for (int i = 0; i < 10; i++) {
		Iteration++;
		Iteration = Test.insert(Iteration, 10);
		
		cout << *Iteration << endl;
	}
	
    return 0;
}
