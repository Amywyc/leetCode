/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    void swap(Interval& num1,Interval& num2){
		int tmp;
		tmp=num1.start;
		num1.start=num2.start;
		num2.start=tmp;
		tmp=num1.end;
		num1.end=num2.end;
		num2.end=tmp;
	}
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int size=intervals.size()-1;
		intervals.push_back(newInterval);
		while(size>=0){
			//case1
			if(intervals[size+1].start>intervals[size].end)
				break;
			//case2
			if((intervals[size+1].start>=intervals[size].start)
				&&(intervals[size+1].start<=intervals[size].end)){
					if(intervals[size+1].end>=intervals[size].end){
						intervals[size].end=intervals[size+1].end;
						
					}
					intervals.erase(intervals.begin()+size+1);
					break;
			}
			//case3
			if(intervals[size+1].start<intervals[size].start){
				if(intervals[size+1].end<intervals[size].start){
					swap(intervals[size],intervals[size+1]);
				}else {
					if((intervals[size+1].end>=intervals[size].start)
					&&(intervals[size+1].end<=intervals[size].end)){
						intervals[size+1].end=intervals[size].end;
					}
					intervals.erase(intervals.begin()+size);
				}
			}
			size--;
		}
		return intervals;
    }
};