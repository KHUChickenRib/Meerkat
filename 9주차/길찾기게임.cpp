#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 노드 정보
struct TreeNode {
    int x;
    int y;
    int index;

    TreeNode* left;
    TreeNode* right;
};

// 부모노드 left, right 포인터 구성
void addNode(TreeNode* root, TreeNode* node) {
    TreeNode* pre = NULL;   // 부모노드 지정
    
    // 포인터 이동
    while (root != NULL) {
        pre = root;
        if (node->x < pre->x)
            root = root->left;
        else
            root = root->right;
    }

    // 부모노드에서 왼쪽,오른쪽은 x좌표로 확인
    if (node->x < pre->x)
        pre->left = node;
    else
        pre->right = node;
}

// preorder 함수
void preorder(vector<int>& v, TreeNode* root) {
    if (root != NULL) {
        v.push_back(root->index);
        preorder(v, root->left);
        preorder(v, root->right);
    }
}

// postorder 함수
void postorder(vector<int>& v, TreeNode* root) {
    if (root != NULL) {
        postorder(v, root->left);
        postorder(v, root->right);
        v.push_back(root->index);
    }
}

// sort시 y좌표 비교 (내림차순)
bool cmp(TreeNode& a, TreeNode& b) {
    return a.y > b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<TreeNode> tree;
    TreeNode root;

    int i;

    // 트리 구성 (left, right는 모두 NULL) 상태
    for (i = 0; i < nodeinfo.size(); i++)
        tree.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });

    // y좌표 내림차순으로 정렬 후 root 찾기
    sort(tree.begin(), tree.end(), cmp);
    root = tree[0];

    // left, right 포인터 지정
    for (i = 1; i < tree.size(); i++)
        addNode(&root, &tree[i]);

    preorder(answer[0], &root);
    postorder(answer[1], &root);

    return answer;
}