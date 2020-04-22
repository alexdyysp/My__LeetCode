# Java

## 数组
1. 打印矩阵
```java
// one vector
int[] dp = new int[n];
for(int i=0; i<n; i++) System.out.print(dp[i] + " ");
System.out.println();

// two vector
int[][] dp = new int[r + 1][c + 1];
for(int i=0; i<r+1; i++){
  for(int j=0; j<c+1; j++) System.out.print(dp[i][j] + " ");
  System.out.println();
}
```

## 字符串String
1. java一般需要化为char数组或者StringBuilder方便操作
```java
char[] chars1 = s1.toCharArray();
StringBuilder str = new StringBuilder(string);
```

## 二叉树BinaryTree
1. BFS
```java
  Queue<TreeNode> nodeQueue = new LinkedList<TreeNode>();
  while(!nodeQueue.isEmpty()){
    int n = nodeQueue.size();
    //...
    for(int i=0; i<n; i++){
        TreeNode tmp = nodeQueue.poll();
        if(tmp.left!=null) nodeQueue.add(tmp.left);
        if(tmp.right!=null) nodeQueue.add(tmp.right);
    }
    //...
}
```
