class Solution {
public:
    int maxArea(vector<int>& height) {
        long long maxArea = 0;
        int left = 0; 
        int right = height.size() - 1; 
        while ( right > left ){
            int width = right - left;
            int currHeight = min(height[left],height[right]);
            long long area = width*currHeight;
            maxArea = max(maxArea,area);
            
            if ( height[right] >= height[left]){
                left++;
            }
            
            else{
                right--;
            }
        }
        return maxArea;
    }
};