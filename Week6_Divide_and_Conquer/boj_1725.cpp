#include <iostream>
using namespace std;
constexpr int N = 100'001;

int n, a[N];

long long get_answer(int left, int right) {
    if(left >= right) return a[right];
    int mid = (left + right) / 2;
    long long ans_left = get_answer(left, mid),
    ans_right = get_answer(mid + 1, right),
    ans = ans_left > ans_right ? ans_left : ans_right;

    int l = mid - 1, r = mid + 1; 
    long long cur_min = a[mid], width = 1;
    ans = ans > cur_min ? ans : cur_min;
    while(l >= left && r <= right) {
        if(a[l] > a[r]) {
            if(a[l] < cur_min) cur_min = a[l];
            l--;
        }
        else {
            if(a[r] < cur_min) cur_min = a[r];
            r++;
        }
        ++width;
        if(cur_min * width > ans) ans = cur_min * width;
    }
    while(l >= left) {
        if(a[l] < cur_min) cur_min = a[l];
        l--;  
        ++width;
        if(cur_min * width > ans) ans = cur_min * width;
    }
    while(r <= right) {
        if(a[r] < cur_min) cur_min = a[r];
        r++;        
        ++width;
        if(cur_min * width > ans) ans = cur_min * width;
    }
    
    return ans;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; cin >> a[++i]);
    cout << get_answer(1, n);
}