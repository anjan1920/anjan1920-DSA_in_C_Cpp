c
lass Solution {
    public:
        int missingNumber(vector<int>& nums) {
    
            //first we find the total sum of the array 
            //then find the actual sum by formula from 1  to n
            //expected sum = n(n+1)/2
            //and the diff of them will be the missing element 
    
            int n = nums.size();
            int calculated_sum = 0;
    
            for(int i=0 ;i<n ;i++ ){
    
                calculated_sum =  calculated_sum + nums[i];
            }
            //find the expected sum
            
            int expected_sum=  n *(n+1)/2;
    
            return (expected_sum - calculated_sum );
            
        }
    };