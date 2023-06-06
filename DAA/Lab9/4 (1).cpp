#include<iostream>

using namespace std;

void bubble(int arr[], int id[], int n){
    int temp;
    for(int i = 0; i<n-1; i++) for(int j = 0; j<n-1-i; j++) if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        temp = id[j];
        id[j] = id[j+1];
        id[j+1] = temp;
    }
    return;
}

void containerLoading(int weight[], int id[], int x[], int n, int c){
    int sum = 0;
    bubble(weight, id, n);
    for(int i = 0; i<n; i++){
        sum += weight[i];
        if(sum<c) x[id[i]] = 1;
        else break;
    }
    return;
}

int main(){
    cout<<"Container loader problem using backtracking.";
    cout<<"\nEnter the number of containers: ";
    int n, c;
    cin>>n;
    int weight[n], id[n], x[n] = {0};
    cout<<"Enter the capacity: ";
    cin>>c;
    cout<<"Enter the weights: ";
    for(int i = 0; i<n; i++) cin>>weight[i];
    for(int i = 0; i<n; i++) id[i] = i;
    containerLoading(weight, id, x, n, c);
    c = 0;
    for(int i = 0; i<n; i++){
        cout<<x[i]<<" ";
        c += x[i];
    }
    cout<<"Maximum possible containers using greedy method: "<<c;
    return 1;
}