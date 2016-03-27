int count_square(int, int);

int square_root(int n) {
  return count_square(n, 1);
}

int count_square(int x, int y) {
  if (x < 0) {
    return (-1);
  }
  if (y * y == x) {
    return (y);
  }
  if (y * y > x) {
    return (-1);
  }
  return count_square(x, y + 1);
}
