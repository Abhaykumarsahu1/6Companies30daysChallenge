#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//mathematical approach.
pair<int,int> findingNumbers(vector<int> &arr){
        int n=arr.size();
        int squareSum = (n * (n + 1) * (2 * n + 1)) / 6;
        int sum = (n * (n + 1)) / 2;

          for (int i = 0; i < n; i++) {
        squareSum -= arr[i] * arr[i];
        sum -= arr[i];
    }

     int missingNumber = (squareSum / sum + sum) / 2;
    int duplicateNumber = missingNumber - sum;

    return make_pair(duplicateNumber,missingNumber);
}
int main(){
    vector<int> arr = {1,3,3};
    pair<int,int> result = findingNumbers(arr);
    cout<<"missing number is: "<< result.second<<endl;
    cout<<"duplicate number is: "<< result.first<<endl;

    return 0;
}