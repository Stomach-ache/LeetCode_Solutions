/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int result = 0;
        for (int i = 0; i < n; ++i) {
            // to avoid using double type as the map key(slot k),
            // I use the pair(a, b) as the key where k = b / a
            map<pair<int, int>, int> slop;
            int localmax = 0, overlap = 0;
            for (int j = i + 1; j < n; ++j) {
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    ++overlap;
                } else {
                    int a = points[j].x - points[i].x;
                    int b = points[j].y - points[i].y;
                    int g = gcd(a, b);
                    a /= g;
                    b /= g;
                    ++slop[make_pair(a, b)];
                    Max(localmax, slop[make_pair(a, b)]);
                }
            }
            Max(result, localmax + overlap + 1);
        }
        return result;
    }

    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }

    void Max(int &x, int y) {
        if (x < y)
            x = y;
    }
};
