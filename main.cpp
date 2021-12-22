#include <iostream>
#include "point.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;



int main() {

	graph a; 
	string in;
	cout << "Enter name imput file" << endl;
	cin >> in;
	cout << endl;
	a.load(in);
	//a.load("list.txt");
	a.dfs(0, -1 );
	a.write_dot("g.dot");
	system("dot g.dot -Tpng -og.png");
	return 0;





}


