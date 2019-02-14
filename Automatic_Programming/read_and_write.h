#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

class Reader {
public:
	string* read(string filename, int& input, int& line_num) {
		ifstream in("..\\input\\" + filename + ".txt");

		if (!in.is_open()) 
			return NULL;
		
		cout << filename << ".txt\n";
		cout << "--------------------------\n";
		in >> input;
		cout << input << '\n';
		string* line = new string[2 * input - 1];
		getline(in, line[line_num]);
		while (!in.eof()) {
			getline(in, line[line_num]);
			cout << line[line_num] << '\n';
			line_num++;
		}
		cout << "__________________________\n\n";
		in.close();
		return line;
	}
};

class Writer {
public:
	void write(string filename, queue<string> code) {
		ofstream out("..\\output\\" + filename + ".cpp");

		cout << filename << ".cpp\n";
		cout << "--------------------------\n";
		while (!code.empty()) {
			cout << code.front() << '\n';
			out << code.front() << '\n';
			code.pop();
		}
		cout << "__________________________\n\n";
		out.close();
		cout << "Code Generating Complete!\n";
		return;
	}
};