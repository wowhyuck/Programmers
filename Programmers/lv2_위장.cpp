#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    vector<pair<string, int>> numClothes;

    for (int i = 0; i < clothes.size(); i++)
    {
        string category = clothes[i][1];
        bool exist = false;

        for (int j = 0; j < numClothes.size(); j++)
        {
            if (category == numClothes[j].first)
            {
                exist = true;
                numClothes[j].second++;
            }
        }

        if (!exist)
            numClothes.push_back(make_pair(category, 1));
    }

    for (int i = 0; i < numClothes.size(); i++)
        answer *= (numClothes[i].second + 1);

    answer--;   // 어떤 의상도 입지 않는 경우 제외

    return answer;
}


int main()
{
    vector<vector<string>> clothes{ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };





    return 0;
}