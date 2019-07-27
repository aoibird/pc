#include <stdio.h>
#include <string.h>
#define MAXS 105

int cnt1[26], cnt2[26];
int n1, n2;
char str1[MAXS], str2[MAXS];

void swap(int a[], int i, int j)
{
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void sort(int a[], int left, int right)
{
  if (left >= right) return;

  int mid = (left + right) / 2;
  swap(a, left, mid);
  int last = left;
  for (int i = left + 1; i <= right; i++) {
    if (a[i] < a[left]) {
      swap(a, i, ++last);
    }
  }
  swap(a, left, last);
  sort(a, left, last-1);
  sort(a, last+1, right);
}

int compare()
{
  for (int i = 0; i < 26; i++) {
    if (cnt1[i] != cnt2[i]) {
      return 0;
    }
  }
  return 1;
}

void trace()
{
  for (int i = 0; i < 26; i++) {
    printf("%d ", cnt1[i]);
  }
  printf("\n");
  for (int i = 0; i < 26; i++) {
    printf("%d ", cnt2[i]);
  }
  printf("\n");
}

int main()
{
  while (scanf("%s", str1) == 1) {
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    scanf("%s", str2);
    //printf("%s\n", str1);
    //printf("%s\n", str2);

    int i = 0;
    while (str1[i] != '\0') {
      cnt1[str1[i] - 'A'] += 1;
      i++;
    }
    int j = 0;
    while (str2[j] != '\0') {
      cnt2[str2[j] - 'A'] += 1;
      j++;
    }

    sort(cnt1, 0, 25);
    sort(cnt2, 0, 25);

    //trace();

    int result = compare();
    if (result) printf("YES\n");
    else printf("NO\n");
  }

}
