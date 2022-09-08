// OJ: https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/

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

    vector<int> postorder(TreeNode *root)
    {
        if (root == NULL)
            return ans;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
        return ans;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        return postorder(root);
    }
};

//morris-traversal
