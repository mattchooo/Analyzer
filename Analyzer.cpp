//
#include "iostream"
#include "string"
#include "chrono"
#include "StringData.h"

using namespace std;

//Declare prototypes:
int LinearSearch(vector<string> dataset, string element);

int BinarySearch(vector<string> dataset, string element);

int main()
{
    //Links together dataset with getStringData:
    vector <string> dataset = getStringData();

    //Sets up clock as well as finding linear & binary searches for "not_here":
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    int linearTime = LinearSearch(dataset, "not_here");
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::steady_clock::duration duration = end - start;
    float time = duration.count() * 1000.0f;

    if(linearTime == -1)
    {
        cout << "Could not find: not_here using linear time\n";
    }
    else
    {
        cout << "not_here found in " << time << "milliseconds using linear time\n";
    }

    start = chrono::steady_clock::now();
    int binaryTime = BinarySearch(dataset, "not_here");
    end = chrono::steady_clock::now();
    duration = end - start;
    time = duration.count() * 1000.0f;

    if(binaryTime == -1)
    {
        cout << "Could not find: not_here using binary time\n";
    }
    else
    {
        cout << "not_here found in " << time << "milliseconds using binary time\n";
    }

    //Finds linear & binary searches for "mzzzz":
    start = chrono::steady_clock::now();
    int linearTime2 = LinearSearch(dataset, "mzzzz");
    end = chrono::steady_clock::now();
    duration = end - start;
    time = duration.count() * 1000.0f;

    if(linearTime2 == -1)
    {
        cout << "Could not find: mzzzz using linear time\n";
    }
    else
    {
        cout << "mzzzz found in " << time << "milliseconds using linear time\n";
    }


    start = chrono::steady_clock::now();
    int binaryTime2 = BinarySearch(dataset, "mzzzz");
    end = chrono::steady_clock::now();
    duration = end - start;
    time = duration.count() * 1000.0f;

    if(binaryTime2 == -1)
    {
        cout << "Could not find: mzzzz using binary time\n";
    }
    else
    {
        cout << "mzzzz found in " << time << "milliseconds using binary time\n";
    }

    //Finds linear & binary searches for "aaaaa":
    start = chrono::steady_clock::now();
    int linearTime3 = LinearSearch(dataset, "aaaaa");
    end = chrono::steady_clock::now();
    duration = end - start;
    time = duration.count() * 1000.0f;

    if(linearTime3 == -1)
    {
        cout << "Could not find: aaaaa using linear time\n";
    }
    else
    {
        cout << "aaaaa found in " << time << "milliseconds using linear time\n";
    }

    start = chrono::steady_clock::now();
    int binaryTime3 = BinarySearch(dataset, "aaaaa");
    end = chrono::steady_clock::now();
    duration = end - start;
    time = duration.count() * 1000.0f;

    if(binaryTime3 == -1)
    {
        cout << "Could not find: aaaaa using binary time\n";
    }
    else
    {
        cout << "aaaaa found in " << time << "milliseconds using binary time\n";
    }

    return 0;
}

int LinearSearch(vector<string> dataset, string element)
{
    int max = dataset.size() - 1;

    //If element is found, return a positive integer:
    for (int i = 0; i < max; i++)
    {
        if (element == dataset[i])
        {
            return i;
        }
    }

    //Else return a -1 as an error:
    return -1;
}


int BinarySearch(vector<string> dataset, string element) {
    //Declare variables:
    int low = 0;
    int high = dataset.size() - 1;

    //Moves midpoint according to the element's placement:
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int compare = -1000;

        if (element == (dataset[mid]))
            compare = 0;


        //Checks if element is present at midpoint
        if (compare == 0)
            return mid;

        //If element is greater, throw out the lower half:
        if (element > (dataset[mid]))
            low = high + 1;

            //If element is smaller, throw out the bigger half:
        else
            low = high - 1;
    }

    //If element not found, return an error message:
    return -1;
}
