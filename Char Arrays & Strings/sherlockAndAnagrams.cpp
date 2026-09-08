#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int sherlockAndAnagrams(string s)
{
    unordered_map <string, int> anagramatic_substring_count;
    int anagram_pairs = 0;

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string substring = s.substr(i, j - i + 1);

            sort(substring.begin(), substring.end());

            anagramatic_substring_count[substring]++;
        }
    }

    for (auto e: anagramatic_substring_count)
    {
        int count = e.second;
        anagram_pairs += (count * ( count - 1)) / 2;
    }
    return anagram_pairs;
}
int main()
{
    string s = "cdcd";
    int res = sherlockAndAnagrams(s);
    cout << res;
    return 0;
}