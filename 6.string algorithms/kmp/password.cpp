#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string str){
    int n = str.size();
    vector<int> dp(n, 0);
    for(int i = 1; i < n; i++){
        int ll = dp[i-1];
        while(ll > 0 && str[ll] != str[i]) ll = dp[ll-1];
        if(ll == 0)
            dp[i] = (str[i] == str[ll]) ? 1 : 0;
        else dp[i] = ll + 1;
    }
    return dp;
}

int main(){
    string str;
    cin >> str;
    vector<int> pi = kmp(str);
    map<int, int> freq;
    for(auto num : pi){
      freq[num]++;
    }
    int ll = pi[str.size()-1];
    if(ll == 0) cout << "Just a legend" << endl;
    else if(freq[ll] > 1) cout << str.substr(0, ll) << endl;
    else{
      ll = pi[ll-1];
      while(ll != 0){
          if(freq[ll]) break;
          ll = pi[ll-1];
      }
      if(ll == 0) cout << "Just a legend" << endl;
      else cout << str.substr(0, ll) << endl;
    }
}