//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#include <vector>
#include <climits> // For INT_MAX and INT_MIN
#include <algorithm> // For min and max

using namespace std;

class Solution {   
public:
    // Function to find the upper bound of a value in a sorted array
    int upper_bound(const vector<int>& arr, int value, int n) {
        int low = 0;
        int high = n; // Use arr.size() as the exclusive end index

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    // Function to count elements less than or equal to x in a matrix
    int countsmallequal(const vector<vector<int>>& matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upper_bound(matrix[i], x, m);
        }
        return cnt;
    }
    
    // Function to find the median of a matrix
    int median(vector<vector<int>>& matrix, int R, int C) {
        int low = INT_MAX;
        int high = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();

        // Find the minimum and maximum values in the matrix
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n * m) / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int smallequal = countsmallequal(matrix, n, m, mid);

            if (smallequal <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends