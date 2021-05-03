#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> item;
    int i, j, loc;

    for (i = 0; i < moves.size(); i++) {
        loc = moves[i] - 1;

        for (j = 0; j < board[loc].size(); j++) {
            if (board[j][loc] != 0) {
                item.push_back(board[j][loc]);
                board[j][loc] = 0;
                break;
            }
        }

        if (*(item.end() - 1) == *(item.end() - 2)) {
            answer += 2;
            item.erase(item.end() - 1);
            item.erase(item.end() - 1);
        }
    }

    return answer;
}