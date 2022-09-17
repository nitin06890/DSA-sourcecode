// OJ: <--link-->

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    int freq = 0;
    bool isEndOfWord = false;
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string &word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            if (curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
            curr->freq++;
        }
        curr->isEndOfWord = true;
    }

    string findPrefixesHelper(string &word)
    {
        string res = "";
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            int idx = word[i] - 'a';
            res += word[i];
            curr = curr->children[idx];
            if (curr->freq == 1)
                return res;
        }
    }
};

class Solution
{
public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie trie;

        for (int i = 0; i < n; i++)
            trie.insert(arr[i]);

        vector<string> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(trie.findPrefixesHelper(arr[i]));

        return ans;
    }
};