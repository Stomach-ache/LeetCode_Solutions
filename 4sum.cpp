class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // sort the array ordered by asc.
        sort(begin(num), end(num));
        int n = num.size();

        vector<vector<int> > ans;
        vector<int> vtmp;
        char str[50];

        // enumerate the beginning and the ending index of quadruplets.
        for (int a = 0; a < n-3; a++) {
            for (int d = a+3; d < n; d++) {
                if (num[a] + num[a+1] + num[a+2] + num[d] > target) break;
                if (num[a] + num[d-2] + num[d-1] + num[d] < target) continue;

                int b = a + 1;
                int c = d - 1;
                int v = target - num[a] - num[d];
                while (b < c) {
                    if (num[b] + num[c] > v) --c;
                    else if (num[b] + num[c] < v) ++b;
                    else {
                        str[0] = 0;
                        sprintf(str, "%d%d%d%d", num[a], num[b], num[c], num[d]);
                        string ss = string(str);
                        if (vis.find(ss) == vis.end()) {
                            vis.insert(str);
                            vtmp.clear();
                            vtmp.push_back(num[a]);
                            vtmp.push_back(num[b]);
                            vtmp.push_back(num[c]);
                            vtmp.push_back(num[d]);
                            ans.push_back(vtmp);
                        }
                        ++b;
                        --c;
                    }
                }
            }
        }
        return ans;
    }
private:
    // record quadruplets that have been found.
    unordered_set<string> vis;
};
