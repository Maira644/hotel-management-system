// ======================================================================1
// #include <iostream>
// #include <vector>
// using namespace std;

// int countNegatives(vector<vector<int>>& grid){
//     int count = 0;

//     for(int i=0; i<grid.size(); i++){
//         for(int j=0; j<grid[i].size(); j++){
//             if(grid[i][j] < 0){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main(){
//     vector<vector<int>> mat = {{5,1,0}, {-5,-5,-5}};
//     cout<<"The total count of negative numbers is: "<<countNegatives(mat)<<endl;

//     return 0;
// }

// =====================================================================2
// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
//     string first = "";
//     string second = "";

//     for(int i=0; i<word1.size(); i++){
//         first += word1[i];
//     }
//     for(int i=0; i<word2.size(); i++){
//         second += word2[i];
//     }
//     if(first == second){
//         return true;
//     }
//     return false;  
// }

// int main(){
//     vector<string> word1 = {"abc", "d", "defg"};
//     vector<string> word2 = {"abcddefg"};

//     cout<<arrayStringsAreEqual(word1, word2)<<endl;

//     return 0;
// }

// =====================================================================3
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// int main(){
//     vector<int> digit = {1,2,3};
//     vector<int>digits;
//     int num = 0;

//     for(int d : digit){
//         num = num * 10 + d;
//     }

//     num += 1;

//     while(num > 0){
//         digits.push_back(num % 10);
//         num /= 10;
//     }
//     reverse(digits.begin(), digits.end());

//     for(int val : digits){
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// =====================================================================4
// #include <iostream>
// #include <vector>
// using namespace std;

// bool validMountainArray(vector<int>& arr){
//     if(arr.size() < 3) return false;

//     for(int i=0; i<arr.size()-1; i++){
//         if(arr[i] == arr[i+1]){
//             return false;
//         }
//     }

//     int st = 1, end = arr.size()-2;
//     int peak = -1;
//     while(st <= end){
//         int mid = st + (end - st) / 2;

//         if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
//             peak = mid;
//             break;
//         }else if(arr[mid-1] < arr[mid]){
//             st = mid+1;
//         }else{
//             end = mid-1;
//         }
//     }
//     if(peak == -1) return false;

//     for(int i=0; i<peak; i++){
//         if(arr[i] >= arr[i+1]) return false;
//     }
//     for(int i=peak; i<arr.size()-1; i++){
//         if(arr[i] <= arr[i+1]) return false;
//     }
//     return true;
// }

// int main(){
//     vector<int> arr = {0, 1, 2, 4, 2, 1};

//     cout<<validMountainArray(arr)<<endl;
//     return 0;
// }

// ========================================================================5
// #include <iostream>
// #include <vector>
// using namespace std;

// bool checkIfExist(vector<int>& arr){
//     int n = arr.size();
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     vector<int> arr = {7, 1, 14, 11};
//     cout<<checkIfExist(arr)<<endl;

//     return 0;
// }

