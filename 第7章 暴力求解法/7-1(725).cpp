#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n;
	bool firstTime = true;
	while (cin >> n && n!= 0) {
		if (!firstTime) cout << endl;
		else firstTime = false;
		bool solved = false;
		for (int i = 0; i<6; i++) {
			for (int j = 0; j<10; j++) {
				for (int k = 0; k<10; k++) {
					for (int l = 0; l<10; l++) {
						for (int m = 0; m<10; m++) {
							int devisor = i * 10000 + j * 1000 + k * 100 + l * 10 + m;
							int dividend = devisor*n;
							if (devisor / 10000>9) continue;
							int num[10] = { 0 };
							//solved = true;
							if (!num[i]) num[i] = 1;
							if (!num[j]) num[j] = 1;
							if (!num[k]) num[k] = 1;
							if (!num[l]) num[l] = 1;
							if (!num[m]) num[m] = 1;
							if (!num[dividend / 10000]) num[dividend / 10000] = 1;
							if (!num[(dividend % 10000) / 1000]) num[(dividend % 10000) / 1000] = 1;
							if (!num[(dividend % 1000) / 100]) num[(dividend % 1000) / 100] = 1;
							if (!num[(dividend % 100) / 10]) num[(dividend % 100) / 10] = 1;
							if (!num[dividend % 10]) num[dividend % 10] = 1;
							int sum = 0;
							for (int o = 0; o<10; o++) {
								sum += num[o];
							}
							if (sum == 10) {
								cout << setfill('0') <<right << setw(5) << dividend << " / " << setfill('0') <<right << setw(5) <<  devisor << " = " << n << endl;
								//cout <<fixed << setw(5)<<setfill('0') << right<< dividend << " / " << setfill('0') << right << setw(5) << devisor << " = " << n << endl;
								solved = true;
							}
						}
					}
				}
			}
		}
		if (!solved) cout << "There are no solutions for " << n << ".\n";
		//else cout << "???" << endl;
		// cout << endl;
	}
}