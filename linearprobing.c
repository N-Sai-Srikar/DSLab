#include <stdio.h>
#define SIZE 10
#define EMPTY -1

int hash(int key)
{
    return key % SIZE;
}
int main()
{
    int table[SIZE];
    int i;

    /* Initialize hash table */
    for (i = 0; i < SIZE; i++)
    {
        table[i] = EMPTY;
    }

    int keys[] = {72, 27, 36, 24, 63, 81, 92, 101};
    int n = 8;

    printf("Inserting using Linear Probing...\n");

    for (i = 0; i < n; i++)
    {
        int key = keys[i];
        int index = hash(key);
        int probe = 0;

        /* Apply the formula: h(k, i) = (h'(k) + i) % SIZE */
        while (table[(index + probe) % SIZE] != EMPTY)
        {
            probe++;
            if (probe == SIZE)
            {
                printf("Table Overflow! Cannot insert %d\n", key);
                break;
            }
        }

        if (probe < SIZE)
        {
            int finalIndex = (index + probe) % SIZE;
            table[finalIndex] = key;
        }
    }

    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", table[i]);
    }

    return 0;
}

