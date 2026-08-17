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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> qt;
        qt.push(root);
        while(!qt.empty())
        {
            int maxi=INT_MIN;
            int size=qt.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* it=qt.front();
                qt.pop();
                maxi=max(maxi,it->val);
                if(it->left) qt.push(it->left);
                if(it->right) qt.push(it->right);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};