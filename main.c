#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef enum {
  right,
  down,
  left,
  up,
} direction_t;

typedef struct {
  uint16_t row_length;
  uint16_t column_length;
  uint16_t data[250]; // Set data on stack
} matrix_t;

void matrix_print_field(const matrix_t *matrix, uint16_t x, uint16_t y) {
  if (x > matrix->row_length - 1) {
    printf("Invalid X coordinate %d ", x);
  } else if (y > matrix->column_length - 1) {
    printf("Invalid Y coordinate %d ", y);
  } else {
    printf("%d ", *(uint16_t *)(matrix->data + y * matrix->row_length + x));
  }
}

void print_matrix(const matrix_t *matrix) {
  direction_t current_direction = right;

  uint16_t current_row_begin = 0;
  uint16_t current_row_end = matrix->row_length;

  uint16_t current_column_begin = 0;
  uint16_t current_column_end = matrix->column_length;

  uint16_t current_x = 0;
  uint16_t current_y = 0;

  uint32_t counter = 0;

  while (++counter <= matrix->row_length * matrix->column_length) {

    matrix_print_field(matrix, current_x, current_y);
    switch (current_direction) {
    case right:
      current_x++;
      if (current_x == current_row_end - 1) {
        current_direction = down;
        current_row_end--;
      }
      break;
    case down:
      current_y++;
      if (current_y == current_column_end - 1) {
        current_direction = left;
        current_column_end--;
      }
      break;
    case left:
      current_x--;
      if (current_x == current_column_begin) {
        current_direction = up;
        current_row_begin++;
      }
      break;
    case up:
      current_y--;
      if (current_y == current_column_begin + 1) {
        current_direction = right;
        current_column_begin++;
      }
      break;
    }
  }
}

void test_print_matrix() {
  uint16_t matrix_one_data[25] = {1,  2,  3,  4,  5,  6,  7,  8,  9,
                                  10, 11, 12, 13, 14, 15, 16, 17, 18,
                                  19, 20, 21, 22, 23, 24, 25};
  matrix_t matrix_one = {
      .row_length = 5,
      .column_length = 5,
  };

  matrix_t matrix_two = {
      .row_length = 8,
      .column_length = 3,
  };

  matrix_t matrix_three = {
      .row_length = 2,
      .column_length = 4,
  };
  memcpy(matrix_one.data, &matrix_one_data, 25 * sizeof(uint16_t));
  memcpy(matrix_two.data, &matrix_one_data, 24 * sizeof(uint16_t));
  memcpy(matrix_three.data, &matrix_one_data, 8 * sizeof(uint16_t));

  printf("Start matrix one test\n");
  print_matrix(&matrix_one);
  printf("\nEnd matrix one test\n");

  printf("\n");

  printf("Start matrix two test\n");
  print_matrix(&matrix_two);
  printf("\nEnd matrix two test\n");

  printf("\n");

  printf("Start matrix three test\n");
  print_matrix(&matrix_three);
  printf("\nEnd matrix three test\n");

  printf("\n");
}

int main() { test_print_matrix(); }
