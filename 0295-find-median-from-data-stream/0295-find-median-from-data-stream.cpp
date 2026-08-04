class MedianFinder {
public:
    priority_queue<int> left;//left_max_heap;
    priority_queue<int, vector<int>,greater<int>> right;//right_min_heap

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left.empty() || num< left.top())
        {
            left.push(num);
        }else{
            right.push(num);
        }

        // always main tain left max heap size one greater than right heap size
        //or both equal

        //if(left heap size is more than 1 greater size by right( means left 3 and right 1))
        //pop from left top insert in right

        if(abs((int)left.size()- (int)right.size())>1)
        {
            right.push(left.top());
            left.pop();
        }else if(left.size()< right.size()){//left size is small that right size (pop from right top insert in left)
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size())
        {
            //even len

            double mid= (left.top()+right.top())/2.0;
            return mid;
        }else{
            //odd len
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */