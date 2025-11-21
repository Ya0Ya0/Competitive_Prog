#include <bits/stdc++.h>
using namespace std;
vector<int> other(vector<int> &deck)
{
     int inc = 2, start = 0, decki = 0;
        vector<int> ans(deck.size());
        sort(deck.begin(), deck.end());
        queue <int> q;
        for(int i = 0; i < deck.size(); i++)
        {
            q.push(i);
        }
        int i = 0;
        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            ans[num] = deck[i++];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
}

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int inc = 2, start = 0, decki = 0;
    vector<int> ans(deck.size(),-1);
    sort(deck.begin(),deck.end());
    for (int i = 0, j = 0; decki < deck.size(); i++)
    {
        for (int z = 0; z < deck.size(); z++)
            if (ans[z] == -1)
            {
                j = z;
                break;
            }
        if(decki==deck.size()-1)
        {
            ans[j] = deck[decki];
            return ans;
        }
        j += start ? inc/2 : 0;
        
        int next = 0;
        for (int k = j; k < deck.size(); k += inc/2)
        {            
            next++;
        }
        for (; j < deck.size(); j += inc)
        {
            ans[j] = deck[decki++];
            
        }
        start = next & 1;
        inc *= 2;
    }

    return ans;
}
void Solve()
{
    vector<int> a{1,2,3,4,5,6,7,8};
    vector<int> b=deckRevealedIncreasing(a);
    return;
}

int main()
{
    int tt = 1; // cin >> tt;
    while (tt--)
    {
        Solve();
    }
}
