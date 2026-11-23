class ProductOfNumbers {
public:

    vector<int> stream; // maintain prefix product array

    ProductOfNumbers() {
        stream = {1};// strating with 1(bcz on product)
    }

    void add(int num) {
        if (num == 0) { // clean the array
            stream = {1};
        } else { // add with prefix
            stream.push_back(stream.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= (int)stream.size()) { 
            return 0; // A 0 appeared inside the last k numbers
        }
        return stream.back() / stream[stream.size() - 1 - k]; // for last k devide k-1 position of stream(for sum we minus and for product we devide)
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */