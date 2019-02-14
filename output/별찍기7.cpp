#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int start = n - 1, finish = n - 1, s = -1, f = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (j >= start && j <= finish)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
		start += s;
		finish += f;
	}

	start = 1, finish = 2 * n - 3, s = 1, f = -1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (j >= start && j <= finish)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
		start += s;
		finish += f;
	}

	return 0;
}
