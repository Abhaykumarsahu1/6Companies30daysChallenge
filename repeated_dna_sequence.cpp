#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        int n = s.size();
        vector<string> ans; // to store the final answer
        if (n <= 10)
            return ans;

        unordered_map<string, int> sequencesCount; // key value pair of answer and string storing in it.

        for (int i = 0; i <= n - 10; ++i)//we ensure that we only consider starting positions where we have enough characters ahead to form a 10-letter sequence without going beyond the string's bounds.
        {
            string currentSequence = s.substr(i, 10); //storing the characters first till 10th index 
            sequencesCount[currentSequence]++; //and incrementing it by 1
            if (sequencesCount[currentSequence] == 2) //if the counts is 2 that means duplicate are present and return them
            {
                ans.push_back(currentSequence);
            }
        }

        return ans;
    }
};

int main()
{
    string input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    Solution solution;
    vector<string> repeatedSequences = solution.findRepeatedDnaSequences(input);

    cout << "Repeated DNA sequences of length 10 in the input string:" << endl;
    for (const string &sequence : repeatedSequences)
    {
        cout << sequence << endl;
    }

    return 0;
}
