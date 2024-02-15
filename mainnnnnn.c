#include <stdio.h>

// Function to recursively find the majority element in an array

int majority_element_recursive(int A[], int n)
{
    // Base case: if the array has only one element, it is the majority element

    if(n == 1)
        return A[0];

        // Divide the array into two halves: left and right

    int left_majority = majority_element_recursive(A , n/2);
    int right_majority = majority_element_recursive(A + n/2 , n - n/2 );

    int count = 0;
    for(int i=0; i< n; i++)
        if(A[i] == left_majority)
            count++;

    if(count > n/2)
        return left_majority;


    count = 0;
    for(int i=0; i< n; i++)
        if(A[i] == right_majority)
            count++;


    if(count > n/2)
        return right_majority;

        //They aren't the same, so a doesn't have a majority element
        //Return -1. We treat -1 as a non-element.
    return -1;
}


int main() {
    // Accept user input for the size of the array
    int n ;
    printf("Enter the size of the array (between 1 and 100): ");
    scanf("%d", & n);

    // Accept user input for the array elements
    int A[n];
    printf("Enter %d elements of the array (between 0 and 100):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Find the majority element of the array
    int majority_element = majority_element_recursive(A , n );

    // Print the majority element
    printf("The majority element is %d\n", majority_element);

    return 0;
}
