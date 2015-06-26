main(int argc, char **argv)
{
  int i;
  int l;

  for (i = 1; i < argc; i++) {
    l = strlen(argv[i]);   
    printf("%c\n", argv[i][l-1]);
  }
}
