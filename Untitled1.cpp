#include <iostream>
#include<math.h>
using namespace std;

class Searching {
public:
    int linear(int a[], int n, int key) {
        int position = -1;
        for (int i = 0; i < n; i++) {
            if (key == a[i]) {
                position = i + 1;
                break;
            }
        }
        return position;
    }

    int binary(int a[], int n, int key) {
        int high = n - 1, low = 0, mid, position = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] == key) {
                position = mid +1;
                break;
            } else {
                if (a[mid] > key) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return position;
    }
    
    int jump(int a[], int n, int key) {
        int step = sqrt(n);
        int prev = 0;

        while (a[min(step, n) - 1] < key) {
            prev = step;
            step += sqrt(n);
            if (prev >= n) {
                return -1; // Not found
            }
        }

        for (int i = prev; i < min(step, n); ++i) {
            if (a[i] == key) {
                return i; // Found
            }
        }
        
        return -1;
    }
};

int main() {
    Searching s;
    int n;
    cout << "Enter maximum no of students" << endl;
    cin >> n;

    int a[n];
    int key, choice;
    cout << "Enter the roll no who attended lectures" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> a[i];
    }

    cout << "Enter Roll no to be searched" << endl;
    cin >> key;
    cout << "Enter choice" << endl;
    cout << "1 Linear Search" << endl;
    cout << "2 Binary Search" << endl;
    cout << "3 Jump Search" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            if (s.linear(a, n, key) != -1)
                cout << "Roll no " << key << " Attended lecture" << endl;
            else
                cout << "Roll no " << key << " Didn't Attended lecture" << endl;
            break;

        case 2:
            if (s.binary(a, n, key) != -1)
                cout << "Roll no " << key << " Attended lecture" << endl;
            else
                cout << "Roll no " << key << " Didn't Attended lecture" << endl;
            break;
            
       case 3:
            if (s.jump(a, n, key) != -1)
                cout << "Roll no " << key << " Attended lecture" << endl;
            else
                cout << "Roll no " << key << " Didn't Attended lecture" << endl;
            break;
       
    }

    return 0;
}
