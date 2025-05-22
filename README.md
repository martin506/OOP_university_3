# OOP University

This project is an **Object-Oriented Programming (OOP)** task from university. It involves working with large datasets of students, performing operations such as input, sorting, and output, while comparing the performance of different container types and optimization flags.

---

## Performance Metrics

### Input Time
- **10000 students**: `0.16832 seconds`
- **100000 students**: `2.12442 seconds`
- **1000000 students**: `10.4156 seconds`

### Students Generating Time
- **1000 students**: `0.00222296 seconds`
- **10000 students**: `0.0159993 seconds`
- **100000 students**: `0.13162 seconds`
- **1000000 students**: `1.03391 seconds`
- **10000000 students**: `10.1767 seconds`

---

## Average Time for Performance

### Using Different Input Files
#### File: `text_files/students1000.txt`
- **Input Time**: `0.00389589 seconds`
- **Read Time**: `0.00402327 seconds`
- **Sort Time**: `0.543587 seconds`
- **Sort to Good and Bad Time**: `0.000694392 seconds`
- **Output Time**: `0.00561752 seconds`
- **Total Time**: `0.553922 seconds`

#### File: `text_files/students10000.txt`
- **Input Time**: `0.0281103 seconds`
- **Read Time**: `0.0304661 seconds`
- **Sort Time**: `0.746183 seconds`
- **Sort to Good and Bad Time**: `0.00717633 seconds`
- **Output Time**: `0.040584 seconds`
- **Total Time**: `0.824409 seconds`

#### File: `text_files/students100000.txt`
- **Input Time**: `0.252412 seconds`
- **Read Time**: `0.260217 seconds`
- **Sort Time**: `1.50441 seconds`
- **Sort to Good and Bad Time**: `0.0595954 seconds`
- **Output Time**: `0.339719 seconds`
- **Total Time**: `2.16395 seconds`

#### File: `text_files/students1000000.txt`
- **Input Time**: `2.57021 seconds`
- **Read Time**: `2.63337 seconds`
- **Sort Time**: `2.23651 seconds`
- **Sort to Good and Bad Time**: `0.459325 seconds`
- **Output Time**: `3.31194 seconds`
- **Total Time**: `8.64114 seconds`

#### File: `text_files/students10000000.txt`
- **Input Time**: `27.3473 seconds`
- **Read Time**: `28.0419 seconds`
- **Sort Time**: `7.5584 seconds`
- **Sort to Good and Bad Time**: `11.6985 seconds`
- **Output Time**: `40.683 seconds`
- **Total Time**: `87.9818 seconds`

---

## Performance with Different Container Types

### Testing with 1,000,000 Students

#### Deque
- **Input Time**: `2.83357 seconds`
- **Read Time**: `2.88493 seconds`
- **Sort Time**: `0.157718 seconds`
- **Sort to Good and Bad Time**: `1.09067 seconds`
- **Output Time**: `6.45212 seconds`
- **Total Time**: `10.5854 seconds`

#### List
- **Input Time**: `2.87507 seconds`
- **Read Time**: `2.87963 seconds`
- **Sort Time**: `2.75329 seconds`
- **Sort to Good and Bad Time**: `1.89583 seconds`
- **Output Time**: `7.03756 seconds`
- **Total Time**: `14.5663 seconds`

#### Vector
- **Input Time**: `2.86478 seconds`
- **Read Time**: `2.99218 seconds`
- **Sort Time**: `0.166391 seconds`
- **Sort to Good and Bad Time**: `1.36359 seconds`
- **Output Time**: `6.29514 seconds`
- **Total Time**: `10.8173 seconds`

---

## Performance with Different Sorting Strategies

### Testing with 1,000,000 Students

#### Deque
- **Input Time**: `3.41568 seconds`
- **Read Time**: `3.36255 seconds`
- **Sort Time**: `0.178233 seconds`
- **Sort to Good and Bad Time**: `1.09387 seconds`
- **Output Time**: `7.07835 seconds`
- **Total Time**: `11.713 seconds`

#### List
- **Input Time**: `3.02607 seconds`
- **Read Time**: `3.16613 seconds`
- **Sort Time**: `2.80693 seconds`
- **Sort to Good and Bad Time**: `1.76607 seconds`
- **Output Time**: `7.28067 seconds`
- **Total Time**: `15.0198 seconds`

#### Vector
- **Input Time**: `2.98935 seconds`
- **Read Time**: `3.30657 seconds`
- **Sort Time**: `0.1754 seconds`
- **Sort to Good and Bad Time**: `1.39922 seconds`
- **Output Time**: `6.74352 seconds`
- **Total Time**: `11.6247 seconds`

---

## Optimization Flags

### Using Classes for Models and Choosing Different Flags

#### O1 Flag
- **Input Time**: `2.91498 seconds`
- **Read Time**: `3.02424 seconds`
- **Sort Time**: `0.150708 seconds`
- **Sort to Good and Bad Time**: `0.934526 seconds`
- **Output Time**: `6.28459 seconds`
- **Total Time**: `10.3941 seconds`

#### O2 Flag
- **Input Time**: `2.71766 seconds`
- **Read Time**: `2.81495 seconds`
- **Sort Time**: `0.144442 seconds`
- **Sort to Good and Bad Time**: `0.927887 seconds`
- **Output Time**: `6.28983 seconds`
- **Total Time**: `10.1771 seconds`

#### O3 Flag
- **Input Time**: `2.79964 seconds`
- **Read Time**: `2.9401 seconds`
- **Sort Time**: `0.104097 seconds`
- **Sort to Good and Bad Time**: `0.903261 seconds`
- **Output Time**: `6.33954 seconds`
- **Total Time**: `10.287 seconds`

---

## System Specifications
- **SSD**: 500 GB
- **RAM**: 32 GB
- **CPU**: 2.6GHz 6‑core Intel Core i7, Turbo Boost up to 4.5GHz, with 12MB shared L3 cache


## Instructions
- `cd to the root of the project`
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`
- **To run tests** `./runTests`
- **To run program** `./OOPUzduotis2`

## In order to download
- there is a dmg file for setup in order to have the project on your own computer
