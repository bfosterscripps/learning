#include <stdio.h>
#include <string.h>
#include "fields.h"

get_mults(IS is)
{
  int i;

  i = 0;
  while (i != 11) {
    printf("Enter the multiple choice answers for questions 1-11 (use - if blank)\n\n> ");
    fflush(stdout);
    i = get_line(is);
    if (i < 0) exit(0);
    printf("\n");
    if (i != 11) printf("You only entered %d answers\n\n", i);
  }
  return;
}

main()
{
  FILE *f;
  IS is;
  char *email;
  char bigstring[10000], out[1000];
  int qnum, outof, pts, i, done;
  char *s;
  char q1a;
  int dash, b, c, d, g, other, ok, e, l1, l2;

  is = new_inputstruct(NULL);
  i = 0;
  while (i != 1) {
    printf("Enter the student's email address: ");
    fflush(stdout);
    i = get_line(is);
    if (i < 0) exit(0);
  }
  email = strdup(is->fields[0]);
  done = 0;
  while (!done) {
    get_mults(is);
    strcpy(bigstring, "<<");
    strcat(bigstring, email);
    strcat(bigstring, ">>=\nSee the grading guide for explanations\n\n");
    
    for (i = 0; i < 11; i++) {
      s = is->fields[i];
      qnum = i+1;
      pts = -1;
      if (qnum == 1) {
        q1a = s[0];
      }
      if (strlen(s) > 1) {
        printf("Question %d: Bad answer: %s\n", qnum, s);
      } else if (qnum >= 1 && qnum <= 3) {
        outof = 3;
        if (s[0] == '-') {
          pts = 0;
        } else if (qnum == 1 && s[0] == 'c') {
          pts = 3;
        } else if (qnum == 2 && s[0] == 'i') {
          pts = 3;
        } else if (qnum == 2 && s[0] == 'g') {
          pts = 1;
        } else if (qnum == 2 && s[0] == 'd') {
          pts = 1;
        } else if (qnum == 2 && s[0] == 'j') {
          pts = 1;
        } else if (qnum == 3 && s[0] == 'c') {
          pts = 3;
        } else if (qnum == 3 && s[0] == 'f') {
          pts = 1;
        } else if (qnum == 3 && s[0] == q1a) {
          pts = 1;
        } else if (s[0] < 'a' || s[0] > 'j') {
          printf("Question %d: Bad answer: %s\n", qnum, s);
        } else {
          pts = 0;
        }
      } else if (qnum >= 4 && qnum <= 7) {
        outof = 4; 
        if (s[0] == '-') {
          pts = 0;
        } else if (qnum == 4 && s[0] == 'b') {
          pts = 4;
        } else if (qnum == 5 && s[0] == 'd') {
          pts = 4;
        } else if (qnum == 6 && s[0] == 'd') {
          pts = 4;
        } else if (qnum == 6 && s[0] == 'b') {
          pts = 1;
        } else if (qnum == 7 && s[0] == 'h') {
          pts = 4;
        } else if (qnum == 7 && s[0] == 'g') {
          pts = 3;
        } else if (qnum == 7 && s[0] == 'c') {
          pts = 1;
        } else if (s[0] < 'a' || s[0] > 'h') {
          printf("Question %d: Bad answer: %s\n", qnum, s);
        } else {
          pts = 0;
        }
      } else if (qnum >= 8 && qnum <= 11) {
        outof = 4; 
        if (s[0] == '-') {
          pts = 0;
        } else if (qnum == 8 && s[0] == 'g') {
          pts = 4;
        } else if (qnum == 8 && s[0] == 'h') {
          pts = 1;
        } else if (qnum == 9 && s[0] == 'l') {
          pts = 4;
        } else if (qnum == 9 && s[0] == 'm') {
          pts = 3;
        } else if (qnum == 9 && s[0] == 'h') {
          pts = 1;
        } else if (qnum == 10 && s[0] == 'k') {
          pts = 4;
        } else if (qnum == 10 && s[0] == 'l') {
          pts = 3;
        } else if (qnum == 10 && s[0] == 'h') {
          pts = 1;
        } else if (qnum == 11 && s[0] == 'e') {
          pts = 4;
        } else if (qnum == 11 && s[0] == 'd') {
          pts = 3;
        } else if (qnum == 11 && s[0] == 'k') {
          pts = 1;
        } else if (s[0] < 'a' || s[0] > 'o') {
          printf("Question %d: Bad answer: %s\n", qnum, s);
        } else {
          pts = 0;
        }
      }
      if (pts >= 0) {
        sprintf(out, "Question %d : %d / %d -- Your answer: %c\n", 
           qnum, pts, outof, s[0]);
        strcat(bigstring, out);
      } else {
        i = 100;
      } 
    }
    done = (i == 11);
  }

  /* Question 12 */

  done = 0;
  outof = 4;
  qnum = 12;
  while (!done) {
    printf("Enter the answers for 12 (- for none): ");
    fflush(stdout);
    i = get_line(is);
    if (i < 0) exit(1);
    if (i > 0 && i < 6) {
      dash = 0; b = 0; c = 0; other = 0; ok = 1;
      for (i = 0; i < is->NF; i++) {
        s = is->fields[i];
        if (strlen(s) > 1) {
          printf("Bad input for Q12: %s\n", is->fields[i]);
          ok = 0;
        } else if (s[0] == '-') {
          dash = 1;
        } else if (s[0] == 'b') {
          b = 1;
        } else if (s[0] == 'c') {
          c = 1;
        } else if (s[0] >= 'a' && s[0] <= 'e') {
          other = 1;
        } else {
          printf("Bad input for Q12: %s\n", is->fields[i]);
          ok = 0;
        }
      }
      if (ok) {
        done = 1;
        if (!b) {
          pts = 0;
        } else if (b && c) {
          pts = 1;
        } else if (b && other) {
          pts = 2;
        } else {
          pts = 4;
        }
      } 
    }
  }
  sprintf(out, "Question %d : %d / %d -- Your answer:", 
           qnum, pts, outof, s[0]);
  strcat(bigstring, out);
  for (i = 0; i < is->NF; i++) {
    strcat(bigstring, " ");
    strcat(bigstring, is->fields[i]);
  }
  strcat(bigstring, "\n");

  /* Question 13 */

  done = 0;
  outof = 5;
  qnum = 13;
  while (!done) {
    printf("Enter the answers for 13 (- for none): ");
    fflush(stdout);
    i = get_line(is);
    if (i < 0) exit(1);
    if (i > 0 && i < 8) {
      dash = 0; l1 = 0; l2 = 0; c = 0; e = 0; ok = 1;
      for (i = 0; i < is->NF; i++) {
        s = is->fields[i];
        if (strlen(s) > 1) {
          printf("Bad input for Q12: %s\n", is->fields[i]);
          ok = 0;
        } else if (s[0] == '-') {
          dash = 1;
        } else if (s[0] == 'c') {
          c = 1;
        } else if (s[0] == 'e') {
          e = 1;
        } else if (s[0] == 'b' || s[0] == 'f') {
          l1 = 1;
        } else if (s[0] >= 'a' && s[0] <= 'g') {
          l2 = 1;
        } else {
          printf("Bad input for Q12: %s\n", is->fields[i]);
          ok = 0;
        }
      }
      if (ok) {
        done = 1;
        if (c || e) {
          if (c && e) {
            pts = 5;
          } else {
            pts = 4;
          }
          if (l1) pts -= 1;
          if (l2) pts -= 2;
        } else if (l1 && !l2) {
          pts = 1;
        } else {
          pts = 0;
        }
      } 
    }
  }
  sprintf(out, "Question %d : %d / %d -- Your answer:", 
           qnum, pts, outof, s[0]);
  strcat(bigstring, out);
  for (i = 0; i < is->NF; i++) {
    strcat(bigstring, " ");
    strcat(bigstring, is->fields[i]);
  }
  strcat(bigstring, "\n");

  /* Question 14 */

  done = 0;
  outof = 5;
  qnum = 14;
  while (!done) {
    printf("Enter the answers for 14 (- for none): ");
    fflush(stdout);
    i = get_line(is);
    if (i < 0) exit(1);
    if (i > 0 && i < 9) {
      dash = 0; l1 = 0; l2 = 0; c = 0; e = 0; ok = 1;
      for (i = 0; i < is->NF; i++) {
        s = is->fields[i];
        if (strlen(s) > 1) {
          printf("Bad input for Q12: %s\n", is->fields[i]);
          ok = 0;
        } else if (s[0] == '-') {
          dash = 1;
        } else if (s[0] == 'c') {
          c = 1;
        } else if (s[0] == 'g') {
          g = 1;
        } else if (s[0] == 'd') {
          d = 1;
        } else if (s[0] == 'h' || s[0] == 'f' || s[0] == 'e') {
          l1 = 1;
        } else if (s[0] >= 'a' && s[0] <= 'h') {
          l2 = 1;
        } else {
          printf("Bad input for Q12: %s\n", is->fields[i]);
          ok = 0;
        }
      }
      if (ok) {
        done = 1;
        if (c || g || d) {
          if (c && g) {
            pts = 5;
          } else if (c || g) {
            pts = 4;
          } else {
            pts = 3;
          }
          if (l1) pts -= 1;
          if (l2) pts -= 2;
        } else if (l1 && !l2) {
          pts = 1;
        } else {
          pts = 0;
        }
      } 
    }
  }
  sprintf(out, "Question %d : %d / %d -- Your answer:", 
           qnum, pts, outof, s[0]);
  strcat(bigstring, out);
  for (i = 0; i < is->NF; i++) {
    strcat(bigstring, " ");
    strcat(bigstring, is->fields[i]);
  }
  strcat(bigstring, "\n");

  printf("\nHere is the grading\n%s\n", bigstring);
  
  i = 0;
  while (i != 1) {
    printf("Enter the grading file to which to append this: ");
    fflush(stdout);
    i = get_line(is);
    if (i < 0) exit(0);
    f = fopen(is->fields[0], "a");
    if (f == NULL) { perror(is->fields[0]); i = 0; }
  }
  fprintf(f, "%s", bigstring);
  fclose(f);
}
