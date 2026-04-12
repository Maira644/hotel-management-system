// ================================================================1
// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(vector<int> arr, int target){
//     int st = 0; int end = arr.size()-1;
//     while(st <= end){
//         int mid = (st + end) / 2;

//         if(target > arr[mid]){
//             st = mid + 1;
//         }else if(target < arr[mid]){
//             end = mid - 1;
//         }else{
//             return mid;
//         }
        
//     }
//     return -1;
// }
// int main(){
//     vector<int> arr1 = {1, 2, 3, 4, 5, 6, 12};
//     int target = 12;
//     cout<<"The target has been found at index "<<binarySearch(arr1, target)<<endl;

//     return 0;
// }

// =================================================================2
// #include <iostream>
// using namespace std;

// int main(){
//     int matrix [3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int rows = 3;
//     int cols = 3;

//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0; 
// }

// =================================================================3
// #include <iostream>
// using namespace std;
// bool linearSearch(int mat[][3], int rows, int cols, int key){
//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++){
//             if(mat[i][j] == key){
//             return true;
//             }
//         }
//     }
//     return false;
// }
// int main(){
//     int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int rows = 3;
//     int cols = 3;

//     cout<< linearSearch(matrix, rows, cols, 8)<<endl;
//     return 0; 
// }

// ================================================================4
// #include <iostream>
// using namespace std;

// int main(){
//     int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int rows = 3;
//     int cols = 3;
//     int key = 5;

//     for(int i=0; i<rows; i++){
//         for(int j=0; j<cols; j++){
//             if(matrix[i][j] == key){
//                 cout<<"rows = "<<i<<" columns = "<<j<<endl;
//             }
//         }
//     }   
//     return 0; 
// }

// =================================================================5
// #include <iostream>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int main(){
//     int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int rows = 3;
//     int cols = 3;
//     int maxRowSum = INT_MIN;

//     for(int i=0; i<rows; i++){
//         int rowSumI = 0;
//         for(int j=0; j<cols; j++){
//             rowSumI += matrix[i][j];
//         }
//         maxRowSum = max(maxRowSum, rowSumI); 
//     } 
//     cout<<"Maximum Row Sum: "<<maxRowSum<<endl;
//     return 0; 
// }

// =================================================================6
// #include <iostream>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int main(){
//     int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 18, 9}};
//     int rows = 3;
//     int cols = 3;
//     int maxRowSum = INT_MIN;

//     for(int j=0; j<cols; j++){
//         int rowSumI = 0;
//         for(int i=0; i<rows; i++){
//             rowSumI += matrix[i][j];
//         }
//         maxRowSum = max(maxRowSum, rowSumI); 
//     } 
//     cout<<"Maximum Column Sum: "<<maxRowSum<<endl;
//     return 0; 
// }

// =================================================================7
// #include <iostream>
// using namespace std;

// int diagonalSum(int mat[][4], int n){
//     int sum = 0;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             if(i == j){
//                 sum += mat[i][j];
//             }else if(j == n-1-i){
//                 sum += mat[i][j];
//             }
//         }
//     }
//     return sum;
// }

// int main(){
//     int matrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12},{13, 14, 15, 16}};
//     int n = 4;

//     cout<<"The sum of primary and secondary diagonal is: "<<diagonalSum(matrix, n)<<endl;

//     return 0; 
// }

// ================================================================8
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int size = 4;

//     for(int i=0; i<matrix.size(); i++){
//         for(int j=0; j<matrix[i].size(); j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0; 
// }

// ================================================================9
// #include <iostream>
// using namespace std;

// int main(){
//     int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int n = 3;

//     for(int j=0; j<n; j++){
//         int product = 1;
//         for(int i=0; i<n; i++){
//             product *= mat[i][j];       
//         }
//         cout<<product<<" ";
//     }
//     return 0;
// }

// ===============================================================10
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector<int>nums = {1, 2, 3, 4};
//     int n = nums.size();
//     vector<int>ans(n);

