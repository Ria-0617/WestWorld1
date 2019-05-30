//
//  BaseGameEntity.cpp
//  WestWorld1
//
//  Created by 田中皓己 on 2019/05/30.
//  Copyright © 2019 田中皓己. All rights reserved.
//
#include "BaseGameEntity.hpp"
#include <cassert>

int BaseGameEntity::m_iNextValidID = 0;

//----------------------------- SetID -----------------------------------------
//
//  this must be called within each constructor to make sure the ID is set
//  correctly. It verifies that the value passed to the method is greater
//  or equal to the next valid ID, before setting the ID and incrementing
//  the next valid ID
//-----------------------------------------------------------------------------
void BaseGameEntity::SetID(int val)
{
    //make sure the val is equal to or greater than the next available ID
    assert ( (val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");
    
    m_ID = val;
    
    m_iNextValidID = m_ID + 1;
}