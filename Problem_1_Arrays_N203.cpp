
#include <iostream>
using namespace std;

// We declare the arrays

int arr[1000];
int temp[1000];

// The main function where the program starts
int main() {

    // Declare variables for array size 'n' and rotations 'd'
    int n;
    int d;

    // Read the two numbers from the user
    cout<<"first enter no of elements ";cout<<endl;
    cout<<"second enter no of left rotations you need";cout<<endl;
    cin >> n >> d;

    // Optimize 'd' in case it's larger than 'n'
    d = d % n;

    //  Read all the numbers into the main array
    cout<<"enter elements of array";cout<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //displays entered array
    cout<<"array before rotation:";
     for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    // 1. Copy the first 'd' elements into the temp array
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // 2. Shift the rest of the main array to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // 3. Copy the elements from 'temp' back to the end of the main array
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
    cout << "Array after left rotation: ";

    // This loop prints all the numbers
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Print a newline at the end for clean formatting
    cout << endl;
    return 0;
}

