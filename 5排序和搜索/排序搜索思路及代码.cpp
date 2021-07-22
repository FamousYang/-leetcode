1、合并两个有序数组
//从后往前比较，大的扔到最后，最后处理剩下的一些，直接顺序赋值过去即可

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        int end = m+n-1;
        int i = m-1;
        int j = n-1;
        while(i>=0 && j>=0 && end>=0){
            if(nums1[i] <= nums2[j]){
                nums1[end--] = nums2[j--];
            }else{
                nums1[end--] = nums1[i--];
            }
        }
        for(i = 0;i<=j;i++){
            nums1[i] = nums2[i];
        }
    }
	
2、第一个错误的版本
//典型二分查找

int firstBadVersion(int n) {
        int left = 1,right = n;
        while(left != right){
            int mid = left+((right-left)>>2);
            if(isBadVersion(mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }