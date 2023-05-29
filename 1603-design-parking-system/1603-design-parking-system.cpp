class ParkingSystem {
    vector<int> available = vector<int>(3);
public:
    ParkingSystem(int big, int medium, int small) {
        available[0] = big, available[1] = medium, available[2] = small;
    }
    
    bool addCar(int carType) {
        if (available[carType - 1] > 0){
            --available[carType - 1];
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */