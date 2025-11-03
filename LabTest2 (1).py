#Student Name : Providence Obiozor
#Student ID: C20499732
#Date: 05/12/2023

#The provided Python code defines a basic RPG-style simulation involving heroes and monsters. 


class Hero:
    """A basic template for a hero with attributes such as name, power level, and health points.
    Implements methods like punch, combat, and a string representation."""

    def __init__(self, hero_name="", power_level=1, health_points=100):
        """Initialize hero attributes."""
        # Private attribute for hero's name
        self.__name = hero_name
        self.health_points = health_points
        self.power_level = power_level

    def punch(self) -> float:
        """Return the punch power, calculated as 2 times the hero's level."""
        return self.power_level * 2

    def get_name(self):
        """Getter method for the hero's name."""
        return self.__name

    def combat(self, monster):
        """Simulate a combat between the hero and a monster."""
        if not isinstance(monster, Monster):
            print("Heroes only fight monsters.")
            return False

        while self.health_points > 0 and monster.health_points > 0:
            # Hero attacks first
            monster.health_points -= self.punch()
            print(f"{self.get_name()} punches {monster.monster_name}!")

            # Check if monster is defeated
            if monster.health_points <= 0:
                print(f"{monster.monster_name} has fallen!")
                return True

            # Monster attacks second
            self.health_points -= monster.attack()
            print(f"{monster.monster_name} attacks {self.get_name()}!")

            # Check if hero is defeated
            if self.health_points <= 0:
                print(f"{self.get_name()} has fallen!")
                return False

        return False


class Monster:
    """A basic template for a monster with attributes like name, strength, health points, and a roar.
    Implements methods for attack and operator overloading for addition."""

    def __init__(self, monster_name="", strength=1.0, health_points=50, roar="Roar!"):
        """Initialize monster attributes."""
        self.monster_name = monster_name
        self.strength = strength
        self.health_points = health_points
        self.roar = roar
        print(self.roar)  # Print the monster's roar upon initialization

    def attack(self) -> float:
        """Return the attack power, linearly related to the monster's strength."""
        return self.strength * 1.5

    def __add__(self, other):
        """Overload the addition operator to create a new monster."""
        if not isinstance(other, Monster):
            raise ValueError("Can only add two monsters.")

        # Concatenate names
        new_name = f"{self.monster_name} + {other.monster_name}"

        # Multiply strengths
        new_strength = self.strength * other.strength

        # Sum health points
        new_health_points = self.health_points + other.health_points

        # Concatenate roars and add three exclamation marks
        new_roar = f"{self.roar}{other.roar}!!!"

        return Monster(new_name, new_strength, new_health_points, new_roar)


class Barbarian(Hero):
    """Represents a Barbarian archetype inheriting from the Hero class."""

    def __init__(self, hero_name="", power_level=1, health_points=100, rage_level=0):
        """Initialize Barbarian attributes."""
        super().__init__(hero_name, power_level, health_points)
        self.rage_level = rage_level

    def attack(self) -> float:
        """Return the attack power, influenced by rage level."""
        return self.power_level * (2 + self.rage_level)


class Archer(Hero):
    """Represents an Archer archetype inheriting from the Hero class."""

    def __init__(self, hero_name="", power_level=1, health_points=80, arrows=30):
        """Initialize Archer attributes."""
        super().__init__(hero_name, power_level, health_points)
        self.arrows = arrows

    def shoot_arrow(self) -> float:
        """Return the arrow power, influenced by the number of arrows."""
        if self.arrows > 0:
            self.arrows -= 1
            return self.power_level * 2.5  # Adjust the arrow power as needed
        else:
            print("No arrows left!")
            return 0


class Assassin(Hero):
    """Represents an Assassin archetype inheriting from the Hero class."""

    def __init__(self, hero_name="", power_level=1, health_points=80, stealth_level=8, poison_dose=3):
        """Initialize Assassin attributes."""
        super().__init__(hero_name, power_level, health_points)
        self.stealth_level = stealth_level
        self.poison_dose = poison_dose

    def sneak_attack(self) -> float:
        """Return the sneak attack power, influenced by stealth level."""
        return self.power_level * (2 + self.stealth_level)

    def apply_poison(self, target):
        """Apply poison to the target, reducing health over time."""
        if not isinstance(target, Hero):
            print("Assassins can only poison other heroes.")
            return

        print(f"{self.get_name()} applies poison to {target.get_name()}!")
        target.health_points -= self.poison_dose

    def combat(self, monster):
        """Override the combat method to include assassin's unique abilities."""
        if not isinstance(monster, Monster):
            print("Heroes only fight monsters.")
            return False

        while self.health_points > 0 and monster.health_points > 0:
            # Assassin attacks first with sneak attack
            monster.health_points -= self.sneak_attack()
            print(f"{self.get_name()} performs a sneak attack on {monster.monster_name}!")

            # Check if monster is defeated
            if monster.health_points <= 0:
                print(f"{monster.monster_name} has fallen!")
                return True

            # Monster attacks second
            self.health_points -= monster.attack()
            print(f"{monster.monster_name} attacks {self.get_name()}!")

            # Check if hero is defeated
            if self.health_points <= 0:
                print(f"{self.get_name()} has fallen!")
                return False

            # Apply poison to the monster
            self.apply_poison(monster)

        return False


# Task 5: Create instances and simulate combat with the Barbarian class
if __name__ == "__main__":
    # Create an instance of the Barbarian class
    barbarian_hero = Barbarian(hero_name="Conan", power_level=5, health_points=150, rage_level=2)

    # Create an instance of the Archer class
    archer_hero = Archer(hero_name="Legolas", power_level=3, health_points=90, arrows=20)

    # Create an instance of the Assassin class
    assassin_hero = Assassin(hero_name="Shadow", power_level=3, health_points=90, stealth_level=10, poison_dose=5)

    # Create two instances of the Monster class
    cyclops_monster = Monster(monster_name="Cyclops", strength=2.0, health_points=30, roar="Growl!")
    werewolf_monster = Monster(monster_name="Werewolf", strength=3.0, health_points=40, roar="Roarrr!")

    # Create a third instance of Monster by adding the first two
    monstrosity = cyclops_monster + werewolf_monster

    # Make each hero combat each monster
    barbarian_result = barbarian_hero.combat(cyclops_monster)
    archer_result = archer_hero.combat(werewolf_monster)
    assassin_result = assassin_hero.combat(monstrosity)

    # Print the final outcome for each hero
    if barbarian_result:
        print("The victory goes to the Barbarian!")
    else:
        print("The Barbarian has fallen.")

    if archer_result:
        print("The victory goes to the Archer!")
    else:
        print("The Archer has fallen.")

    if assassin_result:
        print("The victory goes to the Assassin!")
    else:
        print("The Assassin has fallen.")
