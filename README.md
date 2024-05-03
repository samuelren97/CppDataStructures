# C++ Data structures

## Array List

### Constructors
```c++
List<int> list; // Default constructor will initialise the list with a size 20 of the specified type
List<int> list(5); // Parametered constructor takes an int for the initial size of the list
```

### ForEach method
Iterates through the list calling the lambda for each value of the list
#### Mehod signature
```c++
void forEach(std::function<void(const T&)> func) const;
```
#### Example
```c++
list.forEach([](const int& val) {
    std::cout << val << std::endl;
});
```

### Add method
Adds a value at the end of the list
#### Method signature
```c++
void add(const T& value);
```
#### Example
```c++
List<int> list;
list.add(5);
```

### Insert method
Inserts value at specified index
#### Method signature
```c++
void insert(const int& index, const T& value);
```
#### Example
```c++
// before insert: list = { 1, 2, 3 }
list.insert(1, 10);
// result: list = { 1, 10, 2, 3 }
```

### Remove method
Removes the value at the specified index
#### Method signature
```c++
void remove(const int& index);
```
#### Example
```c++
// before remove: list = { 1, 2, 3 }
list.remove(1);
// result : list = { 1, 3 }
```

### Get method
Get a copy of the value at the specified index
#### Method signature
```c++
T get(const int& index);
```
#### Example
```c++
// list = { 1, 2, 3 }
int val = list.get(1);
// val -> 2
```

### Pop method
Returns and removes the last element of the list
#### Method signature
```c++
// list = { 1, 2, 3 }
int val = list.pop();
// list = { 1, 2 }
// val -> 3
```

### Reverse method
Reverses the current list values  
#### Method signature
```c++
void reverse();
```
#### Example
```c++
// list = { 1, 2, 3 }
list.reverse();
// list = { 3, 2, 1 }
```

### ToReversed method
Returns a reversed copy of the instance of the list
#### Method signature
```c++
List toReversed();
```
#### Example
```c++
// list = { 1, 2, 3 }
List<int> newList = list.toReversed();
// list = { 1, 2, 3 }
// newList = { 3, 2, 1 }
```

### Length method
Returns the number of values inside the list  
#### Method signature
```c++
int length() const;
```

### GetSize Method
Returns the maximum size of the list  
#### Method signature
```c++
int getSize() const;
```