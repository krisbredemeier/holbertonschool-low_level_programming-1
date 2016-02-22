char lowercase(char c) {
  if (c <= 90 && c >= 65) {
    c += 32;
  }
  return c;
}
