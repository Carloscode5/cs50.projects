# Creat a menu dictioary
food_menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00,
}
# Set current price to 0
total_amount = 0
# Loop goes here!
while True:
    try:
        # Get user input
        item = input("Item: ").title()
        # Check if item already in dictionary
        if item in food_menu:
            # Add the item price to total_amount
            total_amount += food_menu[item]
            # Print total amount
            print("Total: $", end="")
            print("{:.2f}".format(total_amount))
    except EOFError:
        # Print new line and stop loop
        print()
        break
