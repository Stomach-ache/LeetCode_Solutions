/*
 *  "/..//////" is also a rational absolute path.
 */
class Solution {
public:
    string simplifyPath(string path) {
        int len = path.size();

        vector<string> dir;
        int i = 0;
        while (i < len) {
            // deal with multiple slashes.
            while (i < len && path[i] == '/') ++i;
            int j = i;
            string temp = "";
            while (j < len && path[j] != '/') {
                temp += path[j];
                ++j;
            }
            if (temp == ".." && dir.size()) dir.pop_back();
            if (temp.size() && temp != "." && temp != "..") dir.push_back(temp);
            i = j + 1;
        }

        string ans = "/";
        len = dir.size();
        for (int i = 0; i < len; i++) {
            ans += dir[i];
            if (i != len-1) ans += '/';
        }
        return ans;
    }
};
