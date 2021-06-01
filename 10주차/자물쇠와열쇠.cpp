#include <string>
#include <vector>

using namespace std;

// ���������� 90�� ȸ��
void rotate(vector<vector<int>>& key) {
    int i, j;
    vector<vector<int>> temp(key.size(), vector<int>(key.size()));

    for (i = 0; i < key.size(); i++)
        for (j = 0; j < key[i].size(); j++)
            temp[i][j] = key[key.size() - j - 1][i];

    key = temp;
}

// �� �� �ִ� üũ (90���� ��� ȸ��)
bool check(vector<vector<int>> board, vector<vector<int>> key, int a, int b) {
    int i, j;
    int cnt = 0;
    int temp = 0;

    // key, lock size
    int m = key.size();
    int n = board.size() - (m - 1) * 2;

    // ���������� 90���� ������ �´��� üũ
    while (cnt < 4) {
        temp = 0;
        // key�� Ȯ���Ų board�� ���纸��
        for (i = a; i < a + m; i++) {
            for (j = b; j < b + m; j++)
                board[i][j] += key[i - a][j - b];
        }

        // lock�� ��� �¾Ƶ����� üũ
        for (i = m - 1; i < m + n - 1; i++) {
            for (j = m - 1; j < m + n - 1; j++) {
                if (board[i][j] == 1)
                    temp++;
            }
        }

        // ��� �´� ���
        if (temp == n * n)
            return true;

        // �� �´� ��� board �������·� ����
        for (i = a; i < a + m; i++) {
            for (j = b; j < b + m; j++)
                board[i][j] -= key[i - a][j - b];
        }

        rotate(key);
        cnt++;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int M = key.size();
    int N = lock.size();
    int i, j;

    // board�� Ȯ�� (�ִ� 2*(m-1)+n��)
    vector<vector<int>> board((M-1)*2+N, vector<int>((M-1)*2+N));

    // lock�� �ش�Ǵ� ���� board�� ä���
    for (i = M - 1; i < M + N - 1; i++) {
        for (j = M - 1; j < M + N - 1; j++)
            board[i][j] = lock[i-M+1][j-M+1];
    }

    // Ȯ���Ų board���� key�� ���纸�� (true�� �ٷ� return)
    for (i = 0; i < board.size() - M + 1; i++) {
        for (j = 0; j < board.size() - M + 1; j++) {
            if (check(board, key, i, j)) {
                answer = true;
                return answer;
            }
        }
    }

    return answer;
}