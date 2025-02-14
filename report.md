#Software Design and Implementation

##Table of Contents

1. [Introduction](#introduction)
2. [Analysis and Design](#analysis-and-design)
   -[Program Specification](#program-specification)
   -[Inputs, Outputs and Processes](#inputs-outputs-and-processes)
   -[Algorithm](#algorithm)
3. [References](#references)

##Introduction

##Analysis and Design

###Program Specification

###Inputs, Outputs and Processes

###Algorithm

```plaintext
RECORD Player
    name: String
    health: Integer
    attackPower: Integer
    defensePower: Integer
    score: Integer
    inventory: array of items
ENDRECORD

RECORD Enemy
    name: String
    health: Integer
    attackPower: Integer
    defensePower: Integer
ENDRECORD

RECORD Item
    name: String
    type: String
    effect: Integer
ENDRECORD

RECORD Scene
    description: String
    choice1: String
    choice2: String
    outcome1: String
    outcome2: String
ENDRECORD

player ← Player('', 100, 20, 10, 0, [])

enemies ← [Enemy('Lord Boros', 40, 10, 5), Enemy('Mosquito Girl', 30, 10, 5)]

scenes ← [
    Scene('One path lead to an abandoned warehouse, the other to a dark alley. Which path will you choose?', 'Abandoned warehouse.', 'Dark alley.', 'Encounter an enemy', 'Explore alley'),
    Scene('You find a door with a riddle: "What is 6 + 9?"', '69', '15', 'Door stays locked and you lose points', 'Door opens and you gain points' ),
    Scene()]

SUBROUTINE start_game()
    OUTPUT'Enter your name: '
    player.name ← USERINPUT
    OUTPUT'Welcome, ' + player.name + ', your adventure begins now!'
    play_game(0)
ENDSUBROUTINE

SUBROUTINE play_game(scene_index)
    IF scene_index >= LEN(scenes) THEN
        OUTPUT'Congratulations! You completed the game.'
        RETURN
    ENDIF

    scene ← scenes[scene_index]
    OUTPUT scene.description
    OUTPUT'1. ' + scene.choice1
    OUTPUT'2. ' + scene.choice2
    choice ← USERINPUT

    IF choice = '1' THEN
        process_outcome(scene.outcome1, scene_index + 1)
    ELSEIF choice = '2' THEN
        process_outcome(scene.outcome2, scene_index + 1)
    ELSE
        OUTPUT'Invalid choice. Try again.'
        play_game(scene_index)
    ENDIF
ENDSUBROUTINE

SUBROUTINE process_outcome(outcome, next_scene_index)
    IF outcome = 'Encounter an enemy' THEN
        combat(random_enemy())
    ELSEIF outcome = 'Explore alley' THEN
        puzzle('riddle')
    ELSEIF outcome = 'Gain a weapon' THEN
        new_item ← Item('Sword', 'Weapon', 10)
        APPEND new_item TO player.inventory 
        OUTPUT'You found a Sword! It increases your attack power.'
        play_game(next_scene_index)
    ELSE
        OUTPUT outcome
        play_game(next_scene_index)
    ENDIF
ENDSUBROUTINE

SUBROUTINE puzzle(puzzle_type)
    IF puzzle_type = 'riddle' THEN
        OUTPUT'What is 6 + 9?'
        OUTPUT'1. 69'
        OUTPUT'2. 15'

        player_choice ← USERINPUT
        IF player_choice = '2' THEN
            player.score ← player.score + 10
            OUTPUT'Correct! The door opens, and you gain 10 points.'
        ELSEIF player_choice = '1' THEN
            player.score ← player.score - 10
            OUTPUT'Wrong answer! The door stays locked, and you lose 10 points.'
        ELSE
            OUTPUT'Invalid choice. Please try again.'
            puzzle('riddle')
        ENDIF
ENDSUBROUTINE
  

SUBROUTINE use_item(item_name)
    IF LEN(player.inventory) == 0 THEN
        OUTPUT'No items available.'
        RETURN
   ENDIF

    FOR item IN player.inventory
        IF item.name = item_name THEN
            IF item.type = 'Food' THEN
                player.health ← player.health + item.effect
                OUTPUT'You used ' + item.name + ' and gained ' + item.effect + ' health.'
            ELSEIF item.type = 'Weapon' THEN
                player.attackPower ← player.attackPower + item.effect
                OUTPUT'You equipped ' + item.name + ', increasing your attack power by ' +
                item.effect
            ENDIF
            REMOVE item FROM player.inventory
            RETURN
        ENDIF
    ENDFOR
    OUTPUT'Item not found in inventory.'
ENDSUBROUTINE

SUBROUTINE combat(enemy)
    OUTPUT'You encounter ' + enemy.name + '!'

    WHILE player.health > 0 AND enemy.health > 0
        player_attack ← player.attackPower + RANDOM(1, 10)
        enemy_attack ← enemy.attackPower + RANDOM(1, 10)
        enemy.health ← enemy.health - player_attack
        IF enemy.health > 0 THEN
            player.health ← player.health - enemy_attack
        ENDIF
    ENDWHILE

    IF player.health <= 0 THEN
        OUTPUT'You were defeated!'
        game_over()
    ELSE 
        OUTPUT'You defeated ' + enemy.name + '!'
    ENDIF
ENDSUBROUTINE

SUBROUTINE random_enemy()
    RETURN enemies [RANDOM(0, LEN(enemies)-1)]
ENDSUBROUTINE

SUBROUTINE game_over()
    OUTPUT'Game Over!'
    OUTPUT'Would you like to go again?'
    OUTPUT'1. Yes'
    OUTPUT'2. No'

    player_choice ← USERINPUT 
    IF player_choice = '1' THEN
        start_game()
    ELSEIF player_choice = '2' THEN
        OUTPUT'Thank you for playing <3'
        RETURN
    ELSE
        OUTPUT'Invalid choice. Please choose again.'
        game_over()
    ENDIF
ENDSUBROUTINE

SUBROUTINE save_game()
    OUTPUT'saving game...'
    OUTPUT'Game saved successfully.'
ENDSUBROUTINE

SUBROUTINE load_game()
ENDSUBROUTINE


start_game()
```

##References
