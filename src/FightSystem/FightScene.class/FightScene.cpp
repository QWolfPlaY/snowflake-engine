//
// Created by WolfPlay on 4/29/2024.
//

#include "FightScene.h"

FightScene::FightScene(Player *player, EnemiesCollection enemiesCollection) :
_player(player) {
    enemies.reserve(enemiesCollection.size); // THIS LINE WAS THE SOLUTION TO A BUG THAT I BATTLE FOR OVER 4 FLUFFING HOURS 💀
    for(unsigned short i = 0; i < enemiesCollection.size; i++) {
        printf("Emplacing enemy | index: %i | Max HP: %i | addr: 0x%p\n", i, enemiesCollection.enemies[i]->getMaxHealth(), &*enemiesCollection.enemies[i]);
        enemies.emplace_back(enemiesCollection.enemies[i]->getMaxHealth());
        printf("Succesfully emplaced enemy %i\n", i);
    }
}

Player *FightScene::getPlayerPtr()
{
    return _player;
}
