#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool ispossible(vector<int> &arr, int n, int m, int maxAllowedTime) {
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxAllowedTime) return false; 
        if (time + arr[i] <= maxAllowedTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
            if (painters > m) return false;
        }
    }
    return true;
}

int minTimeToPaint(vector<int> &arr, int n, int m) {
    int sum = 0, maxval = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxval = max(maxval, arr[i]);
    }

    int st = maxval, end = sum;
    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (ispossible(arr, n, m, mid)) {
            end = mid - 1; 
        } else {
            st = mid + 1;  
        }
    }
    return st; 
}

int main() {
    vector<int> arr = {40, 30, 10, 20};
    int n = arr.size();
    int m = 2;

    cout << "Minimum time to paint: " << minTimeToPaint(arr, n, m) << endl;
    return 0;
}
