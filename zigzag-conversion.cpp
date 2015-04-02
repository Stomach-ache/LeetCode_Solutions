/* the key point is to understand what does ZigZag pattern looks like. */

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s; // return without any change.
        int len = s.size();
        if (len == 0) return s; // return NULL string.

        string ans = ""; // initialize $ans.
        int temp = nRows - 1; // rows indexed from 0.
        for (int r = 0; r < nRows; r++) { // take characters from left to right row by row.
            for (int i = 0; i*temp < len+nRows; i += 2) { // check the first position of every column.
                // $pos holds the position of the first character of the ith column.
                int pos = i * temp;
                // try to append character at positon ($pos-$r).
                if (pos-r >= 0 && pos-r < len && pos-r != (i-2)*temp+r) ans += s[pos-r];
                // try to append character at positon ($pos+$r).
                if (pos+r >= 0 && pos+r < len && pos+r != pos-r) ans += s[pos+r];
            }
        }

        return ans;
    }
};
