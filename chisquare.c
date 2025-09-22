/*Read text file into a usable structure for the Chi-Square test*/

#include <math.h>
#include <stdio.h>

FILE *fp;
int data[4][5];
float expect[3][3];
float stat[3][4];
float chisquare;

int main(void) {

  // Read the file
  fp = fopen("test_data.txt", "r");
  if (fp != NULL) {
    for (int i = 0; i < 5; i++) {
      // Store the information into a matrix
      fscanf(fp, "%d %d %d %d %d", &data[i][0], &data[i][1], &data[i][2],
             &data[i][3], &data[i][4]);
    }
    // Print the stored information to make sure there is no issue
    printf("Recorded Matrix\n");
    for (int i = 0; i < 4; i++) {
      printf("%d %d %d %d %d \n", data[i][0], data[i][1], data[i][2],
             data[i][3], data[i][4]);
    }
  }

  // Compute and store expected value of the data
  float total = data[3][4]; // Set it to float for floating-point division
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      int total_col = data[3][j];
      int total_row = data[i][4];
      expect[i][j] = total_row * (total_col / total);
    }
  }

  // Compute and store the Chi-Square statistic for each cell
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      int observed = data[i][j];
      float expected = expect[i][j];

      stat[i][j] = pow((observed - expected), 2) / expected;
    }

    // Compute the final Chi-Square test statistic
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        chisquare += stat[i][j];
      }
    }
  }
  printf("the Chi-Square statistic is %f\n", chisquare);

  return 0;
}
