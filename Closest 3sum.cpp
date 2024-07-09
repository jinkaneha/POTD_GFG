//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int difference = INT_MAX;
        int ans = 0;
        for (int i = 0; i < arr.size() - 2; i++) {
            int first = arr[i];
            int start = i + 1;
            int end = arr.size() - 1;
            while (start < end) {
                int current_sum = first + arr[start] + arr[end];
                int current_diff = abs(current_sum - target);
                
                if (current_diff < difference || (current_diff == difference && current_sum > ans)) {
                    difference = current_diff;
                    ans = current_sum;
                }
                
                if (current_sum < target) {
                    start++;
                } else if (current_sum > target) {
                    end--;
                } else {
                    return current_sum; 
                }
            }
        }
        return ans;  
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends