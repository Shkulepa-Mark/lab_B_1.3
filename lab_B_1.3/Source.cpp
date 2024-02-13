#include <iostream>
#include <cmath>
using namespace std;

bool isPowerOfN(int num, int n) {
    while (num % n == 0) {
        num /= n;
    }
    return num == 1;
}

int findMaxNumber(int* arr, int size, int& maxIndex) {
    int maxNum = arr[0];
    maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
            maxIndex = i;
        }
    }

    return maxNum;
}

int& getMaxPowerOfN(int* arr, int size, int n)
{
    int maxIndex;
    int maxNum = findMaxNumber(arr, size, maxIndex);
    int maxN = 0;

    for (int i = 0; i < size; i++) {
        if (isPowerOfN(arr[i], n) && arr[i] > maxN) {
            maxN = arr[i];
        }
    }

    if (maxN != 0) {
        cout << "Max Number: " << maxN << endl;
        return arr[maxIndex];
    }

    cout << "Max Number: " << maxNum << endl;
    arr[maxIndex] = 0;
    return arr[maxIndex];
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* numbers = new int[size];

    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    int n;
    cout << "Enter the base number (n): ";
    cin >> n;

    int& maxNumber = getMaxPowerOfN(numbers, size, n);

    cout << "Updated Array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    delete[] numbers;

    return 0;
}
