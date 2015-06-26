char *revstring(char *s)
{
  int i, len;
  char tmp;

  len = strlen(s);

  for (i = 0; i < len/2; i++) {
    tmp = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = tmp;
  }
  return s;
}

main()
{ 
  char s1[100];
  char *s;
  
  strcpy(s1, "Give Him Six!");
  s = revstring(s1);
  strcpy(s1, "Jim");
  printf("%s\n", revstring(s1));
  printf("%s\n", s);
}
