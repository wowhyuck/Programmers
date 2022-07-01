#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n + 1, 1);
    
    for (int i = 0; i < lost.size(); i++)
    {
        int index = lost[i];
        students[index]--;
    }

    for (int i = 0; i < reserve.size(); i++)
    {
        int index = reserve[i];
        students[index]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            if (students[i] == 0 && students[i - 1] == 2)
            {
                students[i - 1]--;
                students[i]++;
            }

            break;
        }

        if (students[i] == 0)
        {
            if (students[i - 1] == 2)
            {
                students[i - 1]--;
                students[i]++;
            }
            else if (students[i + 1] == 2)
            {
                students[i]++;
                students[i + 1]--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (students[i] >= 1)
            answer++;
    }

    return answer;
}


int main()
{
    int n = 5;
    vector<int> lost{ 2, 5 };
    vector<int> reserve{ 1, 3};

    int ret = solution(n, lost, reserve);


    return 0;
}