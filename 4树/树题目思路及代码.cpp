1、二叉树的最大深度
//这道题可以使用二叉树的递归套路来做，也就是左子树和右子树的最大深度比较
//大的那方+1就变成了总体的最大高度

//以下方法为最优解，利用了morris遍历的特性，利用本身叶子节点的空指针，
//临时改变指向来进行遍历的一种方法，时间空间复杂度分别为O(n),O(1)

int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        TreeNode* cur = root;
        TreeNode* mostRight = nullptr;
        int curlevel = 0;                      //curlevel记录上一个到达的节点层数
        int res = INT_MIN;
        while(cur != nullptr){
            mostRight = cur->left;
            if(mostRight != nullptr){        //能到达自己两次
                int leftHeight = 1;
                while(mostRight->right != nullptr && mostRight->right != cur){
                    leftHeight++;
                    mostRight = mostRight->right;
                }                                   //找到最右节点
                if(mostRight->right == nullptr){    //第一次到达
                    curlevel++;
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{                                //第二次到达
                    if(mostRight->left == nullptr){
                        res = max(res,curlevel);
                    }
                    curlevel-=leftHeight;
                    mostRight->right = nullptr;
                }
            }else{                              //只能到达自己一次
                curlevel++;
            }
            cur = cur->right;                  //能到两次并且第二次到，和只能到一次时右移
        }
        int firight = 1;                        //和整棵树最右节点比较
        cur = root;
        while(cur->right != nullptr){
            firight++;
            cur = cur->right;
        }
        if(cur->left == nullptr){
            res = max(res,firight);
        }
        return res;
    }
	
2、验证二叉搜索树
//同理，这个也可以用递归，一直递归查看孩子的值是否大于根节点的值
//仍然可以用MOrris遍历的方法做，设置前结点的指针，如果中序遍历是一直递增的，那么久符合
//很多类似的题目都可以用Morris遍历来改写从而得到最优解
bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        bool res = true;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        TreeNode* mostRight = nullptr;
        while(cur != nullptr){
            mostRight = cur->left;
            if(mostRight != nullptr){
                while(mostRight->right != nullptr && mostRight->right != cur){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == nullptr){
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                }else{
                    mostRight->right = nullptr;
                }
            }
            if(pre != nullptr && pre->val >= cur->val){
                res =  false;
            }
            pre = cur;
            cur = cur->right;
        }
        return res;
    }
	
3、对称二叉树
//简单的递归就能完成

bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isSymmetric(root->left,root->right);
    }
    bool isSymmetric(TreeNode* left,TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr || left->val != right->val){
            return false;
        }
		//需要注意的是，在递归问题里面，由于是镜像比较，故左-左和右-右比，左-右和右-左比
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
	
4、二叉树的层序遍历
//用队列，广度优先遍历

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        //int size = 0;
        while(!que.empty()){
            int size = que.size();          //每一层的长度
            vector<int> X;
            while(size--){
                TreeNode* temp = que.front();
                que.pop();
                X.push_back(temp->val);
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            res.push_back(X);            //一层一层的填入
        }
        return res;
    }
	
5、将有序数组转换为二叉平衡搜索树
//递归，头节点肯定是数组中间的数，然后两边分别创建平衡二叉搜索树，返回即可

TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return nullptr;
        }
        return sortedArrayToBST(nums,0,nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end){
        if(start > end){
            return nullptr;
        }
        int mid = end - ((end-start)>>1);
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums,start,mid-1);
        root->right = sortedArrayToBST(nums,mid+1,end);
        return root;
    }