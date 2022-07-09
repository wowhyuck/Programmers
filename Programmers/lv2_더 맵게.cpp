#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> pq_scoville;

	for (int i = 0; i < scoville.size(); i++)
		pq_scoville.push(scoville[i]);

	while (pq_scoville.top() < K)
	{
		if (pq_scoville.size() == 1)
		{
			answer = -1;
			break;
		}

		int first = pq_scoville.top();
		pq_scoville.pop();

		int second = pq_scoville.top() * 2;
		pq_scoville.pop();

		int sum = first + second;
		pq_scoville.push(sum);

		answer++;
	}

	return answer;
}


int main()
{
	vector<int> scoville{ 1, 3, 2, 9, 10, 12 };
	int K = 7;

	int answer = solution(scoville, K);


	return 0;
}