/*
 * º°Âï±â1  https://www.acmicpc.net/problem/2438
 * º°Âï±â2  https://www.acmicpc.net/problem/2439
 * º°Âï±â3  https://www.acmicpc.net/problem/2440
 * º°Âï±â4  https://www.acmicpc.net/problem/2441
 * º°Âï±â5  https://www.acmicpc.net/problem/2442
 * º°Âï±â6  https://www.acmicpc.net/problem/2443
 * º°Âï±â7  https://www.acmicpc.net/problem/2444
 * º°Âï±â8  https://www.acmicpc.net/problem/2445
 * º°Âï±â9  https://www.acmicpc.net/problem/2446
 * º°Âï±â12 https://www.acmicpc.net/problem/2522
 * º°Âï±â13 https://www.acmicpc.net/problem/2523
 * º°Âï±â14 https://www.acmicpc.net/problem/2556
 */

#include"read_and_write.h"
#include"pattern_analysis.h"
#include"code_generate.h"

int main() {
	string filename;
	int input, line_num = 0;
	cout << "File name >> ";
	cin >> filename;

	Reader rd;
	string* line = rd.read(filename, input, line_num);
	if (line == NULL) {
		cout << "File not found.\n";
		return 0;
	}

	Pattern_Analysor pa;
	if (!pa.pattern_analysis(line, input, line_num)) {
		cout << "Pattern not found.\n";
		return 0;
	}

	Generator gn;
	gn.generate_code(pa.get_pattern());

	Writer wt;
	wt.write(filename, gn.get_code());

	return 0;
}