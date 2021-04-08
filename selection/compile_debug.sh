g++ -std=c++20 -Wall -Wpedantic       \
    main.cpp                          \
    selection.cpp                     \
    -o selection_test_debug           \
    -fsanitize=address                \
    -g