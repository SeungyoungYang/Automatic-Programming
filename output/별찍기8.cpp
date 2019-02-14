#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int start1 = 0, finish1 = 0, f1 = 1;
	int start2 = 2 * n - 1, finish2 = 2 * n - 1, s2 = -1;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if ((j >= start1 && j <= finish1) || (j >= start2 && j <= finish2))
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
		if (i + 1 < input) {
			finish1 += f1;
			start2 += s2;
		}
		else {
			finish1 -= f1;
			start2 -= s2;
		}
	}

	return 0;
}
