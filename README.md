# Project 1: Blood sugar information storage
COSC 2030 project 01

Jacob Williams

### DESCRIPTION:
Stores information about blood sugar over fourteen days and two weeks.


For each day, stores:
- How many blood sugars were read
- The maximum blood sugar read
- The minimum blood sugar read
- The sum of all blood sugar readings.


For each week, stores:
- How many blood sugars were read
- The maximum blood sugar read
- The minimum blood sugar read
- The sum of all blood sugar readings
- The days with the largest per-day change in blood sugar.


Interactivity:
- The user inputs consecutive inputs, allowing positive integral or floating-point values.
- 0 and negative numbers are ignored.
- 'D' or 'Day' shows the daily summary
- 'W' or 'Week' shows the weekly summary
- 'N' or 'Next' goes to next-day input.


Written with only arrays, linked lists.

DUE: October 26.

### PLANNING.
Clearly, we are going to need ARRAYS:
- double daycount[14]
- double daymax[14]
- double daymin[14]
- double daysum[14]

- double weekcount[2]
- double weekmax[2]
- double weekmin[2]
- double weeksum[2]
- double maxchange[4]


We can read values in with cin, and clever manipulation of this will allow us to read in both numerical and character values! (Source for this: Chase Austin)
- Look for floats first, but ignore negative numbers
- Look for the specific character (sequences) that are supposed to interact, ignore otherwise


So the main question remaining is: How do we store the actual values for each day? Do we even need to? 
Perhaps we can just lump them from the input stream into our arrays without worrying about storing specific readings.

Will have to deal with overflow, especially in the per-day and per-week overflow. I'll have to figure out how to deal with that!

Hints! "Big number" helper class
- Trick: string-based number (ugly, but works)
- Better: Store many smaller numbers together, and then just tell the user "sum of all these"
- Or detect when hits MAX_FLT (or whatever) and give as p \* MAX_FLT + remainder

Here, I believe I'll stick with *arrays* as the primary data structure.


### Pseudocode (or pseudopseudocode)


class myStuff{
public:
  // Ended up doing this more or less iteratively in the actual code.
};


### FINAL NOTES

There are a couple of test files, they should be clearly marked. They were just used to test how to deal with overflows and are not part of the actual project!

The code files I compiled:

- bloodSugar.h
- bloodSugar.cpp
- project1.cpp

The executable output file is called Project1.
