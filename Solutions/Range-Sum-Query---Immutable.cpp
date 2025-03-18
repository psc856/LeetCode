//Method -1 -> T(c) -> O(n)  + O(n) -> constructor + SumRange Function
/*
class NumArray {
    vector<int> myArr; //create a variable of class
public:
    NumArray(vector<int>& nums) {
        myArr=nums; //initialise variable with parameter passed
    }
    
    int sumRange(int left, int right) {
        int n=this->myArr.size();
        int ans=0;
        for(int i=left;i<=right;i++){  //loop from left to right and summing up altogether
            ans+=this->myArr[i];
        }
        return ans;
    }
};
*/

//method->2 -> T(c) -> O(n)  + O(1) -> constructor + SumRange Function
class NumArray {
    vector<int> myArr; //create a variable of class
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        myArr.resize(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            myArr[i]=sum;  //storing the sum till that term
        }
        
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return myArr[right];
        return (myArr[right] - myArr[left-1]); //returning the middle part(range) sum only 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */