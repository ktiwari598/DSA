//
// Created by karan on 2/18/2024.
//
#include<bits/stdc++.h>

using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings) {
    int totalMeetings = meetings.size();
    sort(meetings.begin(), meetings.end());
    vector<long long> roomAvailability(n, 0);
    vector<int> ans(n, 0);
    for (int i = 0; i < totalMeetings; i++) {
        int start = meetings[i][0], end = meetings[i][1];
        bool foundUnused = false;
        long long minRoomAvailability = LLONG_MAX;
        int ind;
        for (int j = 0; j < n; j++) {
            if (roomAvailability[j] <= start) {
                foundUnused = true;
                roomAvailability[j] = end;
                ans[j]++;
                break;
            }
            if (roomAvailability[j] < minRoomAvailability) {
                minRoomAvailability = roomAvailability[j];
                ind = j;
            }
        }
        if (!foundUnused) {
            roomAvailability[ind] = roomAvailability[ind] + end - start;
            ans[ind]++;
        }
    }
    int ansIndex, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (ans[i] > maxi) {
            maxi = ans[i];
            ansIndex = i;
        }
    }
    return ansIndex;
}