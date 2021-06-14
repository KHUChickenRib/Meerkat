#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int num;
    int i;

    for (i = 0; i < arr.size(); i++) {
        num = arr[i];
        answer.push_back(num);

        while (num == arr[i])
            i++;
        i--;
    }

    return answer;
}