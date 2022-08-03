/*
TC: O(queries * log(events))
SC: O(events)

Approach:
1. Map stores (end, start)
2. Consider some events have been added and you get a query (start, end)
3. Visualize the map on a number line with keys as end times
4. Let's say you get the "next interval's end time" to your query start time using upper_bound
5. Lower bound of start would be useless because if some end time is equal to query start, it won't overlap ATQ
6. Now, you have used query start time and next interval's end time. To check for overlap, just compare
   query end time and next interval's start time
7. Also, if you didn't find an end time to your query start time, that means all existing intervals ended before
   your start time, Hence no overlap
*/

class MyCalendar {
    map<int, int> mp;
    // Stores end, start
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = mp.upper_bound(start);
        if(next != mp.end() && end > next->second) return false;
        mp[end] = start;
        return true;
    }
};

/*

TC: O(queries * events)
SC: O(events)

class MyCalendar {
    vector<pair<int, int>> events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto event: events){
            if(start < event.second && end > event.first)
                return false;
        }
        events.push_back({start, end});
        return true;
    }
};
*/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */