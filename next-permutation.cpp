class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int sz = num.size();
        int pos1 = -1, pos2;
        for (int i = sz-1; i >= 1; --i) {
            // find the largest index $j such that $num[j] < $num[i].
            for (int j = i-1; j >= 0; --j) if (num[j] < num[i]) {
                if (j > pos1) {
                    pos1 = j;
                    pos2 = i;
                }
                break;
            }
        }
        if (~pos1) {
            swap(num[pos1], num[pos2]);
            sort(begin(num)+pos1+1, end(num));
        } else {
            sort(begin(num), end(num));
        }
    }
};
