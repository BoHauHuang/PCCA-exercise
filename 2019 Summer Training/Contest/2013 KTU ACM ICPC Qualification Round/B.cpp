#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
 
using namespace std;
 
int main(){
    int T;
    cin >> T;
    int c=1;
    long long a[8];
    double area,p;
    int i;
    while(T--){
        for(i=0;i<8;i++){
            cin >> a[i];
        }
        cin >> p;
        area=abs((a[3]-a[7])*(a[0]-a[4])+(a[1]-a[5])*(a[6]-a[2]));
        area/=2;
 
        double ans = p / area;
        area += 0.005;
 
        cout << "Case #" << c << ": ";
        cout << fixed << setprecision(2) << ans << endl;
        c++;
    }
    return 0;
}
