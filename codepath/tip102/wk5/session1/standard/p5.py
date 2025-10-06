class Villager:
    def __init__(self, name, species, catchphrase):
        self.name = name
        self.species = species
        self.catchphrase = catchphrase
        self.furniture = []

    def greet_player(self, player_name):
        return f"{self.name}: Hey there, {player_name}! How's it going, {self.catchphrase}!"

    def set_catchphrase(self, new_catchphrase):
        if len(new_catchphrase) < 20 and all(c.isalpha() or c.isspace() for c in new_catchphrase):
            self.catchphrase = new_catchphrase
            print("Catchphrase updated")
        else:
            print("Invalid catchphrase")

    def add_item(self, item_name):
        allowed = {
            "acoustic guitar",
            "ironwood kitchenette",
            "rattan armchair",
            "kotatsu",
            "cacao tree",
        }
        if item_name in allowed:
            self.furniture.append(item_name)
