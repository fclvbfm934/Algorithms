#include<stdexcept>
/**
*   int binarysearch(cont A, T key)
*
*   Searches a sorted container A for an element key
*   Template parameters:
*       cont: the container that contains the elements, of type T
*       T: the type of the elements in the container
*   Parameters:
        A: the container that has the elements of type T
        key: the element to be found
*   Returns:
        the index the element key is at. Returns -1 if doesn't exist.
*   Exceptions:
*       std::invalid_argument: "Input container is not sorted"
*/
template <typename cont, typename T>
int binarysearch(cont A, T key)
{
    // Check if A is sorted:

    for(int i = 1; i < A.size(); i++)
    {
        if(A[i-1] > A[i])
        {
            throw std::invalid_argument("Input container is not sorted");
        }
    }
    // We are searching for the key in between A[lowerInd] and A[upperInd - 1]
    // The midpoint will be the average, and then we shall confine our search there.
    int lowerInd = 0;
    int upperInd = A.size();
    int midpoint = (lowerInd + upperInd) / 2;

    while(lowerInd != upperInd) //if lowerInd == midpoint, then that means lowerInd and upperInd differ by
        //at most 1
    {
        if(key == A[midpoint])
        {
            return midpoint;
        }
        else if (key < A[midpoint]) //We constrain our search from lowerInd to midpoint
        {
            upperInd = midpoint;
            midpoint = (lowerInd + upperInd) / 2;
        }
        else
        {
            lowerInd = midpoint;
            midpoint = (lowerInd + upperInd) / 2;
        }
    }

    return -1;
}