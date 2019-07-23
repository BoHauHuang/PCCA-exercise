#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(5);
    a.push_back(2);
    bool ch[8]={false},p=false;
    int i;
    do{
        p=true;
        for(i=0;i<8;i++){
            ch[i]=false;
        }
        for(i=0;i<a.size()-1;i++){
            if(((a[i]==1&&a[i+1]==2)||(a[i]==2&&a[i+1]==1))&&ch[0]==false){
                ch[0]=true;
            }
            else if(((a[i]==1&&a[i+1]==3)||(a[i]==3&&a[i+1]==1))&&ch[1]==false){
                ch[1]=true;
            }
            else if(((a[i]==1&&a[i+1]==5)||(a[i]==5&&a[i+1]==1))&&ch[2]==false){
                ch[2]=true;
            }
            else if(((a[i]==2&&a[i+1]==3)||(a[i]==3&&a[i+1]==2))&&ch[3]==false){
                ch[3]=true;
            }
            else if(((a[i]==2&&a[i+1]==5)||(a[i]==5&&a[i+1]==2))&&ch[4]==false){
                ch[4]=true;
            }
            else if(((a[i]==3&&a[i+1]==4)||(a[i]==4&&a[i+1]==3))&&ch[5]==false){
                ch[5]=true;
            }
            else if(((a[i]==4&&a[i+1]==5)||(a[i]==5&&a[i+1]==4))&&ch[6]==false){
                ch[6]=true;
            }
            else if(((a[i]==3&&a[i+1]==5)||(a[i]==5&&a[i+1]==3))&&ch[7]==false){
                ch[7]=true;
            }
            else{
                p=false;
                break;
            }
        }
        if(p){
            for(i=0;i<a.size();i++){
                cout << a[i];
            }
            cout << endl;
        }
    }while(next_permutation(a.begin()+1,a.begin()+8));
	return 0;
}

