
//  Created by reginald on 14-2-4.
//  Copyright (c) 2014年 reginald. All rights reserved.
//

#include "Array.h"


//Longest Consecutive Sequence
//o(n) complexity means hashtable
int Solution:: longestConsecutive(vector<int> &num) {
    unordered_map<int,bool> mp;
    for (auto i : num) {
        mp[i] = false;
    }
    int longest = 0;
    for (auto i : num){
        if (mp[i]) {
            continue;
        }
        int len = 1;
        mp[i] = true;
        for (int j = i + 1; mp.find(j) != mp.end(); ++j) {
            mp[j] = true;
            len++;
        }
        for (int j = i - 1; mp.find(j) != mp.end(); --j) {
            mp[j] = true;
            len--;
        }
        longest = max(longest,len);
    }
    return longest;
}



//Median of Two Sorted Arrays
double find_kth(int *A, int sa, int *B, int sb, int k){
    if (sa > sb) {
        return find_kth(B, sb, A, sa, k);
    }
    if (sa == 0) {
        return B[k-1];
    }
    if (k ==1){
        return min(A[0],B[0]);
    }
    
    int ea = min(k / 2, sa), eb = k - ea;
    if (A[ea - 1] < B[eb - 1]){
        return find_kth(A + ea, sa - ea, B, sb, k - ea);
    }
    else if (A[ea - 1] > B[eb - 1]){
        return find_kth(A, sa, B + eb, sb - eb, k - eb);
    }
    else{
        return  A[ea - 1];
    }
};

