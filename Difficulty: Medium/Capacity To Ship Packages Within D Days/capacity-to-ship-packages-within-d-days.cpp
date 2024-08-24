//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Totaldays(int weights[], int n, int capacity) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < n; ++i) {
            if (load + weights[i] > capacity) {
                ++days;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
    
    int leastWeightCapacity(int arr[], int n, int d) {
        int low = *max_element(arr, arr + n); // Minimum possible capacity
        int high = accumulate(arr, arr + n, 0); // Maximum possible capacity
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int noofdays = Totaldays(arr, n, mid);
            
            if (noofdays <= d) {
                high = mid; // Try for a smaller capacity
            } else {
                low = mid + 1; // Increase capacity
            }
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends