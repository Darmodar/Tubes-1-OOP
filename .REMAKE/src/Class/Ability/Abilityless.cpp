#include "AbilityLess.hpp"


Abilityless::Abilityless() : Ability::Ability(7){

}
bool Abilityless::useAbility(Game<Card>& game, int playerAbility, int player){
    bool allUse = false;
    for(int i=0;i<game.getPlayers().size();i++){
        if(game.getPlayer(i).getAbility()<=0){
            allUse = true;
            break;
        }
    }
    if (playerAbility == 7 ){
        if (Abilityless::isUsingAbility() == false){
            if(!allUse){
                cout<< game.getPlayer(player).getName()<<" akan mematikan kartu ablity lawan!"<<endl;
                cout<<"Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: "<<endl;
                Player Playermati, playerPengguna;
                for(int i=0;i<game.getPlayers().size();i++){
                    if(i != player){
                        cout<< i+1 <<". " << game.getPlayer(i).getName()<<endl;
                    }
                }

                cout<<">";
                int enemyNumber;
                cin >> enemyNumber;
                enemyNumber--;
                Playermati = game.getPlayer(enemyNumber);
                playerPengguna = game.getPlayer(player);
                if(game.getPlayer(enemyNumber).getAbility()>0){
                    Playermati.setAbility(0);
                    cout<<"Kartu ability " << game.getPlayer(enemyNumber).getName() <<" telah dimatikan."<<endl;
                    game.setPlayer(enemyNumber,Playermati);
                    playerPengguna.setAbility(-1);
                    game.setPlayer(player,playerPengguna);
                }else{
                    cout<<"Kartu ability "<< game.getPlayer(enemyNumber).getName() <<" telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia"<<endl;
                    playerPengguna.setAbility(-1);
                    game.setPlayer(player,playerPengguna);
                    return false;
                }
                Ability::setUsingAbility(true);
                return true;
            }else{
                cout<<"Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia"<<endl;
            }
            
        } else {
            printPesan2("ABILITYLESS");
        }
    } else {
        printPesan("ABILITYLESS");
    }
    return false;
    
}