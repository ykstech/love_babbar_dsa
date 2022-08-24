#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print_deque(deque<int> dq){
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}

void print_vector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

vector<int> first_negative_int(vector<int> a,int n,int k){

   deque<int> dq;
   vector<int> ans;

   //process first//
   for(int i=0;i<k;i++){
    if(a[i]<0){
        dq.push_back(i);
    }
   }

   //store ans//
   if(dq.size()>0){
    ans.push_back(a[dq.front()]);
   }else{
    ans.push_back(0);
   }

   //process remaining//
   for(int i=k;i<n;i++){

      if(!dq.empty() && i-dq.front()>=k){
        dq.pop_front();
      }
      if(a[i]<0){
        dq.push_back(i);
      }

      
   //store ans//
   if(dq.size()>0){
    ans.push_back(a[dq.front()]);
   }else{
    ans.push_back(0);
   }
   }

   return ans;



}

int check(deque<int> dq){
if(!dq.empty()){
return dq.front();
}else{
return 0;
}

    
}


vector<int> my_fn(vector<int> v,int n,int k){

deque<int> dq;

deque<int> mdq;
vector<int> ans;


for(int i=0;i<k;i++){
    if(v[i]<0){
    mdq.push_back(i);

    }
    dq.push_back(v[i]);


}
   int x= check(mdq);
   ans.push_back(v[x]);

 //  print_vector(ans);
  // print_deque(mdq);
 //  print_deque(dq);

for(int i=k;i<n;i++){
    dq.pop_front();
    dq.push_back(v[i]);
    if((i-k ) == mdq.front()){
  //  cout<<"hit"<<endl;
    mdq.pop_front();
    }
    if(v[i]<0){
    mdq.push_back(i);

    }
    int x= check(mdq);
    ans.push_back(v[x]);
     //  print_vector(ans);
    //   print_deque(mdq);
   
//   cout<<endl;

}

return ans;

}



int main(){

vector<int> v={-8,-2,3,-6,10,-9,5};
print_vector(v);

print_vector(my_fn(v,7,3));
print_vector(first_negative_int(v,7,3));
}