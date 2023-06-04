#include <stdio.h>

void hanoi (int discs, char from_peg, char to_peg, char aux_peg) {
    if (discs == 1){
        printf("moving disc %d from %c to %c\n", discs, from_peg, to_peg);
        return;
    }
    hanoi(discs-1, from_peg, aux_peg, to_peg);
    printf("moving disc %d from %c to %c\n", discs, from_peg, to_peg);
    hanoi(discs-1, aux_peg, to_peg, from_peg);
}

int main() {
  // This function prompts the user to enter the number of disks and the names of the three pegs.
  // It then calls the hanoi() function to solve the problem.
  int n;
  char from, to, aux;

  printf("Enter the number of disks: ");
  scanf("%d", &n);

  printf("Enter the names of the three pegs: ");
  scanf(" %c %c %c", &from, &to, &aux);

  hanoi(n, from, to, aux);

  return 0;
}

