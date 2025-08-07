#include <stdio.h>
#include <string.h>

union Student {
	int roll_no;
	char name[50];
	int marks[5];
	int total;
};

int main() {

	union Student s;
	int temp_marks[5], total = 0;
	int i;  // Declare i outside the loop
	
	printf("Enter Roll Number: ");
	scanf("%d",&s.roll_no);
	printf("Roll Number: %d\n", s.roll_no);
	
	printf("Enter Name: ");
	scanf(" %[^\n]", s.name);
	printf("Name; %s\n", s.name);
	
	printf("Enter Marks:\n");
	for(i = 0; i < 5; i++) {
		printf("Subject %d: ", i + 1);
		scanf("%d", &temp_marks[i]);
		total += temp_marks[i];
	
	}
	
	printf("marks: ");
	for(i = 0; i < 5; i++) {
		printf("\nTotal: %d\n", s.total);
		
		return 0;
	}
}
	

