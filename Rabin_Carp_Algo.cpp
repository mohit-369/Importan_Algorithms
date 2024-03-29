
#include<bits/stdc++.h>

using namespace std;

int calculatehash(int radix,string B,int m)
{
    int mod = 1e9 + 7;

    int ans = 0;

    int count = 1;

    for (int i = m - 1; i >= 0;i--)
    {
        ans += ((B[i] - 'a') * count) % mod;

        count = (count * radix) % mod;


    }

    return ans%mod;
}

int main()
{
    string A, B;

    cout << "Enter String A" << endl;

    cin >> A;

    cout << "Enter pattern" << endl;

    cin >> B;

    int radix = 26;

    int mod = 1e9 + 7;

    if(A.size()<B.size())
    {
        cout<<-1<<" "<< "NO" << endl;
    }

    int weight=1;

    for (int i = 0; i < B.size();i++)
    {
        weight = (weight * radix) % mod;

    }

    int bhash = calculatehash(radix, B,B.size());

    int m = B.size();

    int ahash = 0;

    int flag = 1;

    for (int i = 0; i <=A.size()-B.size();i++)
    {
        if(i==0)
        {
            ahash = calculatehash(radix, A,B.size());
        }

        else
        {
            ahash = (ahash * radix) % mod - ((A[i - 1] - 'a') * weight) % mod + (A[i +m  - 1] - 'a') % mod;
        }

        if(ahash==bhash)
        {
            flag = 0;
            cout << i << " "
                 << "YES" << endl;

            break;
        }
        
    }

    if(flag)
    {
        cout << "NO" << endl;
    }
}