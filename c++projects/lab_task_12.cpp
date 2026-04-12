// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int>& a, int l, int m, int r) {
//     int n1 = m - l + 1, n2 = r - m;
//     vector<int> L(n1), R(n2);

//     for (int i = 0; i < n1; i++) L[i] = a[l + i];
//     for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];

//     int i = 0, j = 0, k = l;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) a[k++] = L[i++];
//         else a[k++] = R[j++];
//     }
//     while (i < n1) a[k++] = L[i++];
//     while (j < n2) a[k++] = R[j++];
// }

// void mergeSort(vector<int>& a, int l, int r) {
//     if (l >= r) return;
//     int m = l + (r - l) / 2;
//     mergeSort(a, l, m);
//     mergeSort(a, m + 1, r);
//     merge(a, l, m, r);
// }

// int partitionNormal(vector<int>& a, int l, int r) {
//     int pivot = a[r];
//     int i = l - 1;

//     for (int j = l; j <= r - 1; ++j) {
//         if (a[j] <= pivot) {
//             ++i;
//             swap(a[i], a[j]);
//         }
//     }
//     swap(a[i + 1], a[r]);
//     return (i + 1);
// }

// void quickSortNormal(vector<int>& a, int l, int r) {
//     if (l < r) {
//         int pi = partitionNormal(a, l, r);
//         quickSortNormal(a, l, pi - 1);
//         quickSortNormal(a, pi + 1, r);
//     }
// }

// int partitionRandom(vector<int>& a, int l, int r) {
//     // pick a random index between l and r
//     int randomIndex = l + rand() % (r - l + 1);
    
//     // swap random pivot with last element
//     swap(a[randomIndex], a[r]);
    
//     int pivot = a[r];
//     int i = l - 1;

//     for (int j = l; j <= r - 1; ++j) {
//         if (a[j] <= pivot) {
//             ++i;
//             swap(a[i], a[j]);
//         }
//     }
//     swap(a[i + 1], a[r]);
//     return (i + 1);
// }

// void quickSortRandom(vector<int>& a, int l, int r) {
//     if (l < r) {
//         int pi = partitionRandom(a, l, r);
//         quickSortRandom(a, l, pi - 1);
//         quickSortRandom(a, pi + 1, r);
//     }
// }

// void printVec(const vector<int>& a) {
//     for (int x : a) cout << x << " ";
//     cout << "\n";
// }

// int main() {
//     srand(time(0));

//     vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

//     cout << "Original: ";
//     printVec(arr);

//     auto a1 = arr;
//     auto start1 = chrono::high_resolution_clock::now();
//     quickSortNormal(a1, 0, a1.size() - 1);
//     auto end1 = chrono::high_resolution_clock::now();
//     auto time1 = chrono::duration<double, milli>(end1 - start1).count();

//     cout << "Standard Quick Sort: ";
//     printVec(a1);
//     cout << "Time: " << time1 << " ms\n\n";

//     auto a2 = arr;
//     auto start2 = chrono::high_resolution_clock::now();
//     quickSortRandom(a2, 0, a2.size() - 1);
//     auto end2 = chrono::high_resolution_clock::now();
//     auto time2 = chrono::duration<double, milli>(end2 - start2).count();

//     cout << "Randomized Quick Sort: ";
//     printVec(a2);
//     cout << "Time: " << time2 << " ms\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void splitList(Node* head, Node** first, Node** second) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = head;          
    *second = slow->next; 
    slow->next = NULL;      
}

Node* mergeSorted(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    } else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) 
        return head;

    Node *first, *second;
    splitList(head, &first, &second);

    first = mergeSort(first);
    second = mergeSort(second);

    return mergeSorted(first, second);
}

void insert(Node*& head, int val) {
    if (!head) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = new Node(val);
}

int main() {
    Node* head = NULL;

    insert(head, 38);
    insert(head, 27);
    insert(head, 43);
    insert(head, 3);
    insert(head, 9);
    insert(head, 82);
    insert(head, 10);

    cout << "Original List: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List (Merge Sort): ";
    printList(head);

    return 0;
}

