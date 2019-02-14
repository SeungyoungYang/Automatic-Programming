#pragma once
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Generator {
private:
	queue<string> code;
	string indent[5];
	int tab;
public:
	Generator() {
		indent[0] = "", indent[1] = "\t", indent[2] = "\t\t", indent[3] = "\t\t\t", indent[4] = "\t\t\t\t";
		tab = 0;

		code.push("#include<iostream>");
		code.push("using namespace std;\n");
		code.push("int main() {");
		tab++;
		code.push(indent[tab] + "int n;");
		code.push(indent[tab] + "cin >> n;");
	}

	void generate_code(int pattern) {
		string i_arrange, j_arrange, conditional;
		bool has_if = true, has_else = true;

		if (pattern == 8) {
			i_arrange = "2 * n - 1";
			j_arrange = "2 * n";
		}
		else if (pattern >= 5 && pattern <= 9) {
			i_arrange = "n";
			j_arrange = "2 * n - 1";
		}
		else {
			i_arrange = "n";
			j_arrange = "n";
		}

		switch (pattern) {
		case 1:
			has_else = false;
			code.push(indent[tab] + "int start = 0, finish = 0, s = 0, f = 1;");
			break;
		case 2:
			code.push(indent[tab] + "int start = n - 1, finish = n - 1, s = -1, f = 0;");
			break;
		case 3:
			has_else = false;
			code.push(indent[tab] + "int start = 0, finish = n - 1, s = 0, f = -1;");
			break;
		case 4:
			code.push(indent[tab] + "int start = 0, finish = n - 1, s = 1, f = 0;");
			break;
		case 5:
			code.push(indent[tab] + "int start = n - 1, finish = n - 1, s = -1, f = 1;");
			break;
		case 6:
			code.push(indent[tab] + "int start = 0, finish = 2 * (n - 1), s = 1, f = -1;");
			break;
		case 7:
			code.push(indent[tab] + "int start = n - 1, finish = n - 1, s = -1, f = 1;");
			break;
		case 8:
			code.push(indent[tab] + "int start1 = 0, finish1 = 0, f1 = 1;");
			code.push(indent[tab] + "int start2 = 2 * n - 1, finish2 = 2 * n - 1, s2 = -1;");
			break;
		case 9:
			code.push(indent[tab] + "int start = 0, finish = 2 * (n - 1), s = 1, f = -1;");
			break;
		case 12:
			code.push(indent[tab] + "int start = n - 1, finish = n - 1, s = -1, f = 0;");
			break;
		case 13:
			has_else = false;
			code.push(indent[tab] + "int start = 0, finish = 0, s = 0, f = 1;");
			break;
		case 14:
			has_if = false;
			has_else = false;
			break;
		}

		code.push(indent[tab] + "for (int i = 0; i < " + i_arrange + "; i++) {");
		tab++;
		code.push(indent[tab] + "for (int j = 0; j < " + j_arrange + "; j++) {");
		tab++;
		if (has_if) {
			if (pattern == 8)
				code.push(indent[tab] + "if ((j >= start1 && j <= finish1) || (j >= start2 && j <= finish2))");
			else
				code.push(indent[tab] + "if (j >= start && j <= finish)");
			tab++;
		}
		code.push(indent[tab] + "cout << '*';");
		if (has_if)
			tab--;
		if (has_else) {
			code.push(indent[tab] + "else");
			tab++;
			code.push(indent[tab] + "cout << ' ';");
			tab--;
		}
		tab--;
		code.push(indent[tab] + "}");
		code.push(indent[tab] + "cout << '\\n';");
		if (has_if) {
			if (pattern == 8) {
				code.push(indent[tab] + "if (i + 1 < n) {");
				tab++;
				code.push(indent[tab] + "finish1 += f1;");
				code.push(indent[tab] + "start2 += s2;");
				tab--;
				code.push(indent[tab] + "}");
				code.push(indent[tab] + "else {");
				tab++;
				code.push(indent[tab] + "finish1 -= f1;");
				code.push(indent[tab] + "start2 -= s2;");
				tab--;
				code.push(indent[tab] + "}");
			}
			else {
				code.push(indent[tab] + "start += s;");
				code.push(indent[tab] + "finish += f;");
			}
		}
		tab--;
		code.push(indent[tab] + "}\n");

		if (pattern >= 7 && pattern <= 13 && pattern != 8) {
			i_arrange = "n - 1";

			switch (pattern) {
			case 7:
				code.push(indent[tab] + "start = 1, finish = 2 * n - 3, s = 1, f = -1;");
				break;
			case 9:
				code.push(indent[tab] + "start = n - 2, finish = n, s = -1, f = 1;");
				break;
			case 12:
				code.push(indent[tab] + "start = 1, finish = n - 1, s = 1, f = 0;");
				break;
			case 13:
				code.push(indent[tab] + "start = 0, finish = n - 2, s = 0, f = -1;");
				break;
			}

			code.push(indent[tab] + "for (int i = 0; i < " + i_arrange + "; i++) {");
			tab++;
			code.push(indent[tab] + "for (int j = 0; j < " + j_arrange + "; j++) {");
			tab++;
			code.push(indent[tab] + "if (j >= start && j <= finish)");
			tab++;
			code.push(indent[tab] + "cout << '*';");
			tab--;
			if (has_else) {
				code.push(indent[tab] + "else");
				tab++;
				code.push(indent[tab] + "cout << ' ';");
				tab--;
			}
			tab--;
			code.push(indent[tab] + "}");
			code.push(indent[tab] + "cout << '\\n';");
			code.push(indent[tab] + "start += s;");
			code.push(indent[tab] + "finish += f;");
			tab--;
			code.push(indent[tab] + "}\n");
		}

		code.push(indent[tab] + "return 0;");
		tab--;
		code.push("}");

		return;
	}

	queue<string> get_code() {
		return code;
	}
};