#include <string>
#include <vector>
#include <queue>

using namespace std;

// 로봇 상태 저장
struct Coord {
    int y1;
    int x1;
    int y2;
    int x2;
    int time;
};

bool check[100][100][2];        // 방문여부 체크 (가로.세로 따로)

// BFS로 최소시간 찾기
int bfs(vector<vector<int>> board) {
    int result = 0;
    queue<Coord> q;
    Coord c;

    q.push({ 0,0,0,1,0 });
    check[0][0][0] = true;

    while (!q.empty()) {
        c = q.front();
        q.pop();

        // 도착점
        if (c.x2 == board.size() - 1 && c.y2 == board.size() - 1) {
            result = c.time;
            break;
        }

        // 가로
        if (c.x2 - c.x1 == 1) {
            // 오른쪽 이동
            if (c.x2 < board.size() - 1) {
                if (board[c.y1][c.x2 + 1] == 0) {
                    if (!check[c.y1][c.x1 + 1][0]) {
                        q.push({ c.y1, c.x1 + 1, c.y1, c.x2 + 1, c.time + 1 });
                        check[c.y1][c.x1 + 1][0] = true;
                    }
                }
            }
            // 왼쪽 이동
            if (c.x1 > 0) {
                if (board[c.y1][c.x1 - 1] == 0) {
                    if (!check[c.y1][c.x1 - 1][0]) {
                        q.push({ c.y1, c.x1 - 1, c.y1, c.x2 - 1, c.time + 1 });
                        check[c.y1][c.x1 - 1][0] = true;
                    }
                }
            }
            // 아래로 이동
            if (c.y1 < board.size() - 1) {
                if (board[c.y1 + 1][c.x1] == 0 && board[c.y1 + 1][c.x2] == 0) {
                    if (!check[c.y1 + 1][c.x1][0]) {
                        q.push({ c.y1 + 1, c.x1, c.y1 + 1, c.x2, c.time + 1 });
                        check[c.y1 + 1][c.x1][0] = true;
                    }
                }
            }
            // 위로 이동
            if (c.y1 > 0) {
                if (board[c.y1 - 1][c.x1] == 0 && board[c.y1 - 1][c.x2] == 0) {
                    if (!check[c.y1 - 1][c.x1][0]) {
                        q.push({ c.y1 - 1, c.x1, c.y1 - 1, c.x2, c.time + 1 });
                        check[c.y1 - 1][c.x1][0] = true;
                    }
                }
            }
            // 회전축 기준 위로
            if (c.y1 > 0) {
                if (board[c.y1 - 1][c.x1] == 0 && board[c.y1 - 1][c.x2] == 0) {
                    // 왼쪽이 위로 이동
                    if (!check[c.y1 - 1][c.x2][1]) {
                        q.push({ c.y1 - 1, c.x2, c.y1, c.x2, c.time + 1 });
                        check[c.y1 - 1][c.x2][1] = true;
                    }
                    // 오른쪽이 위로 이동
                    if (!check[c.y1 - 1][c.x1][1]) {
                        q.push({ c.y1 - 1, c.x1, c.y1, c.x1, c.time + 1 });
                        check[c.y1 - 1][c.x1][1] = true;
                    }
                }
            }
            // 회전축 기준 아래로
            if (c.y1 < board.size() - 1) {
                if (board[c.y1 + 1][c.x1] == 0 && board[c.y1 + 1][c.x2] == 0) {
                    // 왼쪽이 아래로 이동
                    if (!check[c.y1][c.x2][1]) {
                        q.push({ c.y1, c.x2, c.y1 + 1, c.x2, c.time + 1 });
                        check[c.y1][c.x2][1] = true;
                    }
                    // 오른쪽이 아래로 이동
                    if (!check[c.y1][c.x1][1]) {
                        q.push({ c.y1, c.x1, c.y1 + 1, c.x1, c.time + 1 });
                        check[c.y1][c.x1][1] = true;
                    }
                }
            }
        }
        // 세로
        else {
            // 아래로 이동
            if (c.y2 < board.size() - 1) {
                if (board[c.y2 + 1][c.x1] == 0) {
                    if (!check[c.y1 + 1][c.x1][1]) {
                        q.push({ c.y1 + 1, c.x1, c.y2 + 1, c.x1, c.time + 1 });
                        check[c.y1 + 1][c.x1][1] = true;
                    }
                }
            }
            // 위로 이동
            if (c.y1 > 0) {
                if (board[c.y1 - 1][c.x1] == 0) {
                    if (!check[c.y1 - 1][c.x1][1]) {
                        q.push({ c.y1 - 1, c.x1, c.y2 - 1, c.x1, c.time + 1 });
                        check[c.y1 - 1][c.x1][1] = true;
                    }
                }
            }
            // 오른쪽 이동
            if (c.x1 < board.size() - 1) {
                if (board[c.y1][c.x1 + 1] == 0 && board[c.y2][c.x1 + 1] == 0) {
                    if (!check[c.y1][c.x1 + 1][1]) {
                        q.push({ c.y1, c.x1 + 1, c.y2, c.x1 + 1, c.time + 1 });
                        check[c.y1][c.x1 + 1][1] = true;
                    }
                }
            }
            // 왼쪽 이동
            if (c.x1 > 0) {
                if (board[c.y1][c.x1 - 1] == 0 && board[c.y2][c.x1 - 1] == 0) {
                    if (!check[c.y1][c.x1 - 1][1]) {
                        q.push({ c.y1, c.x1 - 1, c.y2, c.x1 - 1, c.time + 1 });
                        check[c.y1][c.x1 - 1][1] = true;
                    }
                }
            }
            // 회전축 기준 오른쪽
            if (c.x1 < board.size() - 1) {
                if (board[c.y1][c.x1 + 1] == 0 && board[c.y2][c.x1 + 1] == 0) {
                    // 위가 오른쪽
                    if (!check[c.y2][c.x1][0]) {
                        q.push({ c.y2, c.x1, c.y2, c.x1 + 1, c.time + 1 });
                        check[c.y2][c.x1][0] = true;
                    }
                    // 아래가 오른쪽
                    if (!check[c.y1][c.x1][0]) {
                        q.push({ c.y1, c.x1, c.y1, c.x1 + 1, c.time + 1 });
                        check[c.y1][c.x1][0] = true;
                    }
                }
            }
            // 회전축 기준 왼쪽
            if (c.x1 > 0) {
                if (board[c.y1][c.x1 - 1] == 0 && board[c.y2][c.x1 - 1] == 0) {
                    // 위가 왼쪽
                    if (!check[c.y2][c.x1 - 1][0]) {
                        q.push({ c.y2, c.x1 - 1, c.y2, c.x1, c.time + 1 });
                        check[c.y2][c.x1 - 1][0] = true;
                    }
                    // 아래가 왼쪽
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