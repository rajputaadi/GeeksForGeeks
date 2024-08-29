//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string reverseWords(string s) {
        int i =0;
        int n = s.size();
        string result;
        while(i<n){
            while(i<n && s[i] == '.') i++;
            if(i>=n) break;
            int j = i+1;
            while(j<n && s[j]!='.') j++;
            string sub = s.substr(i,j-i);
            if(result.empty()) result = sub;
            else{
                result =  sub + "." + result;
            }
            i = j+1;

        }
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends