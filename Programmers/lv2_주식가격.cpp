#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size(); i++)
    {
        int time = 0;
        int index = i;
        int start_price = prices[index];
        while (index != prices.size() - 1 && start_price <= prices[index])
        {
            time++;
            index++;
        }

        answer.push_back(time);
    }

    return answer;
}


int main()
{
    vector<int> prices{ 1, 2, 3, 2, 3 };

    vector<int> answer = solution(prices);

    return 0;
}