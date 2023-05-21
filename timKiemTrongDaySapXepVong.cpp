#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int h, int x) {
    if (h >= l) {
        int mid = (l + h) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, h, x);
    }
    return -1;
}

int findPivot(int arr[], int l, int h) {  //tim vi tri a[i] > a[i+1]
    if (h < l) return -1;
    if (h == l) return l;
    int mid = (l + h) / 2;
    if (mid < h && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > l && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[l] >= arr[mid])
        return findPivot(arr, l, mid - 1);
    return findPivot(arr, mid + 1, h);
}

int searchInSortedRotatedArray(int arr[], int n, int x) {
    int pivot = findPivot(arr, 0, n - 1);
    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, x);
    if (arr[pivot] == x)
        return pivot;
    if (arr[0] <= x)
        return binarySearch(arr, 0, pivot - 1, x);
    return binarySearch(arr, pivot + 1, n - 1, x);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << searchInSortedRotatedArray(arr, n, x) + 1 << endl;
    }
    return 0;
}

