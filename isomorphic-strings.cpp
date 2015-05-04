class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int len = s.size();
        vector<int> maps(300, -1);
        vector<int> mapt(300, -1);
        for (int i = 0; i < len; ++i) {
            int idt = t[i];
            int ids = s[i];
            if ((maps[ids] == -1 || maps[ids] == idt) && (mapt[idt] == -1 || mapt[idt] == ids)) {
                maps[ids] = idt;
                mapt[idt] = ids;
            } else {
                return false;
            }
        }

        return true;
    }
};
