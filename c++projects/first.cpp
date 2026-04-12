// ========================================1
// #include <iostream> 
// using namespace std;

// int main() 
// {
//     int N,count,fact;
//     cout<<"Enter a number: ";
//     cin>>N;

//     fact = 1;
//     count = 1;

//     while(N >= count)
//     {
//         fact = fact * count;
//         count++;
//     }
//     cout<<"The factorial of the given number is: "<<fact<<endl;

        
//     return 0;
// }

// ==========================================2
// #include <iostream> 
// using namespace std;

// int main()
// {
//     char letter;
//     cout<<"Enter a letter: ";
//     cin>>letter;
    
    
//     if(letter >= 'a' && letter <= 'z'){
//         cout<<"The letter is lowercase\n";
//     }else if(letter >= 'A' && letter <= 'Z'){
//         cout<<"The letter is uppercase\n";
//     }else{
//         cout<<"Invalid input, enter an English alphabet!\n";
//     }
//     return 0;
// } 

// =========================================3
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int N;
//     cout<<"Enter a number: ";
//     cin>>N;

//     int sum = 0;
//     for(int count = 1; N >= count; count++){
//         sum = sum + count;
//     }
//     cout<<"The sum of the natural number is: "<<sum<<endl;
//     return 0;
// }

// ==========================================4
// #include <iostream> 
// using namespace std;

// int main(){
//     int num;
//     cout<<"Enter a number: ";
//     cin>>num;

//     int Oddsum = 0;
//     int count = 1;

//     while(num >= count){
//         if(count % 2 != 0){
//             Oddsum = Oddsum + count;
//             count++;
//         }else{
//             count++;
//         }
//     }
//     cout<<"The sum of odd numbers is: "<<Oddsum<<endl;
//     return 0;
// }

// ==========================================5
// #include <iostream> 
// using namespace std;

// int main(){
//     int N,i;
//     cout<<"Enter a number: ";
//     cin>>N;
//     i = 2;
//     bool isPrime = true;
//     while(i <= (N-1)){
//         if(N % i == 0){
//             isPrime = false;
//             break;
//         }
//         i++;
//     }
//     if(isPrime == true){
//         cout<<"It is a prime number";
//     }else{
//         cout<<"It is a non prime number";
//     }

//     return 0;
// }

// =========================================6
// #include <iostream> 
// using namespace std;

// int main()
// {
//    int N,count,sum;
//    cout<<"Enter a number: ";
//    cin>>N;

//    count = 1;
//    sum = 0;

//    while(N >= count){
//     if(count % 3 == 0){
//         sum = sum + count;
//     }
//     count++;
    
//    } 
//    cout<<"The sum of the numbers that are divisible by 3 is "<<sum<<endl;

//     return 0;
// }

// =========================================7
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int n = 4;
//     for(int i=1; i <= n; i++){
//         for(int j=1; j <= n; j++){
//             cout<<j<<" ";
//         }
//         cout<<endl;
//     }
   
//     return 0;
// }

// =========================================8
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int n = 4;
//     for(int i=0; i < n; i++){
//         char ch = 'A';
//     for(int j=0; j < n; j++){
//         cout<<ch<<" ";
//         ch+=1;
//     }
//     cout<<endl;
//     } 
   
//     return 0;
//}

// =========================================9
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int n = 3;
//     int num = 1;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout<< num <<" ";
//             num++;
//         }
//         cout<<endl;
//     }   
//     return 0;
// }

// ========================================10
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int n = 3;
//     char ch = 'A';
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             cout<< ch <<" ";
//             ch++;
//         }
//         cout<<endl;
//     } 
     
//     return 0;
// }

