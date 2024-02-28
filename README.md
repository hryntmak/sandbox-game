# Sandbox game

## Award

  This semester's work belongs to the category of games. Your goal is to create a specific game, 
  which will be modifiable through configuration files. 
  Do not try to define all values directly in the code (even using constants). 
  Place them in the configuration files (one or more) that your program will load.

  Your task is to program a simple 2D sandbox game. Sandbox games are characterized primarily by the ability to modify existing environments.

  The game must meet the following functionality:

-  implement players (e.g. character, spaceship,...), his condition (BC. energy, life, armor,...) and allow you to interact with the environment (e.g. mine, dig, build,...).

-  Create a (combat) injury model that has at least 3 different causes (e.g. falling from a height, a duel with the enemy, staying in lava,...).

-  Create a simple environment model, implement at least 3 different mechanics (e.g. gravity, water overflow, tree growth,...).

-  the game must be configurable from the file:

      a) map (or even better its generator),

      B) definition of individual enemies, names of objects or their attributes.

-  the game must be able to save and then load the Played Game.

  Where can polymorphism be used? (best)

    + characters: player, animals, friend (trader), enemy (various kinds), …

    + action effects: fall (takes lives according to the quadrate of height), blow (takes lives according to strength and defense), contact with lava (applies Fire and takes 1 Life each), …

    + environment: air (does nothing), water (when used with a bucket fills or empties it), clay (player collects and stores in inventory), 
    coal and other ores (if the player holds a pickaxe, it will be mined), ladder (moves the player to the end), …

    + user interface: console, ncurses, SDL, OpenGL (various variants), …

# Specification

I will implement a sandbox game inspired by games like Minecraft, Terraria and Don't starve. 
The player is surrounded on the map by an impenetrable bedrock (16x8 blocks without a wall) and can move on 4 sides. 
On the map there is always a block of bed, computer and electricity generator for this computer. 
There may also be other blocks on the map, such as soil, sand, coal, a tree(can be a sapling), a fungus, water and lava. 
With some of these blocks the player can interact, through some he can pass or even move. 
The player can mine blocks and use them as fuel for the generator(not all blocks release energy when burned).
Some blocks can only be mined with a pickaxe (also there is a block) in hand (active block in inventory) 
The player needs electricity to do a progtest on the computer. 
Also, using the computer, the player can try to pass (a limited number of attempts) progtest and get some score depending on the readiness of the task, there is also a chance to get a red flag. 
If a player receives a red flag, it will cause him some damage. Also, damage is done if the player fails to pass the progtest and for each action without energy.
Energy can be obtained by the player if he eats something (mushrooms) or sleeps. Energy is consumed when moving and mining blocks. 
Mined blocks are stored in a limited inventory, the active block can be placed in front of you. After sleep, the player not only restores energy, 
but also on the map can grow mushrooms and trees, of course, approaching the deadline of the progtest. The end of the game occurs when the player dies, the progtest deadline comes, or the player wants to finish alone.
The map, the life of the player, his energy, inventory, level of programming, amount of electricity, difficulty of the progtest, maximum number of attempts, etc.can be configured using the configuration file.

Input/output indicator without output characteristics:
```
Enter movement:
$ W
+----------------+
|                |
|      ###       |
|           CGB  |
|  T             |
|       ^        |
|  t             |
|           ?    |
|         .      |
+----------------+
Enter movement:
$ W
+----------------+
|                |
|      ###       |
|           CGB  |
|  T    ^        |
|                |
|  t             |
|           ?    |
|         .      |
+----------------+
Enter movement:
$ D
+----------------+
|                |
|      ###       |
|           CGB  |
|  T    >        |
|                |
|  t             |
|           ?    |
|         .      |
+----------------+
Enter movement:
$ D
+----------------+
|                |
|      ###       |
|           CGB  |
|  T     >       |
|                |
|  t             |
|           ?    |
|         .      |
+----------------+
```

```
'^', 'v', '>', '<' - player, it depends on the direction of movement
'#' - Soil
'C' - Computer
'G' - electricity generator
'B' - Bed
'.'- Small mushroom (can not snist)
'?'- Large mushroom (can snist)
't' - sapling(no fuel, can pass)
'T' - Tree (is fuel, can not pass)
etc.
```

# Polymorphism

Polymorphism is applied within the class hierarchy 'CBlock' and 'CAction'.

The class `CBlock` has 5 (there will be more) descendants: `CAirBlock`, `CDirtBlock`, `CComputerBlock`, `CBedBlock` and `CBedrockBlock`.
This class is needed in order to have different blocks on the map that behave differently when interacting with them.
The `CBlock` class has polymorphic methods `update`, `refresh` and `action`. 
 The `update` method tells the block that it is a new day and those blocks that depend on time can change or do something(saplings and small mushrooms will grow).
 The `refresh` method is called for neighboring blocks with the block that was delivered or destroyed
 It receives a two-dimensional array of blocks and its position to interact in some way with neighboring blocks(for example, water replaces non - solid neighboring blocks on a copy of itself-it flows out).
 The `action` method constructs and returns an implementation of the caction(pointer) class depending on the implementation of the CBlock class itself. The caction event takes place already in the Cgame class.
 For example, `CBedBlock` changes the day when interacting and restores the player's energy (`CSkipDay` as pointer to `CAction`).

The class `CAction` has its descendants: `CNoAction`, `CBurn`, `CEnergyAction`, `CMakeProgtest`, `CSkipDay`, `CSubmitProgtest`, `Cakedamage`.
This class is needed so that any Block does not know about the characteristics of the player or progtest and does not take them in its methods as parameters.
The `CAction` class has polymorphic methods `activate`, `changeStats` and `changeProgtest`.
 The `activate` method, depending on the implementation of the class, makes some changes with the characteristics of the player and the progtest.
 The `changeStats` method, depending on the implementation of the class, makes some changes only with the characteristics of the player.
 The `changeProgtest` method, depending on the implementation of the class, makes some changes to the characteristics of the progtest.
 For example, `CTakeDamage` removes the amount of HP in a player that was specified when instantiating the class.
