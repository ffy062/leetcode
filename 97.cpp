#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int sub_sol[110][110];
    bool isInterleave(string s1, string s2, string s3) {
        int len_1 = s1.length(), len_2 = s2.length();
        if(len_1 + len_2 != s3.length()) {
            return false;
        }
        for(int i = 0; i < len_1 + 1; ++i) {
            for(int j = 0; j < len_2 + 1; ++j) {
                sub_sol[i][j] = -1;
            }
        }
        return dp_sol(s1, s2, s3, len_1, len_2);
    }
    // use dynamic programming to solve the problem
    bool dp_sol(string& s1, string& s2, string& s3, int len_1, int len_2) {
        bool result;
        if(len_1 == 0 && len_2 == 0) {
            return true;
        }
        if(sub_sol[len_1][len_2] == 0) {
            return false;
        }
        if(sub_sol[len_1][len_2] == 1) {
            return true;
        }
        if(len_1 == 0 && s2[len_2 - 1] != s3[len_2 - 1]) {
            sub_sol[len_1][len_2] = 0;
            return false;
        }   
        if(len_2 == 0 && s1[len_1 - 1] != s3[len_1 - 1]) {
            sub_sol[len_1][len_2] = 0;
            return false;
        }
        if(len_1 != 0 && s1[len_1 - 1] == s3[len_1 + len_2 - 1]) {
            result = dp_sol(s1, s2, s3, len_1 - 1, len_2);
            if(result) {
                sub_sol[len_1][len_2] = 1;
                return true;
            }
        }
        if(len_2 != 0 && s2[len_2 - 1] == s3[len_1 + len_2 - 1]) {
            result = dp_sol(s1, s2, s3, len_1, len_2 - 1);
            if(result) {
                sub_sol[len_1][len_2] = 1;
                return true;
            }
        }
        sub_sol[len_1][len_2] = 0;
        return false;
    }
};

int main() {
    string s1, s2, s3;
    Solution ss;
    cin >> s1 >> s2 >> s3;
    
    if(ss.isInterleave(s1, s2, s3)) {
        cout << "true\n";
    }
    else {
        cout << "false\n";
    }
    return 0;
}