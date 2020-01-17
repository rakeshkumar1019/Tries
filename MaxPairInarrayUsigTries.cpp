#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Trie{
	public:
	Trie* left;
	Trie* right;
};

void buildTrie(Trie* head,int val){
	
	Trie* curr=head;
	for(int i=31;i>=0;i--){
		int bit=(val>>i)&1;
		
		if(bit==0){
			if(!curr->left){
				curr->left=new Trie();
			}
			curr=curr->left;
		}else{
			if(!curr->right){
			    curr->right=new Trie();
			}
			curr=curr->right;
		}
	}
	
}

int  maxpairXor(Trie* head,int* arr,int n){
	int max_xor=INT_MIN;

	for(int i=0;i<n;i++){
			Trie* curr=head;
		int val=arr[i];
		int curr_xor=0;
	     for(int j=31;j>=0;j--){
	     	int bit=(val>>j)&1;
	     	
	     	if(bit==0){
            //right
               if(curr->right){
               	curr_xor+=pow(2,j);
               	curr=curr->right;
               	
			   }else{
			   	curr=curr->left;
			   }

			 }else{
             //left
                if(curr->left){
                	curr_xor+=pow(2,j);
                	curr=curr->left;
				}else{
					curr=curr->right;
				}
			 }
	     	
		 }
		 
		 if(curr_xor > max_xor){
		max_xor=curr_xor;
	}
		
	}
	
	
	
	return max_xor;
}
int main(){
	int n;
	cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	Trie* head=new Trie();
	for(int i=0;i<n;i++){
	
	buildTrie(head,arr[i]);
    }
    
    cout<<maxpairXor(head,arr,n);
}
