// median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArraysFinal(vector<int> &nums1, vector<int> &nums2){
  int n = nums1.size(); 
  int m = nums2.size();

  // we'll always just run it on nums1 being the smaller array
  if (n > m) return findMedianSortedArraysFinal(nums2, nums1);

  // binary search range -> i can take 0 elements from array 1 all the way up to all elements from array 1
  int low = 0, high = n;
  // handles the odd case pushing the median to the left half
  int halfCount = (n + m + 1) / 2;

  while (low <= high){
    // represents how many elements to take from array 1
    int cut1 = low + (high - low) / 2;
    // represents how many elements to take from array 2
    int cut2 = halfCount - cut1;

    // if cut has no elements -INF
    int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
    // if cut has all elements +INF
    int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];

    int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
    int r2 = (cut2 == m) ? INT_MAX : nums2[cut1];

    // validation of boundaries 
    if (l1 > r2){
      // l1 is too large to be in the left half, push it to the right by taking elements from array 2 - meaning reduce cut1 
      high = cut1 - 1;
    } else if (l2 > r1){
      // l2 is too large to be in the left half, push it to the right by taking elements from array 1 -> meaning increase cut1 
      low = cut1 + 1;
    } else {
      // this config is actually how elements from arr1 and arr2 will be chosen in the merged sorted array 
      if ((n + m) % 2 == 1) return max(l1, l2);
      else return double(max(l1, l2) + min(r1, r2)) / 2;
    }
  }

  return 0.0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
  // I need to cut the smaller array, it will tell me how many elemets to the left and right 
  int n = nums1.size();
  int m = nums2.size();

  // how many elements in each half
  // +1 because in the odd case i'm putting the median value on the left half so i can just fnd the correct border value and that will be the median
  int halfCount = (n + m + 1) / 2;

  // now we can place cuts on the smaller array (search space will be reduced since the number of elements in the half are fixed)
  int low = 0, high = min(n, m) - 1;

  while (low <= high){
    // this is the number of elements taken in array 1 (cut 1)
    int cut1 = low + (high - low) / 2;
    // which element from array 1 is at the border of this cut? 
    // need better handling of edge cases -> when there are no elements in l1 l2 or r1 r2
    int l1;
    cut1 == 0 ? l1 = INT_MIN : l1 = nums1[cut1-1];
    // the right next element will be the border element of the right
    int r1 = nums1[cut1];

    // now i can find the border one's for array 2
    int l2 = nums2[halfCount - cut1 - 1];
    int r2 = nums2[halfCount - cut1];

    // now the validation checks 
    if (l1 > r2){
      // meaning l1 is too big and needs to go on the right, and if i take fewwer elements from array 1, this l1 will automatically get pushed to the right 
      high = cut1 - 1;
    } else if (l2 > r1) {
      // l2 is too big and needs to go on the right, if i take more elements from array 1, this will be pushed to the right 
      low = cut1 + 1;
    } else {
      // now this is pretty much the sorted config, and my median is dependent on l1 l2 r1 r2
      // if it's even, then it's the average of the edge numbers, otherwise it's the last number from left half
      if ((n + m) % 2 == 1){
        return max(l1, l2); 
      } else {
        return double(max(l1, l2) + min(r1, r2)) / 2;
      }
    }
  }
  return -1;

}

int medianNaive(vector<int> &arr1, vector<int> &arr2) {
  int n = arr1.size();
  int m = arr2.size();

  // merge them into 1 massive array
  // can also just keep a counter, where i track which number will be the median while i'm iterating through both the arrays (pseudo merging) 
  vector<int> v;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) {
      v.push_back(arr1[i++]);
    } else {
      v.push_back(arr2[j++]);
    }
  }

  while (i < n) {
    v.push_back(arr1[i++]);
  }
  while (j < m) {
    v.push_back(arr2[j++]);
  }

  // now if size is even, then we'll take the average
  // if size is odd, then it's the size/2 idx
  if (v.size() % 2 == 1) {
    return v[v.size() / 2];
  } else {
    return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> arr1(n);
  vector<int> arr2(m);

  for (auto &it : arr1)
    cin >> it;
  for (auto &it : arr2)
    cin >> it;

  cout << medianNaive(arr1, arr2);
}