//     for(int i=0; i<n; i++){
//         int prod = 1;
//         for(int j=0; j<n; j++){
//             if(i != j){
//                 prod *= nums[j];
//             }
//         }
//         ans[i] = prod;
//     }
//     for(int i=0; i<n; i++){
//         cout<<ans[i]<<", ";
//     }
//     cout<<endl;
//     return 0;
// }

// ===============================================================11
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){ 
    // 1)Basic 
    // vector<int> vec = {1, 2, 3, 4, 5};
    // vec.erase(vec.begin() + 2);
    // vec.erase(vec.begin()+1, vec.begin()+3);

    // vec.insert(vec.begin() + 2, 6);
    // vec.clear();

    // for(int val : vec){
    //     cout<<val<<" ";
    // }
    // cout<<endl;

    // 2)Forward loop
    // vector<int> vec = {1, 2, 3, 4, 5};
    // for(auto it=vec.begin(); it!=vec.end(); it++){
    //     cout<<*(it)<<" ";
    // }
    // cout<<endl;

    // 3)Backward loop
    // vector<int> vec = {1, 2, 3, 4, 5};
    // for(auto it=vec.rbegin(); it!=vec.rend(); it++){
    //         cout<<*(it)<<" ";
    // }
    //cout<<endl;

    // 4) descending order
    // vector<int> vec = {1, 2, 3, 4, 5};
    // sort(vec.begin(), vec.end(), greater<int>());
    // for(int val : vec){
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    
    // cout<<*(max_element(vec.begin(), vec.end()));
//     return 0; 
// }

// ===================================================================12
// #include <iostream>
// #include <vector>
// using namespace std;

// int sinNonDuplicate(vector<int> A){
//     int n = A.size();
//     if(n == 1) return A[0];

//     int st = 0, end = n-1;
//     while(st <= end){
//         int mid = st + (end - st) /2;
//         if(mid == 0 && A[0] != A[1]) return A[mid];
//         if(mid == n-1 && A[n-1] != A[n-2]) return A[mid];

//         if(A[mid-1] != A[mid] && A[mid] != A[mid+1]) return A[mid];

//         if(mid % 2 == 0){
//             if(A[mid-1] == A[mid]){
//                 end = mid-1;
//             }else{
//                 st = mid+1;
//             }
//         }else{
//             if(A[mid-1] == A[mid]){
//                 st = mid+1;
//             }else{
//                 end = mid-1;
//             } 
//         }
//     }
//     return -1;
// }

// int main(){
//     vector<int> Arr = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    
//     cout<<"The element that is a single, non duplicate is: "<<sinNonDuplicate(Arr)<<endl;
//     return 0;
// }
 
// ==================================================================13
// #include <iostream>
// using namespace std;

// int gcd(int a, int b){
//     while(a > 0 && b > 0){
//         if(a > b){
//             a = a % b;
//         }else{
//             b = b % a;
//         }
//     }
//     if(a == 0) return b;
//     return a;
// }
// int lcm(int a, int b){
//     int GCD = gcd(a, b);
//     return (a * b) / GCD;
// }

// int main(){
//     cout<<"The GCD of the two numbers is: "<<gcd(20, 28)<<endl;
//     cout<<"The LCM of the two numbers is: "<<lcm(20, 28)<<endl;

//     return 0;
// }

// ==================================================================14
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// string lastWord(string phrase){
//     string word = "";
//     for(int i=phrase.length()-1; i>=0; i--){
//         if(phrase[i] == ' '){
//             break;
//         }else{
//             word += phrase[i];
//         }
//     }
//     reverse(word.begin(), word.end());
//     return word;
// }
// int main(){
//     string phrase;
//     cout<<"Enter a phrase: ";
//     getline(cin, phrase);

//     int count = 0;
//     for(int i=phrase.length()-1; i>=0; i--){
//         if(phrase[i] == ' '){
//             break;
//         }else{
//             count++;
//         }
//     }
//     cout<<"The count of the last word "<<lastWord(phrase)<<" of the pharse is: "<<count<<endl;
//     return 0;
// }

// ==================================================================15
// #include <iostream>
// #include <algorithm>
// #include <climits>
// using namespace std;

// int main(){
//     int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     int maxInRow[3] = {};
//     int rows = 3;
//     int cols = 3;

//     for(int i=0; i<rows; i++){
//         int maxValue = INT_MIN;
//         for(int j=0; j<cols; j++){
            
//             maxValue = max(maxValue, mat[i][j]);
//         }
//         maxInRow[i] = maxValue;     
//     } 
//     cout<<"Maximum element in each row: ";
//     for(int i=0; i<rows; i++){
//         cout<<maxInRow[i]<<" ";
//     }
//     cout<<endl;
//     return 0; 
// }

// =================================================================16
// #include <iostream>
// using namespace std;

// int main(){
//     int nums[4] = {1, 2, 3, 4};
//     int newNums[4];
//     int prod = 1;

//     for(int i=0; i<4; i++){
//         prod *= nums[i];
//     }

//     for(int i=0; i<4; i++){
//         newNums[i] = prod / nums[i];
//     }
    
//     for(int i=0; i<4; i++){
//         cout<<newNums[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// =================================================================17
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     vector<char> s = {'h', 'e', 'l', 'l', 'o'};
//     int start = 0;
//     int end = s.size()-1;

//     while(start < end){
//         swap(s[start], s[end]);
//         start++;
//         end--;
//     }

//     for(int i=0; i<s.size(); i++){
//         cout<<s[i]<<" ";
//     }
//     cout<<endl; 
//     return 0;
// }

// ==================================================================18
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     double nums;
//     cout<<"Enter a number: ";
//     cin>>nums;

//     double result = sqrt(nums);
//     if(result * result == nums){
//         cout<<"It is a perfect square";
//     }else{
//         cout<<"It is not a perfect square";
//     }
//     return 0;
// }

// =================================================================19
// #include <iostream>
// #include <vector>
// using namespace std;

// int peakIndexInMountainArray(vector<int>& A) {
//     int st = 1, end = A.size() - 2;

//     while(st <= end){
//         int mid = st + (end - st) / 2;

//         if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){
//             return mid;
//         }else if(A[mid-1] < A[mid]){
//             st = mid+1;
//         }else{
//             end = mid-1;
//         }
//     }
//     return -1;    
// }

// int main() {
//     vector<int> A = {0, 3, 8, 9, 5, 2};
//     int peakindex = peakIndexInMountainArray(A);

//     cout<<"The element that is at the peak is: "<<A[peakindex]<<endl;
   
//     return 0; 
// }

// ==================================================================20
// #include <iostream>
// using namespace std;

// void ascendingOrder(int arr[], int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] > arr[j]){
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

// void print(int arr[], int n){
//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     int arr[5] = {4, 1, 5, 2, 3};
//     int n = 5;
//     cout<<"After reversing: "<<endl;
//     ascendingOrder(arr, n);
//     print(arr, n);

//     return 0;
// }

// =======================================================================21
// #include <iostream>
// #include <string>
// using namespace std;

// bool isAlphaNum(char ch){
//     if((ch >= '0' && ch <='9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
//         return true;
//     }
//     return false;
// }

// bool isPalindrome(string s){
//     int st=0, end=s.length()-1;

//     if(!isAlphaNum(s[st])){
//         st++; 
//     }
//     if(!isAlphaNum(s[end])){
//         end--; 
//     }
//     if(tolower(s[st]) != tolower(s[end])){
//         return false;
//     }
//     st++; end--;

//     return true;
// }
// int main(){
//     string s = "Ac$3e3c&a";
//     cout<<isPalindrome(s)<<endl;
    
//     return 0;
// }

// ========================================================================22
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string s = "AA";
//     int A = 0;

//     bool isAbsent = true;
//     bool isLeave = true;

//     for(int i=0; i<s.length(); i++){
//         if(s[i] == 'A'){
//             A++;
//         }
//     }
//     if(A >= 2){
//         isAbsent = false;
//     }
//     for(int i=0; i<s.length(); i++){
//         if(s[i] == 'L'){
//             if(s[i] == s[i+1] && s[i+1] == s[i+2]){
//                 isLeave = false;
//             }
            
//         }
//     }
//     if(isAbsent == false || isLeave == false){
//         cout<<"The student is not eligible"<<endl;
//     }else{
//         cout<<"The student is eligible"<<endl;
//     }
//     return 0;
// }
 
// =========================================================================23
// #include <iostream>
// #include <unordered_map>
// #include <string>
// using namespace std;

// int main() {
//     string str = "hello world";
//     unordered_map<char, int> freq;  

//     for (char i : str) {
//         freq[i]++;  
//     }

//     cout << "Unique characters: ";
//     for (char i : str) {
//         if (freq[i] == 1) {  
//             cout << i << " ";
//         }
//     }
//     return 0;
// }

// ========================================================================24
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main(){
//     vector<int> arr = {-7, -3, 2, 3, 11};
//     vector<int> arr1;

//     for(int i=0; i<arr.size(); i++){
//         arr1.push_back(arr[i] * arr[i]);
//     }
//     sort(arr1.begin(), arr1.end());
//     for(int i=0; i<arr1.size(); i++){
//         cout<<arr1[i]<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// =======================================================================25 
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s = "lamma";
//     string repeat = "";

//     for(int i=0; i<s.length(); i++){
//         char word = s[i];
//         for(int j=i+1; j<s.length(); j++){
//             if(s[i] == s[j]){
//                 repeat += s[i];
//             }
//         }
//     }
//     for(int i=0; i<repeat.length(); i++){
//         char letter = repeat[i];
//         for(int j=i+1; j<repeat.length(); j++){
//             if(repeat[i] == repeat[j]){
//                 repeat.erase(i, 1);
//             }
//         }
//     }
//     cout<<"The repeating letters are: "<<repeat<<endl;
//     return 0;
// }

// ======================================================================26 
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector<int> arr = {5, 2, 11, 7, 15};
//     int target = 9;
//     vector<int> ans;

//     for(int i=0; i<5; i++){
//         int first = arr[i];
//         for(int j=i+1; j<5; j++){
//             int second = arr[j];
//             int sum = first + second;
//             if(sum == target){
//                ans.push_back(i);
//                ans.push_back(j); 
//             }
//         }
//     }
//     if(ans.empty()){
//         cout<<"No pairs found"<<endl;
//     }else{
//         cout<<"The index of the pairs are: ";
//         for(int i : ans){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <map>
// #include <vector>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main(){
    // pair<int, int> p = {1, 5};
    // pair<string, int> s = {"maira", 8};
    // cout<<s.first<<endl;
    // cout<<s.second<<endl;

    // pair<int, pair<char, int>> t = {1, {'a', 3}};
    // cout<<t.first<<endl;
    // cout<<t.second.first<<endl;
    // cout<<t.second.second<<endl;

    // vector<pair<int, int>> vec = {{1, 2}, {2, 3}, {3, 4}};
    // vec.push_back({4, 5});
    // for(auto p : vec){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    // map<string, int> m;
    // m["tv"] = 100;
    // m["laptop"] = 100;
    // m["headphones"] = 50; 
    // m["tablet"] = 120;
    // m["watch"] = 50;
    // for(auto p : m){
    //     cout<<p.first<<" : "<<p.second<<endl;
    // }
    // if(m.find("tv") != m.end()){
    //     cout<<"found\n";
    // }else{
    //     cout<<"not found\n";
    // }

//     vector<int> vec = {1, 2, 3, 4, 5};
//     cout<<*(max_element(vec.begin(), vec.end()))<<endl;

//     return 0;
// }

// ====================================================================27
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> vec;
//     int N;
//     cin>>N;
//     for(int i=0; i<N; i++){
//         int num;
//         cin>>num;
//         vec.push_back(num);
//     } 
//     reverse(vec.begin(), vec.end());
//     for(int i=0; i<vec.size(); i++){
//         cout<<vec[i];
//     } 
//     return 0;
// }

// =====================================================================28 
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
//     vector<int> ans;
//     unordered_set<int> s;
//     int n = grid.size();
//     int a, b;
//     int expSum = 0, actualSum = 0;

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             actualSum += grid[i][j];
//             if(s.find(grid[i][j]) != s.end()){
//                 a = grid[i][j];
//                 ans.push_back(a);
//             }
//             s.insert(grid[i][j]);
//         }
//     }
//     expSum = (n*n) * (n*n + 1) / 2;
//     b = expSum + a - actualSum;
//     ans.push_back(b);
//     return ans;

// }

// int main(){
//     vector<vector<int>> grid = {{9,1,7}, {8,9,2}, {3,4,6}};
//     vector<int> result = findMissingAndRepeatedValues(grid);
//     for(int val : result){
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// ====================================================================29
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// int findDuplicates(vector<int>& nums){
//     unordered_set<int> s;

//     for(int val : nums){
//         if(s.find(val) != s.end()){
//             return val;
//         }
//         s.insert(val);
//     }
//     return -1;
// }

// int main(){
//     vector<int> arr = {3, 1, 2, 3, 4};
//     cout<<"The duplicate value is : "<<findDuplicates(arr)<<endl;

//     return 0;
// }

// ======================================================================30
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector<int> nums = {2,0,2,1,1,0,1,2,0,0};
//     int n = nums.size();

//     int count0 = 0, count1 = 0, count2 = 0;

//     for(int i=0; i<n; i++){
//         if(nums[i] == 0){
//             count0++;
//         }else if(nums[i] == 1){
//             count1++;
//         }else{
//             count2++;
//         }
//     }

//     int idx = 0;
//     for(int i=0; i<count0; i++){
//         nums[idx] = 0;
//         idx++;
//     }
//     for(int i=0; i<count1; i++){
//         nums[idx] = 1;
//         idx++;
//     }
//     for(int i=0; i<count2; i++){
//         nums[idx] = 2;
//         idx++;
//     }

//     for(int val : nums){
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// ========================================================================31
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main(){
//     vector<char> chars = {'a','a','b','b','c','c','c'};
//     int n = chars.size();
//     int idx = 0;

//     for(int i=0; i<n; i++){
//         char ch = chars[i];
//         int count = 0;

//         while(i<n && chars[i] == ch){
//             count++; i++;
//         }
//         if(count == 1){
//             chars[idx++] = ch;
//         }else{
//             chars[idx++] = ch;
//             string str = to_string(count);
//             for(char dig : str){
//                 chars[idx++] = dig;
//             }
//         }
//         i--;
//     }
//     chars.resize(idx);
    
//     for(char val : chars){
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// ========================================================================32
// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string a = "slowing";
//     string b = "fasting";
//     string str = "";

//     for(int i=0; i<a.length(); i++){
//         for(int j=0; j<b.length(); j++){
//             if(a[i] == b[j] && i == j){
//                 str += a[i];
//             }
//         }
//     }
//     cout<<"The repeating part is: "<<str<<endl;

//     return 0;
// }

// =========================================================================33
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums){
//     int n = nums.size();
//     vector<vector<int>> ans;

//     sort(nums.begin(), nums.end());

//     for(int i=0; i<n; i++){
//         if(i>0 && nums[i] == nums[i-1]) continue;
//         int j=i+1, k=n-1;

//         while(j < k){
//             int sum = nums[i] + nums[j] + nums[k];
//             if(sum < 0){
//                 j++;
//             }else if(sum > 0){
//                 k--;
//             }else{
//                 ans.push_back({nums[i], nums[j], nums[k]});
//                 j++; k--;

//                 while(j<k && nums[j] == nums[j-1]) j++;
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     vector<int> vec = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> result = threeSum(vec);

//     for(int i = 0; i < result.size(); i++){
//         for(int j = 0; j < result[i].size(); j++){
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// ======================================================================34
// #include <iostream>
// #include <cmath>
// using namespace std;

// int addDigits(int num){
//     if(num == 0) return 0;
//     while(floor(log10(abs(num))) + 1 != 1){
//         int sum = 0;
//         while(num > 0){
//             int lastDigit = num % 10;
//             num /= 10;
//             sum += lastDigit;
//         }
//         num = sum;
//     }
//     return num;
// }

// int main(){
//     int nums = 0;
//     cout<<"The sum of digits until one digit: "<<addDigits(nums)<<endl;
    
//     return 0;
// }

// =======================================================================35
// #include <iostream>
// #include <vector>
// #include <climits>
// #include <algorithm>
// using namespace std;

// int maximumProduct(vector<int>& nums){
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int maxPro = INT_MIN;

//     for(int i=0; i<n; i++){
//         int j=i+1, k=n-1;
//         while(j < k){
//             int sum = nums[i] * nums[j] * nums[k];
//             maxPro = max(maxPro, sum);
//             j++; k--;
//         }
//     }
//     return maxPro;
// }

// int main(){
//     vector<int> num = {-100, -2, -3, 1};
//     cout<<"Maximum Product of three numbers is: "<<maximumProduct(num)<<endl;
//     return 0;
// }

// =========================================================================36
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// bool rotateString(string s, string goal){
//     int n = s.length();
//     if (n != goal.length()) return false;

//     for (int i = 0; i < n; i++) {
//         rotate(s.begin(), s.begin() + 1, s.end());
//         if (s == goal) return true;
//     }
//     return false;
// }

// int main(){
//     string s = "abcde";
//     string goal = "abced";

//     cout<<rotateString(s, goal)<<endl;
    
//     return 0;
// }

// ==========================================================================37
// #include <iostream>
// #include <vector>
// using namespace std;

// int maxArea(vector<int>& height){
//     int maxWater = 0;
//     int lp = 0, rp = height.size()-1;

//     while(lp < rp){
//         int w = rp - lp;
//         int ht = min(height[lp], height[rp]);
//         int currWater = w * ht;
//         maxWater = max(maxWater, currWater);

//         height[lp] < height[rp] ? lp++ : rp--;
//     }
//     return maxWater;
// }

// int main(){
//     vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
//     cout<<"The maximum water containing container is: "<<maxArea(height)<<endl;

//     return 0;
// }

// ===========================================================================38
// #include <iostream>
// using namespace std;

// int subtractProductAndSum(int n){
//     int product = 1;
//     int sum = 0;

//     while(n > 0){
//         int lastDigit = n % 10;
//         n /= 10;
//         product *= lastDigit;
//         sum += lastDigit;
//     }
//     int ans = product - sum;
//     return ans;
// }

// int main(){
//     int num = 4421;
//     cout<<subtractProductAndSum(num)<<endl;

//     return 0;
// }

// ==========================================================================39
// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// int findNumbers(vector<int>& nums){
//     int count = 0;

//     for(int i=0; i<nums.size(); i++){
//         int n = nums[i];
//         int digit = (int)log10(n)+1;
//         if(digit % 2 == 0){
//             count++;
//         }
//     }
//     return count;
// }

// int main(){
//     vector<int> num = {555, 901, 482, 1771};
//     cout<<findNumbers(num)<<endl; 

//     return 0;
// }

// ===========================================================================40
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main(){
//     vector<int> num = {1, 2, 0, 0};
//     vector<int> output;
//     int k = 34;
//     int total = 0;

//     for(int n : num){
//         total = total * 10 + n;
//     }
//     int newNum = total + k;
//     while(newNum > 0){
//         int lastDigit = newNum % 10;
//         newNum /= 10;

//         output.push_back(lastDigit);
//     }
//     reverse(output.begin(), output.end());
//     for(int val : output){
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     return 0;
// }





