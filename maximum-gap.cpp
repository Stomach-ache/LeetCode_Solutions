#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2) return 0;
        vector<int> &arr(num);
        RadixSort(arr);
        int res = 0;
        for (int i = 1; i < arr.size(); i++) res = max(res, arr[i] - arr[i - 1]);
        return res;
    }
    void RadixSort(vector<int> &num) {
        vector<vector<int> > bucket(10);
        int len = num.size();
        vector<int> ten;
        int a = 1;
        for (int i = 0; i < 10; i++, a *= 10) ten.push_back(a);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < len; j++) {
                int k = (num[j] / ten[i]) % 10;
                bucket[k].push_back(num[j]);
            }
            num.clear();
            for (int j = 0; j < 10; j++) if (bucket[j].size()) {
                for (int k = 0; k < bucket[j].size(); k++) num.push_back(bucket[j][k]);
                bucket[j].clear();
            }
        }
    }
};

int main(void) {
	vector<int> num;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		num.push_back(x);
	}
	Solution A;
	cout << A.maximumGap(num) << endl;
	for (int i = 0; i < n; i++) cout << num[i] << ' ';
	cout << endl;
	return 0;
}
	
