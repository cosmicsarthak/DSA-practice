class Item:
    grocery = []  # string type
    f_price = []   # int type
    f_quantity = []   # int type [in kg]

    def __init__(self, name, price, quantity):
        # self.name = name
        # self.price = price
        # self.quantity = quantity
        self.grocery.append(name)
        self.f_price.append(price)
        self.f_quantity.append(quantity)
        print("\n*******  Displaying Fruit Shop  *******")
        # self.display()  # calling  display()  to print the items | price | quantity

    def purchase(self):  # subtracting quantity....
        name = input(
            "\nEnter the name of the item(must be present in the shop) to purchase: ")
        num = int(input("Enter the quantity to purchase: "))

        index = self.grocery.index(name)  # get index by name
        # delete the user quantity with actual quantity
        self.f_quantity[index] -= num

    def increaseStock(self):  # adding quantiy...
        m1 = input("\nAdd a new item to the shop: ")
        m2 = int(input("Enter the price of the new item: "))
        m3 = int(input("Enter the quantity of the new item: "))
        self.grocery.append(m1)  # appending the new product...
        self.f_price.append(m2)  # appending the price of the new product..
        self.f_quantity.append(m3)  # appending the quantity..

    def display(self):
        print("\n Available Items in shop...\n")
        i = 0
        while i < len(self.grocery):
            print(
                f"name: {self.grocery[i]} | price: {self.f_price[i]} | quantity: {self.f_quantity[i]}(kg)")
            i += 1


print("\n*******  Welcome to the Fruit Shop  *******")


choice = 1
while choice:
    if choice == 1:
        name = input("Add item to the shop: ")
        price = int(input("Add price of the item: "))
        quantity = int(input("Add quantity of the item: "))
        s = Item(name, price, quantity)
        s.display()
    if choice == 2:
        s.increaseStock()
    if choice == 3:
        s.purchase()
    choice = int(input(
        "Press '1' - add item or Press '2' - Increase stock: or Press '3' - Purchase "))
