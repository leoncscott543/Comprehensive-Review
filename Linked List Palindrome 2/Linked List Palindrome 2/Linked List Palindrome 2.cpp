// Linked List Palindrome 2.cpp : Defines the entry point for the console application.
// given a singly linked list, determine if its a palindrome
/*
base case: 
if the list == NULL return false
if head-link = NULL, return true

using the linked list:
1. size of list 0(n) time complexity... 0(1) space
2. take the size of the list and divide it by 2
3. traverse list up to the size/2 spot.... 
4. call a if_odd(size) function so we know what to do at the halfway mark
5. if size is odd, copy the current node (the half way node) and insert it 
4. make new list by reversing the nodes after size/2
5. compare both list while traversing
6. Space complexity for this solution 0(1), time complexity is 0(n)
7. advantage of this solution is that its a constant space complexity with 0(n) time.... disatvantage is that its more complex to implement and read for someone wanting to update it

using an array
1. find size of list 0(n)
2. make an array and store list's values in it
3. make a while loop that terminatets when we get to the half of the size of the list... 
4. make two interative integers.... one that counts down and one that counts up... ex int up = 0... up++, int down = size().... down--
6. compare array[up] with array[down] each interation
7. if they do not equal, return false
8. at the end of loop, return true; 
9. make sure that all conditions and base cases are satisfied.... dont let the list get away with murder
10. time complexity = 0(n)... space complexity = 0(n) sense we have to make a new array of size n.... 
11. advantage of this method is that its simpler to implement and probably easier to read, but it does take up extra space as a trade off
*/

#include "stdafx.h"


int main()
{
    return 0;
}

