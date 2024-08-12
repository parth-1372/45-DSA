class Solution {
  public:
    // Function to find the starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n) {
        int start = 0; // Starting index
        int currPetrol = 0; // Current petrol in the truck
        int totalPetrol = 0; // Total petrol that truck can collect
        int totalDistance = 0; // Total distance that truck needs to cover

        for (int i = 0; i < n; i++) {
            totalPetrol += p[i].petrol;
            totalDistance += p[i].distance;
            currPetrol += p[i].petrol - p[i].distance;

            // If current petrol is negative, we cannot start from 'start'
            // so we need to start from the next pump
            if (currPetrol < 0) {
                start = i + 1;
                currPetrol = 0; // Reset current petrol
            }
        }

        // If total petrol is less than total distance, it is not possible to complete the tour
        return (totalPetrol < totalDistance) ? -1 : start;
    }
};