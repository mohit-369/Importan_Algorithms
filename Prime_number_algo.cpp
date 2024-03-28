#include<bits/stdc++.h>
using namespace std;

void prime1(int n)
{
    // t.c->O(N);
    int flag = 1;
    if (n == 1)
    {  cout << "NO" << endl;
    return;}
      

    for (int i = 2; i < n;i++)
    {
        if(n%i==0)
        {
            cout << "NO" << endl;
            flag = 0;
            break;
        }
    }

    if(flag)
    {
        cout << "YES" << endl;
    }

    return;
}

void prime2(int n)
{
    // t.c-> O(sqrt(N)) 
    if(n==1)
    {
        cout << "NO" << endl;

        return;
    }

    int flag = 1;

    for (int i = 2; i <=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cout << "NO" << endl;
            flag = 0;
            break;
        }
    }

    if(flag)
    {
        cout << "YES" << endl;
    }
}

void primefactor(int n,vector<pair<int,int>> &prime_factor)
{
    // t.c=>O(sqrt(N)log(N));
    
    for (int i = 2; i <=sqrt(n); i++)
    {
        if(n%i==0)
        {
            int count = 0;

            while(n%i==0)
            {
                count++;
                n /= i;
            }

            prime_factor.push_back({i, count});
        }
    }

    if(n>1)
        prime_factor.push_back({n, 1});
}

int main()
{
    int n;
    cout << "Enter the number to check is prime or not" << endl;
    cin >> n;
    prime1(n);
    prime2(n);

    vector<pair<int, int>> prime_factor;

    primefactor(n, prime_factor);

    for (int i = 0; i < prime_factor.size();i++)
    {
        cout << prime_factor[i].first << " " << prime_factor[i].second;
        cout << endl;
    }

        return 0;
}