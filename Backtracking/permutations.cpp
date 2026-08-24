#include<iostream>
#include<string>
using namespace std;

void permutate(string str, string ans)
{
    // Base case
    if(str.size() == 0)
    {
        cout << ans << "  ";
        return;
    }

    //choose every character one by one
    for(int i = 0; i < str.size(); i++)
    {
        char ch = str[i];

        string remaining = str.substr(0, i) + str.substr(i + 1);

        permutate(remaining, ans + ch);
    }
}

int main()
{
    string str = "abc";

    permutate(str, "");

    return 0;
}
