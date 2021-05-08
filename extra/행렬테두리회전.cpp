#include <string>
#include <vector>

using namespace std;

int getmin(vector<int> query, vector<vector<int>> v) {
    int i, j;
    int min = v[query[0] - 1][query[1] - 1];
    int temp = v[query[0] - 1][query[1] - 1];

    for (j = query[1]; j < query[3]; j++) {
        if (min > v[query[0] - 1][j])
            min = v[query[0] - 1][j];
    }
    j--;

    for (i = query[0]; i < query[2]; i++) {
        if (min > v[i][j])
            min = v[i][j];
    }
    i--;

    for (j = query[3] - 2; j >= query[1] - 1; j--) {
        if (min > v[i][j])
            min = v[i][j];
    }
    j++;

    for (i = query[2] - 2; i >= query[0] - 1; i--) {
        if (min > v[i][j])
            min = v[i][j];
    }

    return min;
}

void rotate(vector<int> query, vector<vector<int>>& v) {
    int i, j;

    int temp = v[query[0] - 1][query[1] - 1];

    for (j = query[1]; j < query[3]; j++)
        swap(v[query[0] - 1][j], temp);
    j--;

    for (i = query[0]; i < query[2]; i++)
        swap(v[i][j], temp);
    i--;

    for (j = query[3] - 2; j >= query[1] - 1; j--)
        swap(v[i][j], temp);
    j++;

    for (i = query[2] - 2; i >= query[0] - 1; i--)
        swap(v[i][j], temp);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns));
    int i, j;
    int num = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            v[i][j] = num;
            num++;
        }
    }

    for (i = 0; i < queries.size(); i++) {
        answer.push_back(getmin(queries[i], v));
        rotate(queries[i], v);
    }

    return answer;
}