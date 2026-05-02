#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

// Leetcode 539 - Problem Statement:Minimum Time Difference
// The problem is to find the minimum time difference between any two time points in a list of time points.
// Each time point is given in "HH:MM" format, and the time points are
//consider the circular nature of the 24-hour clock.

//example: timePoints = ["23:59", "00:00", "01:30", "22:00"]
//the minimum time difference is between "23:59" and "00:00", which is 1 minute.


int findMinDifference(vector<string>& timePoints) {
    //first we convert the times to minutes
    //THEN  sort the minutes so that we can get the right order
    // i.e day starts at 00:00 and ends at 23:59
    vector<string> times = timePoints;
    vector<int> minutes;
    for (int i = 0; i < times.size(); i++) {
        int hour = stoi(times[i].substr(0, 2));//from 0 indx to 2 size '23:59'->23
        int minute = stoi(times[i].substr(3, 2));//from 3 to .. 59
        int total_minute = hour * 60 + minute;
        minutes.push_back(total_minute);
    }

    // sort minutes
    sort(minutes.begin(), minutes.end());

    int minDiff = INT_MAX;

    // compute normal differences of the adjacent minutes i.e 2:20 - 2:10 = 10
    for (int i = 0; i < minutes.size() - 1; i++) {
        int normalDiff = minutes[i + 1] - minutes[i];
        minDiff = min(minDiff, normalDiff);
    }
    /***/
    //Since the day is circular,
    // we need to consider the difference between the last and first minutes also
    //cause the first and last time in our list will give  the min circular difference
    //total minutes in a day = 24*60 = 1440 i.e 0:00 to 24:00 time 
    //so the time diff from our list end time to mid of night = 1440 - our last time
    //and time diff from mid night  to our first time  is first time -00:00

    //i.e total circular time diff = [24:00(mid nigth )-list end time to ] + ..
    //..[list first time - mid night 00:00]
    //circular_diff =  1400 - last time + first time - 0:00
    int circularDiff = (1440 - minutes.back() + minutes[0]);
    minDiff = min(minDiff, circularDiff);

    return minDiff;
}

int main() {
    vector<string> timePoints = {"23:59", "00:00", "01:30", "22:00"};
    int result = findMinDifference(timePoints);
    cout << "Minimum difference in minutes: " << result << endl;
    return 0;
}
