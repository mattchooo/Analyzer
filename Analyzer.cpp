#include <iostream>

using namespace std;
#include "StringData.h"

#include <cstdlib>

#include <string>
#include <vector>
#include <chrono>


int linearSearch(vector<string> dataSet, string element)
    {

        int lenData = dataSet.size();
        //Iterate through every index and see if the element is equal to the element at some index in the dataset.
        for(int i=0;i<lenData;i++)
        {
            if(element==(dataSet[i]))
            {
                cout << "The Linear Search found the element at index " << i << endl;
                return i;

            }
        }
        printf("The Linear Search did not find the element");
        return -1;
    }
int binarySearch(vector <string> dataSet, string element)
    {
        int lenData = dataSet.size();
        int minIndex=0;
        int highIndex=lenData;
        int mid;
        //Uses the formulas given in lecture to perform binary search. Return the mid value if it is the element.
        //If the element is greater than the mid of the dataset, make the min the mid+1
        //If the element is less than the mid of the dataset, make the max, the mid-1.
        while(minIndex <= highIndex)
        {
            mid=(minIndex+(highIndex-minIndex)/2);
            if (element==dataSet[mid])
            {
                cout << "The Binary Search found the element at index " << mid << endl;
                return mid;


            }
            if (element.compare(dataSet[mid]) > 0)
            {
                minIndex=mid+1;
            }
            if (element.compare(dataSet[mid]) < 0)
            {
                highIndex=mid-1;
            }
        }
        printf("The Binary Search did not find the element");
        return -1;


    }
int main()
    {   //Scan in the element we want
        string element;
        cout << "Enter the element you want to search for: ";
        cin >> element;
        //Get the set of datsets
        vector<string> data=  getStringData();
        //Check the time the binary search takes
        //Use the given function for time
        long firstTime1 = systemTimeNanoseconds();
        int result1;
        result1 = binarySearch(data, element);
        long currentTime1 = systemTimeNanoseconds();
        long lastTime1 = currentTime1 - firstTime1;

        cout << "The Binary Search took " << lastTime1 << endl;
        //Check the time the linear search takes
        long firstTime2 = systemTimeNanoseconds();
        int result2;
        result2 = linearSearch(data, element);
        long currentTime2 = systemTimeNanoseconds();
        long lastTime2 = currentTime2 - firstTime2;
        cout << "The Linear Search took " << lastTime2 << endl;
    }
