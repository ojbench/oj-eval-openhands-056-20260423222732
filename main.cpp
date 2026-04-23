#include <iostream>
#include <set>
#include <utility>
using namespace std;

// Check if two intervals [a,b] and [c,d] overlap
bool overlap(int a, int b, int c, int d) {
    return a <= d && c <= b;
}

int main() {
    int n;
    cin >> n;
    
    set<pair<int, int>> intervals;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            
            // Find and remove all overlapping intervals
            int count = 0;
            auto it = intervals.begin();
            while (it != intervals.end()) {
                if (overlap(it->first, it->second, l, r)) {
                    it = intervals.erase(it);
                    count++;
                } else {
                    ++it;
                }
            }
            
            // Add the new interval
            intervals.insert({l, r});
            
            cout << count << endl;
        } else if (op == 'B') {
            cout << intervals.size() << endl;
        }
    }
    
    return 0;
}
