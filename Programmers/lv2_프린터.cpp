#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int solution(vector<int> priorities, int location) {
    int answer = 0;
    int index = 0;
    vector<int> sort_priorities;

    for (int i = 0; i < priorities.size(); i++)
        sort_priorities.push_back(priorities[i]);

    sort(sort_priorities.begin(), sort_priorities.end());


    while (sort_priorities.empty() != true)
    {
        index = index % priorities.size();

        if (priorities[index] == sort_priorities.back())
        {
            answer++;
            if (location == index)
                break;

            sort_priorities.pop_back();
        }

        index++;
    }

    return answer;
}


int main()
{
    vector<int> priorities{ 1, 1, 9, 1, 1, 1 };
    int location = 0;

    int answer = solution(priorities, location);

    return 0;
}