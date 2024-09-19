//chart.cpp
//Sharma, Kalpit
//ksharma12
#include <iostream>
using namespace std;
// Purpose: print the bar chart
// Input Parameters: input array: all the elements are stored in an array:: 
//                                size: size of the array:: largest: largest element
// Output Parameters: print the stars and spaces according to the input
void bar_chart(int input_array[], int size, int largest){
    //consider it as a worksheet and use the concept of rows and columns
    for (int row = largest; row > 0; row--)
    {
        //from the highest to zero using it to print the spaces and stars
        for (int col = 0; col < size; col++)
        {
            if (input_array[col] >= row)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
        
    }
    
}
// Purpose: find the largest value from the input
// Input Parameters: input array: all the elements are stored in the array::
//                   size: size is the number of input elements
// Output Parameters: <Output Parameter Descriptions (separate multiple with a semicolon)>
// Return Value: <Description: Description of return value.> (You may omit this if the function // or method does not return a value).
int find_largest(int values[], int size){
    int largest = 0;
    for (int i = 0; i < size; i++)
    {
        if (values[i] > largest)
        {
            largest = values[i];
        }
        
    }
    return largest;
    //returning the largest value
}
int main(){
    const int MAX = 100;
    //setting it to 100 so that the maximum number of inputs can be 100
    int input_array[MAX];
    int value, count = 0;

    while (cin >> value)
    {
        if (value == 0)
        break; //to ensure that 0 is used to enter all the elements 
        input_array[count] = value;
        count++;
        
    }

    int largest = find_largest(input_array, count);
    bar_chart(input_array, count, largest);// calling the function to print 

    
    return 0;
}