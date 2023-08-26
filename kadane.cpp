#include<bits/stdc++.h>
using namespace std;
int kadane(int* arr, int n,int& max, int& start_index, int& end_index, int& temp_start_index){
    int current = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>(arr[i]+current)){
            temp_start_index = i;
            current = arr[i];
        }else{
            current += arr[i];
        }
        if(current>max){
            end_index = i;
            max = current;
            start_index = temp_start_index;
        }
    }
    return max, start_index, end_index;
}
int main(){
    int n;
    int start_index = 0, end_index = 0, temp_start_index = 0, max=0;
    cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    kadane(arr, n,max, start_index, end_index, temp_start_index);
    cout<<max<<endl;
    for(int i=start_index;i<=end_index;i++){
        cout<<arr[i]<<" ";
    }
}