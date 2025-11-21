// #include <bits/stdc++.h>
// using namespace std;
// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <limits>
// #include <gtest/gtest.h>
// #include <cmath>
// #include <limits>
// /**
//  * This function performs a binary search to find the value of mid that satisfies the given function.
//  * 
//  * Input:
//  *  - n: The target value for the equation.
//  *  - eps: The precision threshold to determine when the search is complete.
//  *  - f: A lambda function representing the equation to solve.
//  *  - l: The lower bound of the search range.
//  *  - r: The upper bound of the search range.
//  * 
//  * Output:
//  *  - Returns the value of mid that satisfies the equation within the given precision.
//  */
// double binarySearch(double n, double eps, auto f, double l, double r)
// {
//     while (true) {
//         double mid = (l + r) / 2;
//         double cur = f(mid);
//         if (std::abs(cur - n) < eps) {
//             return mid;
//         }
//         if (n - cur > 0) {
//             l = mid;
//         } else {
//             r = mid;
//         }
//     }
// }
// /**
//  * This function solves for the value of mid that satisfies the equation mid^2 + sqrt(mid) = n
//  * using a binary search algorithm. The result is printed with a precision of 10 decimal places.
//  * 
//  * Input:
//  *  - n: A double value representing the target value for the equation.
//  * 
//  * Output:
//  *  - Prints the value of mid that satisfies the equation to 10 decimal places.
//  */
// void Solve()
// {
//     const double eps = 1e-6;
//     double n;
//     std::cin >> n;

//     double l = 0, r = n;
//     auto f = [&](double mid) {
//         return mid * mid + std::sqrt(mid);
//     };

//     double result = binarySearch(n, eps, f, l, r);
//     std::cout << std::setprecision(10) << result;
// }


// /**
//  * Unit test for the binarySearch function.
//  */
// TEST(BinarySearchTest, TestSimpleCase) {
//     auto f = [](double mid) {
//         return mid * mid + std::sqrt(mid);
//     };

//     const double eps = 1e-6;
//     const double expectedMid = 1.5; // Expected mid value for n = 3
//     const double n = 3;

//     EXPECT_DOUBLE_EQ(binarySearch(n, eps, f, 0, 2), expectedMid);
// }

// /**
//  * Unit test for the binarySearch function with a more complex function.
//  */
// TEST(BinarySearchTest, TestComplexCase) {
//     auto f = [](double mid) {
//         return mid * mid * mid + std::sqrt(mid) + 1;
//     };

//     const double eps = 1e-6;
//     const double expectedMid = 2.0; // Expected mid value for n = 10
//     const double n = 10;

//     EXPECT_DOUBLE_EQ(binarySearch(n, eps, f, 0, 3), expectedMid);
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

