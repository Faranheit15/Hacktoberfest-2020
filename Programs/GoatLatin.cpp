#include<bits/stdc++.h>
using namespace std;
string toGoatLatin(string S){
        string res,str;
        string ch="a",ma="ma";
        S=S+" ";
        int size=S.size();
        for(int i=0;i<size;i++){
            if(S[i]==' '){   
                if(str[0]=='A'||str[0]=='E'||str[0]=='I'||str[0]=='O'||str[0]=='U'||
                   str[0]=='a'||str[0]=='e'||str[0]=='i'||str[0]=='o'||str[0]=='u') str+=ma;
                else{
                    str=str.substr(1)+str[0]+ma;
                }
                res+=str+ch+" ";
                ch+="a";
                str="";
            }
            else str+=S[i];
        }
        res.pop_back();
        return res;
    }
    int main(){
      string s;
      cin>>s;
      cout<<toGoatLatin(s)<<endl;
      return 0;
    }
