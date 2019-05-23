//
//  Miner.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/23.
//  Copyright © 2019 田中皓己. All rights reserved.
//

#include "Miner.hpp"

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
