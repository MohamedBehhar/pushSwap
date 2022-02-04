# PushSwap

## Table of contents
  - [The Project](#The-Project)
  - [Gif](#Gif)
  - [Algorithm](#Algorithm)
  - [What I Learned](#What-I-Learned)


## The Project

The goal of this project is to sort an array of integers using the fewest number possible of  the given instructions :

**sa**	:	swap a - swap the first 2 elements at the top of stack a.
**sb**	:	swap b - swap the first 2 elements at the top of stack b. 
**ss**	:	sa and sb at the same time.
**pa**	:	push a - take the first element at the top of b and put it at the top of a. 
**pb**	:	push b - take the first element at the top of a and put it at the top of b. 
**ra**	:	rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
**rb**	:	rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
**rr**	:	ra and rb at the same time.
**rra**	:	reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

## Gif

![Untitled](https://user-images.githubusercontent.com/43113421/152566457-b4d64590-283e-47c5-811b-1ea9ef54fad2.gif)


## Algorithm

To accomplish this project, i decided to work with doubly linked list to implement the stack, and for sorting I worked
with three different algorithms:

**Three Sort:**

I just compar the first element with it's successors and based of this comparision 
decid wich instructions to do.
I should not do more than three instructions.

**Five Sort:**

I find the smallest two element in stack_A and push them to stack _B, when stack_A is of size three, i sort it with 
three sort, and the push the tow elements in stack_B to stack_A.

**Hundred Or Less Sort**
***The first steep:***

I find the median of the elements in the stack_A, the i pushed everything belew the 
median to stack_B, 
when pushing to stack_B i devise the median by two and if the element that i pushed to 
stack_B is less than the 
median / 2, i rotate stack_B (rb) to keep the smallest number on the top.

***The second step:***

I push back the elements in stack_B to stack_A while sorting them, to do this, I find 
the biggest elements in stack_B and push it back to stack_A then rotate stack_A to place that element under the median, i do the same for the 
smallest element in stack_B bui do keep it it the top of stack_A and not rotating it until stack_B is empty.

***The Third step***:
Now that we have the first half (belew the median) sorted, we gonna do the same for the second half of the stack
(above the median), and Congratulation :D you make it.

**Five Hundred or less Sort**

I used radix sort where I do bitwise and operator between 1 and the least significant bit, if it's equal to 1 i 
do ra, else i push that element to stack_B.
I keep repeating this process until stack_A is sorted and stack_B is empty.
	



## What I Learned

I really enjoyed working on this project, it was very hard at the first but  because of it i learned a lot about 
Sorting Algorihms wich is a very important thing to know for every developper.
Also managing memory by prveting any kind of memory leaks and freeing any allocated memory  is crucial to validate
this project.

