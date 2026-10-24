class Solution {
public:
    int toDay (string s, vector <int>& prefixmonth)
    {
        // extracting day and month from the string
        int day = stoi (s.substr (3,5));        
        int month = stoi (s.substr (0,2));

        // taking prev month and adding days of curr month to it, therefore if curr month is january therefore taking 0 and curr month (january) days to it
        return (month == 1? 0 : prefixmonth[month-2]) + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector <int> prefixmonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    // days in every month
        int calculate = 0;  

        // storing the days till that month including curr month, means 31, 31+28, 31+28+31, 31+28+31+30, ....
        for (int i=0; i<prefixmonth.size(); i++)
        {
            calculate += prefixmonth[i];
            prefixmonth[i] = calculate;
        }

        // finding the date among whole 365 days, with the help of our prefixmonth vector
        int start_alice = toDay (arriveAlice, prefixmonth); 
        int end_alice = toDay (leaveAlice, prefixmonth);
        int start_bob = toDay (arriveBob, prefixmonth);
        int end_bob = toDay (leaveBob, prefixmonth);

        int start = max (start_alice, start_bob);   // who came arrived last
        int end = min (end_alice, end_bob);         // who leaved first

        return max (0, end-start+1);    // if it goo in -ve, means they never meet hence return 0     
    }
};