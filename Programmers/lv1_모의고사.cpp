#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> p1{ 1, 2, 3, 4, 5 };
    vector<int> p2{ 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> p3{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> score(3, 0);
    
    for (unsigned int i = 0; i < answers.size(); i++)
    {
        int index = i % 5;
        if (answers[i] == p1[index])
            score[0]++;

        index = i % 8;
        if (answers[i] == p2[index])
            score[1]++;

        index = i % 10;
        if (answers[i] == p3[index])
            score[2]++;
    }

    vector<int>::iterator it = max_element(score.begin(), score.end());

    for (int i = 0; i < 3; i++)
        if (*it == score[i])
            answer.push_back(i + 1);

    return answer;
}


int main()
{
    vector<int> answers{ 1, 3, 2, 4, 2 };

    vector<int> answer = solution(answers);

    return 0;
}