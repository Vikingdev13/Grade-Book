[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=3076448&assignment_repo_type=AssignmentRepo)
# Gradebook
## Points: 20

## Submission
`commit` and `push` your code to the `master` branch on the remote GitHub repository **before** the deadline.

## Clone
`clone` this repo to repl.it or your local machine using the link provided on the GitHub repo page

Use the included files as your template to start the program maintaining the filenames given.

## Description
You will be creating a program to help a teacher calculate final grades for a class.  The program will calculate a final letter grade base on a standard 90/80/70/60 scale.

You will be taking input from a file that contains all of the names and grades of each student. You will find the average for each student and output each student's final letter grade.

1. Your program should accept the filename from the command-line as shown in the example below
	* Add error checking to make sure the appropriate number of command line arguments were passed
2. Read in the input file correctly
	* Add error checking to make sure the file was opened correctly
3. Calculate the final grade for each student
4. Generate a report that matches the example below
	* Show table of grades with final letter grade
	* Print off all names with the **floating point** average 

### Input file format
The input file will have the following format:
```
First Line: Number of assignments
Second line: Number of students
Third Line: Student Names, space delimited
Fourth+ Line(s): Grades for all students for one assignment, space delimited.
```

Example of input file format:
```
8
5
Joel Bob Susan Hillary John
100 92 84 76 68
99 91 83 75 67
98 90 82 74 66
97 89 81 73 65
96 88 80 72 64
95 87 79 71 63
94 86 78 70 62
93 85 77 69 0 
```

Your program should:
* Calculate final grades
* Print the report

### Requirements
* Use the given template and **filename** for your submission.
* You must use functions in an appropriate way
* Must use dynamic multidimensional arrays
	* 2D array to hold student names
		* Student names will not be longer than 10 characters
	* 2D array to hold all grades
		* Use the values from the file as the sizes for your arrays
	* Array to hold final letter grades
		* Use the values from the file as the sizes for your arrays
* Because your arrays are dynamic your program should be able to handle a file of any reasonable size. (There may be MANY students and grades.)


#### Required Functions (You must fill in the parameters):
```c
void getGrades(...);
void printGrades(...);
void getStudents(...);
void printStudents(...);
void calcGrades(...);
void printFinalLetterGrades(...);
void printPercentageGrades(...);
```

### Example Output
```
$ ./a.out infile.txt
      Joel       Bob     Susan   Hillary      John

       100        92        84        76        68
        99        91        83        75        67
        98        90        82        74        66
        97        89        81        73        65
        96        88        80        72        64
        95        87        79        71        63
        94        86        78        70        62
        93        85        77        69         0
         A         B         B         C         F



      Joel : 96.50 %
       Bob : 88.50 %
     Susan : 80.50 %
   Hillary : 72.50 %
      John : 56.88 %
```
