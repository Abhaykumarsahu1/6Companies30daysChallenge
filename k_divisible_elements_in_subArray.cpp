#include <iostream>
#include <vector>
#include <set>
using namespace std;
int countDistinct(vector<int> &arr,int k,int p){
    int size = arr.size();
    set <string> st;
    for (int i = 0; i < size; i++)
    {
        int count =0;
        string s ="";
        for (int j = i; j < size; j++)
        {
            if (arr[j]%p==0) count++;
            if (count<=k)
            {
                s+=to_string(arr[j])+'.';
                st.insert(s);
            }
            else
            {
                break;
            }
            
            
        }
        
    }
    return st.size();
}
int main(){
    vector<int> arr ={2,3,3,2,2};
    cout<<"total sub_arrays in the set are: "<<countDistinct(arr,2,2);
    return 0;
}