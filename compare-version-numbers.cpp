/*
 * pay attention to that numbers may exists heading zeros.
 * ps. string::npos = (1<<32) - 1.
 */
class Solution {
public:
    typedef unsigned int uint;
    int compareVersion(string version1, string version2) {
        uint len1 = version1.size();
        uint len2 = version2.size();

        uint i = 0, j = 0;
        while ( 1 ) {
            if (i >= len1 && j >= len2) return 0;
            uint v1 = 0, v2 = 0;
            while (i < len1 && version1[i] != '.') { v1 = v1*10+version1[i]-'0'; ++i; }
            while (j < len2 && version2[j] != '.') { v2 = v2*10+version2[j]-'0'; ++j; }

            if (v1 < v2) return -1;
            else if (v1 > v2) return 1;
            else {
                ++i; ++j;
            }
        }
    }
};
