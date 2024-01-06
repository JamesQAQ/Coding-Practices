class ParkingSystem {
private:
  vector<int> slot;

public:
  ParkingSystem(int big, int medium, int small) {
    slot = vector<int>({big, medium, small});
  }

  bool addCar(int carType) {
    if (slot[carType - 1]) {
      slot[carType - 1]--;
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
