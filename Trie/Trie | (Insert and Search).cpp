// OJ: <--link-->

#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord = false;
};

class Trie
{
private:
    TrieNode *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children[word[i] - 'a'] == NULL)
                curr->children[word[i] - 'a'] = new TrieNode();
            curr = curr->children[word[i] - 'a'];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *curr = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (curr->children[word[i] - 'a'] != NULL)
                curr = curr->children[word[i] - 'a'];
            else
                return false;
        }
        return curr->isEndOfWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (curr->children[prefix[i] - 'a'] != NULL)
                curr = curr->children[prefix[i] - 'a'];
            else
                return false;
        }
        return true;
    }
};