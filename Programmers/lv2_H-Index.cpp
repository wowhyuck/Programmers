#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> temp;
    priority_queue<int> pq;

    for (int item : citations)
        temp.push_back(item);

    sort(temp.begin(), temp.end());
    
    int h = 0;
    while (true)
    {
        int num = 0;
        for (int i = 0; i < temp.size(); i++)
            if (temp[i] >= h)
                num++;
        bool condition = num >= h;
        if (num >= h)
            answer = h;
        else
            break;
        h++;
    }

    return answer;
}


int main()
{
    vector<int> citations{ 9, 9, 9, 12 };

    int answer = solution(citations);

    return 0;
}