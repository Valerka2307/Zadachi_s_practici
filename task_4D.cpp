#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        
        s = "L" + s; 
        
        int curr = 0;
        bool success = true;
        
        while (curr <= n) {
            if (s[curr] == 'L') {
                bool found_log = false;
                

                for (int jump = min(m, n + 1 - curr); jump >= 1; --jump) {
                    if (curr + jump > n || s[curr + jump] == 'L') {
                        curr += jump;
                        found_log = true;
                        break;
                    }
                }
                
                if (!found_log) {
                    curr += m;
                }
            } 
            else if (s[curr] == 'W') {
                curr += 1;
                k -= 1;
                
                if (k < 0) {
                    success = false;
                    break;
                }
            } 
            else if (s[curr] == 'C') {
                success = false;
                break;
            }
        }

        if (success) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
