//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    bool issquare(const vector<vector<int>>& mat, int row, int col, int size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (mat[row + i][col + j] != 1) {
                    return false;
                }
            }
        }
        return true;
    }

    int maxSquare(int n, int m, vector<vector<int>>& mat) {
        int max_side = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int currentmaxside = min(n - i, m - j);
                for (int side = 1; side <= currentmaxside; side++) {
                    if (issquare(mat, i, j, side)) {
                        max_side = max(max_side, side);
                    } else {
                        break;
                    }
                }
            }
        }

        return max_side;

 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
    
}
// } Driver Code Ends