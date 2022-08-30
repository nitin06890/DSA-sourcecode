// OJ: https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(string pat, string txt)
    {
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<char, int> mp;

        for (char it : pat)
            mp[it]++;
        int k = pat.size();
        int n = txt.size();
        int cnt = mp.size();

        while (j < n)
        {
            if (mp.find(txt[j]) != mp.end())
            {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0)
                    cnt--;
            }
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                if (cnt == 0)
                    ans++;
                if (mp.find(txt[i]) != mp.end())
                {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1)
                        cnt++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};