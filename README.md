Project 2 for CMP SCI 2250 at University of Missouri Saint Louis 1/9/18 by Bryan Fisk

Project Stipulations:

Note: When your main body makes any function calls using arrays, you should output to the screen the array before and after the call to see how it changes.

Part 1) In the first part of this program, start by prompting the user for the size of arrays to work with (accept any values from 1 to 52). You will write several functions that work with integer arrays. Start by writing a function (initialize_array) that takes in an array and fills it with sequential whole numbers (0,1,2 and so on) up to the size of the array.  After initialization, display the array and then call a function that creates a NEW array by shuffling (algorithm given at the bottom of this document) the current one and returning that new array through the return statement. By shuffling, I mean the original contents of the array will be in random locations after the call. So, after this function call, you will have a second array with the numbers shuffled and the original array unchanged. Display the contents of both arrays after the function call.

 

Required functions:

void initialize_array(int [], int);

int * shuffle_array(const int [], int);

void print_array(const int [], int);

 

 

 

 

Part 2) In this part you will write two functions that take in an array and create subarrays from it. One function will go through the array, count up the number of odd numbers in the array. It will then dynamically create a new array, fill it up with the odd integers in the array and then return the size of this array through one of the parameters. The second function will do the same for the even numbers in the array.  Display the original array before making your function calls to split the array, then display all 3 arrays afterwards.

 

Required functions:

 

int * createOddArray(const int [], int, int &);

 

int * createEvenArray(const int [], int, int &);

 

 

 

Part 3) Finally, write a function that takes in two integer arrays and their sizes. This function should then create and allocate an array inside the function of the same size as the largest of these two arrays. The function should then go through both arrays starting at the lowest index. At each index, compare their values and put the highest of these values in the 3rd array that we created. If one array isn’t large enough, the other array will always win at those indices. Output this array. Sort this 3rd array using selection sort and then output the results to the screen again. This array does not need to be returned to the main body.

 

Required functions:

void array_war(int *, int, int *, int);

void sort_array(int *,int);

 

Part 4) Write a main body that feeds each of the parts to each other, one after another. So start by creating a shuffled array. Then split it up with calls to createOddArray and createEvenArray. Then send it to array_war and sort the resulting array.

 

Example:

 

Please enter the size of the array:10

Original array is:[0 1 2 3 4 5 6 7 8 9]

Shuffled array is:[4 5 0 2 3 9 8 1 7 6]

After call to createOddArray, oddArray is:[5 3 1 7]

After call to createEvenArray, evenArray is:[4 0 2 8 6]

ArrayFight winners were:[5 3 2 8 6]

Sorted ArrayFight winners were:[2 3 5 6 8]

 

 

Details: For this project, ensure that all your arrays should be dynamically allocated.

 

Shuffle algorithm: To shuffle an array, you can use the following pseudocode or your own algorithm:

To shuffle an array a of n elements (indices 0..n-1):

  for i from n - 1 downto 1 do

       j = random integer with 0 <= j <= i

       exchange a[j] and a[i]

Notes: Make sure to follow proper programming style and to include comments as you go. Try to debug and finish each part before continuing on with the next part. If at any point you get numbers that do not make sense, this is probably an indication of memory problems, so debug before moving on. I have given you prototypes that should work for all functions. If you feel it is necessary to vary from these prototypes, please talk to me.
