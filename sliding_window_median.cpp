/*
Given an array of numbers and a number ‘k’, find the median of all the ‘k’ sized sub-arrays (or windows) of the array.
*/
#include<bits/stdc++.h>
using namespace std;

template <typename T, class Container = vector<T>,
            class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
    public:
    bool remove(const T &valueToRemove) {
        auto itr=std::find(this->c.begin(), this->c.end(), valueToRemove);
        if(itr == this->c.end()) {
            return false;
        }
        this->c.erase(itr);
        std::make_heap(this->c.begin(), this->c.end(), this->comp);
        return true;
    }
};
class MedianOfWindow{
    public:
    priority_queue_with_remove<int> maxHeap;
    priority_queue_with_remove<int, vector<int>, greater<int>> minHeap;
    void balanceHeaps() {
        if(maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    vector<float> findSlidingWinMedian(vector<int> input, int k) {
        int start=0;
        vector<float> ans;
        for(int end=0; end<input.size(); end++) {
            if(maxHeap.empty() || input[end] <= maxHeap.top()) {
                maxHeap.push(input[end]);
            } else {
                minHeap.push(input[end]);
            }

            balanceHeaps();

            if(end-start+1>=k) {
                if(maxHeap.size()==minHeap.size()) {
                    ans.push_back((minHeap.top() + maxHeap.top())/2.0);
                } else {
                    ans.push_back(maxHeap.top());
                }

                // remove end[start] from the heap
                if(input[start] <= maxHeap.top()) {
                    maxHeap.remove(input[start]);
                } else {
                    minHeap.remove(input[start]);
                }
                start++;
                balanceHeaps();
            }
        }
        return ans;
    }
};

int main() {
    MedianOfWindow obj;
    vector<float> ans=obj.findSlidingWinMedian({1, 2, -1, 3, 5}, 2);
    for(int index=0; index<ans.size(); index++) {
        cout<<ans[index]<<endl;
    }
    // Figure out a way to implement remove operation in stl heap
    return 0;
}