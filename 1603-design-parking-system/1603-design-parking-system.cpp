class ParkingSystem {
private:
    int big, medium, small;
    unordered_map<int, int> carType_capacity;
    unordered_map<int, int> current_status{{1,0},{2,0},{3,0}};
public:
    ParkingSystem(int big, int medium, int small) {
        this -> big = big;
        this -> medium = medium;
        this -> small = small;
        carType_capacity = {{1, this->big}, {2, this -> medium}, {3, this -> small}};
        
    }
    
    bool addCar(int carType) {
        ++current_status[carType];
        return current_status[carType] <= carType_capacity[carType];
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */