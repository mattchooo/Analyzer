public class Analyzer {

    //Scans data set 1-by-1 to find value:
    public static int LinearSearch(String[] dataSet, String element)
    {
        int max = dataSet.length - 1;

        for (int i = 0; i < max; i++)
        {
            int compare = element.compareTo(String.valueOf(dataSet[i]));

            if (compare == 0)
            {
                return i;
            }
        }

        //Else return a -1 as an error:
        return -1;
    }

    //Scans data set through dividing midpoints to find value:
    public static int BinarySearch(String[] dataSet, String element) {
        int low = 0;
        int high = dataSet.length - 1;

        while (high >= low) {

            int mid = (high + low) / 2;
            int compare = element.compareTo(String.valueOf(dataSet[mid]));

            if (compare > 0) {
                low = mid + 1;
            } else if (compare < 0) {
                high = mid - 1;
            } else {
                return mid;
            }
        }

        //Else return -1 as an error:
        return -1;
    }

    public static void main(String[] args)
    {
        //Links string data to acquire characters:
        String [] dataSet = StringData.getData();

        //Tests for not_here input in linear & binary time:
        long startTime = System.nanoTime();
        int linearTime = LinearSearch(dataSet, "not_here");
        long stopTime = System.nanoTime();

        long TotalTime = stopTime - startTime;

        if (linearTime == -1)
        {
            System.out.println("Could not find: not_here using linear time");
        }
        else
        {
            System.out.println("not_here found in " + TotalTime + "nanoseconds using linear time");
        }

        startTime = System.nanoTime();
        int binaryTime = BinarySearch(dataSet, "not_here");
        stopTime = System.nanoTime();

        TotalTime = stopTime - startTime;

        if (binaryTime == -1)
        {
            System.out.println("Could not find: not_here using binary time");
        }
        else
        {
            System.out.println("not_here found in "+ TotalTime + " nanoseconds using binary time");
        }

        //Tests for mzzzz input in linear & binary time:
        startTime = System.nanoTime();
        linearTime = LinearSearch(dataSet, "mzzzz");
        stopTime = System.nanoTime();

        TotalTime = stopTime - startTime;

        if (linearTime == -1)
        {
            System.out.println("Could not find: mzzzz using linear time");
        }
        else
        {
            System.out.println("mzzzz found in "+ TotalTime + " nanoseconds using linear time");
        }

        startTime = System.nanoTime();
        binaryTime = BinarySearch(dataSet, "mzzzz");
        stopTime = System.nanoTime();

        TotalTime = stopTime - startTime;

        if (binaryTime == -1)
        {
            System.out.println("Could not find: mzzzz using binary time");
        }
        else
        {
            System.out.println("mzzzz found in "+ TotalTime + " nanoseconds using binary time");
        }

        //Tests for aaaaa input in linear & binary time:
        startTime = System.nanoTime();
        linearTime = LinearSearch(dataSet, "aaaaa");
        stopTime = System.nanoTime();

        TotalTime = stopTime - startTime;

        if (linearTime == -1)
        {
            System.out.println("Could not find: aaaaa using linear time");
        }
        else
        {
            System.out.println("aaaaa found  "+ TotalTime + " nanoseconds using linear time");
        }

        startTime = System.nanoTime();
        binaryTime = BinarySearch(dataSet, "aaaaa");
        stopTime = System.nanoTime();

        TotalTime = stopTime - startTime;

        if (binaryTime == -1)
        {
            System.out.println("Could not find: aaaaa using binary time");
        }
        else
        {
            System.out.println("aaaaa found in "+ TotalTime + " nanoseconds using binary time");
        }
    }
}
