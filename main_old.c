#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  uint16_t row_length;
  uint16_t column_length;
  uint16_t data[250]; // Set data on stack
} matrix_t;

void print_row(const uint16_t *data, uint16_t length, bool reverse) {
  if (reverse) {
    for (int i = length - 1; i >= 0; i--) {
      printf("%d ", data[i]);
    }
  } else {
    for (int i = 0; i < length; i++) {
      printf("%d ", data[i]);
    }
  }
}

void test_print_row() {
  printf("Print row test\n");
  uint16_t row[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  print_row(row, 10, false);
  print_row(row, 10, true);
  printf("\nEnd of print row test\n");
}

void print_matrix(const matrix_t *matrix) {
  printf("Print matrix test\n");
  for (uint16_t outer_i = 0; outer_i < matrix->column_length; outer_i++) {
    bool reverse = outer_i % 2 != 0;
    print_row(matrix->data + outer_i * matrix->row_length, matrix->row_length,
              reverse);
  }
  printf("\nEnd of print matrix test\n");
}

void test_print_matrix() {
  uint16_t matrix_one_data[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,
                                  10, 11, 12, 13, 14, 15, 16, 17, 18,
                                  19, 20, 21, 22, 23, 24, 25};
  matrix_t matrix_one = {
      .row_length = 5,
      .column_length = 5,
  };
  memcpy(matrix_one.data, &matrix_one_data, 25 * sizeof(uint16_t));
  print_matrix(&matrix_one);
}

int main() {

  test_print_row();
  test_print_matrix();
}
