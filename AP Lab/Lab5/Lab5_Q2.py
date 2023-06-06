class Vehicle:
    def __init__(self):
        self.name = input("Enter Vehicle Owner's Name:")
        self.idnum = input("Enter Vehicle ID:")
        self.manu = input("Enter Manufacturer:")

    def displayVeh(self):
        print("Vehicle Owner's Name:", self.name, "\nVehicle ID:", self.idnum, "\nManufacturer:", self.manu)

class Passenger(Vehicle):
    def __init__(self):
        super().__init__()
        self.numPass = input("Enter  Number of Passengers:")

    def displayPass(self):
        super().displayVeh()
        print("Number of Passengers:", self.numPass)

p = Passenger()
p.displayPass()
