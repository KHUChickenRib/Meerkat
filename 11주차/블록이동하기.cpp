#include <string>
#include <vector>
#include <queue>

using namespace std;

// �κ� ���� ����
struct Coord {
    int y1;
    int x1;
    int y2;
    int x2;
    int time;
};

bool check[100][100][2];        // �湮���� üũ (����.���� ����)

// BFS�� �ּҽð� ã��
int bfs(vector<vector<int>> board) {
    int result = 0;
    queue<Coord> q;
    Coord c;

    q.push({ 0,0,0,1,0 });
    check[0][0][0] = true;

    while (!q.empty()) {
        c = q.front();
        q.pop();

        // ������
        if (c.x2 == board.size() - 1 && c.y2 == board.size() - 1) {
            result = c.time;
            break;
        }

        // ����
        if (c.x2 - c.x1 == 1) {
            // ������ �̵�
            if (c.x2 < board.size() - 1) {
                if (board[c.y1][c.x2 + 1] == 0) {
                    if (!check[c.y1][c.x1 + 1][0]) {
                        q.push({ c.y1, c.x1 + 1, c.y1, c.x2 + 1, c.time + 1 });
                        check[c.y1][c.x1 + 1][0] = true;
                    }
                }
            }
            // ���� �̵�
            if (c.x1 > 0) {
                if (board[c.y1][c.x1 - 1] == 0) {
                    if (!check[c.y1][c.x1 - 1][0]) {
                        q.push({ c.y1, c.x1 - 1, c.y1, c.x2 - 1, c.time + 1 });
                        check[c.y1][c.x1 - 1][0] = true;
                    }
                }
            }
            // �Ʒ��� �̵�
            if (c.y1 < board.size() - 1) {
                if (board[c.y1 + 1][c.x1] == 0 && board[c.y1 + 1][c.x2] == 0) {
                    if (!check[c.y1 + 1][c.x1][0]) {
                        q.push({ c.y1 + 1, c.x1, c.y1 + 1, c.x2, c.time + 1 });
                        check[c.y1 + 1][c.x1][0] = true;
                    }
                }
            }
            // ���� �̵�
            if (c.y1 > 0) {
                if (board[c.y1 - 1][c.x1] == 0 && board[c.y1 - 1][c.x2] == 0) {
                    if (!check[c.y1 - 1][c.x1][0]) {
                        q.push({ c.y1 - 1, c.x1, c.y1 - 1, c.x2, c.time + 1 });
                        check[c.y1 - 1][c.x1][0] = true;
                    }
                }
            }
            // ȸ���� ���� ����
            if (c.y1 > 0) {
                if (board[c.y1 - 1][c.x1] == 0 && board[c.y1 - 1][c.x2] == 0) {
                    // ������ ���� �̵�
                    if (!check[c.y1 - 1][c.x2][1]) {
                        q.push({ c.y1 - 1, c.x2, c.y1, c.x2, c.time + 1 });
                        check[c.y1 - 1][c.x2][1] = true;
                    }
                    // �������� ���� �̵�
                    if (!check[c.y1 - 1][c.x1][1]) {
                        q.push({ c.y1 - 1, c.x1, c.y1, c.x1, c.time + 1 });
                        check[c.y1 - 1][c.x1][1] = true;
                    }
                }
            }
            // ȸ���� ���� �Ʒ���
            if (c.y1 < board.size() - 1) {
                if (board[c.y1 + 1][c.x1] == 0 && board[c.y1 + 1][c.x2] == 0) {
                    // ������ �Ʒ��� �̵�
                    if (!check[c.y1][c.x2][1]) {
                        q.push({ c.y1, c.x2, c.y1 + 1, c.x2, c.time + 1 });
                        check[c.y1][c.x2][1] = true;
                    }
                    // �������� �Ʒ��� �̵�
                    if (!check[c.y1][c.x1][1]) {
                        q.push({ c.y1, c.x1, c.y1 + 1, c.x1, c.time + 1 });
                        check[c.y1][c.x1][1] = true;
                    }
                }
            }
        }
        // ����
        else {
            // �Ʒ��� �̵�
            if (c.y2 < board.size() - 1) {
                if (board[c.y2 + 1][c.x1] == 0) {
                    if (!check[c.y1 + 1][c.x1][1]) {
                        q.push({ c.y1 + 1, c.x1, c.y2 + 1, c.x1, c.time + 1 });
                        check[c.y1 + 1][c.x1][1] = true;
                    }
                }
            }
            // ���� �̵�
            if (c.y1 > 0) {
                if (board[c.y1 - 1][c.x1] == 0) {
                    if (!check[c.y1 - 1][c.x1][1]) {
                        q.push({ c.y1 - 1, c.x1, c.y2 - 1, c.x1, c.time + 1 });
                        check[c.y1 - 1][c.x1][1] = true;
                    }
                }
            }
            // ������ �̵�
            if (c.x1 < board.size() - 1) {
                if (board[c.y1][c.x1 + 1] == 0 && board[c.y2][c.x1 + 1] == 0) {
                    if (!check[c.y1][c.x1 + 1][1]) {
                        q.push({ c.y1, c.x1 + 1, c.y2, c.x1 + 1, c.time + 1 });
                        check[c.y1][c.x1 + 1][1] = true;
                    }
                }
            }
            // ���� �̵�
            if (c.x1 > 0) {
                if (board[c.y1][c.x1 - 1] == 0 && board[c.y2][c.x1 - 1] == 0) {
                    if (!check[c.y1][c.x1 - 1][1]) {
                        q.push({ c.y1, c.x1 - 1, c.y2, c.x1 - 1, c.time + 1 });
                        check[c.y1][c.x1 - 1][1] = true;
                    }
                }
            }
            // ȸ���� ���� ������
            if (c.x1 < board.size() - 1) {
                if (board[c.y1][c.x1 + 1] == 0 && board[c.y2][c.x1 + 1] == 0) {
                    // ���� ������
                    if (!check[c.y2][c.x1][0]) {
                        q.push({ c.y2, c.x1, c.y2, c.x1 + 1, c.time + 1 });
                        check[c.y2][c.x1][0] = true;
                    }
                    // �Ʒ��� ������
                    if (!check[c.y1][c.x1][0]) {
                        q.push({ c.y1, c.x1, c.y1, c.x1 + 1, c.time + 1 });
                        check[c.y1][c.x1][0] = true;
                    }
                }
            }
            // ȸ���� ���� ����
            if (c.x1 > 0) {
                if (board[c.y1][c.x1 - 1] == 0 && board[c.y2][c.x1 - 1] == 0) {
                    // ���� ����
                    if (!check[c.y2][c.x1 - 1][0]) {
                        q.push({ c.y2, c.x1 - 1, c.y2, c.x1, c.time + 1 });
                        check[c.y2][c.x1 - 1][0] = true;
                    }
                    // �Ʒ��� ����
                    if (!check[c.y1][c.x1 - 1][0]) {
                        q.push({ c.y1, c.x1 - 1, c.y1, c.x1, c.time + 1 });
                        check[c.y1][c.x1 - 1][0] = true;
                    }
                }
            }
        }
    }
    return result;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    answer = bfs(board);

    return answer;
}