bool nextPermutation(string& nums) {
    if(nums.empty()) return false;
    int i=nums.size()-1;
    while(i>=1 && nums[i]<=nums[i-1]) i--;
    if(i==0) return false; // no next permutation, i.e. already largest
    
    int j=nums.size()-1;
    while(nums[j]<=nums[i-1]) j--;
    swap(nums[i-1],nums[j]);
    
    reverse(nums.begin()+i,nums.end());
    return true;
}