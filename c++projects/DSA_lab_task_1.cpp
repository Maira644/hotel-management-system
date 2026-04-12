// #include<iostream>
// using namespace std;

// void displayArray(){
//     int arr[5];

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>arr[i]; 
//     }

//     cout<<"\nThe final Array: "<<endl;
//     for(int i=0; i<5; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     displayArray();

//     return 0;
// }

// question 2:
// #include<iostream>
// using namespace std;

// int sum(){
//     int sum = 0;

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         int num;
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>num;
//         sum += num;
//     }
//     return sum;
// }

// int average(){
//     int sum = 0;

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         int num;
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>num;
//         sum += num;
//     }
//     return sum/5;
// }

// int main(){
//     cout<<"The total sum of 5 numbers is: "<<sum()<<endl;
//     cout<<"The average of 5 numbers is: "<<average()<<endl;

//     return 0;
// }

// question 3:
// #include<iostream>
// #include<climits>
// using namespace std;

// int maximum(){
//     int max = INT_MIN;

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         int num;
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>num;

//         if(num > max){
//             max = num;
//         }
//     }
//     return max;
// }

// int minimum(){
//     int min = INT_MAX;

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         int num;
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>num;

//         if(num < min){
//             min = num;
//         }
//     }
//     return min;
// }

// int main(){
//     cout<<"The maximum number is: "<<maximum()<<endl;
//     cout<<"The minimum number is: "<<minimum()<<endl;

//     return 0;
// }

//  question 4:
// #include<iostream>
// using namespace std;

// void reverse(){
//     int arr[5];

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>arr[i]; 
//     }

//     cout<<"\nAfter reversing: "<<endl;
//     for(int i=4; i>=0; i--){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// int main(){
//     reverse();
//     return 0;
// }

// question 5:
// #include<iostream>
// #include<climits>
// using namespace std;

// int second_largest_element(){
//     int arr[5];

//     cout<<"Enter 5 numbers "<<endl;
//     for(int i=0; i<5; i++){
//         cout<<"Enter "<<(i+1)<< " number: ";
//         cin>>arr[i]; 
//     }

//     int max = INT_MIN;
//     int secondmax = INT_MIN;

//     for(int i=0; i<5; i++){
//         if(arr[i] > max){
//             secondmax = max;
//             max = arr[i];
//         }else if(arr[i] > secondmax && arr[i] != max){
//             secondmax = arr[i];
//         }
//     }
//     return secondmax;
// }

// int main(){
//     cout<<"The second largest element is: "<<second_largest_element()<<endl;

//     return 0;
// }

// question 6:
#include<iostream>
using namespace std;

void countFrequency(int arr[], int n){
    int freq[n];
    int newArr[n];
    int newIndex = 0;

    for(int i=0; i<n; i++){
        int count = 1;
        if(arr[i] == -1){
            continue;
        }
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -1;
            }
        }
        newArr[newIndex] = arr[i];
        freq[newIndex] = count;
        newIndex++;
    }

    cout<<"Element Frequency"<<endl;
    for(int i=0; i<newIndex; i++){
        cout<<newArr[i]<<" : "<<freq[i]<<endl;
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 2, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countFrequency(arr, n);
    return 0;
}