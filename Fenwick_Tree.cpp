#include<bits/stdc++.h>
using namespace std;

vector<int> v;

vector<int> bit;

int query(int idx)
{

    // t.c-> O(logN)
    int ans = 0;

    while(idx>0)
    {
        ans += bit[idx];

        idx -= idx & (-idx);
    }

    return ans;
}

void update(int idx,int val,int n)
{
    // t.c->O(logN)
    while(idx<=n)
    {
        bit[idx] += val;

        idx += idx & (-idx);
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    v.resize(n + 1, 0);

    bit.resize(n + 1, 0);

    for (int i = 1; i <=n;i++)
    {
        cin >> v[i];

        update(i, v[i], n);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q;i++)
    {
        int q1;
        cin >> q1;

        if(q1==0)
        {
            int index;

            cout << "Enter value of index to get prefix sum upto index value must be between 1 to " << n << endl;



            cin >> index;

            cout << query(index) << endl;
        }

        else{
            int val, index;
            cout << "enter the value to update at index";
            cin >> val >> index;

            update(index, -v[index], n);

            update(index, val, n);

            cout << "Enter enter the value of index to get updated prefix sum " << endl;

            int idx;

            cin >> idx;

            cout << query(idx) << endl;
        }
    }

    return 0;
}