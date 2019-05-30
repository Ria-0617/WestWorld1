//
//  main.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include <iostream>
#include "EntityNames.hpp"
#include "Miner.hpp"


int main(int argc, const char * argv[]) {
    Miner miner(ent_Miner_Bob);
    
    for(int i = 0;i < 30; ++i){
        miner.Update();
    }
    
    
    return 0;
}
