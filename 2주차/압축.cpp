#include <string>
#include <vector>

using namespace std;

// �ѱ��� �ܾ� ����
string alpha[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K"
                    ,"L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V"
                    ,"W", "X", "Y", "Z" };

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> word;
    string newword;
    int index = 1;
    int i;

    // �� ���� �߰�
    word.push_back("0");
    for (i = 0; i < 26; i++) {
        word.push_back(alpha[i]);
    }

    // ù ��° ���� ó��
    answer.push_back(msg[0] - 64);
    if (msg.length() == 1)
        return answer;

    newword = msg.substr(0, 2);
    word.push_back(newword);

    while (index < msg.length()) {
        // ���� �� ���ڿ� ã��(�ڿ��� ���� Ž��)
        for (i = word.size() - 1; i >= 0; i--) {
            if (msg.find(word[i], index) == index) {
                answer.push_back(i);
                index += word[i].length();
                break;
            }
        }
        // �ڿ� �� ã�ƾ� �ϴ� ��� (������ �߰�)
        if (msg[index] != '\0') {
            newword = word[i] + msg.substr(index, 1);
            word.push_back(newword);
        }
    }

    return answer;
}