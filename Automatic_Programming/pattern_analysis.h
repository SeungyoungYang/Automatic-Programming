#pragma once
#include<iostream>
#include<string>
using namespace std;

class Pattern_Analysor {
private:
	int pattern;
public:
	Pattern_Analysor() {
		pattern = -1;
	}

	bool pattern_analysis(string* line, int input, int line_num) {
		int max_length = 0, p;

		if (line_num != input && line_num != 2 * input - 1)
			return false;

		for (int i = 0; i < line_num; i++) {
			if (line[i].length() > max_length)
				max_length = line[i].length();
		}

		if (max_length == input) { // Pattern 1 
			int star_num, count;

			if (line_num == input) { // º°Âï±â14
				star_num = input * input;
				count = 0;

				for (int i = 0; i < max_length; i++) {
					if (line[i].length() != max_length)
						break;

					for (int j = 0; j < line[i].length(); j++) {
						if (line[i].at(j) != '*') {
							i = max_length;
							break;
						}
						count++;

						if (i + 1 == max_length && j + 1 == line[i].length()) {
							if (star_num == count) {
								pattern = 14;
								return true;
							}
							return false;
						}
					}
				}
			}

			int start, finish, s, f;

			if (line[0].at(0) == '*') {
				start = 0;

				if (line[0].length() == 1) { // º°Âï±â1
					finish = 0;
					s = 0;
					f = 1;
					pattern = 1;
				}
				else if (line[input - 1].at(0) == '*') { // º°Âï±â3
					finish = input - 1;
					s = 0;
					f = -1;
					pattern = 3;
				}
				else { // º°Âï±â4
					finish = input - 1;
					s = 1;
					f = 0;
					pattern = 4;
				}
			}
			else { // º°Âï±â2
				start = input - 1;
				finish = input - 1;
				s = -1;
				f = 0;
				pattern = 2;
			}

			star_num = input * (input + 1) / 2;
			count = 0;

			for (int i = 0; i < input; i++) {
				for (int j = 0; j < line[i].length(); j++) {
					if (j >= start && j <= finish) {
						if (line[i].at(j) != '*')
							return false;

						count++;
					}
					else {
						if (line[i].at(j) != ' ')
							return false;
					}
				}
				start += s;
				finish += f;
			}

			if (star_num != count)
				return false;

			if (line_num == 2 * input - 1) { // Pattern 3
				star_num = input * (input + 1) / 2;
				count = 0;
				start = 0;
				finish = input - 1;

				if (line[2 * (input - 1)].at(0) == '*') { // º°Âï±â13
					s = 0;
					f = -1;
					pattern = 13;
				}
				else { // º°Âï±â12
					s = 1;
					f = 0;
					pattern = 12;
				}

				for (int i = input - 1; i < 2 * input - 1; i++) {
					for (int j = 0; j < line[i].length(); j++) {
						if (j >= start && j <= finish) {
							if (line[i].at(j) != '*')
								return false;

							count++;
						}
						else {
							if (line[i].at(j) != ' ')
								return false;
						}
					}
					start += s;
					finish += f;
				}

				if (star_num != count)
					return false;
			}

			return true;
		}
		else if (max_length == 2 * input - 1) { // Pattern 2
			int star_num, count;
			int start, finish, s, f;

			if (line[0].at(0) == ' ') { // º°Âï±â5
				start = input - 1;
				finish = input - 1;
				s = -1;
				f = 1;
				pattern = 5;
			}
			else { // º°Âï±â6
				start = 0;
				finish = 2 * (input - 1);
				s = 1;
				f = -1;
				pattern = 6;
			}

			star_num = input * input;
			count = 0;

			for (int i = 0; i < input; i++) {
				for (int j = 0; j < line[i].length(); j++) {
					if (j >= start && j <= finish) {
						if (line[i].at(j) != '*')
							return false;

						count++;
					}
					else {
						if (line[i].at(j) != ' ')
							return false;
					}
				}
				start += s;
				finish += f;
			}

			if (star_num != count)
				return false;

			if (line_num == 2 * input - 1) { // Pattern 4
				star_num = input * input;
				count = 0;

				if (line[input - 1].at(0) == ' ') { // º°Âï±â9
					start = input - 1;
					finish = input - 1;
					s = -1;
					f = 1;
					pattern = 9;
				}
				else { // º°Âï±â7
					start = 0;
					finish = 2 * (input - 1);
					s = 1;
					f = -1;
					pattern = 7;
				}

				for (int i = input - 1; i < 2 * input - 1; i++) {
					for (int j = 0; j < line[i].length(); j++) {
						if (j >= start && j <= finish) {
							if (line[i].at(j) != '*')
								return false;

							count++;
						}
						else {
							if (line[i].at(j) != ' ')
								return false;
						}
					}
					start += s;
					finish += f;
				}
				if (star_num != count)
					return false;
			}

			return true;
		}
		else if (max_length == 2 * input) { // Pattern 5
			int star_num = 2 * input*input, count = 0;
			int start1 = 0, finish1 = 0, f1 = 1;
			int start2 = 2 * input - 1, finish2 = 2 * input - 1, s2 = -1;

			for (int i = 0; i < line_num; i++) { // º°Âï±â8
				for (int j = 0; j < line[i].length(); j++) {
					if ((j >= start1 && j <= finish1) || (j >= start2 && j <= finish2)) {
						if (line[i].at(j) != '*')
							return false;

						count++;
					}
					else {
						if (line[i].at(j) != ' ')
							return false;
					}
				}
				if (i + 1 < input) {
					finish1 += f1;
					start2 += s2;
				}
				else {
					finish1 -= f1;
					start2 -= s2;
				}
			}

			if (star_num != count)
				return false;

			pattern = 8;
			return true;
		}

		return false;
	}

	int get_pattern() {
		return pattern;
	}
};