// solution-josebrodriguez.cpp

// Created by: Jose Rodriguez


#include <sstream>
#include <vector>
#include <string>
#include <iostream>

// Creates a class called CountDrinks that has three public methods to count the minimum number of drinks
// to reach the end of the vector, find the maximum number in the drinks vector, and find the minimum
// number of drinks to reach the end of a rearranged vector.
class CountDrinks {
public:
    // Finds the minimum number of drinks Tux should have to reach the end of a vector
    int min_drinks(std::vector<int>& nums) {
        std::vector<int> data{0};

        // Loops through each element in the vector from the parameter
        for (int i = 0; i < nums.size(); ++i) {

            // and counts the number of drinks and then stores into the new vector
            if (i + nums[i] >= data.size()) {
                for (int j = data.size(); j <= i + nums[i]; ++j) {
                    data.push_back(data[i] + 1);
                }
            }

            // Exit for loop to prevent too more iterations than the size of the original vector
            if (data.size() >= nums.size()) {
                break;
            }

        }

        // Returns the value 
        return data[nums.size() - 1] + 1;
    }

    int max_pos(std::vector<int>& nums){ // Finds index of maximum element in vector
        int max_pos = 0; // Initializes the

        // Loop through each element in vector 
        for (int i = 0; i < nums.size(); ++i){
            // and if the current element is greater than the value saved in nums[max_pos]...
            if(nums[i] > nums[max_pos]){ 
                max_pos = i; // then set max_pos to the current iterator
            }
        }

        return max_pos;
    }

    // Rearranges a vector so that the largest element is sent to the front and then calls class method min_drinks
    // to return the minimum number of drinks to reach the end of this new vector
    int min_drinks_rearranged(std::vector<int>& nums, int max_index){
        // Initialize a new vector
        std::vector<int> new_vec;
        new_vec.push_back(nums[max_index]); // and set the first element to the largest element in the old vector

        // Generates values for new vector by inserting all remaing values from old vector and excluding
        // the maximum value since it is already at the beginning
        for (int i = 0; i < nums.size(); ++i){
            if (i != max_index){
                new_vec.push_back(nums[i]);
            }
            
        }

        CountDrinks self;    
        return self.min_drinks(new_vec); // return the minimum number of drinks
    }
};


int main()
{
    // Initializes items to be used to get input
    std::vector<int> vec;
    std::string buffer;
    int data;
    std::getline(std::cin, buffer);
    std::istringstream iss(buffer);

    // Grabs each element from the input stream and inserts it into a vector
    while (iss >> data) vec.push_back(data);

    CountDrinks find;

    // Calls class methods to find the results for Part A and Part B, and prints them into
    // stdout. For Part A, the program finds the minimum number of drinks Tux needs to reach the end of
    // a vector array. For Part B, the program first rearranges the vector before finding the minimum
    // number of drinks.
    std::cout << "Part A: " << find.min_drinks(vec) << std::endl;
    std::cout << "Part B: " << find.min_drinks_rearranged(vec,find.max_pos(vec)) << std::endl;
    
}
