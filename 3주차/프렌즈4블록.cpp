#include <string>
#include <vector>

using namespace std;

// 지워야 하는 대상 파악 (대상인 경우는 각 원소를 1로) -> update시 똑같은 과정이 필요함
vector<vector<int>> count_board(int m, int n, vector<string> board) {
    int i, j;
    vector<vector<int>> result(m, vector<int>(n, 0)); // (2차원 배열 모두 0으로 초기화)

    // scan하여 각 board 원소 파악
    for (i = 0; i < m - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            // 알파벳 체크 (참고로 대문자는 1을 return)
            if (isalpha(board[i][j]) == 0)
                continue;
            // 4개 인접 블록 체크
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

// 스캔 하여 카운팅
int scan_board(int m, int n, vector<string> board) {
    int i, j;
    vector<vector<int>> cnt(m, vector<int>(n, 0));
    int result = 0;

    cnt = count_board(m, n, board);     // scan하여 조사
    
    // 1인 갯수 파악
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

    cnt = count_board(m, n, board);     // scan하여 update 대상 조사

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            // update 필요한 경우
            if (cnt[i][j] == 1) {
                if (i == 0)
                    board[0][j] = -1;
                // 위에서 부터 내려오기
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
        temp = scan_board(m, n, board);     // 테이블 스캔

        // 더 이상 없는 경우
        if (temp == 0)
            break;
        else
            update_board(m, n, board);      // 테이블 update
        answer += temp;
    }
    return answer;
}