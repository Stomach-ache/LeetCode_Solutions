/* use KMP algorithm to find pattern from text. */

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        if (len1 == 0 && len2 == 0) return 0;
        if (len1 != 0 && len2 == 0) return 0;
        if (len1 < len2) return -1;

        /* calculate failure array */
        vector<int> fail(len2+1);
        fail[0] = fail[1] = 0;
        for (int i = 1; i < len2; i++) {
            int j = fail[i];
            while (j > 0 && needle[j] != needle[i]) j = fail[j];
            fail[i+1] = needle[j]==needle[i] ? j+1 : 0;
        }

        /* find pattern(needle) from text(haystack) */
        int j = 0;
        for (int i = 0; i < len1; i++) {
            while (j > 0 && needle[j] != haystack[i]) j = fail[j];
            if (needle[j] == haystack[i]) j++;

            if (j == len2) return i-len2+1;
        }
        return -1;
    }
};
