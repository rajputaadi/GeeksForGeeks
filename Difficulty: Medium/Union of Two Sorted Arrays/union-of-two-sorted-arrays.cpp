//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
       vector<int> unionArr;
    int n1 = n, n2 = m;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            unionArr.push_back(arr1[i]);
            while (i + 1 < n1 && arr1[i] == arr1[i + 1]) i++; // Skip duplicates in arr1
            i++;
        } else if (arr2[j] < arr1[i]) {
            unionArr.push_back(arr2[j]);
            while (j + 1 < n2 && arr2[j] == arr2[j + 1]) j++; // Skip duplicates in arr2
            j++;
        } else { // arr1[i] == arr2[j]
            unionArr.push_back(arr1[i]);
            while (i + 1 < n1 && arr1[i] == arr1[i + 1]) i++; // Skip duplicates in both arr1 and arr2
            while (j + 1 < n2 && arr2[j] == arr2[j + 1]) j++;
            i++;
            j++;
        }
    }

    // Append remaining elements of arr1
    while (i < n1) {
        unionArr.push_back(arr1[i]);
        while (i + 1 < n1 && arr1[i] == arr1[i + 1]) i++; // Skip duplicates in arr1
        i++;
    }

    // Append remaining elements of arr2
    while (j < n2) {
        unionArr.push_back(arr2[j]);
        while (j + 1 < n2 && arr2[j] == arr2[j + 1]) j++; // Skip duplicates in arr2
        j++;
    }

    return unionArr;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends