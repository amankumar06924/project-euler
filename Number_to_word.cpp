#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){

    string s;
    cin >> s;
    map<int, string> mp = {{0, ""},
                           {1, "One"},
                           {2, "Two"},
                           {3, "Three"},
                           {4, "Four"},
                           {5, "Five"},
                           {6, "Six"},
                           {7, "Seven"},
                           {8, "Eight"},
                           {9, "Nine"},
                           {10, "Ten"},
                           {11, "Eleven"},
                           {12, "Twelve"},
                           {13, "Thirteen"},
                           {14, "Fourteen"},
                           {15, "Fifteen"},
                           {16, "Sixteen"},
                           {17, "Seventeen"},
                           {18, "Eighteen"},
                           {19, "Nineteen"},
                           {20, "Twenty"},
                           {30, "Thirty"},
                           {40, "Forty"},
                           {50, "Fifty"},
                           {60, "Sixty"},
                           {70, "Seventy"},
                           {80, "Eighty"},
                           {90, "Ninety"},
                           {100, "One Hundred"}};
                    
    // long long int num=stoi(s);
    // if(num==0){
    //     cout<<"zero"<<endl;
    // }
    // else{
    int n = s.size();
    //     int idx=0;
    //     while(s[idx]=='0'){
    //         // s.pop_back();
    //         idx++;
    //     }
    //     string cpy_s="";
    //     for(int i=idx;i<n;++i){
    //         cpy_s+=s[i];
    //     }
    //     cout<<cpy_s<<endl;
    //     s=cpy_s;
    reverse(s.begin(), s.end());
    // n=s.size();
    string ans="";
    for (int i = n; i >= 1;i--)
    
    {

        int pos = i % 3;
        int blg = i / 3 + (i % 3 == 0 ? 0 : 1);
        if (blg == 1)
        {
            if (pos == 0 &&s[i-1]!='0')
            {
                int st = (s[i - 2] - '0') * 10 + (s[i - 3] - '0');
                if (mp[st] != "")
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred "+ mp[st];
                }
                else
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred " + mp[(s[i - 2] - '0') * 10] + " " + mp[s[i - 3] - '0'];
                }
                i-=2;
            }
            else if (pos == 2 && s[i-1]!='0')
            {
                int st = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');
                if (mp[st] != "")
                {
                    ans += mp[st];
                }
                else
                {
                    ans += mp[(s[i - 1] - '0') * 10] + " " + mp[s[i - 2] - '0'];
                }

                i -= 1;
            }
            else if (pos == 1 && s[i-1]!='0')
            {
                ans += mp[s[i - 1] - '0'];
            }
        }
        else if (blg == 2)
        {
            if (pos == 0 && s[i-1]!='0')
            {
                 int st = (s[i - 2] - '0') * 10 + (s[i - 3] - '0');
                if (mp[st] != "")
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred " + mp[st]+" Thousand ";
                }
                else
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred " + mp[(s[i - 2] - '0') * 10] + " " + mp[s[i - 3] - '0']+" Thousand ";
                }
                i -= 2;
            }
            else if (pos == 2 && s[i-1]!='0')
            {
                int st = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');
                if (mp[st] != "")
                {
                    ans += mp[st]+" Thousand ";
                }
                else
                {
                    ans += mp[(s[i - 1] - '0') * 10] + " " + mp[s[i - 2] - '0']+" Thousand ";
                }

                i -= 1;
            }
            else if (pos == 1&&s[i-1]!='0')
            {
                ans += mp[s[i - 1] - '0']+" Thousand ";
            }
            // ans += " Thousand ";
        }
        else if (blg == 3)
        {
            if (pos == 0 && s[i-1]!='0')
            {
                 int st = (s[i - 2] - '0') * 10 + (s[i - 3] - '0');
                if (mp[st] != "")
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred "+ mp[st]+" Million ";
                }
                else
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred " + mp[(s[i - 2] - '0') * 10] + " " + mp[s[i - 3] - '0']+" Million ";
                }
                i -= 2;
            }
            else if (pos == 2 && s[i-1]!='0')
            {
                int st = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');
                if (mp[st] != "")
                {
                    ans += mp[st]+" Million ";
                }
                else
                {
                    ans += mp[(s[i - 1] - '0') * 10] + " " + mp[s[i - 2] - '0']+" Million ";
                }

                i -= 1;
            }
            else if (pos == 1 && s[i-1]!='0')
            {
                ans += mp[s[i - 1] - '0']+" Million ";
            }
            // ans += " Million ";
        }
        else if (blg == 4)
        {
            if (pos == 0 && s[i-1]!='0')
            {
                 int st = (s[i - 2] - '0') * 10 + (s[i - 3] - '0');
                if (mp[st] != "")
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred "+ mp[st]+ " Billion ";
                }
                else
                {
                    ans += mp[s[i - 1] - '0'] + " Hundred " + mp[(s[i - 2] - '0') * 10] +" "+ mp[s[i - 3] - '0']+ " Billion ";
                }
                i -= 2;
            }
            else if (pos == 2 && s[i-1]!='0')
            {
                int st = (s[i - 1] - '0') * 10 + (s[i - 2] - '0');
                if (mp[st] != "")
                {
                    ans += mp[st]+ " Billion ";
                }
                else
                {
                    ans += mp[(s[i - 1] - '0') * 10] + " " + mp[s[i - 2] - '0']+ " Billion ";
                }

                i -= 1;
            }
            else if (pos == 1 && s[i-1]!='0')
            {
                ans += mp[s[i - 1] - '0']+ " Billion ";
            }
            // ans += " Billion ";
        }
    }
    string final_ans="";
    int cnt=0;
    //map<int,int>mp1;
    for(int i=0;i<ans.size();++i){
        if(ans[i]==' '){
            cnt+=1;
            // mp1[i]=cnt;
            if(cnt<=1){
                final_ans+=ans[i];
            }
        }
        else if(ans[i]!=' '){
            cnt=0;
            final_ans+=ans[i];
        }
    }
    cout<<(final_ans==""?"zero":final_ans)<< endl;
    //}
  }
    return 0;
}