#include <bits/stdc++.h>
using namespace std;
class trie{
    public:
    bool endword;
    trie* character[128];
    trie(){
        this->endword = false;
        for(int i = 0; i<128;i++){
            this->character[i]=NULL;
        }
    }
    void insert(string s){
        trie* cur = this;
        for(int i = 0; i<s.length(); i++){
          if(cur->character[s[i]]==NULL){
            cur->character[s[i]]= new trie();
          }
          cur=cur->character[s[i]];
        }
        cur->endword=true;
    }
    bool search(string s){
      trie* cur = this;
      if(cur==NULL) return false;
      for(int i = 0; i<s.length(); i++){
        if(cur->character[s[i]]==NULL)  return false;
      }
      return cur->endword;
    }
}
int main() {
	
	return 0;
}
