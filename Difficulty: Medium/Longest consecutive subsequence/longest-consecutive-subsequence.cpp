//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        if(N==0) return 0;
        sort(arr,arr+N);
        int cnt = 0;
        int longest = 1;
        int last_smallest = INT_MIN;
        for(int i =0; i<N;i++){
            if(arr[i]-1 == last_smallest){
                cnt+=1;
                last_smallest = arr[i];
            }
            else if(last_smallest != arr[i]){
                cnt =1;
                last_smallest = arr[i];
            }
            longest = max(cnt,longest);
        }
        return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends