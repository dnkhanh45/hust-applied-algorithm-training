#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int W, H;
    cin >> W >> H;

    vector<vector<int>> rest(W + 1, vector<int>(H + 1));
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            rest[i][j] = i * j;
        }
    }

    int N;
    cin >> N;
    int x, y;
    for (int i = 1; i <= N; i++)
    {
        cin >> x >> y;
        rest[x][y] = 0;
    }

    int min_lost;
    for (int i = 1; i <= W; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            min_lost = rest[i][j];
            
            for(int k = 1; k < i; k++)
            {
                min_lost = min(min_lost, rest[k][j] + rest[i - k][j]);
            }

            for(int k = 1; k < j; k++)
            {
                min_lost = min(min_lost, rest[i][k] + rest[i][j - k]);
            }

            rest[i][j] = min_lost;
        }
    }

    cout << rest[W][H];
    return 0;
}