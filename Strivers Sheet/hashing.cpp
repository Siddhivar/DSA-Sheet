#include <bits/stdc++.h>
using namespace std;

void countFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (auto it : freq)
    {
        cout << it.first << " : " << it.second << endl;
    }
}

void maxMinFrequency(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int maxFreq = 0, minFreq = n;
    int maxEle = -1, minEle = -1;
    for (auto it : freq)
    {
        int element = it.first;
        int count = it.second;
        if (count > maxFreq)
        {
            maxFreq = count;
            maxEle = element;
        }
        if (count < minFreq)
        {
            minFreq = count;
            minEle = element;
        }
    }
    cout << "Max Element is: " << maxEle << endl;
    cout << "Min Element is: " << minEle << endl;
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, size);
    maxMinFrequency(arr, size);
    return 0;
}