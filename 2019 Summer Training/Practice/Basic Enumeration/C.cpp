#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char *argv[]){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int T;
    cin >> T;
    int a[21][21];
    int i,j;
    bool ch=true;
    while(T--){
        ch=true;
        for(i=0;i<21;i++){
            for(j=0;j<21;j++){
                if(i>=1&&i<20&&j>=1&&j<20){
                    cin >> a[i][j];
                }
                else{
                    a[i][j]=0;
                }
            }
        }
        if(ch){
            for(i=1;i<=19;i++){
                for(j=1;j<=15;j++){
                    if(a[i][j-1]!=1&&a[i][j]==1&&a[i][j+1]==1&&a[i][j+2]==1&&a[i][j+3]==1&&a[i][j+4]==1&&a[i][j+5]!=1){
                        cout << 1 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                    else if(a[i][j-1]!=2&&a[i][j]==2&&a[i][j+1]==2&&a[i][j+2]==2&&a[i][j+3]==2&&a[i][j+4]==2&&a[i][j+5]!=2){
                        cout << 2 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                }
                if(ch==false){
                    break;
                }
            }
        }
        if(ch){
            for(j=1;j<=19;j++){
                for(i=1;i<=15;i++){
                    if(a[i-1][j]!=1&&a[i][j]==1&&a[i+1][j]==1&&a[i+2][j]==1&&a[i+3][j]==1&&a[i+4][j]==1&&a[i+5][j]!=1){
                        cout << 1 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                    else if(a[i-1][j]!=2&&a[i][j]==2&&a[i+1][j]==2&&a[i+2][j]==2&&a[i+3][j]==2&&a[i+4][j]==2&&a[i+5][j]!=2){
                        cout << 2 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                }
                if(ch==false){
                    break;
                }
            }
        }
        if(ch){
            for(i=1;i<=19;i++){
                for(j=1;j<=19;j++){
                    if(i+4<=19&&j+4<=19&&a[i][j]==1&&a[i+1][j+1]==1&&a[i+2][j+2]==1&&a[i+3][j+3]==1&&a[i+4][j+4]==1&&a[i+5][j+5]!=1&&a[i-1][j-1]!=1){
                        cout << 1 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                    else if(i+4<=19&&j+4<=19&&a[i][j]==2&&a[i+1][j+1]==2&&a[i+2][j+2]==2&&a[i+3][j+3]==2&&a[i+4][j+4]==2&&a[i+5][j+5]!=2&&a[i-1][j-1]!=2){
                        cout << 2 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                }
                if(ch==false){
                    break;
                }
            }
        }
        if(ch){
            for(i=19;i>0;i--){
                for(j=1;j<=19;j++){
                    if(i-4>=0&&j+4<19&&a[i][j]==1&&a[i-1][j+1]==1&&a[i-2][j+2]==1&&a[i-3][j+3]==1&&a[i-4][j+4]==1&&a[i+1][j-1]!=1&&a[i-5][j+5]!=1){
                        cout << 1 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                    else if(i-4>=0&&j+4<19&&a[i][j]==2&&a[i-1][j+1]==2&&a[i-2][j+2]==2&&a[i-3][j+3]==2&&a[i-4][j+4]==2&&a[i+1][j-1]!=2&&a[i-5][j+5]!=2){
                        cout << 2 << endl;
                        cout << i << " " << j << endl;
                        ch=false;
                    }
                }
                if(ch==false){
                    break;
                }
            }
        }
        if(ch){
            cout << 0 << endl;
        }
    }
    return 0;
}
