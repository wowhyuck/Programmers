#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        int len = phone_book[i].length();

        for (int j = i + 1; len < phone_book[j].length() && j < phone_book.size(); ++j)
        {
            int startIndex = phone_book[j].find(phone_book[i]);

            if (startIndex == 0)
            {
                answer = false;
                return answer;
            }
        }
    }

    return answer;
}


int main()
{
    vector<string> phone_book = { "119", "114", "112", "123223123", "1231231234" };
    bool answer = solution(phone_book);

    cout << answer << endl;

    return 0;
}