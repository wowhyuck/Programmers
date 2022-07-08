#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0;
    int cur_weight = 0;
    vector<int> arrival_trucks;
    queue<int> truck_bridge;

    for (int i = 0; i < bridge_length; i++)
        truck_bridge.push(0);

    while (arrival_trucks.size() != truck_weights.size())
    {
        if (index != truck_weights.size())
        {
            truck_bridge.push(truck_weights[index]);

            if (truck_bridge.size() > bridge_length)
            {
                if (truck_bridge.front() != 0)
                    arrival_trucks.push_back(truck_bridge.front());
                cur_weight -= truck_bridge.front();
                truck_bridge.pop();
            }

            cur_weight += truck_weights[index];

            if (cur_weight > weight)
            {
                cur_weight -= truck_weights[index];
                truck_bridge.back() = 0;
            }
            else
                index++;
        }
        else
        {
            truck_bridge.push(0);

            if (truck_bridge.size() > bridge_length)
            {
                if (truck_bridge.front() != 0)
                    arrival_trucks.push_back(truck_bridge.front());
                truck_bridge.pop();
            }
        }

        answer++;
    }

    return answer;
}


int main()
{
    int bredge_length = 2;
    int weight = 10;
    vector<int> truck_weights = { 7,4,5,6 };

    int answer = solution(bredge_length, weight, truck_weights);

    return 0;
}