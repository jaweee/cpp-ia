# 类与类的关系

### 1. 复合（composition）， has-a

queue 和 deque 来解释 composition

而 queue 和 deque 的关系也是表示 adapter

也可以通过内存的角度去看 queue，里面是包含

composition 下类的构造和析构

### 2. 复合（composition by reference），

by reference 是学术界的专有的词

pimpl（handle / body），这是一个非常有名的技巧

reference counting

```cpp
// String

```

```cpp
// StringRep
```

copy on write

### 3. 继承

- 三种继承方式：public、protected、private，public 最有用

- 三种
