#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		unsigned int len = ratings.size();
		if (len == 0 || len == 1)
			return len;
		typedef pair<int, int> pii;
		vector<int> candies(len, 0);
		vector<pii> my_pii;

fdkfjsd;
		for (unsigned int i = 0; i < len; i++) {
			my_pii.push_back(pii(ratings[i], i));
		}
		sort(my_pii.begin(), my_pii.end());
		
		for (unsigned int i = 0; i < len; i++) {
			unsigned int x = my_pii[i].second;
			if (x == 0) {
				if (ratings[x] > ratings[x+1])
					candies[x] = candies[x+1] + 1;
				else
					candies[x] = 1;
			}
			else if (x == len - 1) {
				if (ratings[x] > ratings[x-1])
					candies[x] = candies[x-1] + 1;
				else
					candies[x] = 1;
			}
			else {
				if (ratings[x] <= ratings[x-1] && ratings[x] <= ratings[x+1])
					candies[x] = 1;
				else if (ratings[x] == ratings[x+1] && ratings[x] > ratings[x-1])
					candies[x] = candies[x-1] + 1;
				else if (ratings[x] == ratings[x-1] && ratings[x] > ratings[x+1])
					candies[x] = candies[x+1] + 1;
				else
					candies[x] = max(candies[x+1], candies[x-1]) + 1;
			}
		}
		int cnt = 0;
		for (unsigned int i = 0; i < len; i++)
			cnt += candies[i];

		return cnt;
	}
};

int main() {
	int a[] = {1, 2, 4, 4, 3};
	Solution A;
	vector<int> ratings(a, a + 5);
	cout << A.candy(ratings) << endl;
}