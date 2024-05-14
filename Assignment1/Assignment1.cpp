#include <iostream>
#include <string.h>
using namespace std;
struct Student
{
    int rollno;
    string name;
    float sgpa;
};
void display(Student arr[], int l)
{
    cout << "Roll no\t\t"
         << "names\t\t"
         << "sgpa\t\t\n";

    for (int i = 0; i < l; i++)
    {
        cout << arr[i].rollno << "\t\t" << arr[i].name << "\t\t" << arr[i].sgpa << endl;
    }
}
void linearSearch(Student arr[], int k, float SGPA)
{
    int found = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr[i].sgpa == SGPA)
        {
            cout << "student found" << endl
                 << "roll no " << arr[i].rollno << ", "
                 << "name " << arr[i].name << ", sgpa " << arr[i].sgpa << endl;
            found = 1;
            break;
        }
    }
    if (found != 1)
    {
        cout << "no student found\n";
    }
}

void bubblesort(Student arr[], int x)
{
    int i, j;
    Student temp;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < x - i; j++)
        {
            if (arr[j].rollno > arr[j + 1].rollno)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void binarySearch(Student arr[], string name, int p)
{
    int f = 0;
    int l = p - 1;
    bool found = false;

    for (int i = f; i = l; i++)
    {
        int mid = (f + l) / 2;
        if (arr[mid].name == name)
        {
            cout << "name found " << endl;
            cout << "roll no " << arr[i].rollno << ", "
                 << "name " << arr[i].name << ", sgpa " << arr[i].sgpa << endl;
            found = true;
            break;
        }
        else if (arr[mid].name > name)
        {
            l = mid - 1;
        }
        else if (arr[mid].name < name)
        {
            f = mid + 1;
        }
    }
    if (found != true)
    {
        cout << "name not found\n";
    }
}
int partition(Student arr[], int low, int high)
{
    Student pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].sgpa > pivot.sgpa)
        {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(Student arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void insertionsort(Student arr[], int n)
{
    int i, j;
    Student key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].name > key.name)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    // Variable declarations

    int n;
    cout << "enter how many students?\n"
         << endl;
    cin >> n;
    Student students[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nenter details for roll no: " << i + 1 << endl;
        cout << "Enter the roll number:";
        cin >> students[i].rollno;
        cout << "\nEnter name of student: ";
        cin >> students[i].name;
        cout << "\nEnter the SGPA: ";
        cin >> students[i].sgpa;
    }

    cout << "\nLIST YOU ENTERED\n";
    display(students, n);
    cout << "\nenter\n"
         << "0-stop\n"
         << "1-bubble sort-sorted list of roll no\n"
         << "2-insertion sort - sorting alphabetically by names\n"
         << "3-first ten toppers using quick sort\n"
         << "4-linear search to find student according to sgpa\n"
         << "5- binary search to search by name\n";
    for (int choice = 0; choice < 10; choice++)
    {
        cout << "\n\nenter your choice\n";
        cin >> choice;
        cout << "\nchoice entered " << choice;
        if (choice == 0)
        {
            cout << "\nthank you\n";
            break;
        }
        switch (choice)
        {
            cout << "\nenter\n"
                 << "1-bubble sort-sorted list of roll no\n"
                 << "2-insertion sort - sorting alphabetically by names\n"
                 << "3-first ten toppers using quick sort\n"
                 << "4-linear search to find student according to sgpa\n"
                 << "5- binary search to search by name\n";
        case 1:
            cout << "\na) using bubble sort - sorted list of roll no\n";
            bubblesort(students, n);
            display(students, n);
            break;

        case 2:
            insertionsort(students, n);
            cout << endl
                 << "\nb) using insertion sort - sorting alphabetically by names\n";
            display(students, n);
            break;

        case 3:
            quickSort(students, 0, n - 1);
            cout << "\nc) first ten toppers using quick sort\n";
            display(students, min(10, n));
            break;

        case 4:
            cout << "\nd) using linear search to find student according to sgpa" << endl
                 << "enter sgpa to be found" << endl;
            float k;
            cin >> k;
            linearSearch(students, n, k);
            break;

        case 5:
            cout << "\ne) using binary search to search by name\n";
            binarySearch(students, "om", n);
            break;
        }
    }

    return 0;
}
