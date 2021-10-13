import java.util.Scanner;

public class Analyzer {
    public static int linearSearch(String[] dataSet, String element)
    {

        int lenData = dataSet.length;
        //Iterate through every index and see if the element is equal to the element at some index in the dataset.
        for(int i=0;i<lenData;i++)
        {
            if(element.equals(dataSet[i]))
            {
                System.out.println("The Linear Search found the element at index "+ i);
                return i;

            }
        }
        System.out.println("The Linear Search did not find the element");
        return -1;
    }
    public static int binarySearch(String[] dataSet, String element)
    {
        int lenData = dataSet.length;
        int minIndex=0;
        int highIndex=lenData;
        int mid;
        //Uses the formulas given in lecture to perform binary search. Return the mid value if it is the element.
        //If the element is greater than the mid of the dataset, make the min the mid+1
        //If the element is less than the mid of the dataset, make the max, the mid-1.
        while(minIndex <= highIndex)
        {
            mid=(minIndex+(highIndex-minIndex)/2);
            if (element.equals(dataSet[mid]))
            {
                System.out.println("The Binary Search found the element at index "+ mid);
                return mid;


            }
            if (element.compareTo(dataSet[mid]) > 0)
            {
                minIndex=mid+1;
            }
            if (element.compareTo(dataSet[mid]) < 0)
            {
                highIndex=mid-1;
            }
        }
        System.out.println("The Binary Search did not find the element");
        return -1;


    }
    public static void main(String args[])
    {


        String[] dataSet = StringData.getData();
        //Scan in the element we want
        Scanner scanner = new Scanner(System.in);
        String element = scanner.next();
        //Check the time the binary search takes
        long firstTime1 = System.nanoTime();
        int result1 = binarySearch(dataSet, element);
        long lastTime1 = System.nanoTime() - firstTime1;

        System.out.println("The Binary Search took "+ lastTime1);
        //Check the time the linear search takes
        long firstTime2 = System.nanoTime();
        int result2 = linearSearch(dataSet, element);
        long lastTime2 = System.nanoTime() - firstTime2;
        System.out.println("The Linear Search took "+ lastTime2);
    }
}
