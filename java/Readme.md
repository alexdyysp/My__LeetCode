# Java

## 数组
1. 打印矩阵
```java
  // one vector
  int[] dp = new int[n];
  for(int i=0; i<n; i++) System.out.print(dp[i] + ' ');
  System.out.println();
  
  // two vector
  int[][] dp = new int[r + 1][c + 1];
  for(int i=0; i<r+1; i++){
    for(int j=0; j<c+1; j++)
      System.out.print(dp[i][j] + ' '); System.out.print(' ');
    System.out.println();
  }
```
