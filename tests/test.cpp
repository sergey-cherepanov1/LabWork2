/* Sergey Cherepanov st129987@student.spbu.ru
   LabWork2
*/
// tests/test.cpp
#include <gtest/gtest.h>

/// @brief Main entry point for running Google Tests.
/// @param argc Number of command-line arguments.
/// @param argv Array of command-line arguments.
/// @return Exit status (0 for all tests passed).
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
