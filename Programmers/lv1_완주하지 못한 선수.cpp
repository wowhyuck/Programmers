#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); i++)
    {
        if (i == participant.size() - 1)
        {
            answer = participant[i];
            break;
        }

        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}


int main()
{
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki" };

    string answer = solution(participant, completion);

    cout << answer << endl;

    return 0;
}