//
//  State.hpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

class Miner;

class State{
public:
    virtual ~State(){}
    
    virtual void Enter(Miner*) = 0;
    virtual void Execute(Miner*) = 0;
    virtual void Exit(Miner*) = 0;
};

#endif /* State_hpp */
