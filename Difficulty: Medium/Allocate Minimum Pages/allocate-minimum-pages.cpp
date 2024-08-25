//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
  
    int Noofpages(int arr[],int n,int pages){
        int pagescnt = 0;
        int studentcnt = 1;
        for(int i =0 ;i<n;i++){
            if((pagescnt + arr[i]) <= pages){
                pagescnt += arr[i];
            }
            else{
                studentcnt++;
                pagescnt = arr[i];
            }
        }
        return studentcnt;
    }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(m>n) return -1;
        int low = *max_element(arr,arr+n);
        int high = accumulate(arr,arr+n,0);
        int result  = -1;
        
        while(low<=high){
            int mid = (low+high)/2;
            long long  countstudents = Noofpages( arr, n, mid);
            if(countstudents<=m){
                result = mid;
                high = mid-1;
            }
            else  low =mid+1;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends