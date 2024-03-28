#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<bool> &isprime)
{

    

    for (int i = 2; i <= sqrt(n);i++)
    {
        if(isprime[i])
        {
            for (int j = i*i; j <= n;j+=i)
            {
                isprime[j] = false;
            }
        }
    }

    return;
}

int main()
{

    // t.c-> O(Nlog log sqrt(N) )

    int n;
    cout << "Enter number upto which we want Prime Number" << endl;

    cin >> n;

    vector<bool> isprime(n + 1, 1);

    solve(n, isprime);

    for (int i = 0; i < n + 1;i++)
    {
        if(i==0 or i==1)
        {
            continue;
        }
        if(isprime[i])
        {
            cout << i << " ";
        }
    }

    

    cout << endl;

    return 0;
}