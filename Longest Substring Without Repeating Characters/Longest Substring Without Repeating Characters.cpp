#include <iostream>
#include <assert.h>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> charcnt;
		int maxLen = 0;
		int it_start = 0, it_flag = 0;
		for (; it_flag < s.length(); ++it_flag)
		{
			if (!charcnt.count(s[it_flag]) || it_start >= charcnt[s[it_flag]])
			{
				charcnt[s[it_flag]] = it_flag;
				continue;
			}
			int t = it_flag - it_start - 1;
			maxLen = maxLen < t ? t : maxLen;
			++it_start;
			--it_flag;
		}
		return maxLen;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = "abcabcbb";//stringToString(line);

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}