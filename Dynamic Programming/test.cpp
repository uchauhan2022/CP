#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'palindromeChecker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY startIndex
 *  3. INTEGER_ARRAY endIndex
 *  4. INTEGER_ARRAY subs
 */
string f(string s, int n){
   string temp = s;
   //cout<<"string :"<<s<<endl;
   reverse(temp.begin(), temp.end());
   for(int i = 0; i<(s.length()/2 + 1); i++){
     if(s[i]!=temp[i]){
       n--;
     }
     if(n<0){
       return "0";
     }
   }
   return "1";
 }


string palindromeChecker(string s, vector<int> startIndex, vector<int> endIndex, vector<int> subs) {

string ans="";
    for(int i=0;i<startIndex.size();i++)
    {
        int c=0;

            int st=startIndex[i];
            int end=endIndex[i];
            if(st>end)
            {
                swap(st,end);
            }

            string cur = s.substr(st,end-st+1);
            //cout<<cur<<endl;
            string temp = f(cur,subs[i]);
            cout<<temp;
            ans.append(f(cur,subs[i]));
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string startIndex_count_temp;
    getline(cin, startIndex_count_temp);

    int startIndex_count = stoi(ltrim(rtrim(startIndex_count_temp)));

    vector<int> startIndex(startIndex_count);

    for (int i = 0; i < startIndex_count; i++) {
        string startIndex_item_temp;
        getline(cin, startIndex_item_temp);

        int startIndex_item = stoi(ltrim(rtrim(startIndex_item_temp)));

        startIndex[i] = startIndex_item;
    }

    string endIndex_count_temp;
    getline(cin, endIndex_count_temp);

    int endIndex_count = stoi(ltrim(rtrim(endIndex_count_temp)));

    vector<int> endIndex(endIndex_count);

    for (int i = 0; i < endIndex_count; i++) {
        string endIndex_item_temp;
        getline(cin, endIndex_item_temp);

        int endIndex_item = stoi(ltrim(rtrim(endIndex_item_temp)));

        endIndex[i] = endIndex_item;
    }

    string subs_count_temp;
    getline(cin, subs_count_temp);

    int subs_count = stoi(ltrim(rtrim(subs_count_temp)));

    vector<int> subs(subs_count);

    for (int i = 0; i < subs_count; i++) {
        string subs_item_temp;
        getline(cin, subs_item_temp);

        int subs_item = stoi(ltrim(rtrim(subs_item_temp)));

        subs[i] = subs_item;
    }

    string result = palindromeChecker(s, startIndex, endIndex, subs);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
