//  Created by reginald on 14-2-4.
//  Copyright (c) 2014年 reginald. All rights reserved.
//

#ifndef leetcode_Array_h
#define leetcode_Array_h
#include <cstdbool>
#include <iostream>
#include <cmath>
#include <utility>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>


using namespace std;

class Solution{
public:
    int singlenumber(int A[],int n);
    int singleNumber(int A[], int n);
    
    //Longest Consecutive Sequence
    int longestConsecutive(vector<int> &num);
    
    
    vector<int> countingsort(vector<int>&num);
    int boolconsecute(vector<int>&num);
    int removeElement(int A[],int n, int elem);
    
    
    
    //Median of Two Sorted Arrays
    double findMedianSortedArrays(int A[], int m, int B[], int n);
    
    
    //Remove duplicates
    int removeDuplicates(int A[], int n);
    int removeDuplicates_II(int A[], int n);
    
    //Search in Rotated Sorted Array
    int search(int A[], int n, int target);
    bool search_II(int A[], int n, int target);

    //Two Sum
    vector<int> twoSum(vector<int>&numbers,int target);

    //Three Sum
    vector<vector<int>>threeSum(vector<int>&num);
    
    //Three Sum Closet
    int threeSumClosest(vector<int> &num, int target);

    //Four Sum
    vector<vector<int> > fourSum(vector<int> &num, int target);
  
    
    
    //bool sudoku_valid(char [][9]);
    void solveSudoku(char[][9]);




};

#endif
