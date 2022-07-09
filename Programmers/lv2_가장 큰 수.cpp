#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	return a + b < b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp;

	for (int item : numbers)
	{
		string num = to_string(item);
		temp.push_back(num);
	}

	for (int i = 0; i < 10; i++)
		sort(temp.begin(), temp.end(), cmp);

	while (temp.empty() != true)
	{
		answer += temp.back();
		temp.pop_back();
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}


int main()
{
	//vector<int> numbers{ 30, 3, 34, 5, 9 };
	//vector<int> numbers{ 90, 908, 89, 898, 10, 101, 1, 8, 9 };
	vector<int> numbers{ 0,0,0,0 };

	string answer = solution(numbers);

	return 0;
}