// =======================================================================6
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> smallerNumbersThanCurrent(vector<int>& nums){
//     int n = nums.size();
//     vector<int> num;
//     for(int i=0; i<n; i++){
//         int count = 0;
//         for(int j=0; j<n; j++){
//             if(i != j){
//                 if(nums[i] > nums[j]){
//                     count++;
//                 }
//             }
//         }
//         num.push_back(count);
//     }
//     return num;
// }

// int main(){
//     vector<int> nums ={8, 1, 2, 2, 3};
//     vector<int> result = smallerNumbersThanCurrent(nums);

//     for(int val : result){
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// =====================================================================7
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;

// int findLucky(vector<int>& arr) {
//     unordered_map<int, int> freq;
    
//     for (int num : arr) {
//         freq[num]++;
//     }

//     int result = -1;
//     for (auto& p : freq) {
//         if (p.first == p.second) {
//             result = max(result, p.first);
//         }
//     }

//     return result;
// }

// int main(){
//     vector<int> arr = {2, 2, 3, 4};
//     cout<<findLucky(arr)<<endl;

//     return 0;
// } 

// ===================================================================8
// #include<iostream>
// #include <vector>
// #include<algorithm>
// using namespace std;

// int removeElement(vector<int>& nums, int val){
//     nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
//     int k = nums.size();
//     return k;

// }

// int main(){
//     vector<int> nums = {3, 2, 2, 3};
//     int val = 3;

//     cout<<removeElement(nums, val)<<endl;

//     return 0;
// }

// ===================================================================9
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// int strStr(string haystack, string needle){
//     int found = haystack.find(needle);

//     if(0 <= found <= 9){
//         return found;
//     }
//     return -1;
// }

// int main(){
//     string haystack = "leetcode";
//     string needle = "leeto";

//     cout<<"The index is: "<<strStr(haystack, needle)<<endl;

//     return 0;
// }

// =================================================================10
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std; 

// int subarraySum(vector<int>& arr, int k){
//     int n = arr.size();
//     int count = 0;
//     vector<int> prefixSum(n, 0);

//     prefixSum[0] = arr[0];
//     for(int i=1; i<n; i++){
//         prefixSum[i] = prefixSum[i-1] + arr[i];
//     }

//     unordered_map<int, int> m;
//     for(int j=0; j<n; j++){
//         if(prefixSum[j] == k) count++;
    

//         int val = prefixSum[j] - k;
//         if(m.find(val) != m.end()){
//             count += m[val];
//         }

//         if(m.find(prefixSum[j]) == m.end()){
//             m[prefixSum[j]] = 0;
//         }
//         m[prefixSum[j]]++;
//     }
//     return count;
// }

// int main(){
//     vector<int> arr = {1, 1, 1};
//     int k = 2;

//     cout<<subarraySum(arr, k)<<endl;

//     return 0;
// }

// ====================================================================11
// #include<iostream>
// #include<string>
// using namespace std;

// bool isVowel(char ch){
//     if(tolower(ch)=='a' || tolower(ch)=='e' || tolower(ch)=='i' || tolower(ch)=='o' || tolower(ch)=='u'){
//         return true;
//     }else{
//         return false;
//     }
// }

// string reverseVowels(string s){
//     int st = 0, end = s.length()-1;

//     while(st < end){
//         if(!isVowel(s[st])) st++;
//         else if(!isVowel(s[end])) end--;
//         else{
//             swap(s[st], s[end]);
//             st++; end--;
//         }
//     }
//     return s;
// }

// int main(){
//     string s = "A man, a plan, a canal: Panama";
//     cout<<reverseVowels(s)<<endl;

//     return 0;
// }

// ====================================================================12
// #include <iostream>
// #include <vector>
// #include <unordered_set>
// using namespace std;

// vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//     unordered_set<int> set1(nums1.begin(), nums1.end());
//     unordered_set<int> result;

//     for (int num : nums2) {
//         if (set1.find(num) != set1.end()) {
//             result.insert(num);  
//             set1.erase(num);     
//         }
//     }

//     return vector<int>(result.begin(), result.end());
// }

// int main() {
//     vector<int> nums1 = {4, 9, 5};
//     vector<int> nums2 = {9, 4, 9, 8, 4};

//     vector<int> output = intersection(nums1, nums2);

//     for (int val : output) {
//         cout << val << " ";
//     }
//     cout << endl;

//     return 0;
// }

// =====================================================================13
// #include<iostream>
// using namespace std;

// int main(){
//     int n;
//     string ans;
//     while(true){
//         cout<<"Enter a number between 1 and 8";
//         cin>>n;
//         if(n < 1 || n > 8){
//             cout<<"Invalid Input.. enter a number between 1 to 8"<<endl;
//         }
//         for(int i=1; i<=n; i++){
//         for(int j=i; j<n; j++){
//             cout<<".";
//         }
//         for(int j=1; j<=i; j++){
//             cout<<"#";
//         }
//         for(int j=1; j<=1; j++){
//             cout<<" ";
//         }
//         for(int j=1; j<=1; j++){
//             cout<<" ";
//         }
//         for(int j=1; j<=n; j++){
//             if(i == 1){
//                 cout<<"=";
//             }else{
//                 cout<<".";
//             }
//         }
//         for(int j=1; j<=1; j++){
//                 cout<<" ";
//         }
//         for(int j=1; j<=1; j++){
//             cout<<" ";
//         }
//         for(int j=1; j<=i; j++){
//             cout<<"#";
//         }
//         for(int j=i; j<n; j++){
//             cout<<".";
//         }
//         cout<<endl;
//     }
//     cout<<"Do you want to continue..(yes/no)";
//     cin>>ans;
//     if(ans == "yes"){
//         continue;
//     }else{
//         break;
//     }
//     return 0;
//     }
// }

// =================================================================14
// #include<iostream>
// using namespace std;

// void printNUms(int n){
//     if(n == 1){
//         cout<<"1\n";
//         return;
//     }
//     cout<<n<<" ";
//     printNUms(n-1);
// }
// int main(){
//     printNUms(10);

//     return 0;
// }

// =================================================================15 
// #include<iostream>
// using namespace std;

// int factorial(int n){
//     if(n == 0){
//         return 1;
//     }
//     return n * factorial(n-1);
// }

// int main(){
//     cout<<factorial(5)<<endl;;

//     return 0;
// }

// =================================================================14 
// #include<iostream>
// using namespace std;

// int Sum(int n){
//     if(n == 1){
//         return 1;
//     }
//     return n + Sum(n-1);
// }

// int main(){
//     cout<<Sum(5)<<endl;;

//     return 0;
// }

// =================================================================15
// #include<iostream>
// #include<vector>
// #include<unordered_set>
// using namespace std;

// bool anyDuplicates(vector<int>& arr){
//     unordered_set<int> dup;

//     for(int num : arr){
//         if(dup.find(num) != dup.end()){
//             return true;
//         }
//         dup.insert(num);
//     }
//     return false;
// }

// int main(){
//     vector<int> arr = {1, 2, 3, 1};
//     cout<<anyDuplicates(arr)<<endl;

//     return 0;
// }

// ===============================================================16 
// #include<iostream>
// #include<vector>
// #include<unordered_set>
// using namespace std;

// vector<int> distinctNum(vector<int>& arr, int k) {
//     vector<int> ans;

//     for (int i = 0; i <= arr.size() - k; i++) {
//         unordered_set<int> seen;

//         for (int j = i; j < i + k; j++) {
//             seen.insert(arr[j]);  
//         }
//         ans.push_back(seen.size());
//     }

//     return ans;
// }

// int main(){
//     vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
//     int k = 4;
//     vector<int> output = distinctNum(arr, k);

//     for(int num : output){
//         cout<<num<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// ==================================================================17 
// #include<iostream>
// using namespace std;

// int Fabonacci(int n){
//     if(n == 0 || n == 1){
//         return n;
//     }
//     return Fabonacci(n-1) + Fabonacci(n-2);
// }
// int main(){
//     cout<<"The Fabonacci series is: "<<Fabonacci(5)<<endl;

//     return 0;
// }

// =================================================================18
// #include<iostream>
// #include<vector>
// using namespace std;

// bool isSorted(vector<int> arr, int n){
//     if(n == 0 || n == 1){
//         return true;
//     }
//     return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
// }

// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = 5;
//     cout<<isSorted(arr, n)<<endl;

//     return 0;
// }

// ================================================================== 19
// #include<iostream>
// #include<vector>
// using namespace std;

// int binSearch(vector<int>& arr, int tar, int st, int end){
//     if(st <= end){
//         int mid = (st + end) / 2;

//         if(arr[mid] == tar) return mid;
//         else if(arr[mid] <= tar){
//             return binSearch(arr, tar, mid+1, end);
//         }else{
//             return binSearch(arr, tar, st, mid-1);
//         }   
//     }
//     return -1;
// }
// int Search(vector<int>& arr, int tar){
//     return binSearch(arr, tar, 0, arr.size()-1);
// }

// int main(){
//     vector<int> arr = {-1, 0, 3, 5, 9, 12};
//     int tar = 9;
//     cout<<Search(arr, tar)<<endl;
//     return 0;
// }

// ================================================================20
// #include<iostream>
// #include<cmath>
// #include<algorithm>
// using namespace std;

// string convertToBase7(int num){
//     if(num == 0) return 0;

//     bool isNegative = num < 0;
//     num = abs(num);
//     string str = "";

//     while(num > 0){
//         int rem = num % 7;
//         str += to_string(rem);
//         num /= 7;
//     }
//     reverse(str.begin(), str.end());

//     if(isNegative)
//     return "-" + str;

//     return str;
    
// }

// int main(){
//     int n = -7;
//     cout<<convertToBase7(n)<<endl;

//     return 0;
// }

// =================================================================21
// #include<iostream>
// #include<vector>
// using namespace std;

// int main(){
//     vector<int> subSets = {1, 2, 3};
//     vector<vector<int>> powerSet;
//     int n = subSets.size();
//     int powerSize = 1 << n; 

//     for(int i=0; i<powerSize; i++){
//         vector<int>vec;
//         for(int j=0; j<n; j++){
//             if((i & (1 << j)) != 0){
//                 vec.push_back(subSets[j]);
//             }
//         }
//         powerSet.push_back(vec);
//     }

//     for(const auto& subset : powerSet){
//         cout<<"{ ";
//         for(int val : subset){
//             cout<<val<<" ";
//         }
//         cout<<"}"<<endl;
//     }
//     return 0;
// }

// =================================================================22
// #include<iostream>
// #include<string>
// #include<cctype>
// using namespace std;

// bool isVowel(char ch){
//     ch = tolower(ch);

//     if(isalpha(ch)){
//         if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
//     }
//     return false;
// }

// bool isConsonant(char ch){
//     ch = tolower(ch);

//     if(isalpha(ch) && !isVowel(ch)) return true;
//     return false;
// }

// bool isValid(string word){
//     if(word.length() < 3) return false;
//     bool digit = false;
//     bool vowel = false;
//     bool consonant = false;
//     bool alphabet = false;

//     for(int i=0; i<word.length(); i++){
//         if(!isalpha(word[i]) && !isdigit(word[i])) return false;
//         else if(isVowel(word[i])){
//             vowel = true;
//             alphabet = true;
//         }else if(isConsonant(word[i])){
//             consonant = true;
//             alphabet = true;
//         }else if(isdigit(word[i])){
//             digit = true;
//         }
//     }

//     bool digOrAl = false;
//     if(digit || alphabet){
//         digOrAl = true;
//     }

//     if(digOrAl && vowel && consonant){
//         return true;
//     }
//     return false;
// }

// int main(){
//     string word = "3pp";
//     if(isValid(word)){
//         cout<<"The condition satisfies"<<endl;
//     }else{
//         cout<<"The condition does not satisfies"<<endl;
//     }

//     return 0;
// }

// ===============================================================23
// #include<iostream>
// using namespace std;

// bool isHappy(int n){
//     while(true){
//         int sum = 0;
//         while(n > 0){
//             int rem = n % 10;
//             n /= 10;
//             int prod = rem * rem;
//             sum += prod;
//         }
//         n = sum;
//         if(n == 1){
//             return true;
//             break;
//         }else if(n == 4){
//             return false;
//             break;
//         }else continue;
//     }
//     return false;
// }

// int main(){
//     int num = 2;
//     cout<<isHappy(num)<<endl;
    
//     return 0;
// }

// ===============================================================24
// #include<iostream>
// using namespace std;

// bool isUgly(int n){
//     if(n <= 0) return false;

//     while(n % 2 == 0){
//         n /= 2;
//     }
//     while(n % 3 == 0){
//         n /= 3;
//     }
//     while(n % 5 == 0){
//         n /= 5;
//     }
//     if(n == 1) return true;
//     return false;
// }

// int main(){
//     int num = 21;
//     if(isUgly(num)){
//         cout<<"True"<<endl;
//     }else{
//         cout<<"False"<<endl;
//     }

//     return 0;
// }

// ===============================================================25
// #include<iostream>
// using namespace std;

// bool isPowerOfThree(int n){
//     if(n == 0 || n < 0) return false;
//     int orig = n;
//     int prod = 1;

//     while(n % 3 == 0){
//         n /= 3;
//         prod *= 3;
//     }

//     if(n == 1){
//         if(orig == prod){
//             return true;
//         }  
//     }
//     return false;
// }

// int main(){
//     int num = 81;
//     cout<<isPowerOfThree(num)<<endl;

//     return 0;
// }

// ==============================================================26
// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
//     vector<int> result;

//     for(int i=0; i<nums1.size(); i++){
//         for(int j=0; j<nums2.size(); j++){
//             if(nums1[i] == nums2[j]){
//                 result.push_back(nums1[i]);
//                 nums2.erase(nums2.begin() + j);
//                 break;
//             }
//         }
//     }
//     return result;
// }

// int main(){
//     vector<int> n1 = {4, 9, 5};
//     vector<int> n2 = {9, 4, 9, 8, 4};

//     vector<int> intersection = intersect(n1, n2);

//     for(int val : intersection){
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// ==============================================================27
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets){
//     int basketSpace = baskets.size();

//     for(int i=0; i<fruits.size(); i++){
//         for(int j=0; j<baskets.size(); j++){
//             if(fruits[i] <= baskets[j] && baskets[j] != -1){
//                 basketSpace--;
//                 baskets[j] = -1;
//                 break;
//             }
//         }
//     }
//     return basketSpace;
// }

// int main(){
//     vector<int> fruit = {4, 2, 5};
//     vector<int> basket = {3, 5, 4};

//     cout<<numOfUnplacedFruits(fruit, basket)<<endl;

//     return 0;
// }

// ==============================================================28
// #include<iostream>
// #include<unordered_map>
// #include<string>
// #include<vector>
// using namespace std;

// int firstUniqChar(string& s){
//     unordered_map<char, int> freq;

//     for (char ch : s) {
//         freq[ch]++;
//     }

//     for (int i = 0; i < s.length(); i++) {
//         if (freq[s[i]] == 1) {
//             return i;
//         }
//     }

//     return -1;
// }

// int main(){
//     string str = "aabb";
//     cout<<firstUniqChar(str)<<endl;
    
//     return 0;
// }

// ==============================================================29
// #include<iostream>
// #include<string>
// #include<sstream>
// #include<algorithm>
// using namespace std;

// string reverseWords(string str){
//     stringstream ss(str);
//     string word;
//     string ans = "";

//     while(ss >> word){ 
//         reverse(word.begin(), word.end());
//         ans += word + " ";
//     }
//     return ans.substr(0, ans.size()-1);
// }

// int main(){
//     string str = "Mr Ding";
//     cout<<"After reversing: "<<reverseWords(str)<<endl;

//     return 0;
// }

// ===============================================================30
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// string largestGoodInteger(string num){
//     string finalStr = "";

//     for(int i=0; i<num.length(); i++){
//         string subnum = "";
//         if(num[i] == num[i+1] && num[i+1] == num[i+2]){
//             subnum += num[i];
//             subnum += num[i];
//             subnum += num[i];
//         }
//         finalStr += subnum; 
//     }
//     sort(finalStr.begin(), finalStr.end(), greater<char>());
//     return finalStr.substr(0, 3);
// }

// int main(){
//     string num = "3200014888";
//     cout<<largestGoodInteger(num)<<endl;

//     return 0;
// }

// ================================================================31
// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// string largestOddNumber(string num) {
//         while(!num.empty() && (num.back() - '0') % 2 == 0){
//             num.pop_back();
//         }
//         return num;
//     }

// int main(){
//     string num = "486379402";
//     cout<<"The highest odd number is: "<<largestOddNumber(num)<<endl;

//     return 0;
// }

// ===============================================================32
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int maximum69Number (int num){
//     int maxNum = num;
//     vector<int> digits;

//     while(num > 0){
//         digits.insert(digits.begin(), num % 10);
//         num /= 10;
//     }

//     for(int i=0; i<digits.size(); i++){
//         int temp = 0;
//         if(digits[i] == 9){
//             digits[i] = 6;
//             for(int d : digits){
//                 temp = (temp * 10) + d;
//             }
//             maxNum = max(maxNum, temp);
//             digits[i] = 9;
//         }else if(digits[i] == 6){
//             digits[i] = 9;
//             for(int d : digits){
//                 temp = (temp * 10) + d;
//             }
//             maxNum = max(maxNum, temp);
//             digits[i] = 6;
//         }
//     }
//     return maxNum;   
// }

// int main(){
//     int num = 9999;
//     cout<<maximum69Number(num)<<endl;

//     return 0;
// }

// ============================================================33
// #include<iostream>
// #include<vector>
// using namespace std;

// void duplicateZeros(vector<int>& arr){
//     int sz = arr.size();
//     for(int i=0; i<sz; i++){
//         if(arr[i] == 0){
//             arr.insert(arr.begin() + (i+1), 0);
//             i++;
//         }
//     }
//     while(arr.size() != sz){
//         arr.pop_back();
//     }
    
// }

// int main(){
//     vector<int> arr = {1,0,2,3,0,4,5,0};
//     duplicateZeros(arr);

//     for(int val : arr){
//         cout<<val<<" ";
//     }
//     cout<<endl;
    
//     return 0;
// }

// ===========================================================34
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// vector<int> sumZero(int n){
//     vector<int> arr;
//     int sum = 0;

//     for(int i=1; i<n; i++){
//         arr.push_back(i);
//         sum += i;
//     }

//     arr.push_back(-sum);
//     return arr;
// }

// int main(){
//     int n = 6;
//     vector<int> output = sumZero(n);

//     for(int val : output){
//         cout<<val<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

// ===========================================================35
// #include<iostream>
// using namespace std;

// class Node{
// public:
//     int data;
//     Node* next;

//     Node(int val){
//         data = val;
//         next = NULL;
//     }
// };

// class List{
//     Node* head;
//     Node* tail;

// public:
//     List(){
//         head = tail = NULL;
//     }

//     void push_front(int val){
//         Node* newNode = new Node(val);
//         if(head == NULL){
//             head = tail = newNode;
//             return;
//         }else{
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     void push_back(int val){
//         Node* newNode = new Node(val);

//         if(head == NULL){
//             head = tail = newNode;
//         }else{
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     void pop_front(){
//         if(head == NULL){
//             cout<<"LL is empty\n";
//             return;
//         }
//         Node* temp = head;
//         head = head->next;
//         temp->next = NULL;

//         delete temp;
//     }

//     void pop_back(){
//         if(head == NULL){
//             cout<<"LL is empty\n";
//             return;
//         }

//         Node* temp = head;
//         while(temp->next != tail){
//             temp = temp->next;
//         }

//         temp->next = NULL;
//         delete tail;
//         tail = temp;
//     }

//     void insert(int val, int pos){
//         if(pos < 0){
//             cout<<"Invalid position\n";
//             return;
//         }
//         if(pos == 0){
//             push_front(val);
//             return;
//         }

//         Node* temp = head;
//         for(int i=0; i<pos-1; i++){
//             if(temp == NULL){
//                 cout<<"Invalid Position\n";
//                 return;
//             }
//             temp = temp->next;
//         }

//         Node* newNode = new Node(val);
//         newNode->next = temp->next;
//         temp->next = newNode;
//     }

//     void printLL(){
//         Node* temp = head;

//         while(temp != NULL){
//             cout<<temp->data<<"->";
//             temp = temp->next;
//         }
//         cout<<"NULL"<<endl;
//     }

//     int search(int key){
//         Node* temp = head;
//         int idx = 0;

//         while(temp != NULL){
//             if(temp->data == key){
//                 return idx;
//             }
//             temp = temp->next;
//             idx++;
//         }
//         return -1;
//     }
// };

// int main(){
//     List ll;

//     ll.push_front(1);
//     ll.push_front(2);
//     ll.push_front(3);

//     ll.push_back(4);
//     ll.pop_front();
//     ll.pop_back();

//     ll.insert(4, 1);

//     ll.printLL();
//     cout<<ll.search(4)<<endl;

//     return 0; 
// }

// =============================================================36
// #include<iostream>
// using namespace std;

// class ListNode{
// public:
//     int data;
//     ListNode* next;

//     ListNode(int val){
//         data = val;
//         next = NULL;
//     }
// };

// ListNode* reverseList(ListNode* head){
//     ListNode* prev = NULL;
//     ListNode* curr = head;
//     ListNode* next = NULL;

//     while(curr != NULL){
//         next = curr->next;
//         curr->next = prev;

//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }

// void printList(ListNode* head){
//     while(head != NULL){
//         cout << head->data << "->";
//         head = head->next;
//     }
//     cout<<"NULL"<<endl;
// }

// int main(){
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);

//     cout << "Original List: ";
//     printList(head);

//     head = reverseList(head);

//     cout << "Reversed List: ";
//     printList(head);

//     return 0;
// }

// ===========================================================37
// #include<iostream>
// using namespace std;

// class ListNode{
// public:
//     int data;
//     ListNode* next;

//     ListNode(int val){
//         data = val;
//         next = NULL;
//     }
// };

// ListNode* middlenode(ListNode* head){
//     ListNode* slow = head;
//     ListNode* fast = head;

//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }

// void printList(ListNode* head){
//     ListNode* temp = head;

//     while(temp != NULL){
//         cout<<temp->data<<"->";
//         temp = temp->next;
//     }
//     cout<<"NULL"<<endl;
// }

// int main(){
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);
//     head->next->next->next->next = new ListNode(5);

//     cout << "Original List: ";
//     printList(head);

//     ListNode* middle = middlenode(head);
//     cout << "Middle Node: " << middle->data << endl;

//     return 0;
// }

// =======================================================38
// #include<iostream>
// using namespace std;

// class ListNode{
// public:
//     int data;
//     ListNode* next;

//     ListNode(int val){
//         data = val;
//         next = NULL;
//     }
// };

// bool hasCycle(ListNode *head){
//     ListNode* slow = head;
//     ListNode* fast = head;

//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;

//         if(slow  == fast){
//             return true;
//         }
//     }
//     return false;
// }

// int main(){
//     // Create nodes
//     ListNode* head = new ListNode(1);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(3);
//     head->next->next->next = new ListNode(4);

//     // Create a cycle manually (last node points back to node 2)
//     head->next->next->next->next = head->next;

//     // Call hasCycle function
//     if (hasCycle(head)) {
//         cout << "Cycle detected!" << endl;
//     } else {
//         cout << "No cycle." << endl;
//     }

//     return 0;
// }

// =====================================================39
// #include<iostream>
// #include<vector>
// using namespace std;

// class Stack{
//     vector<int> v;

// public:
//     void push(int val){
//         v.push_back(val);
//     }

//     void pop(){
//         v.pop_back();
//     }

//     int top(){
//         return v[v.size()-1];
//     }

//     bool empty(){
//         return v.size() == 0;
//     }

// };

// int main(){
//     Stack s;

//     s.push(10);
//     s.push(20);
//     s.push(30);

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;

//     return 0;
// }

// ========================================================40
// #include<iostream>
// #include<list>
// using namespace std;

// class Stack{
//     list<int> ll;

// public:
//     void push(int val){
//         ll.push_front(val);
//     }

//     void pop(){
//         ll.pop_front();
//     }

//     int top(){
//         return ll.front();
//     }

//     bool empty(){
//         return ll.size() == 0;
//     }

// };

// int main(){
//     Stack s;

//     s.push(10);
//     s.push(20);
//     s.push(30);

//     while(!s.empty()){
//         cout<<s.top()<<" ";
//         s.pop();
//     }
//     cout<<endl;

//     return 0;
// }

