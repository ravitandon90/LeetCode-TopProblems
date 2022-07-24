#include<vector>

using namespace std;

class CanPlaceFlowers {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<bool> canPlace;
        int numPlaced = 0;
        for (int index = 0; index < flowerbed.size(); ++index) canPlace.push_back(true);
        for (int index = 0; index < flowerbed.size(); ++index) {
            if (flowerbed[index] == 1) {
                canPlace[index] = false;
                if (index > 0) canPlace[index - 1] = false;
                if (index < flowerbed.size() - 1) canPlace[index + 1] = false;
            }
        }
        for (int index = 0; index < flowerbed.size(); ++index) {
            if (canPlace[index]) {
                canPlace[index] = false;
                if (index < flowerbed.size() - 1) {
                    canPlace[index + 1] = false;
                }
                ++numPlaced;
            }
        }
        return numPlaced >= n;
    }
};