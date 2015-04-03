class Solution {
public:
    int removeDuplicates(int A[], int n) {

        // find an number, which never appears in
        // range [0, j), from index $j to index $(n-1)
        // and swap it with $A[i].
        int i = 0, j = 0;

        for ( ; j < n; ++j) {
            while (j < n && i && A[j] == A[i-1]) ++j;

            if (j < n) { swap(A[i], A[j]); ++i; };
        }

        // the number of unique elements is $i.
        return i;
    }
};
