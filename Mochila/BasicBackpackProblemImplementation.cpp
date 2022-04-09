#include <bits/stdc++.h>
using namespace std;
int n, x, dp[10002][10002];
pair<int, int> comida[10002];

int EncuentraMaximo(int costo = 0, int i = 0){
    if (costo > x)
        return INT_MIN;
    if (i >= n)
        return 0;
    if (dp[costo][i] != -1)
        return dp[costo][i];
    int izq = EncuentraMaximo(costo + comida[i].first, i + 1) + comida[i].second;
    int der = EncuentraMaximo(costo, i + 1);
    return dp[costo][i] = max(izq, der);
}

int main()
{
    cin >> n >> x;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
        cin >> comida[i].first >> comida[i].second;
    cout << EncuentraMaximo();
    return 0;
}
