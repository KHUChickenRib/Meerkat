#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��� ����
struct TreeNode {
    int x;
    int y;
    int index;

    TreeNode* left;
    TreeNode* right;
};

// �θ��� left, right ������ ����
void addNode(TreeNode* root, TreeNode* node) {
    TreeNode* pre = NULL;   // �θ��� ����
    
    // ������ �̵�
    while (root != NULL) {
        pre = root;
        if (node->x < pre->x)
            root = root->left;
        else
            root = root->right;
    }

    // �θ��忡�� ����,�������� x��ǥ�� Ȯ��
    if (node->x < pre->x)
        pre->left = node;
    else
        pre->right = node;
}

// preorder �Լ�
void preorder(vector<int>& v, TreeNode* root) {
    if (root != NULL) {
        v.push_back(root->index);
        preorder(v, root->left);
        preorder(v, root->right);
    }
}

// postorder �Լ�
void postorder(vector<int>& v, TreeNode* root) {
    if (root != NULL) {
        postorder(v, root->left);
        postorder(v, root->right);
        v.push_back(root->index);
    }
}

// sort�� y��ǥ �� (��������)
bool cmp(TreeNode& a, TreeNode& b) {
    return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<TreeNode> tree;
    TreeNode root;

    int i;

    // Ʈ�� ���� (left, right�� ��� NULL) ����
    for (i = 0; i < nodeinfo.size(); i++)
        tree.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });

    // y��ǥ ������������ ���� �� root ã��
    sort(tree.begin(), tree.end(), cmp);
    root = tree[0];

    // left, right ������ ����
    for (i = 1; i < tree.size(); i++)
        addNode(&root, &tree[i]);

    preorder(answer[0], &root);
    postorder(answer[1], &root);

    return answer;
}