#include <iostream>
#include <deque>
#include <unordered_map>

using namespace std;

class DataStream {
    //variables
    deque<int> dq;
    unordered_map<int,int>mp;
    int value;
    int k;
public:
    //intialise
    DataStream(int value, int k) {
        this -> value = value;
        this -> k = k;
        dq.clear();
        mp.clear();
    }
    
    bool consec(int num) {
        mp[num]++; //add number in map
        dq.push_back(num); //add number in deque
        bool ans = (mp.size() == 1 && dq.size() == k && num == value); //check answer
        if(dq.size() == k){ // remove the first element here
            int front = dq.front();
            dq.pop_front();
            mp[front]--;
            if(mp[front] == 0){ // remove key from map if frequency is zero
                mp.erase(front);
            }
        }
        return ans;
    }
};

int main() {
    int value = 5; // Set the value you want to check for consecutiveness
    int k = 3; // Set the size of the consecutive window

    DataStream* obj = new DataStream(value, k);

    // Test the consecutive function
    cout << obj->consec(5) << endl; // Assuming 5 is the input number
    cout << obj->consec(2) << endl; // Assuming 2 is the input number
    cout << obj->consec(5) << endl; // Assuming 5 is the input number
    cout << obj->consec(5) << endl; // Assuming 5 is the input number

    delete obj; // Remember to delete the object when done
    return 0;
}
