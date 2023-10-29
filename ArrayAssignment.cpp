#include <iostream>

// Define a function to find two numbers in the array that add up to the target.
int* findTwoSum(int* numbers, int numCount, int targetSum) {
    int* resultIndices = new int[2]; // Create an array to store the indices of the two numbers.
    int currentIndex = 0; // Initialize an index for the first number in the array.

    // Utilize a while loop to iterate through the array elements.
    while (currentIndex < numCount) {
        int currentComplement = targetSum - numbers[currentIndex]; // Calculate the complement of the current element.

        // Use a for loop to seek the complement within the remaining elements.
        for (int nextIndex = currentIndex + 1; nextIndex < numCount; ++nextIndex) {
            if (numbers[nextIndex] == currentComplement) {
                resultIndices[0] = currentIndex; // Record the index of the first number.
                resultIndices[1] = nextIndex; // Record the index of the second number.
                return resultIndices; // Provide the result and exit the function.
            }
        }

        ++currentIndex; // Move to the next element if no matching pair is found for the current one.
    }

    delete[] resultIndices; // Deallocate the memory if no solution is found.
    return NULL;
}

int main() {
    int numCount;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> numCount;
    
    int* numbers = new int[numCount]; // Allocate memory for the array.
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < numCount; ++i) {
        std::cin >> numbers[i]; // Input array elements.
    }

    int targetSum;
    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    int* resultIndices = findTwoSum(numbers, numCount, targetSum); // Determine the indices of the two numbers.

    if (resultIndices) {
        std::cout << "Indices of the two numbers: " << resultIndices[0] << " " << resultIndices[1] << std::endl;
        delete[] resultIndices; // Release memory allocated for the result array.
    } else {
        std::cout << "No solution found." << std::endl;
    }

    delete[] numbers; // Release the memory allocated for the array.

    return 0;
}

