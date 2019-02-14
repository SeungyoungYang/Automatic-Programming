#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int start = 0, finish = n - 1, s = 0, f = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j >= start && j <= finish)
				cout << '*';
		}
		cout << '\n';
		start += s;
		finish += f;
	}

	return 0;
}
