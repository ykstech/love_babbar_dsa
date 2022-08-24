#include<bits/stdc++.h>
using namespace std;

class trinode{
    public:
    char data;
    trinode* children[26];
    bool isterminal;

    trinode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }
};

class tri{
    public:
    trinode* root;

    tri(){
        root= new trinode('\0');
        
    }

    void insertutil(trinode* root,string word){
        //base case//
          if(word.length()==0){
            root->isterminal=1;
            return;
          }
          
          int index = word[0]-'a';
          trinode* child;

          if(root->children[index] != NULL){
            child = root->children[index];
          }
          else{
            child = new trinode(word[0]);
            root->children[index] = child;
          }

          insertutil(child,word.substr(1));
    }

    void insertword(string word){
        insertutil(root,word);
    }

    void printSuggestions(trinode* curr,vector<string> &temp,string prefix){

      if(curr->isterminal){
     //     cout<<prefix<<endl;
          temp.push_back(prefix);
          
      }
          //loop to change branch//
        for(char ch ='a'; ch<='z';ch++){
            trinode* next= curr->children[ch-'a'];
             
            if(next!=NULL){
                prefix.push_back(ch);
                cout<<prefix<<endl;
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string str){
        trinode* prev = root;
        vector<vector<string>> output;
        string prefix="";

        for(int i=0;i<str.length();i++){

             char lastch = str[i];
             prefix.push_back(lastch);

             trinode* curr= prev->children[lastch-'a'];
             
             if(curr==NULL){
                break;
             }

             vector<string> temp;
             
             printSuggestions(curr,temp,prefix);

             output.push_back(temp);
             temp.clear();
             prev=curr;

        }
         return output;
    }

};



vector<vector<string>> phone_directory(vector<string> &contactlist,string &query){

tri* t=new tri();

for(int i=0;i<contactlist.size();i++){
    string str=contactlist[i];
    t->insertword(str);
}

return t->getSuggestions(query);
}
int main(){

vector<string> contact_list={"code","codeing","codel","coe"};
string query="c";

vector<vector<string>> ans= phone_directory(contact_list,query);
cout<<"\n ans"<<endl;
for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }



}