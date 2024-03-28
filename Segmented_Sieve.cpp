#include<bits/stdc++.h>
using namespace std;

void solve(int r,vector<bool> &prime)
{
    for (int i = 2; i <=(sqrt(r));i++)
    {
        if(prime[i])
        {
            for (int j = i * i; j <r;j+=i)
            {
                prime[j] = false;
            }
        }
    }

    return;
}

int main()
{

    int l, r;

    cout << "Enter range upto to which you want prime Number" << endl;

    cin >> l >> r;
    // l = 21, r = 50;

    int limit = floor(sqrt(r)) + 1;

    vector<bool> prime(limit, 1);

    solve(limit, prime);
    // cerr << "HELLO";
    vector<bool> isprime(r - l + 1, 1);

    for (int i = 2; i < prime.size();i++)
    {
        if(prime[i])
        {
            // int multiple = ceil(l*1.0 /i);
            int multiple = (l + i - 1) / i;
            if (multiple == 1)
                multiple++;

            int index = multiple * i - l;
            // cerr << index <<" " <<multiple<< " , ";
            for (int j = index; j < isprime.size(); j += i)
            {
                isprime[j] = false;
            }
        }
    }
    // cerr << "DOME";
    for (int i = 0; i < isprime.size(); i++)
    {
        if(isprime[i])
        {
            cout << i + l << " ";
        }
    }

    cout << endl;

    return 0;
}