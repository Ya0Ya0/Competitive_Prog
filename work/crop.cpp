// #include <iostream>
// #include <string>
// #include <iomanip>
 
// using namespace std;
// NSSet *mySet = [NSSet setWithObjects:@(myInt1), @(myInt2), @(myInt3), nil];

// // Function to predict the profit for a given crop
// double predictProfit(string cropType, double totalAcres, double sellingPrice, double totalFertilizerCost, double averageYield) {
//     double profit = (averageYield * totalAcres * sellingPrice) - (totalAcres * totalFertilizerCost);
//     return profit;
// }

// int main() {
//     string cropType;
//     double totalAcres, sellingPrice, totalFertilizerCost, averageYield;

//     // Get information for each crop
//     for (int i = 0; i < 3; i++) {
//         cout << "Enter the type of crop: ";
//         cin >> cropType;

//         cout << "Enter the total area of the field (in acres): ";
//         cin >> totalAcres;

//         cout << "Enter the expected selling price (per ton): ";
//         cin >> sellingPrice;

//         cout << "Enter the total fertilizer cost (per acre): ";
//         cin >> totalFertilizerCost;

//         // Get average yield based on crop type (you'll need to replace these with actual values)
//         if (cropType == "wheat") {
//             averageYield = 2.5; // Example average yield for wheat
//         } else if (cropType == "rice") {
//             averageYield = 3.0; // Example average yield for rice
//         } else if (cropType == "potatoes") {
//             averageYield = 20.0; // Example average yield for potatoes
//         } else {
//             cout << "Invalid crop type entered." << endl;
//             return 1; // Exit with an error
//         }

//         // Calculate and display profit for the current crop
//         double profit = predictProfit(cropType, totalAcres, sellingPrice, totalFertilizerCost, averageYield);
//         cout << cropType << ": " << fixed << setprecision(2) << profit << endl;
//     }

//     // Find the most profitable crop (you'll need to implement this logic)
//     string mostProfitableCrop = "wheat"; // Replace with actual logic to determine the most profitable crop
    
//     // Display the final suggestion
//     cout << "-------------------------" << endl;
//     cout << "Most profitable crop to sow: " << mostProfitableCrop << endl;

//     return 0;
// }