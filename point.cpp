#include <iostream>
#include <vector>
#include "point.h"
#include <fstream>
#include <sstream>
using namespace std;


void graph :: dfs(int v, int p) {
	visited[v] = 1;
	d[v] = l[v] = timer++;
	for (size_t i = 0; i < Graph[v].size(); ++i) {
		int to = Graph[v][i];
		if (to == p) continue;
		if (visited[to])
			l[v] = min(l[v], d[to]);
		else {
			dfs(to, v);
			l[v] = min(l[v], l[to]);
			if (l[to] >= d[v] && p != -1) {
			  if (k[v] == 0) {
					cout << " cut point : " << v << endl;
					k[v] = 1;
				}
			}
		}
	}
	if (p == -1 && Graph[v].size() > 1) {
		cout << " cut point : " << v << endl;
		k[v] = 1;
	}
}


void graph::load(const std::string& filename) {
	fstream F;
	F.open(filename, fstream::in | fstream::out);
	char a;
	std::vector<int> buff;
	//считывание файла
	while (!F.eof() )
	{
		F.get(a);
		if (a != '\n')
			buff.push_back(a - '0');
		else
		{
			Graph.push_back(buff);
			buff.clear();
		}
	}
	if (a != '\n') {
		buff.pop_back();
		Graph.push_back(buff);
	}
	F.close();
	for (int i = 0; i < Graph.size(); i++) {
		for (int j = 0; j < Graph[i].size(); j++) {
			cout << Graph[i][j] << " ";
		}
		cout << endl ;
	}
}

void graph::write_dot(const char* fname)
{
	ofstream out(fname);
	out << "graph {\n";
	for (size_t i = 0; i < Graph.size(); ++i) {
		if (k[i] == 1) {
			out << " " << i << "[color = " << "\"" << "red" << "\"" << "];\n";
		}else
		out << " " << i << ";\n";
	}
	for (size_t v = 0; v < Graph.size(); ++v) {
		for (auto u : Graph[v]) {
			if (u < v) {
				out << " " << v << " -- " << u << ";\n";
			}
		}
	}
	out << "}\n";
}