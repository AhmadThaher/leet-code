/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty() || preorder.empty())
        {
         return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> s;
        s.push(root);

        int inorderIndex = 0;

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = s.top();
            if (node->val != inorder[inorderIndex]) {
                node->left = new TreeNode(preorder[i]);
                s.push(node->left);
            } else {
                while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
                    node = s.top();
                    s.pop();
                    inorderIndex++;
                }
                node->right = new TreeNode(preorder[i]);
                s.push(node->right);
            }
        }

        return root;
    }
};