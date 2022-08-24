#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;



int findpos(vector<int> init,int n){
   int i;
    for( i=0;i<n;i++){
        if(init[i]==0){
           break;
        }
    }
   return i;
}

 vector<int>  findpossiblemoves(int pos){
     
   vector<int>  ans;
   switch (pos)
   {
   case 0: 
   ans.push_back(3);

   ans.push_back(1);

    break;
   case 1:     ans.push_back(0);     ans.push_back(2);    ans.push_back(4);


 
   
       break;
   case 2:    ans.push_back(1);    ans.push_back(5);

  
       break;

   case 3:   ans.push_back(6); ans.push_back(4); ans.push_back(0);
   
   
 
   
       break;
   case 4:  ans.push_back(1);ans.push_back(3);ans.push_back(5);ans.push_back(7);
   
       break;
   case 5:ans.push_back(2);ans.push_back(4); ans.push_back(8);
   
       break;
   case 6: ans.push_back(7);ans.push_back(3); 
   
   
       break;
   case 7:ans.push_back(8); ans.push_back(6); ans.push_back(4);
   
   
   
       break;
   case 8: ans.push_back(7);ans.push_back(5);
    break;

   }
   
   return ans;
}

void printarray(vector<int> arr,int n){
  for(int i=0;i<n;i++){
      cout<<arr[i];
  }
  cout<<endl;
}

vector<int> swap(vector<int> arr,int i,int pos){

int temp=arr[i];
arr[i]=0;
arr[pos]=temp;

return arr; 

}

int heuristic(vector<int> arr,vector<int> final){
int h=0;
for(int i=0;i<arr.size();i++){
    if(arr[i] && arr[i] !=final[i]){
        h++;
    }
}
return h;

}

void runner(vector<int> init,vector<int> final,int prev,int count){

cout<<"iteration "<<count<<endl;
    int n=9;
int pos=findpos(init, n);

vector<int> posvector= findpossiblemoves(pos);

printarray(posvector,posvector.size());
cout<<"prevv "<<prev<<endl;
posvector.erase(std::remove(posvector.begin(), posvector.end(), prev), posvector.end());
prev=pos;
if(init==final || posvector.size()==0 ){
    cout<<"found"<<endl;
    return;
}



printarray(posvector,posvector.size());
int minh=10; vector<int> minpos;
vector<vector<int>> subarrays;
for(int i=0;i<posvector.size();i++){

vector<int> subarr=swap(init,posvector[i],pos);
printarray(subarr,n);
subarrays.push_back(subarr);
int h=heuristic(subarr,final);

minpos.push_back(h);


cout<<h<<endl;
}

for(int i=0;i<minpos.size();i++){
    if(minh>minpos[i]){
        minh=minpos[i];
    }
}

//printarray(minpos,minpos.size());

vector<int> minposm;
//cout<<minpos.size()<<endl;
//cout<<minh<<endl;

for(int i=0;i<minpos.size();i++){
    //cout<<minpos[i];
    if(minpos[i]==minh){
       minposm.push_back(i);
    }
}

printarray(minposm,minposm.size());

int temp = prev;
for(int i=0;i<minposm.size();i++){
cout<<"hi "<<i<<endl;
vector<int> initf=subarrays.at(minposm.at(i)); 

cout<<"prev "<<prev<<endl;
printarray(initf,n);
//printarray(zeropos,n);
count--;
 runner(initf,final,temp,count);
 

}

//cout<<minh<<" "<<minpos<<endl;
//printarray(zeropos,n);
}

int main(){

vector<int> init= {2,3,8,0,6,7,1,5,4}; int n=9;
vector<int> final={1,2,3,4,5,6,7,8,0};

printarray(init,n);
int count=5;
int prev=3;
runner(init,final,prev,count);


return 0;
}