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

    bool searchutil(trinode* root,string word){
        if(word.length()==0){
            return root->isterminal;
        }

        int index= word[0]-'a';
        trinode* child;

        if(root->children[index]!=NULL){
            child= root->children[index];
        }else{
            return false;
        }
        return searchutil(child,word.substr(1));
    }

    bool searchword(string word){
   return  searchutil(root,word);
    }

    void deleteutil(trinode* root,string word){
        if(word.length()==0){
            if(root->isterminal){
              
             root->isterminal=false;
            }else{

            cout<<"does not exist"<<endl;
            }
             return;
        }
           trinode* child;
        int index= word[0]-'a';

         if(root->children[index]!=NULL){
         
          child= root->children[index];
         }else{
            
            cout<<"does not exist"<<endl;
            return;
         }
          deleteutil(child,word.substr(1));
          
        
    }
    
   void deleteword(string word){
     
        cout<<"search"<<endl;
       deleteutil(root,word);
    
   }

};


int main(){
tri *t=new tri();
t->insertword("arm");
t->insertword("do");
t->insertword("timer");
t->insertword("mer");
cout<<"present "<<t->searchword("do")<<endl;
t->deleteword("timer");
cout<<"present "<<t->searchword("mer")<<endl;


}