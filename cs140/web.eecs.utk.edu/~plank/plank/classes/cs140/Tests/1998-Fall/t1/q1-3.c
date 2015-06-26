a(int i, int j)
{
  i = j + i;
  printf("%d 0x%x\n", i, j);
  j -= 4;
}
 
main()
{
  int i, j;
 
  i = 2;
  j = 10;
 
  printf("%d %d\n", i, j);
  a(i, j);
  printf("%d %d\n", i, j);
}
