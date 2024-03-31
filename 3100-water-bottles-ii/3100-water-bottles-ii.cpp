class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles;
        while (numBottles >= numExchange) {
            drunk++;
            numBottles -= numExchange++ -1;
        }
        return drunk;
    }
};