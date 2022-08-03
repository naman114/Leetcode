/*
TC: O(queries * log(events))
SC: O(events)
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