#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int start = 0;
    int complete = 0;

    while (start < progresses.size())
    {
        for (int i = 0; i < progresses.size(); i++)
            if(progresses[i] < 100)
                progresses[i] += speeds[i];

        while (start < progresses.size() && progresses[start] >= 100)
        {
            complete++;
            start++;
        }

        if (complete > 0)
        {
            answer.push_back(complete);
            complete = 0;
        }
    }

    return answer;
}


int main()
{
    vector<int> progresses{ 95, 90, 99, 99, 80, 99 };
    vector<int> speeds{ 1, 1, 1, 1, 1, 1 };

    vector<int> answer = solution(progresses, speeds);

    return 0;
}