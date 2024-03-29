#include<bits/stdc++.h>
using namespace std;

vector<int> solve(string s)
{
    vector<int> lps(s.size(), 0);

    int i = 1;

    int previndex = 0;

    while(i<s.size())
    {
        previndex = lps[i - 1];

        while(previndex>0 && s[previndex]!=s[i])
        {
            previndex = lps[previndex - 1];
        }

        lps[i] = previndex + (s[previndex] == s[i] ? 1 : 0);

        i++;
    }

    return lps;
}

int main()
{
    string s;

    cout << "Enter the String" << endl;

    cin >> s;

    string p;

    cout << "Enter the patter" << endl;

    cin >> p;

    string a = p + '#' + s;

    vector<int> lps;

    lps = solve(a);

    int flag = 1;

    for (int i = 0; i < lps.size();i++)
    {
        if(lps[i]==p.size())
        {
            flag = 0;

            cout << i - 2 * p.size() << endl;

            break;
        }
    }

    if(flag)
    {
        cout << -1 << endl;
    }

    return 0;

}