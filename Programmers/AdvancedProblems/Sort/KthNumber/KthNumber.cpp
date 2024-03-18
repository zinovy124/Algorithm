#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> count(101, 0);
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            result.push_back(i);
        }
    }

    return result;
}

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        int k = commands[i][0] - 1;
        int l = commands[i][1] - 1;
        int m = commands[i][2] - 1;
        vector<int> temp(array.begin() + k, array.begin() + l + 1);
        temp = countingSort(temp);
        answer.push_back(temp[m]);
    }

    return answer;
}

int main(void) {
    vector<int> arr = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> comm = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    vector<int> answer = solution(arr, comm);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}