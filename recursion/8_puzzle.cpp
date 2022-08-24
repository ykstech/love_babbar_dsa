#include<iostream>
#include <bits/stdc++.h>

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

 vector<int>  findpossiblemoves(int pos,vector<int>& zeropos){
     
   vector<int>  ans;
   switch (pos)
   {
   case 0: 
   if(zeropos.at(1)==0){
    ans.push_back(1);
    zeropos.at(1)=1;
   }
   if(zeropos.at(3)==0){
     ans.push_back(3);
     zeropos.at(3)=1;
   }
    break;
   case 1: 
   if(zeropos.at(0)==0){
    ans.push_back(0);
    zeropos.at(0)=1;
   }
   if(zeropos.at(2)==0){
     ans.push_back(2);
     zeropos.at(2)=1;
   }
   if(zeropos.at(4)==0){
    ans.push_back(4);
    zeropos.at(4)=1;
   }
   
       break;
   case 2:
   if(zeropos.at(1)==0){
    ans.push_back(1);
    zeropos.at(1)=1;
   }
   if(zeropos.at(5)==0){
    ans.push_back(5);
    zeropos.at(5)=1;
   }
   
       break;

   case 3:
   
   if(zeropos.at(4)==0){
    ans.push_back(4);
    zeropos.at(4)=1;
   }
   if(zeropos.at(0)==0){
    ans.push_back(0);
    zeropos.at(0)=1;
   }
   if(zeropos.at(6)==0){
    ans.push_back(6);
    zeropos.at(6)=1;
   }
   
       break;
   case 4: 
   
   if(zeropos.at(3)==0){
    ans.push_back(3);
    zeropos.at(3)=1;
   }
   if(zeropos.at(5)==0){
    ans.push_back(5);
    zeropos.at(5)=1;
   }
   if(zeropos.at(1)==0){
    ans.push_back(1);
    zeropos.at(1)=1;
   }
   if(zeropos.at(7)==0){
    ans.push_back(7);
    zeropos.at(7)=1;
   }
       break;
   case 5: 
   if(zeropos.at(4)==0){
    ans.push_back(4);
    zeropos.at(4)=1;
   }
   if(zeropos[2]==0){
    ans.push_back(2);
    zeropos[2]=1;
   }
   if(zeropos[8]==0){
    ans.push_back(8);
    zeropos[8]=1;
   }
   
       break;
   case 6: 
   
   if(zeropos[7]==0){
    ans.push_back(7);
    zeropos[7]=1;
   }
   if(zeropos[3]==0){
    ans.push_back(3);
    zeropos[3]=1;
   }
   
       break;
   case 7:
   
   if(zeropos[6]==0){
    ans.push_back(6);
    zeropos[6]=1;
   }
   if(zeropos[8]==0){
    ans.push_back(8);
    zeropos[8]=1;
   }
   if(zeropos[4]==0){
    ans.push_back(4);
    zeropos[4]=1;
   }
   
   
       break;
   case 8: 
   if(zeropos[7]==0){
    ans.push_back(7);
    zeropos[7]=1;
   }
   if(zeropos[8]==0){
    ans.push_back(8);
    zeropos[8]=1;
   }
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
    if(arr[i]!=final[i]){
        h++;
    }
}
return h;

}

void runner(vector<int> init,vector<int> final,vector<int>& zeropos){

//cout<<"iteration"<<endl;
    int n=9;
int pos=findpos(init, n);
vector<int> posvector= findpossiblemoves(pos,zeropos);


if(init==final || posvector.size()==0){
    return;
}



//printarray(posvector,posvector.size());
int minh=10;int minpos=0;
vector<vector<int>> subarrays;
for(int i=0;i<posvector.size();i++){

vector<int> subarr=swap(init,posvector[i],pos);
//printarray(subarr,n);
subarrays.push_back(subarr);
int h=heuristic(subarr,final);
if(minh>h){
    minh=h;
    minpos=i;
}

//cout<<h<<endl;
}
//cout<<minh<<" "<<minpos<<endl;
//printarray(zeropos,n);
vector<int> initf=subarrays.at(minpos); 
printarray(initf,n);
return runner(initf,final,zeropos);
}

int main(){

vector<int> init= {1,2,3,5,6,0,7,8,4}; int n=9;
vector<int> final={1,2,3,5,8,6,0,7,4};
vector<int> zeropos={0,0,0,0,0,1,0,0,0};

printarray(init,n);
runner(init,final,zeropos);


return 0;
}