// UVa12412 A Typical Homework (a.k.a Shi Xiong Bang Bang Mang)
// Rujia Liu
#include<stdio.h>
#include<string.h>
#define maxn 1000
#define maxl 100
#define EPS 1e-5

int n = 0;
char sid[maxn][maxl];
int cid[maxn];
char name[maxn][maxl];
int score[maxn][5];
int removed[maxn];

const char* course_name[] = {"Chinese", "Mathematics", "English", "Programming"};

int valid(int k) {
  for(int i = 0; i < k; i++) if(!removed[i]) {
    if(strcmp(sid[i], sid[k]) == 0) return 0;
  }
  return 1;
}

void add() {
  for(;;) {
    printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
    scanf("%s", sid[n]);
    if(strcmp(sid[n], "0") == 0) break;
    scanf("%d%s%d%d%d%d", &cid[n], name[n], &score[n][0], &score[n][1], &score[n][2], &score[n][3]);
    if(valid(n)) { score[n][4] = score[n][0]+score[n][1]+score[n][2]+score[n][3]; n++; }
    else printf("Duplicated SID.\n");
  }
}

int rank(int k) {
  int r = 0;
  for(int i = 0; i < n; i++)
    if(!removed[i] && score[i][4] > score[k][4]) r++;
  return r+1;
}

void DQ(int isq) {
  char s[maxl];
  for(;;) {
    printf("Please enter SID or name. Enter 0 to finish.\n");
    scanf("%s", s);
    if(strcmp(s, "0") == 0) break;
    int r = 0;
    for(int i = 0; i < n; i++) if(!removed[i]) {
      if(strcmp(sid[i], s) == 0 || strcmp(name[i], s) == 0) {
        if(isq) printf("%d %s %d %s %d %d %d %d %d %.2f\n", rank(i), sid[i], cid[i], name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], score[i][4]/4.0+EPS);
        else { removed[i] = 1; r++; }
      }
    }
    if(!isq) printf("%d student(s) removed.\n", r);
  }
}

double get_course_stat(int c, int s, int* passed, int* failed) {
  int tot = 0;
  *passed = *failed = 0;
  for(int i = 0; i < n; i++)
    if(!removed[i] && (c == 0 || cid[i] == c)) {
      tot += score[i][s];
      if(score[i][s] >= 60) (*passed)++; else (*failed)++;
    }
  return (double)tot / (double)(*passed + *failed);
}

void get_overall_stat(int c, int* cnt) {
  cnt[0] = cnt[1] = cnt[2] = cnt[3] = cnt[4] = 0;
  for(int i = 0; i < n; i++)
    if(!removed[i] && (c == 0 || cid[i] == c)) {
      int k = 0;
      for(int j = 0; j < 4; j++) if(score[i][j] >= 60) k++;
      cnt[k]++;
    }
}

void stat() {
  int c;
  printf("Please enter class ID, 0 for the whole statistics.\n");
  scanf("%d", &c);
  for(int i = 0; i < 4; i++) {
    int passed, failed;
    double avg = get_course_stat(c, i, &passed, &failed);
    printf("%s\n", course_name[i]);
    printf("Average Score: %.2f\n", avg+EPS);
    printf("Number of passed students: %d\n", passed);
    printf("Number of failed students: %d\n", failed);
    printf("\n");
  }
  int cnt[5];
  get_overall_stat(c, cnt);

  printf("Overall:\n");
  printf("Number of students who passed all subjects: %d\n", cnt[4]);
  printf("Number of students who passed 3 or more subjects: %d\n", cnt[4]+cnt[3]);
  printf("Number of students who passed 2 or more subjects: %d\n", cnt[4]+cnt[3]+cnt[2]);
  printf("Number of students who passed 1 or more subjects: %d\n", cnt[4]+cnt[3]+cnt[2]+cnt[1]);
  printf("Number of students who failed all subjects: %d\n", cnt[0]);
  printf("\n");
}

int main() {
  for(;;) {
    int choice;
    printf("Welcome to Student Performance Management System (SPMS).\n");
    printf("\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n");
    printf("\n");

    scanf("%d", &choice);
    if(choice == 0) break;
    if(choice == 1) add();
    if(choice == 2) DQ(0);
    if(choice == 3) DQ(1);
    if(choice == 4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
    if(choice == 5) stat();
  }
  return 0;
}
