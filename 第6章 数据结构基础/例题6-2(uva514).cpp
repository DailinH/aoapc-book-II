//514 - Concurrency Simulator
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=455
// tmpRun.cpp : Defines the entry point for the console application.
//

#include < iostream > 
#include < stack > 
using namespace std; 
int queueLength; 
const int maxn = 1000 + 10; 
// int srcQueue[maxn] = { 0 };
int tgtQueue[maxn] =  {0 }; 
int main() {
	while (cin >> queueLength && queueLength != 0) {
		int fstElementInLine; 
		while (cin >> fstElementInLine && fstElementInLine) {
			stack < int > s; 
			for (int i = 0; i < queueLength; i++) {
				if ( ! i)tgtQueue[i] = fstElementInLine; 
				else cin >> tgtQueue[i]; 
			}
            bool success = true; 
            int A = 1; 
            int B = 1; 
            while (B <= queueLength) {
                if (A == tgtQueue[B-1]) {
                    A++; 
                    B++; 
                }
                else if ( ! s.empty() && s.top() == tgtQueue[B-1]) {
                    s.pop(); 
                    B++; 
                }
                else if (A <= queueLength) {
                    s.push(A++); 
                }
                else {
                    success = false; 
                    break; 
                }
            }
            cout << (success?"Yes\n":"No\n"); 
            //反面教材QAQ 很容易出现问题
			// for (int i = 1; i <= queueLength; i++) {
			// 	// if (!s.empty() && s.top() == i) {
			// 	// 	s.pop();
			// 	// 	curTrain++;
			// 	// }
			// 	// if (i == tgtQueue[curTrain]) {
			// 	// 	curTrain++;
			// 	// 	continue;
			// 	// }
			// 	// else {
			// 	// 	s.push(i);
			// 	// }
			// }
			// if (curTrain == queueLength - 1)
			// 	cout << "Yes\n"; 
			// else cout << "No\n"; 
		}
		cout << endl; 
	}

	return 0; 
}

