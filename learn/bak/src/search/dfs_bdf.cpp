#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<int, int> index;

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    if (preorder_left > preorder_right) {
        return nullptr;
    }

    int preorder_root = preorder_left;
    int inorder_root = index[preorder[preorder_root]];
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    int size_left_subtree = inorder_root - inorder_left;
    root->left = buildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    root->right = buildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    for (int i = 0; i < n; ++i) {
        index[inorder[i]] = i;
    }
    return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
}


void dfs(TreeNode * root) {
    if (root == nullptr) return;
    cout << root->val << ' ';
    dfs(root->left);
    dfs(root->right);
}

vector<vector<int>> bfs(TreeNode* root) {
    vector <vector<int>> ret;
    if (!root) {
        return ret;
    }
    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(vector <int> ());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ret;
}

int main() {
//	cout << "请输入树的节点个数：" << endl;
//	int n;
//	cin >> n;
    system("chcp 65001");
    vector<int> preorderector = {1,2,3,4,5,6,7,8 };
    vector<int> inorder = {3,2,4,5,1,7,6,8};
//	cout << "请输入前序遍历序：" << endl;
//	for (int i = 0; i < n; ++i) {
//		cin >> preorderector[i];
//	}
//	cout << "请输入中序遍历序列：" << endl;
//	for (int i = 0; i < n; ++i) {
//		cin >> inorder[i];
//	}
    TreeNode* root = buildTree(preorderector, inorder);
    cout << "深度优先遍历的结果为：" << endl;
    dfs(root);
    cout << endl<< "宽度优先遍历的结果为：" << endl;
    vector<vector<int>> res_bfs = bfs(root);
    for (int i = 0; i < res_bfs.size(); i++) {
        for (int j = 0; j < res_bfs[i].size(); ++j) {
            cout << res_bfs[i][j] << ' ';
        }
    }
    return 0;
}

/*
fn bfs(BT root) {
	if (root 为空) return;
	对 root 的一些操作...
	bfs(root->left);
	bfs(root->right);
}
*/
