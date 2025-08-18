#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool ispossible(vector<int> &arr, int N, int C, int minAllowedDist) {
    int cows = 1;                
    int lastStallPos = arr[0];   

    for (int i = 1; i < N; i++) {
        if (arr[i] - lastStallPos >= minAllowedDist) {
            cows++;
            lastStallPos = arr[i];
            if (cows == C) return true;
        }
    }
    return false;
}


int getDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end());

    int minVal = arr[0];
    int maxVal = arr[N - 1];

    int st = 1, end = maxVal - minVal, ans = 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (ispossible(arr, N, C, mid)) { 
            ans = mid;
            st = mid + 1;
        } else {                        
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout << getDistance(arr, N, C) << endl;

    return 0;
}
