#include <string>
#include <vector>

using namespace std;

// ������ �ϴ� ��� �ľ� (����� ���� �� ���Ҹ� 1��) -> update�� �Ȱ��� ������ �ʿ���
vector<vector<int>> count_board(int m, int n, vector<string> board) {
    int i, j;
    vector<vector<int>> result(m, vector<int>(n, 0)); // (2���� �迭 ��� 0���� �ʱ�ȭ)

    // scan�Ͽ� �� board ���� �ľ�
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            // ���ĺ� üũ (����� �빮�ڴ� 1�� return)
            if (isalpha(board[i][j]) == 0)
                continue;
            // 4�� ���� ��� üũ
            if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j]
                && board[i][j] == board[i + 1][j + 1]) {
                result[i][j] = 1;
                result[i + 1][j] = 1;
                result[i][j + 1] = 1;
                result[i + 1][j + 1] = 1;
            }
        }
    }
    return result;
}

// ��ĵ �Ͽ� ī����
int scan_board(int m, int n, vector<string> board) {
    int i, j;
    vector<vector<int>> cnt(m, vector<int>(n, 0));
    int result = 0;

    cnt = count_board(m, n, board);     // scan�Ͽ� ����
    
    // 1�� ���� �ľ�
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (cnt[i][j] == 1)
                result++;
        }
    }
    return result;
}

// board update
void update_board(int m, int n, vector<string>& board) {
    int i, j, k;
    vector<vector<int>> cnt(m, vector<int>(n, 0));

    cnt = count_board(m, n, board);     // scan�Ͽ� update ��� ����

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            // update �ʿ��� ���
            if (cnt[i][j] == 1) {
                if (i == 0)
                    board[0][j] = -1;
                // ������ ���� ��������
                for (k = i; k > 0; k--) {
                    board[k][j] = board[k - 1][j];
                    board[k - 1][j] = ' ';
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int temp;

    while (1) {
        temp = scan_board(m, n, board);     // ���̺� ��ĵ

        // �� �̻� ���� ���
        if (temp == 0)
            break;
        else
            update_board(m, n, board);      // ���̺� update
        answer += temp;
    }
    return answer;
}