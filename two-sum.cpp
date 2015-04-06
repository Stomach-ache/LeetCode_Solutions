#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        typedef pair<int, int> pii;
        vector<pii> my_pair;
        for (unsigned int i = 0; i < numbers.size(); i++) {
        	my_pair.push_back(pii(numbers[i], i+1));
        }
        sort(my_pair.begin(), my_pair.end());
        vector <int> ans;
        unsigned int beg = 0, end = numbers.size() - 1;
        while (beg < end) {
        	if (my_pair[beg].first + my_pair[end].first == target) {
        		ans.push_back(my_pair[beg].second);
        		ans.push_back(my_pair[end].second);
        		break;
        	}
        	else if (my_pair[beg].first + my_pair[end].first > target) {
        		end--;
        	}
        	else if (my_pair[beg].first + my_pair[end].first < target) {
        		beg++;
        	}
         }
         if (ans[0] > ans[1])
         	swap(ans[0], ans[1]);

         return ans;
    }
};

int main() {
	Solution A;
	int a[] = {2, 2, 3, 5};
	vector<int> num(a, a+4);
	vector<int> ans = A.twoSum(num, 4);
	cout << ans[0] << " " << ans[1] << endl;

	return 0;
}