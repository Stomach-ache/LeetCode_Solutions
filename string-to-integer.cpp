/*************************************************************************
    > File Name: String_to_Integer.cpp
    > Author: Stomach_ache
    > Mail: sudaweitong@gmail.com
    > Created Time: 2014年04月26日 星期六 13时42分54秒
    > Propose: 
 ************************************************************************/

#include <cmath>
#include <string>
#include <cstdio>
#include <climits>
#include <fstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
		int atoi(const char *str) {
				unsigned long long ans = 0;
				// is positive ?
				int flag = 1;
				while (*str == ' ') str++;
				if (*str == '+') {
						str++;
				} else if (*str == '-') {
						flag = 0;
						str++;
				}
				while (*str != '\0') {
						if ((*str) < '0' || (*str) > '9')
								break;
						ans = ans * 10 + (*str) - '0';
						if (flag and ans > 2147483647ULL) {
								return INT_MAX;
						} else if (!flag and ans > 2147483648ULL) {
								return INT_MIN;
						}
						str++;
				}

				if (!flag) {
						ans = -ans;
				}
				return (int)ans;
		}
};

int
main(void) {
		Solution A;
		string str = "            -00034786";
		cout << A.atoi(str.c_str()) << endl;

		return 0;
}
