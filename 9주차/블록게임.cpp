#include <string>
#include <vector>

using namespace std;

bool check(vector<vector<int>>& board) {
    int i, j, k;
    int temp;

    for (i = 0; i < board.size() - 1; i++) {
        for (j = 0; j < board[i].size() - 1; j++) {
            // (1,0,0 / 1,1,1)
            if (j < board[i].size() - 2 && board[i][j] != 0 && board[i][j + 1] == 0 && board[i][j + 2] == 0) {
                temp = board[i][j];

                if (temp == board[i + 1][j] && temp == board[i + 1][j + 1] && temp == board[i + 1][j + 2]) {
                    for (k = 0; k < i; k++) {
                        if (board[k][j + 1] != 0 || board[k][j + 2] != 0)
                            break;
                    }
                    if (k == i) {
                        board[i][j] = 0;
                        board[i + 1][j] = 0;
                        board[i + 1][j + 1] = 0;
                        board[i + 1][j + 2] = 0;
                        return true;
                    }
                }
            }
            // (0,0,1 / 1,1,1)
            if (j < board[i].size() - 2 && board[i][j] == 0 && board[i][j + 1] == 0 && board[i][j + 2] != 0) {
                temp = board[i][j + 2];

                if (temp == board[i + 1][j] && temp == board[i + 1][j + 1] && temp == board[i + 1][j + 2]) {
                    for (k = 0; k < i; k++) {
                        if (board[k][j] != 0 || board[k][j + 1] != 0)
                            break;
                    }
                    if (k == i) {
                        board[i][j + 2] = 0;
                        board[i + 1][j] = 0;
                        board[i + 1][j + 1] = 0;
                        board[i + 1][j + 2] = 0;
                        return true;
                    }
                }
            }
            // (0,1,0 / 1,1,1)
            if (j < board[i].size() - 2 && board[i][j] == 0 && board[i][j + 1] != 0 && board[i][j + 2] == 0) {
                temp = board[i][j + 1];

                if (temp == board[i + 1][j] && temp == board[i + 1][j + 1] && temp == board[i + 1][j + 2]) {
                    for (k = 0; k < i; k++) {
                        if (board[k][j] != 0 || board[k][j + 2] != 0)
                            break;
                    }
                    if (k == i) {
                        board[i][j + 1] = 0;
                        board[i + 1][j] = 0;
                        board[i + 1][j + 1] = 0;
                        board[i + 1][j + 2] = 0;
                        return true;
                    }
                }
            }
            // (0,1 / 0,1 / 1,1)
            if (i < board.size() - 2 && board[i][j] == 0 && board[i][j + 1] != 0) {
                temp = board[i][j + 1];
                if (board[i + 1][j] == 0 && temp == board[i + 1][j + 1] && temp == board[i + 2][j] && temp == board[i + 2][j + 1]) {
                    for (k = 0; k < i; k++) {
                        if (board[k][j] != 0)
                            break;
                    }
                    if (k == i) {
                        board[i][j + 1] = 0;
                        board[i + 1][j + 1] = 0;
                        board[i + 2][j] = 0;
                        board[i + 2][j + 1] = 0;
                        return true;
                    }
                }
            }
            // (1,0 / 1,0 / 1,1)
            if (i < board.size() - 2 && board[i][j] != 0 && board[i][j + 1] == 0) {
                temp = board[i][j];
                if (board[i + 1][j + 1] == 0 && temp == board[i + 1][j] && temp == board[i + 2][j] && temp == board[i + 2][j + 1]) {
                    for (k = 0; k < i; k++) {
                        if (board[k][j + 1] != 0)
                            break;
                    }
                    if (k == i) {
                        board[i][j] = 0;
                        board[i + 1][j] = 0;
                        board[i + 2][j] = 0;
                        board[i + 2][j + 1] = 0;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    bool chk = true;

    while (chk) {
        if (check(board)) {
            answer++;
        }
        else
            chk = false;
    }

    return answer;
}