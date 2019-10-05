# Pyton 常用函数

## 列表
- 多元组排序
```python3
  # triple list
  data = [[username[index], timestamp[index], website[index]] for index in range(len(username))]
  # sort username first, timestamps second
  data.sort()
```


## 字典
- defaultdict属于内建函数dict的一个子类，调用工厂函数提供缺失的值。
```python3
  UserTrack = collections.defaultdict(list)
  # 可以直接往对应键值的列表里append内容，不用判断创建
  for u, t, w in data:
    UserTrack[u].append(w);
    
  res = collections.defaultdict(set)
  # 往set内直接添加元素
  for u, w in UserTrack.items():
    for i in itertools.combinations(w, 3):
      res[i].add(u)
```

- 字典排序
可以用dict1.items()，得到包含键，值的元组,由于迭代对象是元组，返回值自然是元组组成的列表

用Lambda 函数对排序的规则进行了定义，x指元组，x[1]是值，x[0]是键
```python3
  # 先逆向排序值长度，再排序键值
  res = sorted(res.items(), key=lambda x:(-len(x[1]), x[0]))
```
