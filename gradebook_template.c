#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NAME_LENGTH 10

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus]);
void printGrades(int assigns, int stus, int grades[assigns][stus]);
void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH]);
void printStudents(int stus, char students[stus][NAME_LENGTH]);
void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[]);
void printFinalLetterGrades(int stus, double final_grades[]);
void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[]);

int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		printf("Error!");
	}
	printf("\n");

	FILE *ifp = fopen("input.txt", "r");

	if (ifp == NULL)
	{
		perror("Error");
		return 1;
	}

	int assigns, stus;

	fscanf(ifp, "%d %d", &assigns, &stus);

	// Function calls
	char students[stus][NAME_LENGTH];
	int grades[assigns][stus];
	double final_grades[stus];

	getStudents(ifp, stus, students);
	getGrades(ifp, assigns, stus, grades);

	printStudents(stus, students);
	printGrades(assigns, stus, grades);

	calcGrades(assigns, stus, grades, final_grades);
	printFinalLetterGrades(stus, final_grades);
	printPercentageGrades(stus, students, final_grades);

	// Close file
	fclose(ifp);
	return 0;
}

void getGrades(FILE *ifp, int assigns, int stus, int grades[assigns][stus])
{
	int i, j;
	for (i = 0; i < assigns; ++i)
	{
		for (j = 0; j < stus; ++j)
		{
			fscanf(ifp, "%d", &grades[i][j]);
		}
	}
}

void printGrades(int assigns, int stus, int grades[assigns][stus])
{
	int i, j;
	for (i = 0; i < assigns; ++i)
	{
		for (j = 0; j < stus; ++j)
		{
			printf(" %10d", grades[i][j]);
		}
		printf("\n");
	}
}
void getStudents(FILE *ifp, int stus, char students[stus][NAME_LENGTH])
{
	int i;

	for (i = 0; i < stus; ++i)
	{
		fscanf(ifp, "%s", students[i]);
	}
}

void printStudents(int stus, char students[stus][NAME_LENGTH])
{

	for (int i = 0; i < stus; ++i)
	{
		printf(" %10s", students[i]);
	}
	printf("\n\n");
}

void calcGrades(int assigns, int stus, int grades[assigns][stus], double final_grades[])
{
	int i, j;

	for (i = 0; i < stus; ++i)
	{

		for (j = 0; j < assigns; ++j)
		{
			final_grades[i] += grades[j][i];
		}
		final_grades[i] /= assigns;
	}
}

void printFinalLetterGrades(int stus, double final_grades[])
{
	int i;

	for (i = 0; i < stus; ++i)
	{
		printf("          ");
		if (final_grades[i] >= 90.0)
		{
			printf("A");
		}
		else if (final_grades[i] >= 80.0)
		{
			printf("B");
		}
		else if (final_grades[i] >= 70.0)
		{
			printf("C");
		}
		else if (final_grades[i] >= 60.0)
		{
			printf("D");
		}
		else
		{
			printf("F");
		}
	}
	printf("\n");
}

void printPercentageGrades(int stus, char students[stus][NAME_LENGTH], double final_grades[])
{
	int i;

	for (i = 0; i < stus; ++i)
	{
		printf("\n %10s : %.2f %%", students[i], final_grades[i]);
	}
	printf("\n\n");
}