#include <stdio.h>
#include <string.h>

int W[6];
int H[6];
int V[6];

int solve()
{
  for (int i = 0; i < 6; i++) {
    if (V[i]) continue;
    int pair = 0;
    for (int j = 0; j < 6; j++)
      if (i!=j && W[i]==W[j] && H[i]==H[j]) { V[i]=V[j]=1; pair=1; break; }
    if (pair == 0) return 0;
  }
  return 1;
}

int main()
{
  while (scanf("%d%d", &W[0], &H[0]) == 2) {
    for (int i = 1; i < 6; i++) {
      scanf("%d%d", &W[i], &H[i]);
    }
    for (int i = 0; i < 6; i++)
      if (H[i] > W[i]) { int temp = W[i]; W[i] = H[i]; H[i] = temp; }

    int result = solve();

    if (result) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
    memset(W, 0, sizeof(W));
    memset(H, 0, sizeof(H));
    memset(V, 0, sizeof(V));
  }
}
