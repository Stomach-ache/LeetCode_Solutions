class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;

        // slow pointer
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            A[ptr] = A[i];
            ++ptr;
            if (i + 1 < n && A[i + 1] == A[i]) {
                A[ptr] = A[i + 1];
                ++ptr;
            }
            int j = i;
            while (j < n && A[j] == A[i]) ++j;
            i = j - 1;
        }
        return ptr;
    }
};
