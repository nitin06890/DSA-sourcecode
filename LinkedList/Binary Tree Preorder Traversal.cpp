// OJ: https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// recursive

class Solution
{
public:
    vector<int> ans;

    vector<int> preorder(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return ans;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        return preorder(root);
    }
};

//morris

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
            TreeNode *curr = root;

            while (curr != NULL)
            {
                if (curr->left == NULL)
                {
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
                else
                {
                    TreeNode *prev = curr->left;
                    while (prev->right && prev->right != curr)
                        prev = prev->right;
                    if (prev->right == NULL)
                    {
                        prev->right = curr;
                        ans.push_back(curr->val);
                        curr = curr->left;
                    }
                    else
                    {
                        prev->right = NULL;
                        curr = curr->right;
                    }
                }
            }
        return ans;
    }
};