#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class graph {
private:
	std :: vector <std :: vector<int>> Graph; 
	std::vector <int> visited{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector <int> d {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	std::vector <int> l{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::vector <int> k{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int timer;
public:
	void dfs(int v, int p );
	void load(const std::string& filename);
	void write_dot(const char* fname);
	
};


#endif