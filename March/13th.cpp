#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateIp(string s) {
        vector<string> result;
        vector<string> current;
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.length()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.length()) break;
            
            string part = s.substr(start, len);
            
            if (part.length() > 1 && part[0] == '0') continue;
            
            if (stoi(part) <= 255) {
                current.push_back(part);
                backtrack(s, start + len, current, result);
                current.pop_back();
            }
        }
    }
};