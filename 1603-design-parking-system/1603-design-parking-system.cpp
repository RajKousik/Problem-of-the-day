class ParkingSystem {
    
private:
    
    int carTypes[4];
    
public:
    ParkingSystem(int big, int medium, int small) {
        
        carTypes[1] = big;
        carTypes[2] = medium;
        carTypes[3] = small;
        
    }
    
    bool addCar(int carType) {
        
        return (carTypes[carType]--) > 0;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */