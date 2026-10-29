# Instructions
## Wave 0: Setup project
1. Fork the repository
1. Enable workflows AND switch GitHub pages to use GitHub actions. Feel free to look back at previous instructions if you forget how to do this.
1. Clone the repository
1. Change into the project repository:
    ```
    cd orbits
    ```
1. Open VSCode in the project repository. If the below command does not work, open VS Code and use File > Open Folder.
    ```
    code .
    ```
1. Re-open the project in the dev container.
1. Run `make` to make the project for the first time

## Wave 1: Understand
1. Make the code
1. Run the game
1. Look at the code. Understand what it's doing. Discuss with your partner. What new features of classes are used here that we haven't seen before? What new Butano classes are used?

## Wave 2: Refactor a function
Refactor `dPadMoveSprite` into a new header and implementation file

## Wave 3: Refactor a class
Refactor `Center` into a new header and implementation file

## Wave 4: Refactor another class
Refactor `Orbiter` into a new new header and implementation file. Remeber to:
- Remove the Orbiter class from main.cpp
- NOT have any implementation in the header file, only declarations
- Have an include guard
- Remove unneeded includes from main

## Wave 5:
Make more interesting sprites!

## Wave 6: Make it your own!
Some possibilities:
- Making it so the player can change where new orbiters spawn and what their initial velocities are
- Making orbiters disappear if they crash into each other (challenging to do efficiently!)
- Making it so all orbiters are removed if you hit start
- Other changes you might like!

## Wave 7: Polishing
Update the README with a better description, a GIF, and a link to the live GitHub pages version.

## Submitting
See Canvas for instructions on submitting