double Solution::findMedianSortedArrays(int *A, int m, int *B, int n){
    int total = m + n;
    if (total & 0x1){ // total is odd
        return find_kth(A, m, B, n, total / 2 + 1);
    }
    else{ // total is even
        return (find_kth(A, m, B, n, total / 2)
                + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
    }
};



//Remove duplicates
int Solution::removeDuplicates(int *A, int n){
    if (n == 0) return 0;
    
    int index = 0;
    for (int i = 1; i < n; i++){
        if (A[index] != A[i]){
            A[++index] = A[i]; //since it's sorted, duplicates must be neighbor
        }
    }
    return index+1;
};

int Solution::removeDuplicates_II(int *A, int n){
    if (n <= 2) return 0;
    
    int index = 2;
    for (int i = 2; i < n; i++){
        if (A[i] != A[index - 2]){
            A[index++] = A[i]; // ++before, add before use; ++behind, add after use
                               // index is tracking at the end of repeated number
        }
    }
    return index;
};




//Search in rotated sorted array
//if duplicated are allowed, compleixty increase from o(log n) to o(n)
int bsearch(int *A, int start, int end, int target){
    int mid = (end + start)/2;
    if (target == A[mid]){
        return mid;
    }
    
    if (end <= start) return -1;

    if (A[start] <= A[mid]){
        if (target >= A[start] and target < A[mid]){
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }
    else{
        if (target <= A[end] and target > A[mid]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return bsearch(A, start, end, target);

};

bool bsearch_II(int *A, int start, int end, int target){
    int mid = (end + start)/2;
    if (target == A[mid]){
        return mid;
    }
    
    if (end <= start) return -1;
    
    if (A[start] <= A[mid]){
        if (A[start] < A[mid]){
            if (target >= A[start] and target < A[mid]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            start++;
        }
    }
    else{
        if (target <= A[end] and target > A[mid]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return bsearch_II(A, start, end, target);
    
};

int Solution::search(int *A, int n, int target){
    return bsearch(A, 0, n-1, target);
};

bool Solution::search_II(int *A, int n, int target){
    return bsearch_II(A, 0, n-1, target);
};




//Two Sum
vector<int> Solution:: twoSum(vector<int>&numbers,int target){
    unordered_map<int, int>mp;
    for (int i = 0; i < numbers.size(); i++) {
        mp[numbers[i]] = i;
    }
    vector<int>ans;
    for (int i = 0; i < numbers.size(); i++) {
        int supl = target - numbers[i];
        if (mp.find(supl) != mp.end() and mp[supl] > i){
            ans.push_back(i + 1);
            ans.push_back(mp[supl] + 1);
            break;
        }
    }
    return ans;
}


//Three Sum
vector<vector<int>> Solution::threeSum(vector<int>&num){
    vector<vector<int>> ans;
    if (num.size() < 3) {
        return ans;
    }
    sort(num.begin(), num.end());
    int target = 0;
    auto last = num.end();
    for (auto a = num.begin(); a < prev(last, 2); ++a) {
        auto b = next(a);
        auto c = prev(last);
        while (b < c) {
            if (*a + *b + *c < target) {
                ++b;
            } else if (*a + *b + *c > target) {
                --c;
            } else {
                ans.push_back({ *a, *b, *c });
                ++b;
                --c;
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;

};



int Solution::singlenumber(int A[],int n){
    int xor_val = A[0];
    for (int i=1; i<n; ++i) {
        xor_val=xor_val^A[i];
    }
    return  xor_val;
}

int Solution:: singleNumber(int A[], int n) {
    int xor_val = A[0];
    int num = A[0];
    for (int i=1; i<n; ++i) {
        xor_val=xor_val^A[i];
    }
    return  xor_val;
    
}


int Solution::boolconsecute(vector<int>&num){
    int max=num[0];
    int min=num[0];
    for (vector<int>::iterator iter=num.begin(); iter!=num.end(); ++iter) {
        if(*iter>max){max=*iter;}
        if(*iter<min){min=*iter;}
    }
    vector<bool> count(max+1-min,0);
    for (int i=0; i<num.size(); ++i) {
        count[num[i]-min]=1;
    }
    int maxconsecute=1;
    int currconsecute=1;
    for(int i=0;i<count.size()-1;++i){
        if(count[i] and count[i+1]){currconsecute++;}
        else{
            if(currconsecute>maxconsecute){maxconsecute=currconsecute;}
            currconsecute=1;
        }
    }
    return maxconsecute;

}


vector<int> Solution::countingsort(vector<int>&num){
    int max=num[0];
    int min=num[0];
    for (vector<int>::iterator iter=num.begin(); iter!=num.end(); ++iter) {
        if(*iter>max){max=*iter;}
        if(*iter<min){min=*iter;}
    }
    vector<int> count(max+1-min,0);
    for (int i=0; i<num.size(); ++i) {
        count[num[i]-min]+=1;
    }
    for(int i=1;i<max+1-min;++i){
        count[i]=count[i-1]+count[i];
    }
    vector<int> new_num(num.size(),0);
    for(int i=(num.size()-1);i>=0;--i){
        new_num[count[num[i]-min]-1]=num[i];
        count[num[i]-min]--;
    }
    return new_num;

}

int Solution::removeElement(int A[], int n, int elem) {
    int i=0;
    int j=0;
    while (i<n){
        if (A[i]!=elem){
            A[j]=A[i];
            j++;
        }
        i++;
    }
    return j;

}

int Solution::maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int m=A[0];
    for (int i=0; i<n; ++i) {
        if(A[i]>m){m=A[i];}
    }
    int sum=0;
    for (int i=0;i<n;i++){
        sum = sum>=0?(sum+A[i]):A[i];
        m=sum>m?sum:m;
    }
    return m;
}

int Solution:: searchInsert(int A[], int n, int target) {
    int i=0;
    while (i<n) {
        if(A[i]>=target){return i;}
        i++;
    }
    if(i==n){return i;}
    return i;
}

int Solution:: maxProfit_I(vector<int> &prices)
{
    int profit=0;
    if (!prices.empty())
    {
        
        int shares = 0;//not have any
        int i=0;
        while (i<prices.size())
        {
            if (i+1<prices.size()) {
                int cur_price = prices[i];
                int next_price = prices[i+1];
                if (next_price<cur_price)
                {
                    if (shares){
                        //sellprice = cur_price;
                        profit+=cur_price*shares;
                        shares=0;
                    }
                    else{i++;continue;}
                }
                else{
                    if (shares) {i++;continue;}
                    else{profit-=cur_price;shares++;}
                }
            }
            else{if(shares){profit+=prices[i]*shares;}}
            i++;
        }
    }
    return profit;
}

int Solution:: maxProfit_II(vector<int>&prices){
    int profit=0;
    int total_profit=0;
    if (!prices.empty()){
        if(prices.size()<2){return total_profit;}
        int curr_profit =0;
        int curr_total_profit=0;
        int i=0;
        //int holds=0;
        while (i<prices.size()) {
            if (i+1<prices.size()) {
                int j=i+1;
                while (j<prices.size() and prices[i]<prices[j]) {
                    curr_profit = prices[j]-prices[i];
                    if(curr_profit>profit){
                        vector<int> temp(prices.begin()+j,prices.end());
                        curr_total_profit = curr_profit+maxProfit(temp);
                        if(curr_total_profit>total_profit){profit=curr_profit;total_profit=curr_total_profit;}
                    }
                    j++;
                }
                if(j==prices.size()){i++;continue;}
                i=j;
            }
            else{break;}
        }
    }
    
    return total_profit;
}


int Solution::maxProfit(vector<int> &prices){
    int profit=0;
    if (!prices.empty()){
        int curr_profit =0;
        int i=0;
        while (i<prices.size()) {
            if (i+1<prices.size()) {
                int j=i+1;
                while (j<prices.size() and prices[i]<prices[j]) {
                    curr_profit = prices[j]-prices[i];
                    if(curr_profit>profit){profit=curr_profit;}
                    j++;
                }
                if(j==prices.size()){i++;continue;}
                i=j;
            }
            else{break;}
        }
    }
    return profit;
}



vector<vector<int>> Solution::threeSum_brute_force(vector<int>&num){
    vector<vector<int>> results;
    sort(num.begin(),num.end());
    int first,second,third;
    vector<int> previous;
    for(int i=0;i<num.size();++i){
        if(i>0 and num[i-1]==num[i]){continue;}
        if(num[i]>0){break;}
        first = num[i];
        for (int j=i+1; j<num.size(); ++j) {
            if(j>i+1 and num[j-1]==num[j]){continue;}
            second = num[j];
            for (int k=j+1; k<num.size(); ++k) {
                third = num[k];
                if (first+second+third==0) {
                    int newpair[] ={first,second,third};
                    vector<int> newvec(newpair,newpair+3);
                    if(results.empty()){results.push_back(newvec);previous = newvec;}
                    else if(newvec!=previous){
                        results.push_back(newvec);
                        previous=newvec;
                        //cout<<i<<'\t'<<j<<'\t'<<k<<endl;
                    }
                    break;
                }
            }
        }
    }
    return results;
}


int Solution::threeSumClosest_on3(vector<int>&num, int target){
    sort(num.begin(), num.end());
    int closet = num[0]+num[1]+num[2];
    int error = abs(closet-target);
    for (int i=0;i<num.size(); ++i) {
        if (num[i]>target) {break;}
        for (int j=i+1; j<num.size(); ++j) {
            if(num[i]+num[j]>target){break;}
            for (int k=j+1; k<num.size(); ++k) {
                int curr = num[i]+num[j]+num[k];
                if(abs(curr-target)<error){error=abs(curr-target);closet=curr;}
                if (curr>target) {
                    break;
                }
            }
        }
    }
    return closet;
}

int Solution::threeSumClosest(vector<int> &num, int target){
    sort(num.begin(), num.end());
    int closet = num[0]+num[1]+num[2];
    int error = abs(closet-target);
    int k = num.size()-1;
    for(int i=0;i<num.size();++i){
        int j=i+1;
        while (j<num.size() and j<k) {
            int curr = num[i]+num[j]+num[k];
            if(abs(curr-target)<error){error=abs(curr-target);closet=curr;}
            if(curr>target){k--;}
            else if(curr<target){j++;}
            else{return closet;}
        }
    }
    return closet;
}

void Solution::threeSum(vector<int> &num, int target,vector<vector<int>> &res, int currnum) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> res_m(4);
    //vector< vector<int> > res;
    vector<int>::iterator it1,it2,it3,iend;
    
    //sort(num.begin(),num.end());
    if(num.size()>=3){
        iend = num.end();
        it1 = num.begin();
        bool f1 = false;
        for ( ;it1!=iend-2;++it1){
            if(f1 && *it1==*(it1-1)) {continue;}
            f1 = true;
            bool f2 = false;
            bool f3 = false;
            it3 = iend-1;
            it2 = it1+1;
            while (it2!=it3){
                
                if(f3 && *it3==*(it3+1)) { it3 = it3 -1 ;continue;}
                if(f2 && *it2==*(it2-1)) { it2 = it2 +1 ;continue;}
                
                if (*it1 + *it2 + *it3==target){
                    res_m.at(1)=*it1;
                    res_m.at(2)=*it2;
                    res_m.at(3)=*it3;
                    res_m.at(0)=currnum;
                    res.push_back(res_m);
                }
                if (*it1 + *it2 + *it3 >target){
                    it3=it3-1;
                    f3 = true;
                    
                }else{
                    it2=it2+1;
                    f2 = true;
                }
                
            }
            
        }
    }
    //return res;
}

vector<vector<int>> Solution::fourSum(vector<int> &num, int target){
    sort(num.begin(),num.end());
    vector<vector<int>> results;
    for (vector<int>::iterator iter=num.begin(); iter!=num.end(); ++iter) {
        if(iter!=num.begin() and *(iter-1)==*iter){continue;}
        vector<int>newnum(iter+1,num.end());
        threeSum(newnum, target-*iter, results,*iter);
    }
    return results;
}

void sudoku_print(map<pair<int, int>, unordered_set<char>>::iterator iter){
    
    cout<<iter->first.first+1<<'\t'<<iter->first.second+1<<':'<<'\t';
    for (auto charit=iter->second.begin(); charit!=iter->second.end(); ++charit) {
        cout<<*charit<<'\t';
    }
    cout<<endl;
}

void sudoku_update(char board[][9], map<pair<int, int>, unordered_set<char>> & candidate){
    
    for(int i=0;i<9;++i){
        map<char,int>i_appear_times;
        i_appear_times['1'] = 0;
        i_appear_times['2'] = 0;
        i_appear_times['3'] = 0;
        i_appear_times['4'] = 0;
        i_appear_times['5'] = 0;
        i_appear_times['6'] = 0;
        i_appear_times['7'] = 0;
        i_appear_times['8'] = 0;
        i_appear_times['9'] = 0;
        map<char, int>j_appear_times(i_appear_times);
        
        stack<map<pair<int, int>, unordered_set<char>>::iterator> elems;
        
        for (auto it=candidate.begin(); it!=candidate.end(); ++it) {
            if(it->first.first==i){
                for (auto iter=it->second.begin(); iter!=it->second.end(); ++iter) {
                    i_appear_times[*iter]+=1;
                }
            }
            if(it->first.second==i){
                for (auto iter=it->second.begin(); iter!=it->second.end(); ++iter) {
                    j_appear_times[*iter]+=1;
                }
            }
        }

        
        for (auto it = i_appear_times.begin(); it!=i_appear_times.end(); ++it) {
            if(it->second==1){
                for (auto iter=candidate.begin(); iter!=candidate.end(); ++iter) {
                    if(iter->first.first==i){
                        if (iter->second.find(it->first)!=iter->second.end()) {
                            board[i][iter->first.second] = it->first;
                            elems.push(iter);
                            //update j and 9 square
                            for (auto iter2 = candidate.begin(); iter2!=candidate.end(); ++iter2) {
                                if(iter2!=iter){
                                    if (iter2->first.first==i or iter2->first.second == iter->first.second) {
                                        if (iter2->second.find(it->first)!=iter2->second.end()) {
                                            iter2->second.erase(it->first);
                                        }
                                    }
                                    if((iter->first.first)/3==(iter2->first.first)/3 and
                                       (iter->first.second)/3==(iter2->first.second)/3){
                                        if(iter2->second.find(it->first)!=iter2->second.end()){
                                            iter2->second.erase(it->first);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        //erase
        while (!elems.empty()) {
            candidate.erase(elems.top());
            elems.pop();
        }
        
        for (auto it = j_appear_times.begin(); it!=j_appear_times.end(); ++it) {
            if(it->second==1){
                for (auto iter=candidate.begin(); iter!=candidate.end(); ++iter) {
                    if(iter->first.second==i){
                        if (iter->second.find(it->first)!=iter->second.end()) {
                            board[iter->first.first][i] = it->first;
                            elems.push(iter);
                            //update j and 9 square
                            for (auto iter2 = candidate.begin(); iter2!=candidate.end(); ++iter2) {
                                if(iter2!=iter){
                                    if (iter2->first.second==i or iter2->first.first == iter->first.first) {
                                        if (iter2->second.find(it->first)!=iter2->second.end()) {
                                            iter2->second.erase(it->first);
                                        }
                                    }
                                    if((iter->first.first)/3==(iter2->first.first)/3 and
                                       (iter->first.second)/3==(iter2->first.second)/3){
                                        if(iter2->second.find(it->first)!=iter2->second.end()){
                                            iter2->second.erase(it->first);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        while (!elems.empty()) {
            candidate.erase(elems.top());
            elems.pop();
        }
    }
    
    //delete all the candidates with set size =1 and update
    bool set_size_1 = false;
    while (!set_size_1) {
        set_size_1 = true;
        stack<map<pair<int, int>, unordered_set<char>>::iterator> erase_elem;
        
        for (auto it=candidate.begin(); it!=candidate.end(); ++it) {
            if(it->second.size()==1){
                board[it->first.first][it->first.second] = *it->second.begin();
                erase_elem.push(it);
                for (auto iter=candidate.begin(); iter!=candidate.end(); ++iter) {
                    if(iter!=it){
                        if(iter->first.first==it->first.first or iter->first.second==it->first.second){
                            if(iter->second.find(*it->second.begin())!=iter->second.end()){
                                iter->second.erase(*it->second.begin());
                            }
                        }
                        if((iter->first.first)/3==(it->first.first)/3 and (iter->first.second)/3==(it->first.second)/3){
                            if(iter->second.find(*it->second.begin())!=iter->second.end()){
                                iter->second.erase(*it->second.begin());
                            }
                        }
                    }
                }
            }
        }
        
        while(!erase_elem.empty()){candidate.erase(erase_elem.top());erase_elem.pop();}
        for (auto it=candidate.begin(); it!=candidate.end(); ++it) {
            if(it->second.size()==1){set_size_1 = false;}
        }
    }
    
}

bool sudoku_valid(char board[][9]){
    map<char,int>i_appear_times;
    i_appear_times['1'] = 0;
    i_appear_times['2'] = 0;
    i_appear_times['3'] = 0;
    i_appear_times['4'] = 0;
    i_appear_times['5'] = 0;
    i_appear_times['6'] = 0;
    i_appear_times['7'] = 0;
    i_appear_times['8'] = 0;
    i_appear_times['9'] = 0;
    map<char,int>j_appear_times=i_appear_times;
    map<char,int> ori_appear_times=i_appear_times;
    map<char,int> block_appear_times = i_appear_times;
    
    for (int i=0; i<9; ++i) {
        //index i
        i_appear_times = ori_appear_times;
        for (int j=0; j<9; ++j) {if(board[i][j]!='.'){i_appear_times[board[i][j]]++;}else{return false;}}
        
        for (auto it = i_appear_times.begin(); it!=i_appear_times.end(); ++it) {
            if (it->second!=1) {return false;}
        }
        
        //index j
        j_appear_times = ori_appear_times;
        for (int j=0; j<9; ++j) {if(board[j][i]!='.'){j_appear_times[board[j][i]]++;}else{return false;}}
        
        for (auto it = j_appear_times.begin(); it!=j_appear_times.end(); ++it) {
            if (it->second!=1) {return false;}
        }
    }
    
    for (int i=0; i<3; ++i) {
        for(int j=0;j<3;++j){
            block_appear_times = ori_appear_times;
            for (int m=0+i*3; m<3+i*3; ++m) {
                for (int n=0+j*3; n<3+j*3; ++n) {if(board[m][n]!='.'){block_appear_times[board[m][n]]++;}else{return false;}}}

            for (auto it=block_appear_times.begin(); it!=block_appear_times.end(); ++it) {
                if (it->second!=1) {return false;}
            }
        }
    }
    
    return true;
}

bool sudoku_check(map<pair<int,int>,unordered_set<char>>::iterator &it, char board [][9]){
    int i = it->first.first;
    int j= it->first.second;
    unordered_set<char> pool = it->second;
    //cout<<"check:\t"<<"i:"<<i<<"\tj:"<<j<<"\tset size"<<pool.size()<<endl;
    for (int m=0; m<9; ++m) {
        if(pool.find(board[i][m])!=pool.end()){pool.erase(board[i][m]);}
        if(pool.find(board[m][j])!=pool.end()){pool.erase(board[m][j]);}
    }
    for (int m = 3*(i/3); m<3+3*(i/3); ++m) {
        for (int n=3*(j/3); n<3+3*(j/3); ++n) {
            if(pool.find(board[m][n])!=pool.end()){pool.erase(board[m][n]);}
        }
    }
    //cout<<"new size:\t"<<pool.size()<<'\n'<<endl;
    it->second = pool;
    if(!pool.empty()){return true;}
    else{return false;}
}

bool sudoku_DFS(map<pair<int,int>,unordered_set<char>>::iterator it, char board [][9],
                map<pair<int,int>,unordered_set<char>> &candidate){
    
    
    if(it==candidate.end()){return false;}
    unordered_set<char> rawpool = it->second;//reserve pool
    if(!sudoku_check(it, board)){//cout<<"i:"<<it->first.first<<"\tj:"<<it->first.second<<"\tcutting branch"<<endl;
        it->second = rawpool; return false;}
    //pool been changed
    
    auto p = it;
    //cout<<"new iteration:"<<'\t';
    //sudoku_print(it);
    ++p;
    if(p==candidate.end()){
        //cout<<"yes\n"<<endl;
        for (auto iter=it->second.begin(); iter!=it->second.end(); ++iter) {
            board[it->first.first][it->first.second] = *iter;
            if(sudoku_valid(board)){
                //cout<<"yes\n"<<endl;
                it->second = rawpool;
                return true;
            }
        }
        it->second = rawpool;
        return false;
    }
    else{
        
        auto iter = it->second.begin();
        while(iter!=it->second.end()){
            board[it->first.first][it->first.second] = *iter;
            iter++;
            if(sudoku_DFS(p, board, candidate)){it->second = rawpool; return true;}
            else{if(iter==it->second.end()){board[it->first.first][it->first.second] = '.';}}
        }
        it->second = rawpool;
        return false;
    }
    
}

bool cmp_by_value(const pair<pair<int, int>, int> &l1, const pair<pair<int, int>, int> &l2){
    return l1.second<l2.second;
}


void Solution:: solveSudoku(char board [][9] ) {
    map<pair<int,int>,unordered_set<char>>candidate;
    unordered_set<char>pool({'1','2','3','4','5','6','7','8','9'});
    for(int i=0;i<9;++i){
        for (int j=0; j<9; ++j) {
            if(board[i][j]=='.'){
                pair<int,int>loc;
                loc.first  = i;
                loc.second = j;
                candidate[loc]=pool;
                for (int m=0; m<9; m++) {
                    if (candidate[loc].find(board[i][m])!=candidate[loc].end()) {
                        candidate[loc].erase(board[i][m]);
                    }
                    if (candidate[loc].find(board[m][j])!=candidate[loc].end()) {
                        candidate[loc].erase(board[m][j]);
                    }
                }
                for (int m=0; m<3; m++) {
                    for (int n=0; n<2; n++){
                        if (candidate[loc].find(board[m+3*(i/3)][n+3*(j/3)])!=candidate[loc].end()) {
                            candidate[loc].erase(board[m+3*(i/3)][n+3*(j/3)]);
                        }
                    }
                }
            }
        }
    }
    //cout<<candidate.size()<<endl;
    sudoku_update(board, candidate);
    //cout<<candidate.size()<<endl;
    bool solved = sudoku_valid(board);
    //DFS search to solve
//    for (auto it=candidate.begin(); it!=candidate.end(); ++it) {
//        sudoku_print(it);
//    }
//    cout<<'\n'<<endl;
    if (!solved) {solved = sudoku_DFS(candidate.begin(), board, candidate);}

    for (int i=0; i<9; ++i) {
        for (int j=0; j<9; ++j) {
            cout<<board[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<'\n'<<endl;
    
    
}
