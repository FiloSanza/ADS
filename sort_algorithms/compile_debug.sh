g++ -std=c++20 -Wall -Wpedantic       \
    main.cpp                          \
    insertion_sort/insertion_sort.cpp \
    merge_sort/merge_sort.cpp         \
    quick_sort/quick_sort.cpp         \
    -o sort_test -g -fsanitize=address