// =========================================11
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int n = 6;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<i+1; j++){
//             cout<<'*'<<" ";
//         }
//         cout<<endl;
//     }
     
//     return 0;
// }

// =========================================12
// #include <iostream> 
// using namespace std;

// int main()
// {
//     int n = 4;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<i+1; j++){
//             cout<<i+1<<" ";
            
//         }
//         cout<<endl;
//     }
     
//     return 0;
// }


// #include <iostream>
// using namespace std;

// int main(){
//     int n = 5;
//     for(int i=1; i<n; i++){
//         for(int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         for(int j=i; j<n; j++){
//             cout<<"  ";
//         }
//         for(int j=i; j<n; j++){
//             cout<<"  ";
//         }
//         for(int j=1; j<=i; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     for(int i=1; i<=n; i++){
//         for(int j=i; j<=n; j++){
//             cout<<"* ";
//         }
//         for(int j=1; j<i; j++){
//             cout<<"  ";
//         }
//         for(int j=1; j<i; j++){
//             cout<<"  ";
//         }
//         for(int j=i; j<=n; j++){
//             cout<<"* ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main(){
//     int n =5;

//     for(int i=1; i<n; i++){
//         for(int j=i; j<=n; j++){
//             cout<<" ";
//         }
//         for(int j=1; j<i; j++){
//             cout<<"*";
//         }
//     for(int j=1; j<=i; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }

//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout<<" ";
//         }
//         for(int j=i; j<n; j++){
//             cout<<"*";
//         }
//     for(int j=i; j<=n; j++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main(){
//     int n = 5;
//     for(int i=1; i< n; i++){
//         for(int j=i; j<=n; j++){
//             cout<<"  ";
//         }
//         for(int j=1; j<i; j++){
//             if(j==1){
//                 cout<<"* ";
//             }else{
//                 cout<<"  ";
//             }
//         }
//         for(int j=1; j<=i; j++){
//             if(j==i){
//                 cout<<"* ";
//             }else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout<<"  ";
//         }
//         for(int j=i; j<n; j++){
//             if(j==i){
//                 cout<<"* ";
//             }else{
//                 cout<<"  ";
//             }
//         }
//         for(int j=i; j<=n; j++){
//             if(j==n ){
//                 cout<<"* ";
//             }else{
//                 cout<<"  ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }

//================================================13
// #include <iostream>
// using namespace std;

// int min(int a, int b){
//     if(a<b){
//         return a;
//     }else{
//         return b;
//     }
// }
    
// int main(){
//     cout<<"The minimum of two numbers is "<<min(5,3)<<endl;
//     return 0;
// }

// ==============================================14
// #include <iostream>
// using namespace std;

// int sumOfDigits(int num){
//     int digitsum = 0;
//     while(num > 0){
//         int lastdig = num % 10;
//         num /= 10;
//         digitsum += lastdig;
//     }
//     return digitsum;
// }
// int main(){
//     cout<<"The sum of the digits is: "<<sumOfDigits(2356)<<endl;
//     return 0;
// }

// ==============================================15
// #include <iostream>
// using namespace std;

// int main(){
//     int n,r,diff;
//     cout<<"Enter the value of n: ";
//     cin>>n;
//     cout<<"Enter the value of r: ";
//     cin>>r;

//     if(r > n){
//         cout<<"Invalid input... r cannot be greater than n!";
//         return 1;
//     }

//     diff = n - r;

//     int factn = 1;
//     int factr = 1;
//     int factdiff = 1;

//     int countn = 1;
//     while(n >= countn){
//         factn = factn * countn;
//         countn++;
//     }
//     int countr = 1;
//     while(r >= countr){
//         factr = factr * countr;
//         countr++;
//     }
//     int countdiff = 1;
//     while(diff >= countdiff){
//         factdiff = factdiff * countdiff;
//         countdiff++;
//     }

//     int bionomial = factn / (factr * factdiff);
//     cout<<"The bionomial coefficient is: "<<bionomial<<endl;
//     return 0; 
// } 

// ============================================16
// #include <iostream>
// using namespace std;

// int main(){
//     int a=0,b=1,c,n,i=3;
//     cout<<"Enter the term: ";
//     cin>>n;
//     cout<<'0'<<endl<<'1'<<endl;
    
//     while(i <= n){
//         c = a + b;
//         cout<<c<<endl;
//         a = b;
//         b = c;
//         i++;
//     }
//     return 0;
// }

// =============================================17
// #include <iostream>
// using namespace std;

// int main(){
//     int n,result,i=0;
//     cout<<"Enter a number: ";
//     cin>>n;

//     while(i <= 12){
//         result = n * i;
//         cout<<n<<" "<<'*'<<" "<<i<<" "<<'='<<" "<<result<<endl;
//         i++;
//     }
//     return 0;
// }

// =============================================18 
// #include <iostream>
// using namespace std;

// int decimal(int decNum){
//     int ans = 0;
//     int power = 1;

//     while(decNum > 0){
//         int rem = decNum % 2;
//         decNum /= 2;
//         ans += (rem * power);
//         power *= 10;  
//     }
//     return ans;
// }
// int main(){
//     cout<<"Binary conversion = "<<decimal(2)<<endl; 
    
//     return 0;
// }

// =============================================19
// #include <iostream>
// using namespace std;

// int binary(int binNum){
//     int ans = 0;
//     int power = 1;

//     while(binNum > 0){
//         int rem = binNum % 10;
//         binNum /= 10;
//         ans += (rem * power);
//         power *= 2;
//     }
//     return ans;
// }
// int main(){
//     cout<<"Decimal conversion = "<<binary(101010)<<endl;

//     return 0;
// }

// =============================================20
// #include <iostream>
// #include <cmath> 
// using namespace std;

// int main() {
//     double result = pow(2, 5);
//     cout << "2 to the power 5 is: " << result << endl;
//     return 0;
// }

// =================================================21
// #include <iostream>
// using namespace std;

// int main(){
//     int num;
//     cout<<"Enter a number: ";
//     cin>>num;

//     if(num <= 0){
//         cout<<"Negative numbers cannot be the power of 2....";
//         return 0;
//     }
//     while(num % 2 == 0){
//         num /= 2;
//     }
//     if(num == 1){
//         cout<<"the given number is power of 2";
//     }else{
//         cout<<"the given number is not power of 2";
//     }
//     return 0;
// }

// =================================================22
// #include <iostream>
// using namespace std;

// int main(){
//     int num,ans,result;
//     cout<<"Enter numbers: ";
//     cin>>num;
//     ans = 0;


//     while(num > 0){
//         int rem = num % 10;
//         num /= 10;
//         ans = (ans + rem) * 10;
//     }
//     ans /= 10;
//     cout<<"Reverse = "<<ans<<endl;

//     return 0;
// }

// ===================================================23
// #include <iostream>
// using namespace std;

// int main(){
//     int nums[] = {5, 15, 22, 1, -15, 24};
//     int size = 6;
//     int smallestIndex = 0;
    

//     for(int i=1; i<size; i++){
//         if(nums[i] < nums[smallestIndex]){
//             smallestIndex = i;
            
//         }
//     }
//     cout << "Smallest number is " << nums[smallestIndex] 
//         << " at index " << smallestIndex << endl;
//     return 0;
// }

// ===================================================24
// #include <iostream>
// using namespace std;

// int linearSearch(int arr[], int sz, int target){
//     for(int i=0; i<sz; i++){
//         if(arr[i] == target){
//             return i;
//         }
//     }
//     return -1;

// }
// int main(){
//     int arr[] = {4, 2, 7, 8, 1, 2, 5};
//     int sz = 7;
//     int target = 8;

//     cout<<linearSearch(arr, sz, target)<<endl;

//     return 0;
// }

// ===================================================25
// #include <iostream>
// using namespace std;

// void reverseArray(int arr[], int sz){
//     int start = 0;
//     int end = sz -1;

//     while(start < end){
//         swap(arr[start] , arr[end]);
//         start++;
//         end--;
//     }
// }
// int main(){
//     int arr[] = {1, 2, 3, 4, 5};
//     int sz = 5; 

//     reverseArray(arr, sz);
//     for(int i=0; i<sz; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     return 0; 
// }

// ===================================================26
// #include <iostream>
// using namespace std;

// int arrPro(int nums[], int size){
//     int product = 1;
//     for(int i=0; i<size; i++){
//         product *= nums[i];
//     }
//     return product;
// }
// int main(){
//     int nums[] = {1, 2, 3, 4, 5};
//     int size = 5;
//     int result = arrPro(nums,size);

//     cout<<"Product = "<<result<<endl;

//     return 0;
// }

// =====================================================27
// #include <iostream>
// using namespace std;

// int main(){
//     int size;
//     cout<<"Enter the size of the array: ";
//     cin>>size;

//     int nums[size];
//     cout<<"Enter "<<size<<" elements: ";
//     for(int i=0; i<size; i++){
//         cin>>nums[i];
//     }
    
//     int min = 0;
//     int max = 0;
    

//     for(int i=1; i<size; i++){
//         if(nums[i] < nums[min]){
//             min = i;    
//         }
//     }

//     for(int i=1; i<size; i++){
//         if(nums[i] > nums[max]){
//             max = i;    
//         }
//     }

//     swap(nums[min] , nums[max]);

//     cout << "Array after swapping: ";
//     for (int i = 0; i < size; i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// ====================================================28
// #include <iostream>
// #include <vector>
// using namespace std;

// int main(){
//     vector <int> nums = {4, 1, 2, 1, 2};
//     int ans = 0;

//     for(int val : nums){
//         ans = ans ^ val;
//     }
//     cout<<"answer = "<<ans<<endl;
//     return 0;
// }

// ====================================================29
// #include <iostream>
// #include <vector> 
// #include <algorithm>
// using namespace std;

// void revVec(vector <int>& vec){
//     reverse(vec.begin(), vec.end());
// }

// int main(){
//     vector <int> nums = {1, 2, 3, 4, 5};

//     revVec(nums);

//     for(int val : nums){
//         cout<<val<<" ";
//     }
//     cout<<endl;
//     return 0;
// }

// =====================================================30
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> PairSum(vector <int> nums, int target){
//     vector <int> ans;
//     int n = nums.size();
//     int i=0, j=n-1;

//     while( i < j){
//         int pairSum = nums[i] + nums[j];
//         if(pairSum > target){
//             j--;
//         }else if(pairSum < target){
//             i++;
//         }else{
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }
//     }
//     return ans;
// }
// int main(){
//     vector <int> nums = {2, 7, 11, 15};
//     int target = 26;

//     vector <int> ans =PairSum(nums, target);
//     cout<<ans[0]<<" , "<<ans[1]<<endl;
//     return 0;
// }

// ====================================================31 
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int Majority(vector <int> nums){
//     int fre = 0, ans = nums[0];
//     int n = nums.size();
//     sort(nums.begin(), nums.end());
//     for(int i=1; i<n; i++){
//         if(nums[i] == nums[i-1]){
//             fre++;
//         }else{
//             fre = 1;
//             ans = nums[i];
//         }
//         if( fre == n/2){
//             return ans;
//         }
//     }
//     return -1;
// }
// int main(){
//     vector <int> nums = {1, 2, 2, 1, 1};
//     int ans = Majority(nums);

//     cout<<"majority element = "<<ans<<endl;
    
//     return 0;
// }

// ====================================================32
// #include <iostream> 
// #include <iomanip>
// using namespace std;

// int main(){
//     float F,C;
//     cout<<"Enter the Fahrenheit temperature: ";
//     cin>>F;

//     C = (F -32) * 5.0 / 9.0;
//     cout<<fixed<<setprecision(1);
//     cout<<"Celsius temperature: "<<C<<endl;
    
//     return 0;
// }

//======================================================33
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main(){
//     int num = 153;
//     int originalnum = num;

//     int sum = 0;
//     while(num > 0){
//         int rem = num % 10;
//         num /= 10;

//         double cube = pow(rem, 3);
//         sum += cube;
//     }
//     if(sum == originalnum){
//         cout<<originalnum<<" is an Armstrong number";
//     }else{
//         cout<<originalnum<<" is not an Armstrong number";
//     }
//     return 0;
// }

//=======================================================34
// #include <iostream>
// using namespace std;

// int main(){
//     int year = 2024;

//     if((year % 4 == 0 && year % 100 != 0) ||
//     (year % 400 == 0)){
//         cout<<year<<" is a leap year";
//     }else{
//         cout<<year<<" is not a leap year";
//     }
//     return 0;
// }


// =======================================================35
// #include <iostream>
// using namespace std;

// int main(){
//     int amount;
//     int denominations[8] = {1000, 500, 100, 50, 10, 5, 2, 1};
//     int counts[8] = {0};

//     cout<<"Enter amount in rupees: ";
//     cin>>amount;
    
//     for(int i=0; i<8; i++){
//         counts[i] = amount / denominations[i];
//         amount = amount % denominations[i];
//     }
//     for(int i=0; i<8; i++){
//         cout<<denominations[i]<<"'s in the given amount is: "<<
//         counts[i]<<endl; 
//     }

//     return 0;
// }

// =======================================================36
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main(){
//     string palindrome;
//     cout<<"Enter a string: ";
//     cin>>palindrome;

//     string original = palindrome;
//     reverse(palindrome.begin(),palindrome.end());
    
//     if(original == palindrome){
//         cout<<"The given string is palindrome";
//     }else{
//         cout<<"The given string is not palindrome";
//     }
//     return 0;
// }

// =======================================================37
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main(){
//     string str,part;
//     cout<<"Enter letters: ";
//     cin>>str;
//     cout<<"Which alphabets you want to erase: ";
//     cin>>part;

//     while(str.length() > 0 && str.find(part) < str.length()){
//         str.erase(str.find(part), part.length());
//     }
//     cout<<"The remaining letters are: "<<str<<" ";
//     cout<<endl;

//     return 0;
// }

// =======================================================38 
// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// int main(){
//     string s;
//     cout<<"Enter the string: ";
//     getline(cin,s);

//     int n = s.length();
//     reverse(s.begin(), s.end());
//     string ans = "";

//     for(int i=0; i<n; i++){
//         string word = "";
//         while(i<n && s[i] != ' '){
//             word += s[i];
//             i++;
//         }
//         reverse(word.begin(), word.end());
//         if(word.length() > 0){
//             ans += " "+word;
//         }
//     }
//     cout<<"The reverse of the string is: "<<ans.substr(1)<<endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>;
// #include <string>
// #include <algorithm>
// using namespace std;

// int main(){
//     vector <string> chars = {"a","a","b","b","c","c","c"};
//     int n = chars.size();
//     int idx = 0;

//     for(int i=0; i<n; i++){
//         string ch = chars[i];
//         int count = 0;

//         while(i<n && chars[i] == ch){
//             count++; i++;
//         }
//         if(count == 1){
//             chars[idx] = ch;
//             idx++;
//         }else{
//             string str = to_string(count);
//             for(char dig : str){
//                 chars[idx] = dig;
//             }
//         }
//         i--;
//     }
//     chars.resize(idx);
//     for()
    
//     return 0;
// }

// ======================================================39
// #include <iostream>
// using namespace std;

// struct Person{
//     string name;
//     int age;
// };

// int main(){
//     Person person1;
//     person1.name = "Maira";
//     person1.age = 18;

//     cout<<"Name: "<<person1.name<<endl;
//     cout<<"Age: "<<person1.age<<endl;

//     return 0;
// }

// =======================================================40
// #include <iostream>
// #include <iomanip>
// using namespace std;

// struct Rectangle{
//     float length;
//     float width;    
// };

// int main(){
//     Rectangle rect;
//     cout<<"Enter length: ";
//     cin>>rect.length;
//     cout<<"Enter width: ";
//     cin>>rect.width;

//     float area = rect.length * rect.width;
//     cout<<fixed<<setprecision(1);
//     cout<<"Area of Rectangle is: "<<area<<endl;

//     return 0;
// } 




 


