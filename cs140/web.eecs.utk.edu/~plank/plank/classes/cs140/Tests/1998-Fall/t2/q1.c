main(int argc, char **argv)
{
  int n, i, k;
  int total;

  if (argc != 2) exit(1);
  n = atoi(argv[1]);
  if (n < 0) exit(1);

  total = -20;

  for (i = 0; i <= n; i++) {
    total++;
    for (k = n; k > 1; k = k / 2) {
      total++;
    }
  }
  printf("%d\n", total);
}

