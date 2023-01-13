class ParkingSystem:
    
    def __init__(self, big: int, medium: int, small: int):
        self.big = big
        self.medium = medium
        self.small = small
        self.carType_capacity = {1:self.big, 2: self.medium, 3: self.small}
        self.current_status = {1:0, 2:0, 3:0}

    def addCar(self, carType: int) -> bool:
        if self.current_status[carType] < self.carType_capacity[carType]:
            self.current_status[carType] += 1
            return True
        else:
            return False


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)