#include <iostream>
 
using namespace std;
const int mx = 1e6;
int A[mx], N, res = -mx;
int odd[mx], even[mx];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        odd[i] = -INT_MAX/2;
        even[i] = -INT_MAX/2;
    }
 
    if (A[0] % 2)
    {
        odd[0] = A[0];
    }
    else{
        even[0] = A[0];
    }
        
 
    for (int i = 1; i < N; i++)
    {
        if (A[i] % 2)
        {
            even[i] = odd[i-1] + A[i];
            odd[i] = max(A[i], even[i-1] + A[i]);
        }
        else
        {
            even[i] = max(A[i], even[i-1] + A[i]);
            odd[i] = odd[i-1] + A[i];
        }
    }
    res = -1e6;
    for (int i=0; i<N; i++){
        res = max(res, even[i]);
    }
    
    // for (int i = 0; i < N - 1; i++)
    // {
    //     int sum = A[i];
    //     if (!(sum % 2))
    //         res = max(res, sum);
    //     for (int j = i + 1; j < N; j++)
    //     {
    //         sum += A[j];
    //         if (!(sum % 2))
 
    //             res = max(res, sum);
    //     }
    // }
    cout << res;
}