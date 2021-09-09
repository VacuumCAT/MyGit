class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        TreeNode* backup=p;
        if(p->right){
            p=p->right;
            while(p->left){
                p=p->left;
            }
            return p;
        }
        while(p->father&&p==p->father->right) p=p->father;
        return p->father;
    }
};