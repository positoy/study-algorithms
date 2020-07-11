#include <iostream>
#include <string>
/*
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2)
            return nullptr;
        else if (t1 && !t2)
            return t1;
        else if (!t1 && t2)
            return t2;

        TreeNode* node = new TreeNode(t1->val + t2->val);
        node->left = mergeTrees(t1->left, t2->left);
        node->right = mergeTrees(t1->right, t2->right);
        return node;
    }

    void printTree(TreeNode* t, std::string direction = "none") {
        std::cout << direction << " : " << t->val << std::endl;
        if (t->left) printTree(t->left, "left");
        if (t->right) printTree(t->right, "right");
    }
};

int main()
{
    struct TreeNode root1(1);
    root1.left = new TreeNode(3);
    root1.right = new TreeNode(2);
    root1.left->left = new TreeNode(5);

    struct TreeNode root2(2);
    root2.left = new TreeNode(1);
    root2.right = new TreeNode(3);
    root2.left->right = new TreeNode(4);
    root2.right->right = new TreeNode(7);

    Solution s;
    struct TreeNode *treeSum = s.mergeTrees(&root1, &root2);

    s.printTree(treeSum);
}