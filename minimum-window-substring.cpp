class Solution {
public:

    string minWindow(string s, string t) {
        // length of string $s
        int len = s.size();

        // the number of each character that required to be found in string $s
        vector<int> require(128, 0);
        // the number of kinds of characters that appear in string $t
        int count = 0;
        for_each(begin(t), end(t), [&require, &count] (char &ch) {
            if (!require[ch]) ++count;
            ++require[ch];
        });
        int ansl = -1, ansr = len;
        int l = 0, r = 0;
        while (r < len) {
            // move a step to right from index $r
            --require[s[r]];
            if (require[s[r]] ==  0) --count;
            while (count == 0) {
                if (r - l < ansr - ansl) {
                    ansl = l; ansr = r;
                }

                // move a step to right from index $l
                ++require[s[l]];
                if (require[s[l]] > 0) ++count;
                ++l;
            }
            ++r;
        }
        if (ansl == -1) return "";
        return s.substr(ansl, ansr - ansl + 1);
    }
};
