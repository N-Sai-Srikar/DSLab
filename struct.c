#include <stdio.h>

struct Student {
	int roll_no;
	char name[50];
	int marks[5];
	int total;
};

int main() {
	struct Student s;
	s.total = 0;
	int i=0;
	printf("Enter Roll Number: ");
	scanf("%d", &s.roll_no);
	
	printf("Enter Name: ");
	scanf(" %[^\n]", s.name);
	
	for(i = 0; i < 5; i++) {
		printf("Enter marks for subject %d: ", i+1);
		scanf("%d", &s.marks[i]);
		s.total += s.marks[i];
	
}

 	printf("\n--- Student Details (Using Structure) ---\n");
  	printf("Roll Number: %d\n", s.roll_no);
	printf("Name: %s\n", s.name);
	printf("Marks: ");
	for(i = 0; i < 5; i++) {
		  printf("%d ", s.marks[i]);
    }
	printf("\nTotal: %d\n", s.total);
     getch();
	 return 0;
}
