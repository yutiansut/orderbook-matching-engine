#include <iostream>

#include "marketData.hpp"
#include "marketDataDelegate.hpp"
#include "order.hpp"


using namespace webbtraders;


void marketData::subscribe( std::shared_ptr<marketDataDelegate> p_subscriber )
{
    m_traders.insert(p_subscriber);
}

/*void marketData::onOrderExecution( const order& p_order)
  {
  // // this has to go through Market Data API
  // m_traders.insert(p_order.ID())->onTrade();
  // std::cout << "Order Executed" << std::endl;
  }*/


void marketData::publishPublicTrades()
{
    for ( auto& tr : m_traders )
    {
        tr->onPublicTrade();
    }  
}

/*void marketData::onTrade()
  {

  }*/

