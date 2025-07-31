int numWaterBottles(int numBottles, int numExchange) {
    int emptyBottles = numBottles;
    int BottlesDrunk = numBottles;
    while(emptyBottles >= numExchange){
        int BottlesToDrink = emptyBottles / numExchange;
        BottlesDrunk += BottlesToDrink;
        emptyBottles =  BottlesToDrink + (emptyBottles % numExchange);
    }
    return BottlesDrunk;
}