//
//  Miner.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "Miner.hpp"

Miner::Miner(int id):BaseGameEntity(id),
m_Location(shack),
m_iGoldCarried(0),
m_iMoneyInBank(0),
m_iThirst(0),
m_iFatigue(0),
m_pCurrentState(GoHomeAndSleepTilRested::Instance()){
    
}

void Miner::Update(){
    m_iThirst += 1;
    
    if(m_pCurrentState){
        m_pCurrentState->Execute(this);
    }
}

void Miner::ChangeState(State* pNewState){
    // それぞれのメソッドを呼び出そうとする前に両方のステートが有効かを確かめる
    assert(m_pCurrentState && pNewState);
    
    m_pCurrentState->Exit(this);
    m_pCurrentState = pNewState;
    m_pCurrentState->Enter(this);
}

//-----------------------------------------------------------------------------
void Miner::AddToGoldCarried(const int val) {
    m_iGoldCarried += val;
    
    if (m_iGoldCarried < 0) m_iGoldCarried = 0;
}


//-----------------------------------------------------------------------------
void Miner::AddToWealth(const int val) {
    m_iMoneyInBank += val;
    
    if (m_iMoneyInBank < 0) m_iMoneyInBank = 0;
}


//-----------------------------------------------------------------------------
bool Miner::Thirsty()const {
    if (m_iThirst >= ThirstLevel){return true;}
    
    return false;
}

//-----------------------------------------------------------------------------
bool Miner::Fatigued()const {
    if (m_iFatigue > TirednessThreshold)
    {
        return true;
    }
    
    return false;
}
