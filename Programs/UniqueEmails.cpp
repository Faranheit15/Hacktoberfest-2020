#include<bits/stdc++.h>
using namespace std;
int numUniqueEmails(vector<string>& e) {
        int size=e.size();
        set<string>res;
        string s="";
        for(int i=0;i<size;i++){
            for(int j=0;j<e[0].size();j++){
                s+=e[i][j];
                 cout<<s<<endl;
            }
        }   
    return size;
 }
 int main(){
    int n;cin>>n;
    string s;
    vector<int>emails(n);
    for(int i=0;i<n;i++){
      cin>>s;
      emails.push_back(s);
    }
    cout<<numUniqueEmails(emails)<<endl;
    return 0;
 }
